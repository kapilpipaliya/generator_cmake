#ifndef DGRAPHCODEGENERATOR_H
#define DGRAPHCODEGENERATOR_H

#include <QWidget>
#include <QtWidgets>

namespace widgets {
class DgraphCodeGenerator : public QWidget {
  Q_OBJECT

 public:
  explicit DgraphCodeGenerator(QWidget *parent = nullptr);
  ~DgraphCodeGenerator();

 private:
};
}  // namespace widgets
#endif  // DGRAPHCODEGENERATOR_H
