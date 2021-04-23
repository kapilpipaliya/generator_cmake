
#include "./ControllerEntry.h"
//#include <boost/algorithm/string.hpp>
#include <fstream>
#include <iostream>
#include <regex>
#include "./syncroute.h"
#include "pystring/pystring.hpp"
ControllerEntry::ControllerEntry(const std::vector<std::string> &controllers, const std::string &arguments) : controllers(controllers), arguments(arguments) {}
ControllerEntry::~ControllerEntry() {}
std::string ControllerEntry::generate(bool eventadd, bool protoadd)
{
  if (!eventadd && !protoadd) { return ""; }
  if (controllers.size() < 1) { std::cout << "Invalid parameters!" << std::endl; }
  auto routesFilePath = drogonPath + "model_instructions/routes.txt";
  auto routefilecontent = read_all(routesFilePath);
  std::ofstream oRouteFile(routesFilePath, std::ofstream::out);
  if (!oRouteFile)
  {
    perror("");
    exit(1);
  }
  std::string r = "";
  for (auto className : controllers)
  {
    // update cmakelist file.
    auto cmakefile = cppTimePath + "CMakeLists.txt";
    auto cmakecontent = read_all(cmakefile);
    std::ofstream oCMakeFile(cmakefile, std::ofstream::out);
    if (!oCMakeFile)
    {
      perror("");
      exit(1);
    }
    auto todoactorFile = drogonPath + "actor/todoactor.cpp";
    auto todoactorcontent = read_all(todoactorFile);
    std::ofstream oTodoActorFile(todoactorFile, std::ofstream::out);
    if (!oTodoActorFile)
    {
      perror("");
      exit(1);
    }
    std::regex regex("::");
    if (eventadd)
    {
      std::string includeline;
      includeline += "#include \"service/time/";
      std::vector<std::string> spiltv;
      pystring::split(className, spiltv, "::");
      std::string result{};
      for (unsigned long i = 0; i < spiltv.size(); ++i) { result += pystring::lower(spiltv[i]) + "/"; }
      std::string enumname;
      enumname += std::regex_replace(className, regex, std::string("_"));
      includeline += result + enumname;
      includeline += ".h\"";
      {
        if (pystring::find(todoactorcontent, includeline) == -1)
        {
          std::smatch match;
          todoactorcontent = pystring::replace(todoactorcontent, "// auto_include_above", includeline + "\n// auto_include_above");
        }
      }
      std::string eventline;
      eventline += "    if (event1 == " + pystring::lower(enumname) + ") {" + "\n";
      eventline += "      handleService<timeservice::" + className + ">(event1, event2, wsConnPtr, contx, std::move(message));" + "\n    }";
      {
        if (pystring::find(todoactorcontent, eventline) == -1)
        {
          std::smatch match;
          todoactorcontent = pystring::replace(todoactorcontent, "    // auto_event_above", eventline + "\n    // auto_event_above");
        }
        {
          if (pystring::find(routefilecontent, pystring::lower(enumname)) == -1)
          {
            std::smatch match;
            routefilecontent += "\n" + pystring::lower(enumname);
          }
        }
      }
      /*{
        r += "add this path to " + cppTimePath +
             "CMakeLists.txt:\n";
        r += "AUX_SOURCE_DIRECTORY(./" +
             pystring::lower(
                 std::regex_replace(className, regex, std::string("/"))) +
             " SRC)" + "\n";
      }*/
      {
        std::string c1 = "AUX_SOURCE_DIRECTORY(./" + pystring::lower(std::regex_replace(className, regex, std::string("/"))) + " SRC)";
        if (pystring::find(cmakecontent, c1) == -1)
        {
          std::smatch match;
          cmakecontent = pystring::replace(cmakecontent, "#auto_source_above", c1 + "\n#auto_source_above");
        }
      }
    }
    if (protoadd)
    {
      std::string c2 = "AUX_SOURCE_DIRECTORY(./" + pystring::lower(std::regex_replace(className, regex, std::string("/"))) + "/proto SRC)";
      if (pystring::find(cmakecontent, c2) == -1)
      {
        std::smatch match;
        cmakecontent = pystring::replace(cmakecontent, "#auto_source_above", c2 + "\n#auto_source_above");
      }
    }
    oCMakeFile << cmakecontent;
    oTodoActorFile << todoactorcontent;
    oRouteFile << routefilecontent;
    gen::SyncRoute sync;
    sync.sync(routefilecontent);
  }
  return r;
}
