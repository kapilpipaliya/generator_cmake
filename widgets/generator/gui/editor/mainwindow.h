#ifndef MAINWINDOWGENERATOR_EDITOR_H
#define MAINWINDOWGENERATOR_EDITOR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
class QAction;
class QMenu;
class QPlainTextEdit;
class QSessionManager;
QT_END_NAMESPACE

//! [0]
namespace widgets {

namespace generator {
class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);

  void loadFile(const QString &fileName);

  bool event(QEvent *event) override;

  QPlainTextEdit *textEdit;

 protected:
  void closeEvent(QCloseEvent *event) override;

 signals:
  void runScript(QString filename);
  void runLine(QString filename);
  void focusChanged(QPlainTextEdit *);

 private slots:
  void newFile();
  void open();
  bool save();
  bool saveAs();
  void about();
  void documentWasModified();
#ifndef QT_NO_SESSIONMANAGER
  void commitData(QSessionManager &);
#endif
 signals:
  void currFileChanged(QString s);

 private:
  void createActions();
  void createStatusBar();
  void readSettings();
  void writeSettings();
  bool maybeSave();
  bool saveFile(const QString &fileName);
  void setCurrentFile(const QString &fileName);
  QString strippedName(const QString &fullFileName);

  QString curFile;
};
//! [0]
}  // namespace generator
}  // namespace widgets
#endif
