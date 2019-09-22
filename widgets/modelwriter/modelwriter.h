#ifndef MODELWRITER_H
#define MODELWRITER_H

#include <QWidget>

namespace Ui {
class ModelWriter;
}
class QSortFilterProxyModel;
namespace widgets {
class Data;
class ModelWriter : public QWidget
{
    Q_OBJECT

public:
    explicit ModelWriter(QWidget *parent = nullptr);
    ~ModelWriter();

private slots:
 void on_treeView_doubleClicked(const QModelIndex &index);

 void on_toolButton_all_clicked();
 void on_lineEdit_filter_textEdited(const QString &arg1);
private:
    Ui::ModelWriter *ui;

private:
 void addItem(QString item);
 QString toCamelCase(QString &s);
 Data *sourceModel;
 QSortFilterProxyModel *proxyModel;
};
}
#endif // MODELWRITER_H
