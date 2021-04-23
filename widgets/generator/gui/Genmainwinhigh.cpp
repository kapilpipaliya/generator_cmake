// todo: we should be able to rename files too.
//
#include "./Genmainwinhigh.h"
#include <fstream>
#include <iostream>
//#include <range/v3/all.hpp>  // get everything
//#include <boost/algorithm/string.hpp>
//#include <boost/filesystem.hpp>
#include <filesystem>
#include <regex>
#include "../../widgets/terminal/termwidgettool.h"
#include "../generator/ControllerEntry.h"
#include "../generator/DGraphSchema.h"
#include "../generator/JSClass.h"
#include "../generator/Service.h"
#include "../generator/mygenerator.h"
#include "../generator/protogenerator.h"
#include "./editor/mainwindow.h"
#include "pystring/pystring.hpp"
#include "thirdparty/toolwindowmanager/src/ToolWindowManager.h"
namespace widgets
{
namespace generator
{
EverythingGenerator::EverythingGenerator(QWidget *parent) : QWidget(parent) { init(); }
void EverythingGenerator::init()
{
  initAngelScript();
  auto v1 = new QVBoxLayout(this);
  auto v1_h1 = new QHBoxLayout();
  auto v1_h1_v1 = new QVBoxLayout();
  auto v1_h1_v2 = new QVBoxLayout();
  v1_h1->addLayout(v1_h1_v1);
  v1_h1->addLayout(v1_h1_v2);
  auto v1_grid = new QGridLayout();
  v1->addItem(v1_h1);
  v1->addItem(v1_grid);
  v1->setStretch(0, 5);
  v1->setStretch(1, 1);
  auto eventLabel = new QLabel(this);
  eventLabel->setText("Event:");
  auto protoLabel = new QLabel(this);
  protoLabel->setText("Proto:");
  auto serviceLabel = new QLabel(this);
  serviceLabel->setText("Service:");
  auto jsresultLabel = new QLabel(this);
  jsresultLabel->setText("JS:");
  auto clearbutton = new QToolButton(this);
  clearbutton->setText("clear");
  v1_grid->addWidget(clearbutton, 0, 0, 1, 4);
  eventresult = new QPlainTextEdit(this);
  eventresult->setPlainText("");
  protoresult = new QPlainTextEdit(this);
  protoresult->setPlainText("");
  serviceresult = new QPlainTextEdit(this);
  serviceresult->setPlainText("");
  jsresult = new QPlainTextEdit(this);
  jsresult->setPlainText("");
  v1_grid->addWidget(eventLabel, 1, 0);
  v1_grid->addWidget(protoLabel, 1, 1);
  v1_grid->addWidget(serviceLabel, 1, 2);
  v1_grid->addWidget(jsresultLabel, 1, 3);
  v1_grid->addWidget(eventresult, 2, 0);
  v1_grid->addWidget(protoresult, 2, 1);
  v1_grid->addWidget(serviceresult, 2, 2);
  v1_grid->addWidget(jsresult, 2, 3);
  connect(clearbutton, &QToolButton::clicked, [this]() {
    eventresult->clear();
    protoresult->clear();
    serviceresult->clear();
    jsresult->clear();
  });
  auto h = new QHBoxLayout();
  auto newFileButton = new QToolButton(this);
  newFileButton->setText("NFile");
  auto newDirButton = new QToolButton(this);
  newDirButton->setText("NDir");
  auto renameButton = new QToolButton(this);
  renameButton->setText("Ren");
  auto deleteButton = new QToolButton(this);
  deleteButton->setText("Del");
  auto dolphinButton = new QToolButton(this);
  dolphinButton->setText("Dolp");
  auto sublButton = new QToolButton(this);
  sublButton->setText("Subl");
  auto copyButton = new QToolButton(this);
  copyButton->setText("^C");
  auto terminalButton = new QToolButton(this);
  terminalButton->setText("T");
  h->addWidget(newFileButton);
  h->addWidget(newDirButton);
  h->addWidget(renameButton);
  h->addWidget(deleteButton);
  h->addWidget(dolphinButton);
  h->addWidget(sublButton);
  h->addWidget(copyButton);
  h->addWidget(terminalButton);
  // add filter to v1_h1_v1
  auto filterEdit = new QLineEdit(this);
  v1_h1_v1->addWidget(filterEdit);
  v1_h1_v1->addItem(h);
  auto lay = new ToolWindowManager(this);
  v1_h1_v2->addWidget(lay);
  // add dir tree to v1_h1_v1
  QString rootPath = QDir::current().path();
  auto model = new QFileSystemModel();
  auto tree = new QTreeView(this);
  model->setRootPath("/home/kapili3/");  // watched
  tree->setModel(model);
  tree->sortByColumn(0, Qt::AscendingOrder);  // hack?
  tree->setRootIndex(model->index("/home/kapili3/"));
  tree->setCurrentIndex(model->index("/home/kapili3/jdragon/my_scripts/"));
  // "/home/kapili3/jdragon/model_instructions/";
  //  if (!rootPath.isEmpty()) {
  //    const QModelIndex rootIndex =
  //    model->index(QDir::cleanPath(rootPath)); if (rootIndex.isValid())
  //    tree->setRootIndex(rootIndex);
  //  }
  // Demonstrating look and feel features
  tree->setAnimated(false);
  tree->setIndentation(20);
  tree->setSortingEnabled(true);
  const QSize availableSize = QApplication::desktop()->availableGeometry(tree).size();
  tree->resize(availableSize / 2);
  tree->setColumnWidth(0, tree->width() / 3);
  v1_h1_v1->addWidget(tree);
  connect(filterEdit, &QLineEdit::textChanged, [filterEdit, model]() {
    auto filterText = filterEdit->text();
    model->setNameFilters({filterText});
    model->setNameFilterDisables(false);
  });
  connect(newFileButton, &QToolButton::clicked, [tree, model, this]() {
    auto a = new QDialog;
    auto filenameLabel = new QLabel(a);
    filenameLabel->setText("File Name:");
    auto filenameText = new QLineEdit(a);
    filenameText->setText(filename);
    auto namespLabel = new QLabel(a);
    namespLabel->setText("NameSpace:");
    auto namespaceText = new QLineEdit(a);
    namespaceText->setText(namespacename);
    auto reqprotoLabel = new QLabel(a);
    reqprotoLabel->setText("Request:");
    auto reqprotoText = new QLineEdit(a);
    reqprotoText->setText(reqProtoname);
    auto reqprotoText2 = new QPlainTextEdit(a);
    auto resprotoLabel = new QLabel(a);
    resprotoLabel->setText("Request:");
    auto resprotoText = new QLineEdit(a);
    resprotoText->setText(respProtoname);
    auto resprotoText2 = new QPlainTextEdit(a);
    auto jsLabel = new QLabel(a);
    jsLabel->setText("JS FileName:");
    auto jsText = new QLineEdit(a);
    jsText->setText(jsfilename);
    auto okBut = new QPushButton(a);
    okBut->setText("&Ok");
    auto cancelBut = new QPushButton(a);
    cancelBut->setText("&Cancel");
    auto grid = new QGridLayout(a);
    grid->addWidget(filenameLabel, 0, 0);
    grid->addWidget(filenameText, 0, 1);
    grid->addWidget(namespLabel, 1, 0);
    grid->addWidget(namespaceText, 1, 1);
    grid->addWidget(reqprotoLabel, 2, 0);
    grid->addWidget(reqprotoText, 2, 1);
    grid->addWidget(reqprotoText2, 3, 0, 1, 2);
    grid->addWidget(resprotoLabel, 4, 0);
    grid->addWidget(resprotoText, 4, 1);
    grid->addWidget(resprotoText2, 5, 0, 1, 2);
    grid->addWidget(jsLabel, 6, 0);
    grid->addWidget(jsText, 6, 1);
    grid->addWidget(okBut, 7, 0);
    grid->addWidget(cancelBut, 7, 1);
    auto reqp = R"(syntax = "proto3";
package timeservice;
message RegistrationRequest {
  string name = 1;
  string username = 2;
  string password = 3;
})";
    auto resp = R"(syntax = "proto3";
package timeservice;
message RegistrationResponse {
  enum ErrorStatus {
     OK = 0;
     INVALID_USERNAME = 1;
     WEAK_PASSWORD= 2;
      USERNAME_EXIST =3;
      UNKNOWN_ERROR=4;
  }
  ErrorStatus status = 1;
  string token = 2;
  string error_msg =3;
})";
    reqprotoText2->setPlainText(reqp);
    resprotoText2->setPlainText(resp);
    connect(reqprotoText, &QLineEdit::textChanged, [reqprotoText, reqprotoText2, resprotoText]() {
      if (!reqprotoText->text().isEmpty()) { resprotoText->setText(reqprotoText->text()); }
      auto req = "message " + reqprotoText->text() + "Request";
      auto t = reqprotoText2->toPlainText().replace(QRegExp("message (\\w*)Request", Qt::CaseSensitive, QRegExp::RegExp2), req);
      reqprotoText2->setPlainText(t);
    });
    connect(resprotoText, &QLineEdit::textChanged, [resprotoText, resprotoText2]() {
      auto req = "message " + resprotoText->text() + "Response";
      auto t = resprotoText2->toPlainText().replace(QRegExp("message (\\w*)Response", Qt::CaseSensitive, QRegExp::RegExp2), req);
      resprotoText2->setPlainText(t);
    });
    a->open();
    reqprotoText2->setTabChangesFocus(true);
    resprotoText2->setTabChangesFocus(true);
    connect(okBut, &QToolButton::clicked, [a, filenameText, namespaceText]() {
      if (filenameText->text().isEmpty())
      {
        QMessageBox::information(a, "File name required", "fill file name");
        filenameText->setFocus();
        return;
      }
      if (namespaceText->text().isEmpty())
      {
        QMessageBox::information(a, "Namespace is required", "fill namespace");
        namespaceText->setFocus();
        return;
      }
      a->accept();
    });
    connect(cancelBut, &QToolButton::clicked, [a]() {
      a->reject();
      delete a;
    });
    connect(a, &QDialog::accepted, [a, tree, model, filenameText, namespaceText, reqprotoText, resprotoText, jsText, reqprotoText2, resprotoText2, this]() {
      if (!filenameText->text().isEmpty()) filename = filenameText->text();
      if (!namespaceText->text().isEmpty()) namespacename = namespaceText->text();
      if (!reqprotoText->text().isEmpty()) reqProtoname = reqprotoText->text();
      if (!resprotoText->text().isEmpty()) respProtoname = resprotoText->text();
      if (!jsText->text().isEmpty()) jsfilename = jsText->text();
      /* copy a sample file:
    bool ok;
    QString text = QInputDialog::getText(this, "File Name",
                                         "File Name:",
    QLineEdit::Normal, QDir::home().dirName(), &ok); if (ok &&
    !text.isEmpty()) { auto mindex = tree->currentIndex(); auto path =
    model->filePath(mindex).toStdString(); if (model->isDir(mindex)) {
      } else {
        path = std::filesystem::path(path).parent_path().string();
      }
      auto newFile = path + "/" + text.toStdString();
      std::ofstream oSourceFile(newFile.c_str(), std::ofstream::out);
      if (!oSourceFile) {
        perror("");
        exit(1);
      }

      auto readFile =
    "/home/kapili3/jdragon/model_instructions/sample.txt"; auto content1
    = read_all(readFile); oSourceFile << content1;
    }
    */
      {
        auto mindex = tree->currentIndex();
        auto path = model->filePath(mindex).toStdString();
        if (model->isDir(mindex)) {}
        else
        {
          path = std::filesystem::path(path).parent_path().string();
        }
        auto newFile = path + "/" + filenameText->text().toStdString();
        std::ofstream oSourceFile(newFile.c_str(), std::ofstream::out);
        if (!oSourceFile)
        {
          perror("");
          exit(1);
        }
        oSourceFile << namespaceText->text().toStdString();
        oSourceFile << "\n";
        if (!reqprotoText->text().isEmpty())
        {
          oSourceFile << "--generate_request_proto\n";
          oSourceFile << reqprotoText2->toPlainText().toStdString() + "\n";
          oSourceFile << "--end\n";
        }
        if (!resprotoText->text().isEmpty())
        {
          oSourceFile << "--generate_response_proto\n";
          oSourceFile << resprotoText2->toPlainText().toStdString() + "\n";
          oSourceFile << "--end\n";
        }
        oSourceFile << "--server_class\n\n--end\n";
        if (!jsText->text().isEmpty())
        {
          oSourceFile << "--client_class\n";
          oSourceFile << "filename:" + jsText->text().toStdString() + "\n";
          oSourceFile << "--end\n";
        }
      }
      delete a;
    });
  });
  connect(newDirButton, &QToolButton::clicked, [this, tree, model]() {
    bool ok;
    QString text = QInputDialog::getText(this, "Dir Name", "File Name:", QLineEdit::Normal, QDir::home().dirName(), &ok);
    if (ok && !text.isEmpty())
    {
      auto mindex = tree->currentIndex();
      auto path = model->filePath(mindex).toStdString();
      if (model->isDir(mindex)) { std::filesystem::create_directory(path + "/" + text.toStdString()); }
      else
      {
        path = std::filesystem::path(path).parent_path().string();
        std::filesystem::create_directory(path + "/" + text.toStdString());
      }
    }
  });
  connect(renameButton, &QToolButton::clicked, [this, tree, model]() {
    bool ok;
    QString text = QInputDialog::getText(this, "Dir Name", "File Name:", QLineEdit::Normal, QDir::home().dirName(), &ok);
    if (ok && !text.isEmpty())
    {
      auto mindex = tree->currentIndex();
      auto path = model->filePath(mindex).toStdString();
      auto parent = std::filesystem::path(path).parent_path().string();
      std::filesystem::rename(path, parent + "/" + text.toStdString());
    }
  });
  connect(deleteButton, &QToolButton::clicked, [this, tree, model]() {
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Sure", "100%?", QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
      auto mindex = tree->currentIndex();
      auto path = model->filePath(mindex).toStdString();
      auto parent = std::filesystem::path(path).parent_path().string();
      std::filesystem::remove_all(path);
    }
    else
    {
      qDebug() << "Yes was *not* clicked";
    }
  });
  connect(dolphinButton, &QToolButton::clicked, [this, tree, model]() {
    auto mindex = tree->currentIndex();
    auto path = model->filePath(mindex).toStdString();
    if (model->isDir(mindex))
    {
      std::string command = "dolphin --select " + path + " & disown";
      system(command.c_str());
    }
    else
    {
      // path = std::filesystem::path(path).parent_path().string();
      std::string command = "dolphin --select " + path + " & disown";
      system(command.c_str());
    }
  });
  connect(sublButton, &QToolButton::clicked, [this, tree, model]() {
    auto mindex = tree->currentIndex();
    auto path = model->filePath(mindex).toStdString();
    if (model->isDir(mindex))
    {
      std::string command = "subl " + path;
      system(command.c_str());
    }
    else
    {
      path = std::filesystem::path(path).parent_path().string();
      std::string command = "subl  " + path;
      system(command.c_str());
    }
  });
  connect(copyButton, &QToolButton::clicked, [this, tree, model]() {
    auto mindex = tree->currentIndex();
    auto path = model->filePath(mindex);
    QApplication::clipboard()->setText(path);
  });
  connect(terminalButton, &QToolButton::clicked, [this, tree, model, lay]() {
    auto term = new TermWidgetTool(this);
    term->setWindowTitle("T");
    term->tree = tree;
    term->model = model;
    lay->addToolWindow(term, ToolWindowManager::LastUsedArea);
    connect(term->terminal, &QTermWidget::finished, [term]() { term->deleteLater(); });
    connect(term, &TermWidgetTool::runLine, [this](TermWidgetTool *termwidgettool) {
      if (focusEditor)
      {
        auto line = focusEditor->textCursor().block().text().trimmed();
        termwidgettool->terminal->execute(line);
      }
    });
  });
  // add tabwidget to v1_h1_v2
  /*{
  auto tabWidget1 = new QTabWidget(this);
  tabWidget1->setTabsClosable(true);
  QString fileName;
  QFileInfo fileInfo(fileName);
  v1_h1_v2->addWidget(tabWidget1);
  }*/
  v1_h1->setStretch(1, 2);
  this->setLayout(v1);
  // connect dirtree with tabbar
  connect(tree, &QTreeView::clicked, [model, lay, this](const QModelIndex &index) {
    if (model->isDir(index)) { return; }
    auto editor = new widgets::generator::MainWindow(this);
    // auto file = index.data().toString();
    auto file = model->filePath(index);
    editor->loadFile(file);
    editor->setWindowFlags(Qt::Widget);
    editor->show();
    /*{
      auto i = tabWidget1->addTab(editor, index.data().toString());
      tabWidget1->setCurrentIndex(i);
    }*/
    lay->addToolWindow(editor, ToolWindowManager::LastUsedArea);
    connect(editor, &widgets::generator::MainWindow::runScript, [this](QString filename) {
      // auto r = script->CompileScript(filename.toStdString());
      // if (r) {
      // script->Execute("");
      //}
      runAllGenerators(filename);
    });
    connect(editor, &widgets::generator::MainWindow::runLine, [this, lay](QString line) {
      auto tm = new TermWidgetTool(this);
      tm->terminal->execute(line);
      lay->addToolWindow(tm, ToolWindowManager::LastUsedArea);
    });
    connect(editor, &widgets::generator::MainWindow::focusChanged, [this](QPlainTextEdit *textEdit) { focusEditor = textEdit; });
  });
  /*connect(tabWidget1, &QTabWidget::tabCloseRequested, [tabWidget1](int index)
  { tabWidget1->widget(index)->deleteLater(); tabWidget1->removeTab(index);
  });*/
}
void EverythingGenerator::initAngelScript()
{
  //---------angelscript
  // Create the script engine
  // script = new Script;
  // Compile the script code
  // auto r = script->CompileScript("");
  // if (r) {
  // execute
  // script->Execute("");
  //}
}
void EverythingGenerator::runAllGenerators(const QString &filename)
{
  // we get a vector of std::string
  std::vector<std::string> controllres;
  auto file_read = read_all(filename.toStdString());
  std::istringstream f(file_read);
  std::string line;
  // Read first line:
  std::getline(f, line);
  /*boost::trim(line);
  boost::split(controllres, line, [](char c) { return c == ' '; });*/
  // we pass this wectors to each generator.
  // generate classes for all generators ..
  // to each class pass this vector...
  // find which vectors we will run
  // auto controllers_entry_gen = find_section(file_read, "--generate
  // controller");
  auto d_graph_args = find_section(file_read, "--dgraph_schema");
  auto request_proto_args = find_section(file_read, "--generate_request_proto");
  auto response_proto_args = find_section(file_read, "--generate_response_proto");
  auto server_class_args = find_section(file_read, "--server_class");
  auto client_class_args = find_section(file_read, "--client_class");
  if (!line.empty())
  {
    auto protogen = !request_proto_args.empty() || !response_proto_args.empty();
    auto eventadd = !server_class_args.empty();
    ControllerEntry c{controllres, line};
    eventresult->appendPlainText(QString::fromStdString(c.generate(eventadd, protogen)));
  }
  /* This class is not needed now.
--dgraph_schema
 # alter

# alter_end
# query

# query_end
# mutation

# mutation_end
  --end

  if (!d_graph_args.empty()) {
    DGraphSchema c{controllres, d_graph_args};
    r += c.generate();
  }*/
  if (!request_proto_args.empty())
  {
    ProtoGenerator c{controllres, request_proto_args};
    std::smatch match;
    std::regex_search(request_proto_args, match, std::regex("message (\\w.*) \\{"));
    auto namespace_ = match.str(1);
    auto comment = match.size() == 2 ? false : true;
    protoresult->appendPlainText(QString::fromStdString(c.generate("Request", namespace_, comment)));
  }
  if (!response_proto_args.empty())
  {
    ProtoGenerator c{controllres, response_proto_args};
    std::smatch match;
    std::regex_search(response_proto_args, match, std::regex("message (\\w.*) \\{"));
    auto namespace_ = match.str(1);
    auto comment = match.size() == 2 ? false : true;
    protoresult->appendPlainText(QString::fromStdString(c.generate("Response", namespace_, comment)));
  }
  if (!server_class_args.empty())
  {
    Service c{controllres, server_class_args};
    serviceresult->appendPlainText(QString::fromStdString(c.generate()));
  }
  if (!client_class_args.empty())
  {
    std::smatch match;
    std::regex_search(request_proto_args, match, std::regex("message (\\w.*) \\{"));
    auto namespacereq = match.str(1);
    auto commentreq = match.size() == 2 ? false : true;
    std::regex_search(response_proto_args, match, std::regex("message (\\w.*) \\{"));
    auto namespaceres = match.str(1);
    auto commentres = match.size() == 2 ? false : true;
    JSClass c{controllres, client_class_args};
    jsresult->appendPlainText(QString::fromStdString(c.generate(namespacereq, commentreq, namespaceres, commentres)));
  }
  // compare seperate regex and if match find run app. generator.
}
std::string EverythingGenerator::read_all(const std::string &filename)
{
  std::ifstream istrm(filename, std::ios::in);
  istrm.seekg(0, std::ios::beg);
  return {std::istreambuf_iterator<char>{istrm}, std::istreambuf_iterator<char>{}};
}
std::string EverythingGenerator::find_section(const std::string &file_read, const std::string &section_name)
{
  std::regex regex(".*" + section_name + R"(([\W\w\n]*?)--end)", std::regex_constants::ECMAScript | std::regex_constants::icase | std::regex_constants::extended);
  std::smatch controller_match;
  if (std::regex_search(file_read, controller_match, regex))
  {
    if (controller_match.size() > 2) throw("It must be 1 match");
    if (controller_match.size() == 1) return controller_match[0];
    if (controller_match.size() == 2) return controller_match[1];
  }
  return "";
}
void EverythingGenerator::removeFirstLastLine(std::string &str)
{
  std::vector<std::string> v;
  pystring::splitlines(str, v);
  v.erase(v.begin());
  v.erase(v.end());
  str = pystring::join("\n", v);
}
}  // namespace generator
}  // namespace widgets
