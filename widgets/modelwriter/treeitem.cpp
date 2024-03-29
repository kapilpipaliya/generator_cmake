#include "./treeitem.h"
namespace widgets {
//! [0]
TreeItem::TreeItem(const QVector<QVariant> &data, TreeItem *parent)
    : m_itemData(data), m_parentItem(parent) {}
//! [0]

//! [1]
TreeItem::~TreeItem() { qDeleteAll(m_childItems); }
//! [1]

//! [2]
void TreeItem::appendChild(TreeItem *item) { m_childItems.append(item); }
//! [2]

//! [3]
TreeItem *TreeItem::child(int row) {
  if (row < 0 || row >= m_childItems.size()) return nullptr;
  return m_childItems.at(row);
}
//! [3]

//! [4]
int TreeItem::childCount() const { return m_childItems.count(); }
//! [4]

//! [5]
int TreeItem::columnCount() const { return m_itemData.count(); }
//! [5]

//! [6]
QVariant TreeItem::data(int column) const {
  if (column < 0 || column >= m_itemData.size()) return QVariant();
  return m_itemData.at(column);
}
//! [6]

//! [7]
TreeItem *TreeItem::parentItem() { return m_parentItem; }
//! [7]

//! [8]
int TreeItem::row() const {
  if (m_parentItem)
    return m_parentItem->m_childItems.indexOf(const_cast<TreeItem *>(this));

  return 0;
}
//! [8]
}  // namespace widgets
