#include "sqlcompare.h"
#include <drogon/orm/DbClient.h>
#include <QSortFilterProxyModel>
#include <QtDebug>
#include <QtSql>
#include "../modelwriter/data.h"
#include "ui_sqlcompare.h"

namespace widgets {
SqlCompare::SqlCompare(QWidget* parent)
    : QWidget(parent), ui(new Ui::SqlCompare) {
  ui->setupUi(this);

  auto db1 = ui->lineEdit_db1;
  auto db2 = ui->lineEdit_db2;
  auto table = ui->lineEdit_table;
  auto columns = ui->lineEdit_columns;
  auto go = ui->toolButton_go_2;
  auto save = ui->toolButton_save_2;
  auto order_by = ui->lineEdit_order_by;
  auto where = ui->lineEdit_where;

  auto result1 = ui->textEdit_1;
  auto result2 = ui->textEdit_2;

  sourceModel = new Data(this);
  proxyModel = new QSortFilterProxyModel(this);
  proxyModel->setSourceModel(sourceModel);
  ui->treeView->setModel(proxyModel);

  ui->treeView->resizeColumnToContents(0);
  /*
  connect(ui->toolButton_filter_clear, &QToolButton::clicked, [this]() {
    // Set the string you want to filter on using setFilterFixedString()
    // or setFilterRegExp() in your QSortFilterProxyModel
    proxyModel->setFilterRegExp("");
    ui->lineEdit_filter->setText("");
  });
  */
  connect(ui->treeView, &QTreeView::pressed,
          [table, this](const QModelIndex& index) {
            auto text = index.data().toString();
            table->setText(text);
          });
  connect(ui->toolButton_set, &QToolButton::pressed, [columns, this]() {
    auto text = ui->lineEdit_result_columns->text();
    columns->setText(text);
  });
  connect(ui->toolButton_c, &QToolButton::pressed, [db1, table, this]() {
    auto db = QSqlDatabase::database("client1");
    QSqlDatabase client1;
    if (db.isValid()) {
      client1 = db;
    } else {
      client1 = QSqlDatabase::addDatabase("QPSQL", "client1");
    }
    client1.setDatabaseName(db1->text());
    client1.setHostName("localhost");
    client1.setPort(5432);
    if (!client1.open("postgres", "postgres")) {
      qDebug() << "unsuccess:" << client1.lastError();
      client1 = QSqlDatabase();
      QSqlDatabase::removeDatabase(QString("client1"));
      qDebug() << "unsuc: " << client1.lastError();
    } else {
      auto record = client1.driver()->record(ui->lineEdit_table->text());
      auto c = record.count();
      auto r_column = ui->lineEdit_result_columns;
      r_column->clear();
      QString s;
      for (int i = 0; i < c; ++i) {
        auto f = record.field(i);
        s += f.name();
        s += ", ";
      }
      r_column->setText(s);
    }
  });
  connect(
      go, &QToolButton::clicked,
      [this, db1, db2, columns, table, where, order_by, result1, result2]() {
        auto strSql_1 = "SELECT " + columns->text() + " FROM " + table->text() +
                        " " + where->text() + " " + order_by->text();
        auto strSql_2 = "SELECT " + columns->text() + " FROM " + table->text() +
                        " " + where->text() + " " + order_by->text();
        /*
      auto connStr_1 = "dbname=" + db1->text() + "user=postgres
      passwd=postgres"; auto connStr_2 = "dbname=" + db2->text() +
      "user=postgres passwd=postgres";

      //    auto client2 =
      drogon::orm::DbClient::newPgClient(connStr_2.toStdString(), 5);


      try {
        auto client1 =
            drogon::orm::DbClient::newPgClient(connStr_1.toStdString(), 5);
        auto result = client1->execSqlSync(strSql_1.toStdString());
        for (auto it : result) {
          for (auto it2 : it) {
            result1->appendPlainText(it2.c_str());
          }
        }
      } catch (const std::exception& e) {
        result1->setPlainText("Error selecting result" + QString(e.what()));
      }
    */
        result1->clear();
        result2->clear();
        setresult(db1->text(), strSql_1, result1);
        setresult(db2->text(), strSql_2, result2);
        if (result1->toPlainText() == result2->toPlainText()) {
          ui->label_5->setText("Matched");
        } else {
          ui->label_5->setText("Not Matched");
        }
      });
}

SqlCompare::~SqlCompare() { delete ui; }

void SqlCompare::setresult(QString database, QString strSql,
                           QTextEdit* result) {
  auto db = QSqlDatabase::database("client1");
  QSqlDatabase client1;
  if (db.isValid()) {
    client1 = db;
  } else {
    client1 = QSqlDatabase::addDatabase("QPSQL", "client1");
  }
  client1.setDatabaseName(database);
  client1.setHostName("localhost");
  client1.setPort(5432);
  if (!client1.open("postgres", "postgres")) {
    qDebug() << "unsuccess:" << client1.lastError();
    client1 = QSqlDatabase();
    QSqlDatabase::removeDatabase(QString("client1"));
    qDebug() << "unsuc: " << client1.lastError();
  } else {
    auto record = client1.driver()->record(ui->lineEdit_table->text());
    auto c = record.count();
    auto r_column = ui->lineEdit_result_columns;
    r_column->clear();
    QString s;
    for (int i = 0; i < c; ++i) {
      auto f = record.field(i);
      s += f.name();
      s += ", ";
    }
    QSqlQuery query("", client1);  // executes query
    query.prepare(strSql);
    if (query.exec()) {
      r_column->setText(s);
      while (query.next()) {
        auto count = query.record().count();
        for (int i = 0; i < count; ++i) {
          auto text = result->toPlainText();
          text += query.value(i).toString();
          text += ", ";
          result->setText(text);
        }
        auto text = result->toPlainText();
        text += "\n";
        result->setText(text);
      }
    } else {
      qDebug() << query.lastError() << ": " << query.lastQuery();
    }
  }
}
}  // namespace widgets
