#include "mainwinhigh.h"
#include <QMdiArea>
#include <QMdiSubWindow>
#include <QToolBar>
#include "sqlite/orm.h"
#include "sqlite_orm.h"
#include "widgets/json/jsongenerator.h"
#include "widgets/modelwriter/modelwriter.h"
#include "widgets/namespace/namespacegenerator.h"
#include "widgets/sqlcompare/sqlcompare.h"
#include "widgets/stl/stl.h"
#include "widgets/yaml/yamlgenerator.h"

MainWinHigh::MainWinHigh(QWidget *parent) : MainWindow(parent) {
  setWindowTitle(tr("Generator Software"));

  //    M_DB dbConnection = M_DB(0);
  //    QPixmap p1 = dbConnection.getImage();
  // QPixmap p2 = p1.scaled(500, 500, Qt::KeepAspectRatio); // on constructor we
  // not have proper size of label.
  //    this->setWindowIcon(p1);

  auto newToolBar = new QToolBar(this);
  addToolBar(Qt::TopToolBarArea, newToolBar);

  auto yamlAction = new QAction("Yaml");
  newToolBar->addAction(yamlAction);
  connect(yamlAction, &QAction::triggered, [this]() {
    auto child = new widgets::YamlGenerator();
    addMdiChild(child);
    child->show();
  });
  auto jsonAction = new QAction("Json");
  newToolBar->addAction(jsonAction);
  connect(jsonAction, &QAction::triggered, [this]() {
    auto child = new widgets::JsonGenerator();
    addMdiChild(child);
    child->show();
  });
  auto drogon_model_action = new QAction("drogon model");
  newToolBar->addAction(drogon_model_action);
  connect(drogon_model_action, &QAction::triggered, [this]() {
    auto child = new widgets::ModelWriter();
    addMdiChild(child);
    child->show();
  });
  auto namespaceAction = new QAction("namespace");
  newToolBar->addAction(namespaceAction);
  connect(namespaceAction, &QAction::triggered, [this]() {
    auto child = new widgets::NameSpaceGenerator();
    addMdiChild(child);
    child->show();
  });
  auto sqlcompareAction = new QAction("sqlcompare");
  newToolBar->addAction(sqlcompareAction);
  connect(sqlcompareAction, &QAction::triggered, [this]() {
    auto child = new widgets::SqlCompare();
    addMdiChild(child);
    child->show();
  });
  auto stlAction = new QAction("STL");
  newToolBar->addAction(stlAction);
  connect(stlAction, &QAction::triggered, [this]() {
    auto child = new widgets::Stl();
    addMdiChild(child);
    child->show();
  });

  Orm m;
}

void MainWinHigh::adminLoggedIn() {
  this->show();
  configToolBar = new QToolBar(tr("config"), this);
  addToolBar(Qt::LeftToolBarArea, configToolBar);
  // fileToolBar->addAction(configAct);
}

void MainWinHigh::userLoggedIn() { this->show(); }

void MainWinHigh::showConfigDialog() {
  //  confDialog = new ConfDialog(this);
  //  confDialog->show();
}

QWidget *MainWinHigh::createMdiChild() {
  auto child = new widgets::ModelWriter(this);
  QMdiSubWindow *subWindow = mdiArea->addSubWindow(child);
  subWindow->setWindowIcon(QIcon(":/images/copy.png"));
  subWindow->resize(1100, 800);
  return child;
}
void MainWinHigh::addMdiChild(QWidget *child) {
  QMdiSubWindow *subWindow = mdiArea->addSubWindow(child);
  subWindow->setWindowIcon(QIcon(":/images/copy.png"));
  subWindow->resize(1100, 800);
}

void MainWinHigh::newFile() {
  QWidget *child = createMdiChild();
  child->show();
}

/*
void MainWinHigh::open()
{
    QString fileName = QFileDialog::getOpenFileName(this);
    if (!fileName.isEmpty()) {
        QMdiSubWindow *existing = findMdiChild(fileName);
        if (existing) {
            mdiArea->setActiveSubWindow(existing);
            return;
        }

        QWidget *child = createMdiChild();
        if (child->loadFile(fileName)) {
            statusBar()->showMessage(tr("File loaded"), 2000);
            child->show();
        } else {
            child->close();
        }
    }
}
*/
void MainWinHigh::save() {
  //  if (activeMdiChild() && activeMdiChild()->save())
  //    statusBar()->showMessage(tr("File saved"), 2000);
}
