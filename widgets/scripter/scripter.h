#ifndef SCRIPTER_H
#define SCRIPTER_H
#include <QMainWindow>
#include <QPushButton>
#include <QString>
namespace widgets {
class Scripter : public QWidget {
  Q_OBJECT

 public:
  explicit Scripter(QWidget *parent = nullptr);
  ~Scripter();

 private slots:
  void alert(QString a, QString b);
  void startSHnow();
  void startSHnowSUDO();
  void TMPkiller();
  void LittleKiller(QString a);

 private:
  void initUi();
  void addButton(QString line, bool isSudo);
  void addNewButton();
};

class QYN : public QPushButton {
  Q_OBJECT
 public:
  explicit QYN(QWidget *parent = 0);

 public slots:

 private:
};
}  // namespace widgets
#endif  // R.E.M. - it's the end of the world as we know it ...
