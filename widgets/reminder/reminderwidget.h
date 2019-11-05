#ifndef REMINDERWIDGET_H
#define REMINDERWIDGET_H
#include <QWidget>
#include "sqlite/orm.h"

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
namespace widgets{
class ReminderWidget : public QWidget
{
  Q_OBJECT
 public:
  explicit ReminderWidget(QWidget *parent = nullptr);

 signals:

 public slots:
  void addTask(QString task);

 private:
  QVBoxLayout *verticalLayout1;
  QTableWidget *tableWidget_tasks;
  QHBoxLayout *taskaddhorizontalLayout;
  QLabel *label_task;
  QLineEdit *lineEdit_task;
  QToolButton *toolButton_add;
  void setWidths();


  QTimer *myTimer;
  void addTaskToTable(ReminderSetting);
  QDialog *activedialog{nullptr};
};
}
#endif // REMINDERWIDGET_H
