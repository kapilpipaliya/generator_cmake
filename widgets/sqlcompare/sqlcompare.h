#ifndef SQLCOMPARE_H
#define SQLCOMPARE_H

#include <QWidget>
class QLineEdit;
class QTextEdit;
class QSortFilterProxyModel;
namespace Ui {
class SqlCompare;
}


namespace widgets {
class Data;
class SqlCompare : public QWidget
{
    Q_OBJECT

public:
    explicit SqlCompare(QWidget *parent = nullptr);
    ~SqlCompare();

private:
    Ui::SqlCompare *ui;


Data *sourceModel;
    QSortFilterProxyModel *proxyModel;

    void setresult(QString database, QString strSql, QTextEdit *result);
};
}
#endif // SQLCOMPARE_H
