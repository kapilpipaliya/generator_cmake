#pragma once

#include <QWidget>
#include <QtWidgets>
namespace widgets {

class ReactGenerator : public QWidget {
  Q_OBJECT
 private:
  void init();
  void exportgenerator(QHBoxLayout *hbox);
  void reactivestatgenerator(QHBoxLayout *hbox);
  void elementdirectivesgenerator(QHBoxLayout *hbox);
  void importgenerator(QHBoxLayout *hbox);
  void protobufgenerator(QHBoxLayout *hbox);

 public:
  explicit ReactGenerator(QWidget *parent = nullptr);
  ~ReactGenerator();

 private:
};
}  // namespace widgets

