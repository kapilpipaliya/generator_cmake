#pragma once
#include <QWidget>
#include <QtWidgets>
namespace widgets
{
class ReactGenerator : public QWidget
{
  Q_OBJECT
private:
  void init();
  void hookGenerator(QHBoxLayout *hbox);
  void componentSkeletonGenerator(QHBoxLayout *hbox);
  void eventListenerGenerator(QHBoxLayout *hbox);
  void importgenerator(QHBoxLayout *hbox);
  void protobufgenerator(QHBoxLayout *hbox);
public:
  explicit ReactGenerator(QWidget *parent = nullptr);
  ~ReactGenerator();
private:
};
}  // namespace widgets
