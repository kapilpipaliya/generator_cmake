#include "./syncroute.h"

#include <unistd.h>

#include <boost/algorithm/string.hpp>
#include <boost/filesystem.hpp>
#include <fstream>
#include <iostream>
#include <regex>
#include <string>

#include "thirdparty/pystring/pystring.h"

namespace widgets {

SyncRoute::SyncRoute(QWidget *parent) : QWidget(parent) {
  routesFilePath = "/home/kapili3/jdragon/model_instructions/routes.txt";

  init();
  initTextEdit();
}

void SyncRoute::init() {
  auto v1 = new QVBoxLayout(this);

  auto buttons_h = new QHBoxLayout();
  auto syncnowButton = new QToolButton(this);
  syncnowButton->setText("sync now!");
  buttons_h->addWidget(syncnowButton);

  resultText = new QTextEdit(this);

  v1->addItem(buttons_h);
  v1->addWidget(resultText);

  connect(syncnowButton, &QToolButton::clicked, this, &SyncRoute::sync);
}

void SyncRoute::initTextEdit() {
  auto content1 = QString::fromStdString(read_all(routesFilePath));
  resultText->setText(content1);
}

void SyncRoute::sync() {
  // write c++ and js route file

  // save
  {
    std::ofstream oRouteFile(routesFilePath, std::ofstream::out);
    if (!oRouteFile) {
      perror("");
      exit(1);
    }
    oRouteFile << resultText->toPlainText().toStdString();
  }
  // generate c++ file
  {
    auto cppEnumFilePath = "/home/kapili3/jdragon/actor/timeroutes.h";
    std::ofstream oRouteFile(cppEnumFilePath, std::ofstream::out);
    if (!oRouteFile) {
      perror("");
      exit(1);
    }
    auto a = R"(#ifndef TIMEROUTES_H
#define TIMEROUTES_H
namespace superactor {
namespace todoactor {
enum all_services { )";
    oRouteFile << a << "\n";

    auto stringlist = resultText->toPlainText().split("\n");
    std::vector<std::string> list;
    for (auto &s : stringlist) {
      if (!s.trimmed().isEmpty()) {
        list.push_back(s.toStdString());
      }
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
      if (!oRouteFile) {
        perror("");
        exit(1);
      }
      oRouteFile << "export enum event {\n";
      auto stringlist = resultText->toPlainText().split("\n");
      std::vector<std::string> list;
      for (auto &s : stringlist) {
        if (!s.trimmed().isEmpty()) {
          list.push_back(s.toStdString());
        }
      }
      oRouteFile << pystring::join(",\n", list);
      oRouteFile << "\n"
                 << "}";
    }
    // run tsc compiler:
    {
      auto command =
          "cd /home/kapili3/k/svelte/sapper/time_management && yarn event";
      system(command);
    }
  }
}

}  // namespace widgets
