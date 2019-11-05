#ifndef SYNCROUTE_H
#define SYNCROUTE_H
#include <QtWidgets>

#include "../generator/generator/mygenerator.h"

namespace widgets {
class SyncRoute : public QWidget, public MyGenerator {
  Q_OBJECT

 private:
  void init();
  void initTextEdit();

  std::string routesFilePath;

 public:
  SyncRoute(QWidget *parent = nullptr);
  QTextEdit *resultText;

 public slots:
  void sync();
};
}  // namespace widgets
#endif  // SYNCROUTE_H
