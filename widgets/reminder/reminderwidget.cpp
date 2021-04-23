#include "./reminderwidget.h"
#include <QDateTime>
#include <QDialog>
#include <QTimer>
#include "sqlite/orm.h"
namespace widgets
{
ReminderWidget::ReminderWidget(QWidget *parent) : QWidget(parent)
{
  this->setAttribute(Qt::WA_DeleteOnClose);
  verticalLayout1 = new QVBoxLayout(this);
  verticalLayout1->setObjectName(QString::fromUtf8("verticalLayout1"));
  verticalLayout1->setContentsMargins(0, 0, 0, 0);
  tableWidget_tasks = new QTableWidget(this);
  tableWidget_tasks->setObjectName(QString::fromUtf8("tableWidget_tasks"));
  verticalLayout1->addWidget(tableWidget_tasks);
  taskaddhorizontalLayout = new QHBoxLayout();
  taskaddhorizontalLayout->setObjectName(QString::fromUtf8("taskaddhorizontalLayout"));
  label_task = new QLabel(this);
  label_task->setObjectName(QString::fromUtf8("label_task"));
  lineEdit_task = new QLineEdit(this);
  lineEdit_task->setObjectName(QString::fromUtf8("lineEdit_task"));
  toolButton_add = new QToolButton(this);
  toolButton_add->setText("Add");
  toolButton_add->setObjectName(QString::fromUtf8("toolButton_add"));
  taskaddhorizontalLayout->addWidget(label_task);
  taskaddhorizontalLayout->addWidget(lineEdit_task);
  taskaddhorizontalLayout->addWidget(toolButton_add);
  verticalLayout1->addLayout(taskaddhorizontalLayout);
  tableWidget_tasks->setRowCount(0);
  tableWidget_tasks->setColumnCount(6);
  QStringList headers;
  headers << "Id"
          << "Task"
          << "Started"
          << "Finished"
          << "Duration"
          << "Actions";
  tableWidget_tasks->setHorizontalHeaderLabels(headers);
  /*auto reminders = storage.get_all<ReminderSetting>();
  for (auto &r : reminders) {
    addTaskToTable(r);
  }*/
  setWidths();
  myTimer = new QTimer(this);
  myTimer->start(60000);
  auto slot = [this]() {
    if (activedialog)
    {
      activedialog->showNormal();
      if (!activedialog->isActiveWindow())
      {
        activedialog->hide();
        activedialog->show();
        //        activedialog->activateWindow();
      }
      activedialog->raise();
      return;
    }
    auto dialog = new QDialog(this);
    dialog->raise();
    dialog->setWindowFlag(Qt::WindowStaysOnTopHint);
    dialog->setAttribute(Qt::WA_ShowWithoutActivating);
    auto hbox = new QHBoxLayout(dialog);
    auto rowcount = tableWidget_tasks->rowCount();
    QString lasttask;
    if (rowcount > 0) { lasttask = tableWidget_tasks->item(rowcount - 1, 1)->data(Qt::DisplayRole).toString(); }
    auto task = new QLineEdit();
    task->setText(lasttask);
    hbox->addWidget(task);
    dialog->show();
    activedialog = dialog;
    dialog->connect(dialog, &QDialog::accepted, [this]() { activedialog = nullptr; });
    dialog->connect(dialog, &QDialog::rejected, [this]() { activedialog = nullptr; });
    dialog->connect(task, &QLineEdit::returnPressed, [dialog, task, this]() {
      activedialog = nullptr;
      dialog->accept();
      addTask(task->text());
    });
  };
  connect(myTimer, &QTimer::timeout, slot);
  connect(lineEdit_task, &QLineEdit::returnPressed, [this]() { addTask(lineEdit_task->text()); });
  connect(toolButton_add, &QToolButton::clicked, [this]() { addTask(lineEdit_task->text()); });
}
void ReminderWidget::addTask(QString task)
{
  auto rowcount = tableWidget_tasks->rowCount();
  QString lasttask;
  int lasttaskid = 0;
  QString finished;
  if (rowcount > 0)
  {
    lasttask = tableWidget_tasks->item(rowcount - 1, 1)->data(Qt::DisplayRole).toString();
    lasttaskid = tableWidget_tasks->item(rowcount - 1, 0)->data(Qt::DisplayRole).toInt();
    finished = tableWidget_tasks->item(rowcount - 1, 3)->data(Qt::DisplayRole).toString();
  }
  if (task != lasttask)
  {
    // QDateTime timeNow = QDateTime::currentDateTime();
    addTaskToTable(Orm::taskSaveSetting(task.toStdString()));
    if (rowcount > 0 && finished.isEmpty())
    {
      auto r = Orm::taskUpdateSetting(lasttaskid);
      auto finishedItem = tableWidget_tasks->item(rowcount - 1, 0);
      auto durationItem = tableWidget_tasks->item(rowcount - 1, 4);
      finishedItem->setText(QString::fromStdString(r.finished));
      durationItem->setText(QString::fromStdString(r.duration));
      // stop_button->deleteLater();
      auto parentWidget = tableWidget_tasks->cellWidget(rowcount - 1, 5);
      if (parentWidget)
      {
        QToolButton *stop_button = parentWidget->findChild<QToolButton *>("stop");
        stop_button->setDisabled(true);
      }
    }
  }
}
void ReminderWidget::setWidths()
{
  tableWidget_tasks->setColumnWidth(0, 50);
  tableWidget_tasks->setColumnWidth(1, 250);
  tableWidget_tasks->setColumnWidth(2, 150);
  tableWidget_tasks->setColumnWidth(3, 150);
  tableWidget_tasks->setColumnWidth(4, 150);
  tableWidget_tasks->setColumnWidth(5, 120);
}
void ReminderWidget::addTaskToTable(ReminderSetting r)
{
  auto id = r.id;
  auto task = QString::fromStdString(r.task);
  auto started = QString::fromStdString(r.started);
  auto finished = QString::fromStdString(r.finished);
  auto duration = QString::fromStdString(r.duration);
  auto rowcount = tableWidget_tasks->rowCount();
  tableWidget_tasks->setRowCount(rowcount + 1);
  auto row = rowcount;
  QTableWidgetItem *idItem = new QTableWidgetItem(QString::number(id));
  tableWidget_tasks->setItem(row, 0, idItem);
  QTableWidgetItem *taskItem = new QTableWidgetItem(task);
  tableWidget_tasks->setItem(row, 1, taskItem);
  QTableWidgetItem *startedItem = new QTableWidgetItem(started);
  tableWidget_tasks->setItem(row, 2, startedItem);
  QTableWidgetItem *finishedItem = new QTableWidgetItem(finished);
  tableWidget_tasks->setItem(row, 3, finishedItem);
  QTableWidgetItem *durationItem = new QTableWidgetItem(duration);
  tableWidget_tasks->setItem(row, 4, durationItem);
  auto widget = new QWidget(this);
  auto hlayout = new QHBoxLayout(widget);
  if (finished.isEmpty())
  {
    auto stop_button = new QToolButton(this);
    stop_button->setText("stop");
    stop_button->setObjectName(QString::fromUtf8("stop"));
    hlayout->addWidget(stop_button);
    connect(stop_button, &QToolButton::clicked, [id, stop_button, finishedItem, durationItem]() {
      auto r = Orm::taskUpdateSetting(id);
      finishedItem->setText(QString::fromStdString(r.finished));
      durationItem->setText(QString::fromStdString(r.duration));
      // stop_button->deleteLater();
      stop_button->setDisabled(true);
    });
  }
  auto delete_button = new QToolButton(this);
  delete_button->setText("delete");
  hlayout->addWidget(delete_button);
  hlayout->setContentsMargins(0, 0, 0, 0);
  tableWidget_tasks->setCellWidget(row, 5, widget);
  connect(delete_button, &QToolButton::clicked, [id, idItem, this]() {
    Orm::taskRemoveValue(id);
    tableWidget_tasks->removeRow(idItem->row());
    // stop_button->deleteLater();
  });
  tableWidget_tasks->scrollToBottom();
}
}  // namespace widgets
