#include "./bookmarks.h"

#include <QtWidgets>

#include "../terminal/termwidgettool.h"

namespace widgets {
Bookmarks::Bookmarks(QWidget *parent) : QWidget(parent) {
  this->setAttribute(Qt::WA_DeleteOnClose);

  auto v = new QVBoxLayout(this);

  auto tm = new TermWidgetTool();
  v->addWidget(tm);
}
}  // namespace widgets
