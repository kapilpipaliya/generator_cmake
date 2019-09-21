#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}
class QSortFilterProxyModel;
class Data;

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private slots:
  void on_actionclient_triggered();

  void on_treeView_doubleClicked(const QModelIndex &index);

  void on_toolButton_all_clicked();
  void on_lineEdit_filter_textEdited(const QString &arg1);

 private:
  Ui::MainWindow *ui;
  void addItem(QString item);
  QString toCamelCase(QString &s);
  QSortFilterProxyModel *proxyModel;
  Data *sourceModel;
};

#endif  // MAINWINDOW_H
