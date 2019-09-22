#include <QApplication>
#include "mainwinhigh.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  MainWinHigh w;
  //  drogon::app().loadConfigFile("./config.json");
  // auto clientPtr = drogon::app().getDbClient("sce");
  w.show();

  return a.exec();
}
