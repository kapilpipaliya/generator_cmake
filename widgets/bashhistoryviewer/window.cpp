/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/
#include "./window.h"
#include <QClipboard>
#include <QtWidgets>
#include <fstream>
#include <iostream>
#include <sstream>

const string myHistoryFile = "~/.bash_history";
const string myFavouritesFile = "~/.bash_favourites";

using namespace std;
namespace widgets {
namespace bashHistoryViewer {
Window::Window() {
  myIcons = new Icons;
  myTab = new QTabWidget;
  myToolBar = new QToolBar;
  historyPage = new HistoryPage;
  favPage = new FavPage;

  myTab->addTab(historyPage->get(), "History");
  myTab->addTab(favPage->get(), "Favourites");
  myTab->setCurrentIndex(0);

  setCentralWidget(myTab);
  addToolBarItems();

  addToolBar(Qt::LeftToolBarArea, myToolBar);
}

string Window::execCommand(const char *cmd) {
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

void Window::addToolBarItems() {
  copyEntryButton = new QPushButton(*myIcons->ICON_COPY, "Copy");

  connect(copyEntryButton, &QPushButton::clicked, this, &Window::copyToClip);

  saveEntryButton = new QPushButton(*myIcons->ICON_HEART, "Add favourite");
  connect(saveEntryButton, &QPushButton::clicked, this,
          &Window::addToFavourites);

  deleteEntryButton = new QPushButton(*myIcons->ICON_DELETE, "Delete");
  connect(deleteEntryButton, &QPushButton::clicked, this,
          &Window::deleteTableLine);

  myToolBar->addWidget(saveEntryButton);
  myToolBar->addWidget(copyEntryButton);
  myToolBar->addWidget(deleteEntryButton);
}

int Window::writeFavourites(string favourites) {
  if (favourites != "" && favourites != "\n") {
    string str;
    stringstream ss;

    ss << "echo "
       << "'" << favourites << "'"
       << " >> " << myFavouritesFile << endl;
    str = ss.str();

    int r = system(str.c_str());
    // int result = system(("touch "+myFavouritesFile).c_str());
    if (favourites.find("'") != string::npos) {
      cout << "found!" << '\n';
    }
  }
  return 1;
}

void Window::deleteTableLine() {
  cout << "Delete row" << endl;
  favPage->proxyModel->removeRow(favPage->proxyView->currentIndex().row());
  emit favPage->proxyModel->dataChanged(favPage->proxyView->currentIndex(),
                                        favPage->proxyView->currentIndex());

  vector<string> arr;
  for (int i = 0; i < favPage->proxyModel->rowCount(); i++) {
    QModelIndex item = favPage->proxyModel->index(i, 0);
    string myString = item.data().toString().toStdString();
    arr.push_back(myString);
  }

  system(("rm " + myFavouritesFile).c_str());
  system(("touch " + myFavouritesFile).c_str());

  for (int i = 0; i < arr.size(); i++) {
    stringstream ss;
    ss << "echo '" << arr[i] << "' >> " << myFavouritesFile;
    string s = ss.str();
    int r = system(s.c_str());
  }
}

int Window::copyToClip() {
  int myIndex = myTab->currentIndex();
  if (myIndex == 1) {
    QString myHistItem = favPage->proxyView->currentIndex().data().toString();
    QClipboard *clipboard = QGuiApplication::clipboard();
    QString originalText = clipboard->text();
    clipboard->setText(myHistItem);
    // cout << "Copied successfully\n" << myHistItem.toStdString() << endl;

  } else if (myIndex == 0) {
    QString myFavItem =
        historyPage->proxyView->currentIndex().data().toString();
    // clip::set_text(myFavItem.toStdString());
    QClipboard *clipboard = QGuiApplication::clipboard();
    QString originalText = clipboard->text();
    clipboard->setText(myFavItem);
    // cout << "Copied successfully\n" << myFavItem.toStdString() << endl;
  }
  return 0;
}

void Window::addToFavourites() {
  QModelIndex myCurrentItem = historyPage->proxyView->currentIndex();
  QString myText = myCurrentItem.data().toString();
  // string myString = myText.toStdString();
  int newItemIndex = favPage->proxyModel->rowCount();
  favPage->proxyModel->insertRow(newItemIndex);
  favPage->proxyModel->setData(favPage->proxyModel->index(newItemIndex, 0),
                               myText);
  writeFavourites(myText.toUtf8().toStdString());
  emit favPage->proxyModel->dataChanged(myCurrentItem, myCurrentItem);
}

void Window::setSourceModel(QAbstractItemModel *model,
                            QAbstractItemModel *favModel) {
  historyPage->proxyModel->setSourceModel(model);
  historyPage->proxyView->scrollToBottom();
  favPage->proxyModel->setSourceModel(favModel);
  favPage->proxyView->scrollToBottom();
}

}  // namespace bashHistoryViewer
}  // namespace widgets
