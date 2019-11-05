#include <QApplication>
#include <QFile>
#include <QPalette>
#include <QStandardItemModel>
#include <QStyleFactory>
#include <QTextStream>
#include <QTime>
#include <array>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <string>
#include "./window.h"
using namespace std;

static int mySize;

const string myHistoryFile = "~/.bash_history";
const string myFavouritesFile = "~/.bash_favourites";

void addTableLine(QAbstractItemModel *model, const QString &text) {
  model->insertRow(0);
  model->setData(model->index(0, 0), text);
}

string exec(const char *cmd) {
  array<char, 128> buffer;
  string result;
  unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
  if (!pipe) {
    throw runtime_error("popen() failed!");
  }
  while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
    result += buffer.data();
  }
  return result;
}

vector<string> splitToVector(string wanted) {
  vector<string> arr;
  istringstream input;
  input.str(wanted);
  for (string line; getline(input, line);) {
    // cout<< line << endl;
    arr.push_back(line);
  }
  return arr;
}

QAbstractItemModel *createHistoryModel(QObject *parent) {
  QStandardItemModel *model = new QStandardItemModel(0, 1, parent);
  model->setHeaderData(0, Qt::Horizontal, QObject::tr("History"));
  string rawHistory;
  string catHistFile = "cat " + myHistoryFile;
  string touchHistFile = "touch " + myHistoryFile;
  int result = system("bash history -a");
  rawHistory = exec(catHistFile.c_str());

  vector<string> myCleanHistory;
  myCleanHistory = splitToVector(rawHistory);
  mySize = myCleanHistory.size();

  for (int i = mySize; i > -1; i--) {
    try {
      if (myCleanHistory[i] != "" && myCleanHistory[i] != "\n" &&
          myCleanHistory[i] != "\n" != NULL) {
        QString myString = QString::fromStdString(myCleanHistory[i]);
        addTableLine(model, myString);
      }
    } catch (exception) {
      cout << "File was empty" << endl;
    }
  }
  return model;
}

QAbstractItemModel *createFavouritesModel(QObject *parent) {
  QStandardItemModel *model = new QStandardItemModel(0, 1, parent);
  model->setHeaderData(0, Qt::Horizontal, QObject::tr("Favourites"));

  string rawHistory;
  string catFavFile = "cat " + myFavouritesFile;
  string touchFavFile = "touch " + myFavouritesFile;

  cout << "Creating favourites file" << endl;
  system(touchFavFile.c_str());
  rawHistory = exec(catFavFile.c_str());

  vector<string> myCleanHistory;
  myCleanHistory = splitToVector(rawHistory);
  mySize = myCleanHistory.size();

  for (int i = mySize - 1; i > -1; i--) {
    try {
      if (myCleanHistory[i] != "" && myCleanHistory[i] != "\n" &&
          myCleanHistory[i] != "\n" != NULL) {
        QString myString = QString::fromStdString(myCleanHistory[i]);
        addTableLine(model, myString);
      }
    } catch (exception) {
      stringstream msg;
      msg << "Exception at index " << i;
      cout << msg.str() << endl;
    }
  }
  return model;
}

QWidget *getBashHistoryViewer() {
  auto window1 = new widgets::bashHistoryViewer::Window;

  qApp->setStyle(QStyleFactory::create("Fusion"));

  QPalette darkPalette;
  darkPalette.setColor(QPalette::Window, QColor(53, 53, 53));
  darkPalette.setColor(QPalette::WindowText, Qt::white);
  darkPalette.setColor(QPalette::Base, QColor(25, 25, 25));
  darkPalette.setColor(QPalette::AlternateBase, QColor(53, 53, 53));
  darkPalette.setColor(QPalette::ToolTipBase, Qt::white);
  darkPalette.setColor(QPalette::ToolTipText, Qt::white);
  darkPalette.setColor(QPalette::Text, Qt::white);
  darkPalette.setColor(QPalette::Button, QColor(53, 53, 53));
  darkPalette.setColor(QPalette::ButtonText, Qt::white);
  darkPalette.setColor(QPalette::BrightText, Qt::red);
  darkPalette.setColor(QPalette::Link, QColor(42, 130, 218));
  darkPalette.setColor(QPalette::Highlight, QColor(42, 130, 218));
  darkPalette.setColor(QPalette::HighlightedText, Qt::black);

  qApp->setPalette(darkPalette);

  qApp->setStyleSheet(
      "QToolTip { color: #ffffff; background-color: #2a82da; border: 1px solid "
      "white; }");

  window1->setSourceModel(createHistoryModel(window1),
                          createFavouritesModel(window1));
  window1->show();
  return window1;
}
