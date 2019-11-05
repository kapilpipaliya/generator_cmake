#ifndef TERMWIDGETTOOL_H
#define TERMWIDGETTOOL_H

#include <QtWidgets>
#include <functional>

#include "./termwidget.h"

class TermWidgetTool : public QWidget {
  Q_OBJECT
 public:
  explicit TermWidgetTool(QWidget *parent = nullptr);
  ~TermWidgetTool();
  TermWidget *terminal = nullptr;
  QTreeView *tree = nullptr;
  QFileSystemModel *model = nullptr;

 signals:
  void runLine(TermWidgetTool *termwidgettool);

 private:
  QHBoxLayout *h;
  void addButton(const QString &title, const QString &tooltip,
                 const QString &command);
  void addButton(const QString &title, const QString &tooltip,
                 std::function<void()> run);
};

#endif  // TERMWIDGETTOOL_H
