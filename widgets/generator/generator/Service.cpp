
#include "./Service.h"

#include <drogon/DrTemplateBase.h>
#include <drogon/utils/Utilities.h>
#include <fmt/format.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include <fstream>
#include <iostream>
#include <regex>
#include <string>

#include "thirdparty/pystring/pystring.h"

Service::Service(const std::vector<std::string> &controllers,
                 const std::string &arguments)
    : controllers(controllers), arguments(arguments) {}

Service::~Service() {}

std::string Service::generate() {
  if (controllers.size() < 1) {
    std::cout << "Invalid parameters!" << std::endl;
  }
  for (auto className : controllers) {
    auto output_dir = getOutputPath(cppTimePath, className);

    std::regex regex("::");
    std::string fileName =
        std::regex_replace(className, regex, std::string("_"));

    std::string headFileName = output_dir + fileName + ".h";
    std::string sourceFilename = output_dir + fileName + ".cpp";

    createDirectory(headFileName);
    // std::cout << headFileName << std::endl;
    auto content1 = read_all(headFileName);
    auto content2 = read_all(sourceFilename);
    {
      // overwrite without confirmation:
      /*
      std::ifstream iHeadFile(headFileName.c_str(), std::ifstream::in);
      std::ifstream iSourceFile(sourceFilename.c_str(), std::ifstream::in);

      if (iHeadFile || iSourceFile) {
        std::cout << "The file you want to create already exists, "
                     "overwrite it(y/n)?"
                  << std::endl;
        auto in = getchar();
        (void)getchar();  // get the return key
        if (in != 'Y' && in != 'y') {
          std::cout << "Abort!" << std::endl;
          exit(0);
        }
      }
      */
    }
    std::ofstream oHeadFile(headFileName.c_str(), std::ofstream::out);
    std::ofstream oSourceFile(sourceFilename.c_str(), std::ofstream::out);
    if (!oHeadFile || !oSourceFile) {
      perror("");
      exit(1);
    }

    std::cout << "create a service:" << className << std::endl;

    createFilterHeaderFile(oHeadFile, className, fileName, content1);
    createSourceFile(oSourceFile, className, fileName, content2);
  }
  return "created a service: ";
}

void Service::createFilterHeaderFile(std::ofstream &file,
                                     const std::string &className,
                                     const std::string &fileName,
                                     const std::string &content) {
  /*auto templ = drogon::DrTemplateBase::newTemplate("service_h");
drogon::HttpViewData data;
if (className.find("::") != std::string::npos) {
  auto namespaceVector = drogon::utils::splitString(className, "::");
  data.insert("className", namespaceVector.back());
  namespaceVector.pop_back();
  data.insert("namespaceVector", namespaceVector);
} else {
  data.insert("className", className);
}
data.insert("filename", fileName);
file << templ->genText(data);
*/

  file << "#pragma once\n";
  file << "#include \"service/time/timeservicebase.h\"\n";
  file << "#include \"./proto/" + fileName + "Request.pb.h\"\n";
  file << "#include \"./proto/" + fileName + "Response.pb.h\"\n";
  {
    file << "// inc\n";
    auto find2 = find_section_in_string(content, "// inc");
    file << find2;
    file << "// inc_end\n";
  }

  std::string class_name = className;
  std::string namepace_path = "/";
  auto pos = class_name.find("::");
  size_t namespaceCount = 0;
  file << "namespace timeservice\n{\n";
  while (pos != std::string::npos) {
    ++namespaceCount;
    auto namespaceName = class_name.substr(0, pos);
    class_name = class_name.substr(pos + 2);
    file << "namespace " << namespaceName << "\n";
    namepace_path.append(namespaceName).append("/");
    file << "{\n";
    pos = class_name.find("::");
  }
  file << "class " << class_name << ": public TimeServiceBase\n";
  {
    file << "/*inh*/\n";
    auto find =
        find_section_in_string(content, R"(/\*inh\*/)", R"(/\*inh_end\*/)");
    file << find;
    file << "/*inh_end*/\n";
  }

  file << "{\n";
  file << "  public:\n";
  file << "    " << class_name
       << "(int event1_, int event2_, const drogon::WebSocketConnectionPtr "
          "&wsConnPtr_,\n"
       << "        std::shared_ptr<websocket::todo::TodoContext> context_,\n"
       << "        std::string &&message_);\n";
  file << "  void run();\n";

  file << "  private:\n";
  file << "  // extend_class\n";
  auto find = find_section_in_string(content, "// extend_class");
  file << find;
  file << "  // extend_class_end\n";
  file << "};\n";
  if (namespaceCount > 0) {
    do {
      if (namespaceCount > 0) {
        --namespaceCount;
      }
      file << "}\n";
    } while (namespaceCount > 0);
  }
  file << "}\n";
}

void Service::createSourceFile(std::ofstream &file,
                               const std::string &className,
                               const std::string &fileName,
                               const std::string &content) {
  /*auto templ = drogon::DrTemplateBase::newTemplate("service_cc");
drogon::HttpViewData data;
if (className.find("::") != std::string::npos) {
  auto pos = className.rfind("::");
  data.insert("namespaceString", className.substr(0, pos));
  data.insert("className", className.substr(pos + 2));
} else {
  data.insert("className", className);
}
data.insert("filename", fileName);
file << templ->genText(data);*/

  file << "#include \"./" << fileName << ".h\"\n";

  auto class_name = "timeservice::" + className;

  std::vector<std::string> v;
  pystring::split(className, v, "::");
  file << class_name << "::" + v.at(v.size() - 1) + "(\n";
  file << "    int event1_, int event2_, const drogon::WebSocketConnectionPtr "
          "&wsConnPtr_,\n";
  file << "    std::shared_ptr<websocket::todo::TodoContext> context_,\n";
  file << "    std::string &&message_)\n";
  file << "    : TimeServiceBase(event1_, event2_, wsConnPtr_, context_,\n";
  file << "                      std::move(message_))\n";

  {
    file << "/*inh*/\n";
    auto find =
        find_section_in_string(content, R"(/\*inh\*/)", R"(/\*inh_end\*/)");
    file << find;
    file << "/*inh_end*/\n";
  }
  file << "{}\n";

  file << "void " << class_name << "::run() {\n";
  file << "  // run\n";
  auto find = find_section_in_string(content, "// run");
  if (find.empty()) {
    auto c =
        R"(  timeservice::{0}Request *msg = getmsg<timeservice::{0}Request>();

  auto res = new timeservice::{0}Response();
  //res->set_json(data);
  sendmsg<timeservice::{0}Response>(res);)";
    find = fmt::format(c, pystring::lower(std::regex_replace(
                              className, std::regex("::"), std::string("_"))));
  }
  file << find;
  file << "  // run_end\n";
  file << "}\n";
  file << "// extend_class\n";
  auto find2 = find_section_in_string(content, "// extend_class");
  file << find2;
  file << "// extend_class_end\n";
}
