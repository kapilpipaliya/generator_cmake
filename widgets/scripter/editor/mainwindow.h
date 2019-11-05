#ifndef MAINWINDOWSCRIPTER_EDITOR_H
#define MAINWINDOWSCRIPTER_EDITOR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
class QAction;
class QMenu;
class QPlainTextEdit;
class QSessionManager;
QT_END_NAMESPACE

//! [0]
namespace widgets {

namespace scripter {
class EditorMainWindow : public QMainWindow {
  Q_OBJECT

 public:
  EditorMainWindow(QWidget *parent = nullptr);

  void loadFile(const QString &fileName);

 protected:
  void closeEvent(QCloseEvent *event) override;

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

  QPlainTextEdit *textEdit;
  QString curFile;
};
//! [0]
}  // namespace scripter
}  // namespace widgets
#endif
