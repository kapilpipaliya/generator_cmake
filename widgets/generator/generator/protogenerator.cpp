#include "./protogenerator.h"
//#include <boost/algorithm/string.hpp>
//#include <boost/filesystem.hpp>
#include <fstream>
#include <iostream>
#include <regex>
#include "pystring/pystring.hpp"
ProtoGenerator::ProtoGenerator(const std::vector<std::string> &controllers, const std::string &arguments) : controllers(controllers), arguments(arguments) {}
ProtoGenerator::~ProtoGenerator() {}
std::string ProtoGenerator::generate(std::string suffix, std::string namespace_, bool comment)
{
  saveProtoFile(suffix, namespace_, comment);
  compileProtoFile(suffix, namespace_, comment);
  return "";
}
void ProtoGenerator::saveProtoFile(const std::string &suffix, std::string namespace_, bool comment)
{
  // set output path:
  auto className = controllers.at(0);
  auto output_dir = getOutputPath(cppTimePath, className);
  std::regex regex("::");
  std::string fileName = std::regex_replace(className, regex, std::string("_"));
  protoFile = output_dir + "proto/" + fileName + suffix + ".proto";
  createDirectory(protoFile);
  std::ofstream oHeadFile(protoFile.c_str(), std::ofstream::out);
  oHeadFile << arguments;
}
void ProtoGenerator::compileProtoFile(const std::string &suffix, std::string namespace_, bool comment)
{
  std::string jspath =
      "/home/kapili3/k/svelte/sapper/time_management/src/routes/_js/protos/"
      "time/";
  auto className = controllers.at(0);
  jspath += pystring::lower(std::regex_replace(className, std::regex("::"), std::string("/")));
  jspath += "/proto/";
  /*auto protofilename = boost::filesystem::path(protoFile).filename().string();
  auto j_file =
      std::regex_replace(protofilename, std::regex("\\.proto"), "_pb.js");
  std::string deletejs = "cd " + jspath + " && rm " + j_file;
  system(deletejs.c_str());

  // c files is at same place where proto file is
  auto c_folder = boost::filesystem::path(protoFile).parent_path();
  // note h_file and cc_file is full path of file.
  auto h_file = std::regex_replace(protoFile, std::regex("\\.proto"), ".pb.h");
  auto cc_file =
      std::regex_replace(protoFile, std::regex("\\.proto"), ".pb.cc");
  auto del_c_files =
      "cd " + c_folder.string() + " && rm " + h_file + " && rm " + cc_file;
  //[^\/]*\.proto
  system((del_c_files.c_str()));*/
  std::string p;
  // you can see generate_proto.sh on d-graph-js client.
  p += " cd " + cppServicePath +
       " && "
       "/home/kapili3/k/cpp_stuff/vcpkg/packages/protobuf_x64-linux/tools/"
       "protobuf/protoc --plugin=protoc-gen-ts=/usr/local/bin/protoc-gen-ts ";
  p += std::string("--cpp_out=") + ". ";
  // out_dir must exist.
  p += "--js_out=import_style=commonjs,binary:/home/kapili3/k/svelte/sapper/"
       "time_management/src/routes/_js/protos "
       "--ts_out=service=false:/home/kapili3/k/svelte/sapper/time_management/"
       "src/routes/_js/protos ";
  std::string protoFileFixed = std::regex_replace(protoFile, std::regex(cppServicePath), ".");
  p += protoFileFixed;
  std::cout << p << std::endl;
  system(p.c_str());
}
