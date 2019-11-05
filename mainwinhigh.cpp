#include "./mainwinhigh.h"

#include <QMdiArea>
#include <QMdiSubWindow>
#include <QToolBar>

#include "sqlite/orm.h"
#include "sqlite_orm.h"
#include "widgets/apihandler/apihandler.h"
#include "widgets/bashhistoryviewer/initialfunctions.h"
#include "widgets/bashhistoryviewer/window.h"
#include "widgets/bashrcconfig/window.h"
#include "widgets/bookmarks/bookmarks.h"
#include "widgets/classgenerator/classgenerator.h"
#include "widgets/dgraphcode/dgraphcodegenerator.h"
#include "widgets/generator/gui/Genmainwinhigh.h"
#include "widgets/modelwriter/modelwriter.h"
#include "widgets/querybuilder/querybuilder.h"
#include "widgets/reminder/reminderwidget.h"
#include "widgets/scripter/scripter.h"
#include "widgets/sqlcompare/sqlcompare.h"
#include "widgets/stl/stl.h"
#include "widgets/svelte/sveltegenerator.h"
#include "widgets/syncroute/syncroute.h"
#include "widgets/wstest/wstest.h"
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

  auto bashrcconfigAction = new QAction("bashrc-config", this);
  newToolBar->addAction(bashrcconfigAction);
  connect(bashrcconfigAction, &QAction::triggered, [this]() {
    auto child = new widgets::bashrcconfig::Window();
    addMdiChild(child);
    child->show();
  });

  QString IV1, IV2, IV3, AppName;
  IV1 = "0";
  system(qPrintable("echo " + IV1 + " > /tmp/Scripter-Theme"));
  IV2 = ".";
  system(qPrintable("echo " + IV2 + " > /tmp/Scripter-Path"));
  IV3 = "~/my_scripts/programms/";
  system(qPrintable("echo " + IV3 + " > /tmp/Scripter-SH-Path"));
  AppName = "codegen";
  system(qPrintable("pidof " + AppName + " | wc -w > /tmp/Scripter-Task"));
  auto scripterAction = new QAction("scripter", this);
  newToolBar->addAction(scripterAction);
  connect(scripterAction, &QAction::triggered, [this]() {
    auto child = new widgets::Scripter();
    addMdiChild(child);
    child->show();
  });

  auto generatorAction = new QAction("generator", this);
  generatorAction->setShortcuts({QKeySequence(tr("Ctrl+G"))});
  newToolBar->addAction(generatorAction);
  connect(generatorAction, &QAction::triggered, [this]() {
    auto child = new widgets::generator::EverythingGenerator();
    addMdiChild(child);
    child->show();
  });

  auto bashhistoryviewerAction = new QAction("bash h viewer", this);
  newToolBar->addAction(bashhistoryviewerAction);
  connect(bashhistoryviewerAction, &QAction::triggered, [this]() {
    auto child = getBashHistoryViewer();
    addMdiChild(child);
    child->show();
  });
  auto syncrouteAction = new QAction("sync now", this);
  newToolBar->addAction(syncrouteAction);
  connect(syncrouteAction, &QAction::triggered, [this]() {
    auto child = new widgets::SyncRoute();
    addMdiChild(child);
    child->show();
  });

  auto yamlAction = new QAction("Yaml", this);
  newToolBar->addAction(yamlAction);
  connect(yamlAction, &QAction::triggered, [this]() {
    auto child = new widgets::YamlGenerator();
    addMdiChild(child);
    child->show();
  });
  auto svelteAction = new QAction("svelte", this);
  newToolBar->addAction(svelteAction);
  connect(svelteAction, &QAction::triggered, [this]() {
    auto child = new widgets::SvelteGenerator();
    addMdiChild(child);
    child->show();
  });
  auto dgraphcodeAction = new QAction("dgraph-code", this);
  newToolBar->addAction(dgraphcodeAction);
  connect(dgraphcodeAction, &QAction::triggered, [this]() {
    auto child = new widgets::DgraphCodeGenerator();
    addMdiChild(child);
    child->show();
  });
  auto drogon_model_action = new QAction("drogon model", this);
  newToolBar->addAction(drogon_model_action);
  connect(drogon_model_action, &QAction::triggered, [this]() {
    auto child = new widgets::ModelWriter();
    addMdiChild(child);
    child->show();
  });

  auto sqlcompareAction = new QAction("sqlcompare", this);
  newToolBar->addAction(sqlcompareAction);
  connect(sqlcompareAction, &QAction::triggered, [this]() {
    auto child = new widgets::SqlCompare();
    addMdiChild(child);
    child->show();
  });
  auto stlAction = new QAction("STL", this);
  newToolBar->addAction(stlAction);
  connect(stlAction, &QAction::triggered, [this]() {
    auto child = new widgets::Stl();
    addMdiChild(child);
    child->show();
  });
  auto wsAction = new QAction("WsTest", this);
  newToolBar->addAction(wsAction);
  connect(wsAction, &QAction::triggered, [this]() {
    auto child = new WsTest();
    addMdiChild(child);
    child->show();
  });
  auto reminderAction = new QAction("Reminder", this);
  newToolBar->addAction(reminderAction);
  connect(reminderAction, &QAction::triggered, [this]() {
    auto child = new widgets::ReminderWidget();
    addMdiChild(child);
    child->show();
  });
  auto apiHelperAction = new QAction("Api Helper", this);
  newToolBar->addAction(apiHelperAction);
  connect(apiHelperAction, &QAction::triggered, [this]() {
    auto child = new widgets::ApiHandler();
    addMdiChild(child);
    child->show();
  });
  auto classGeneratorAction = new QAction("Class Generator", this);
  newToolBar->addAction(classGeneratorAction);
  connect(classGeneratorAction, &QAction::triggered, [this]() {
    auto child = new widgets::ClassGenerator();
    addMdiChild(child);
    child->show();
  });
  auto bookmarksAction = new QAction("Bookmarks", this);
  newToolBar->addAction(bookmarksAction);
  connect(bookmarksAction, &QAction::triggered, [this]() {
    auto child = new widgets::Bookmarks();
    addMdiChild(child);
    child->show();
  });

  auto queryBuilderAction = new QAction("query builder", this);
  newToolBar->addAction(queryBuilderAction);
  connect(queryBuilderAction, &QAction::triggered, [this]() {
    auto child = new widgets::QueryBuilder();
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
