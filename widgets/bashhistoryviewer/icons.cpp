#include "./icons.h"
//#include <QtSvg>
#include "QIcon"
#include "QtGui/QPixmap"

Icons::Icons() {
  ICON_COPY = new QIcon(QPixmap(":/icons/copy.svg"));
  ICON_DELETE = new QIcon(QPixmap(":/icons/delete.svg"));
  ICON_HEART = new QIcon(QPixmap(":/icons/heart.svg"));
}
