#ifndef DATA_H
#define DATA_H

#include <QAbstractItemModel>
#include <QModelIndex>
#include <QVariant>
namespace widgets {
class TreeItem;
class Data : public QAbstractItemModel {
  Q_OBJECT
 public:
  explicit Data(QObject *parent = nullptr);
  ~Data();

  QModelIndex index(int row, int column,
                    const QModelIndex &parent = QModelIndex()) const;
  QModelIndex parent(const QModelIndex &child) const;
  int rowCount(const QModelIndex &parent = QModelIndex()) const;
  int columnCount(const QModelIndex &parent = QModelIndex()) const;
  QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
  Qt::ItemFlags flags(const QModelIndex &index) const override;
  QVariant headerData(int section, Qt::Orientation orientation,
                      int role = Qt::DisplayRole) const override;
  TreeItem *getItem(const QModelIndex &index) const;
 signals:

 public slots:

 private:
  void setupModelData();
  void addTable(QString table_name, QString columns);
  TreeItem *rootItem;
};

}
#endif  // DATA_H
