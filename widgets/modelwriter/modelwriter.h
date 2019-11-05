#ifndef MODELWRITER_H
#define MODELWRITER_H

#include <QWidget>

namespace Ui {
class ModelWriter;
}
class QSortFilterProxyModel;

class QToolButton;
class QPlainTextEdit;
class QCodeEditor;
class QGroupBox;
namespace widgets {
class Data;
class ModelWriter : public QWidget {
  Q_OBJECT

 public:
  explicit ModelWriter(QWidget *parent = nullptr);
  ~ModelWriter();

 private slots:
  void on_lineEdit_filter_textEdited(const QString &arg1);

 private:
  Ui::ModelWriter *ui;

 private:
  QString load(QString key, QString default_value);
  void set(QString key, QString value);
  QString get(QString key);

  void addItem(QString item);
  QString toCamelCase(QString &s);
  Data *sourceModel;
  QSortFilterProxyModel *proxyModel;

  void setGoSaveTemplate(QString key, QString default_value, QToolButton *go,
                         QToolButton *save, QToolButton *delete_button,
                         QGroupBox *box, QCodeEditor *templ, QCodeEditor *result,
                         std::function<void()> slot);
  void setTemplResult(QCodeEditor *templ, QCodeEditor *result);

  void cppeditor(QCodeEditor *editor);

  QGroupBox *groupboxCreate(QString key, QString value);
};
}  // namespace widgets
#endif  // MODELWRITER_H
