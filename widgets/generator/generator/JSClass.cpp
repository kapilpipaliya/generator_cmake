
#include "./JSClass.h"
//#include <drogon/DrTemplateBase.h>
//#include <drogon/utils/Utilities.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fstream>
#include <iostream>
#include <regex>
#include <string>
//#include "pystring/pystring.hpp"
JSClass::JSClass(const std::vector<std::string> &controllers, const std::string &arguments) : controllers(controllers), arguments(arguments)
{
  _outputPath =
      "/home/kapili3/k/svelte/sapper/time_management/src/routes/_js/protos/"
      "time/";
}
JSClass::~JSClass() {}
std::string JSClass::generate(std::string namespacereq, bool commentreq, std::string namespaceres, bool commentres)
{
  if (controllers.size() < 1) { std::cout << "Invalid parameters!" << std::endl; }
  for (auto className : controllers)
  {
    auto output_dir = getOutputPath(_outputPath, className);
    {
      std::regex regex("::");
      std::string fileName = std::regex_replace(className, regex, std::string("_"));
      std::string headFileName = output_dir + fileName + ".js";
      createDirectory(headFileName);
      auto content1 = read_all(headFileName);
      /* javascript class is not helpful instead use components composition
--client_class
filename:auth/kapil/Login.svelte


      --end
      */
      /*{
        std::ofstream oHeadFile(headFileName.c_str(), std::ofstream::out);
        if (!oHeadFile) {
          perror("");
          exit(1);
        }
        createClassFile(oHeadFile, className, fileName, content1, namespacereq,
                        commentreq, namespaceres, commentres);
      }*/
    }
    {
      std::string routeFileName;
      std::smatch match;
      if (std::regex_search(arguments, match, std::regex("filename:(.*)")))
      {
        //    for (size_t i = 0; i < controller_match.size(); ++i)
        //      std::cout << i << ": " << controller_match[i] << '\n';
        routeFileName = match[1];
      }
      if (!routeFileName.empty())
      {
        std::string routeFileFullPath = "/home/kapili3/k/svelte/sapper/time_management/src/routes/" + routeFileName;
        auto count = countMatchInRegex(routeFileName, "\\/");
        createDirectory(routeFileFullPath);
        auto content_route = read_all(routeFileFullPath);
        std::ofstream oRouteFile(routeFileFullPath, std::ofstream::out);
        if (!oRouteFile)
        {
          perror("");
          exit(1);
        }
        createRouteFiles(oRouteFile, className, routeFileFullPath, content_route, count, namespacereq, commentreq, namespaceres, commentres);
      }
    }
    std::cout << "create a javascript class:" << className << std::endl;
  }
  return "created a service: ";
}
/*void JSClass::createClassFile(std::ofstream &file, const std::string
&className, const std::string &fileName, const std::string &content, std::string
namespacereq, bool commentreq, std::string namespaceres, bool commentres) {
  std::vector<std::string> v;
  pystring::split(className, v, "::");
  auto class_ = v.at(v.size() - 1);

  std::string fileName_ =
      std::regex_replace(className, std::regex("\\.js"), std::string(""));

  file << "import BaseService from '../../../baseservice.js'\n";
  file << "const " + class_ +
              "Request = "
              "require('./proto/" +
              fileName_ + "Request_pb.js')\n";
  file << "const " + class_ +
              "Response = "
              "require('./proto/" +
              fileName_ + "Response_pb.js')\n";
  file << "export class " << class_ << " extends BaseService {\n";
  file << "  constructor() {\n";
  file << "    this." + class_ + "Request = new " + class_ + "Request();\n"
       << "    this." + class_ + "Response = new " + class_ + "Response();\n"
       << "  }\n";
  file << "  // extend_class\n";
  auto find = find_section_in_string(content, "// extend_class");
  file << find;
  file << "  // extend_class_end\n";
  file << "};\n";
}*/
void JSClass::createRouteFiles(std::ofstream &file,
                               const std::string &className,
                               const std::string &filePath,
                               const std::string &content,
                               long parentno,
                               std::string namespacereq,
                               bool commentreq,
                               std::string namespaceres,
                               bool commentres)
{
  // std::vector<std::string> v;
  // pystring::split(className, v, "::");
  // auto class_ = v.at(v.size() - 1);
  auto output_dir = getOutputPath("_js/protos/time/", className);
  std::string fileName_ = std::regex_replace(className, std::regex("::"), std::string("_"));
  /*auto path = boost::filesystem::path(filePath);
  std::string filename = path.filename().string();
  // auto contxtfname = "/_" + pystring::replace(filename, ".svelte",
  // "-1-ctx.js"); auto instfname = "/_" + pystring::replace(filename, ".svelte",
  // "-2-inst.js"); auto stylefname = "/_" + pystring::replace(filename,
  // ".svelte", "-3.less");
  auto templfname = "/_" + pystring::replace(filename, ".svelte", ".pug");*/
  std::string dirdot;
  for (int i = 0; i < parentno; ++i) { dirdot += "../"; }
  if (parentno == 0) { dirdot = "./"; }
  {// generate main file.
   // file << "<script src='." << contxtfname << "'
   // context='module'></script>\n";
   /*{
     file << "<script context='module'>\n";
     if (commentreq) file << "//";
     file << "import {" << namespacereq << " as Req} from '" << dirdot;
     file << output_dir << "proto/" << fileName_ << "Request_pb.js'\n";
     if (commentres) file << "//";
     file << "import {" << namespaceres << " as Res} from '" << dirdot;
     file << output_dir << "proto/" << fileName_ << "Response_pb.js'\n";
     file << "import { Ws } from '" << dirdot << "_js/ws/ws_todo.js'\n";
     file << "import {event} from '" + dirdot + "_js/events/event.js'\n";

     file << "// ctx_import\n";
     auto find_ctx_import = find_section_in_string(content, "// ctx_import");
     file << find_ctx_import;
     file << "// ctx_import_end\n";

     file << "export async function preload(page, session) {\n";
     file << "Ws.setupConnection(this.req, this.res)\n";

     // not need more lines:
     // file << "// const " << pystring::firstlower(namespacereq) << " = new ";
     // file << namespacereq + "\n";

     file << "// export\n";
     auto find_export_fn = find_section_in_string(content, "// export");
     file << find_export_fn;
     file << "// export_end\n";

     file << "}\n";

     // There is no need for this block
     //file << "// ctx\n";
     //auto find_script_context = find_section_in_string(content, "// ctx");
     //file << find_script_context;
     //file << "// ctx_end\n";

     file << "</script>\n";
   }*/
   // file << "<script src='." << instfname << "'></script>\n";
   {file << "<script>\n";
  /*{
    file << "// import {" << namespacereq << "} from '";
    file << dirdot;
    file << output_dir << "proto/" << fileName_ << "Request_pb.js'\n";
    file << "// import {" << namespaceres << "} from '";
    file << dirdot;
    file << output_dir << "proto/" << fileName_ << "Response_pb.js'\n";
    file << "// import {event} from '" + dirdot + "_js/events/event.js'\n";
    file << "if(process.browser){ S.setupConnection() }\n";
  }*/
  // file << "// inst\n";
  auto find_script = find_section_in_string(content, "// inst");
  if (find_script.empty())
  {
    auto c = R"(import { onMount, onDestroy } from "svelte";
let data = []

const fetch = () => {
  const req = new Req()
  const bytes = req.serializeBinary()

  Ws.trigger(event.{0}, 0, bytes)
}
fetch()
onMount(()=>{
  Ws.bind(event.admin_user_user_list, 0, 1, (bytes) => {
    const res = Res.deserializeBinary(bytes)
    switch (res.getStatus()) {
      case Res.ErrorStatus.OK:
        menu_data = res.getJson()
        console.log(menu_data)
        break;
      case Res.ErrorStatus.UNAUTHORISED:
        err(res.getErrorMsg())
        break
      default:
        err(res.getErrorMsg())
        break;
    }
  })
})
onDestroy(()=> {
  Ws.unbind(event.{0}, 0)
}))";
    /*find_script =
        fmt::format(c, pystring::lower(std::regex_replace(
                           className, std::regex("::"), std::string("_"))));*/
  }
  // file << find_script;
  // file << "// inst_end\n";
  file << "</script>\n";
}
// file << "<style src='." << stylefname << "' lang='less'></style>\n";
/*file << "<template src='." << templfname << "'></template>\n";*/
// file << "<!-- component -->\n";
// auto find = find_section_in_string(content, "<!-- component -->",
//                                   "<!-- component_end -->");
// file << find;
// file << "<!-- component_end -->\n";
}
// create context file
/*{
  auto filepath = path.parent_path().string() + contxtfname;
  auto file_read = read_all(filepath);
  std::ofstream oFile(filepath.c_str(), std::ofstream::out);
  if (!oFile) {
    perror("");
    exit(1);
  }
  if (commentreq) oFile << "//";
  oFile << "import {" << namespacereq << "} from '";
  for (int i = 0; i < parentno; ++i) {
    oFile << "../";
  }
  oFile << output_dir << "proto/" << fileName_ << "Request_pb.js'\n";
  if (commentres) oFile << "//";
  oFile << "import {" << namespaceres << "} from '";
  for (int i = 0; i < parentno; ++i) {
    oFile << "../";
  }
  oFile << output_dir << "proto/" << fileName_ << "Response_pb.js'\n";
  oFile << "// export async function preload(page, session) {return {}}\n";
  oFile << "// const " << pystring::firstlower(namespacereq) << " = new "
        << namespacereq + "\n";
  oFile << "// manual_script\n";

  auto find_script_context =
      find_section_in_string(file_read, "// manual_script");
  oFile << find_script_context;
  oFile << "// manual_script_end\n";
}*/
/*{
  auto filepath = path.parent_path().string() + instfname;
  auto file_read = read_all(filepath);
  std::ofstream oFile(filepath.c_str(), std::ofstream::out);
  if (!oFile) {
    perror("");
    exit(1);
  }
  {
    oFile << "//";
    oFile << "import {" << namespacereq << "} from '";
    for (int i = 0; i < parentno; ++i) {
      oFile << "../";
    }
    oFile << output_dir << "proto/" << fileName_ << "Request_pb.js'\n";
    oFile << "//";
    oFile << "import {" << namespaceres << "} from '";
    for (int i = 0; i < parentno; ++i) {
      oFile << "../";
    }
    oFile << output_dir << "proto/" << fileName_ << "Response_pb.js'\n";
  }
  oFile << "import {event} from '" + dirdot + "_js/events/event.js'\n";
  oFile << "if(process.browser){ S.setupConnection() }\n";
  oFile << "// instance_script\n";
  auto find_script = find_section_in_string(file_read, "// instance_script");
  oFile << find_script;
  oFile << "// instance_script_end\n";
}*/
//  {
//    auto filepath = path.parent_path().string() + stylefname;
//    auto file_read = read_all(filepath);
//    std::ofstream oFile(filepath.c_str(), std::ofstream::out);
//    if (!oFile) {
//      perror("");
//      exit(1);
//    }
//    oFile << "/* style */\n";
//    auto find_style = find_section_in_string(file_read, "\\/\\* style
//    \\*\\/",
//                                             "\\/\\* style_end \\*\\/");
//    oFile << find_style;
//    oFile << "/* style_end */\n";
//  }
{
  /*auto filepath = path.parent_path().string() + templfname;
  auto file_read = read_all(filepath);
  std::ofstream oFile(filepath.c_str(), std::ofstream::out);
  if (!oFile) {
    perror("");
    exit(1);
  }*/
  // oFile << "//- pug\n";
  // auto find = find_section_in_string(file_read, "//- pug");
  // oFile << find;
  // oFile << "//- pug_end\n";
}
}
