#include "./syncroute.h"
#include <unistd.h>
//#include <boost/algorithm/string.hpp>
//#include <boost/filesystem.hpp>
#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include "pystring/pystring.hpp"
namespace gen
{
SyncRoute::SyncRoute(QWidget *parent) : QWidget(parent) { routesFilePath = drogonPath + "model_instructions/routes.txt"; }
void SyncRoute::sync(const std::string &content)
{
  // write c++ and js route file
  // generate c++ file
  {
    auto cppEnumFilePath = drogonPath + "/actor/timeroutes.h";
    std::ofstream oRouteFile(cppEnumFilePath, std::ofstream::out);
    if (!oRouteFile)
    {
      perror("");
      exit(1);
    }
    auto a = R"(#ifndef TIMEROUTES_H
#define TIMEROUTES_H
namespace superactor {
namespace todoactor {
enum all_services { )";
    oRouteFile << a << "\n";
    auto stringlist = QString::fromStdString(content).split("\n");
    std::vector<std::string> list;
    for (auto &s : stringlist)
    {
      if (!s.trimmed().isEmpty()) { list.push_back(s.toStdString()); }
    }
    oRouteFile << pystring::join(",\n", list);
    auto b = R"(};
}
}
#endif // TIMEROUTES_H
)";
    oRouteFile << "\n" << b;
  }
  // generate js file
  {
    auto jsEnumFilePath =
        "/home/kapili3/k/svelte/sapper/time_management/src/routes/_js/events/"
        "event.ts";
    {
      std::ofstream oRouteFile(jsEnumFilePath, std::ofstream::out);
      if (!oRouteFile)
      {
        perror("");
        exit(1);
      }
      oRouteFile << "export enum event {\n";
      auto stringlist = QString::fromStdString(content).split("\n");
      std::vector<std::string> list;
      for (auto &s : stringlist)
      {
        if (!s.trimmed().isEmpty()) { list.push_back(s.toStdString()); }
      }
      oRouteFile << pystring::join(",\n", list);
      oRouteFile << "\n"
                 << "}";
    }
    // run tsc compiler:
    {
      auto command = "cd /home/kapili3/k/svelte/sapper/time_management && yarn event";
      system(command);
    }
  }
}
}  // namespace gen
