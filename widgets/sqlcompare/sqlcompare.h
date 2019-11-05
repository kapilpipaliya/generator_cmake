#ifndef SQLCOMPARE_H
#define SQLCOMPARE_H

#include <QWidget>
#include "ui_sqlcompare.h"
class QLineEdit;
class QTextEdit;
class QSortFilterProxyModel;
namespace Ui {
class SqlCompare;
}

namespace widgets {
class Data;
class SqlCompare : public QWidget {
  Q_OBJECT

 public:
  explicit SqlCompare(QWidget* parent = nullptr);
  ~SqlCompare();
 private slots:
  void loadAll();
  void saveAll();

 private:
  Ui::SqlCompare* ui;
  QString load(QString key, QString default_value);
  void set(QString key, QString value);
  QString get(QString key);

  QLineEdit* db1;
  QLineEdit* db2;
  QLineEdit* table;
  QLineEdit* columns;
  QToolButton* go1;
  QToolButton* go2;
  QToolButton* go_all;
  QToolButton* match;
  QToolButton* count;
  QLineEdit* order_by;
  QLineEdit* where;
  QTextEdit* result1;
  QTextEdit* result2;

  QString getSql1();
  QString getSql2();

  Data* sourceModel;
  QSortFilterProxyModel* proxyModel;

  void getresult(QString database, QString strSql, QTextEdit* result);
  void matchresult();
  void getcount();
};
}  // namespace widgets
#endif  // SQLCOMPARE_H
