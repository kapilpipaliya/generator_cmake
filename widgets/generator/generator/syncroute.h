#ifndef SYNCROUTE_H
#define SYNCROUTE_H
#include <QtWidgets>

#include "./mygenerator.h"
namespace gen {
class SyncRoute : public QWidget, public MyGenerator {
  Q_OBJECT

 private:
  void init();
  void initTextEdit();

  std::string routesFilePath;

 public:
  SyncRoute(QWidget *parent = nullptr);


 public slots:
  void sync(const std::string &content);
};
}  // namespace widgets
#endif  // SYNCROUTE_H
