#ifndef SVELTEGENERATOR_H
#define SVELTEGENERATOR_H

#include <QWidget>
#include <QtWidgets>
namespace widgets {

class SvelteGenerator : public QWidget {
  Q_OBJECT
 private:
  void init();
  void exportgenerator(QHBoxLayout *hbox);
  void reactivestatgenerator(QHBoxLayout *hbox);
  void elementdirectivesgenerator(QHBoxLayout *hbox);
  void importgenerator(QHBoxLayout *hbox);
  void protobufgenerator(QHBoxLayout *hbox);

 public:
  explicit SvelteGenerator(QWidget *parent = nullptr);
  ~SvelteGenerator();

 private:
};
}  // namespace widgets
#endif  // SVELTEGENERATOR_H
