#ifndef YAMLGENERATOR_H
#define YAMLGENERATOR_H

#include <QWidget>
#include <functional>

namespace Ui {
class YamlGenerator;
}

class QToolButton;
class QPlainTextEdit;
class YamlGenerator : public QWidget
{
    Q_OBJECT

public:
    explicit YamlGenerator(QWidget *parent = nullptr);
    ~YamlGenerator();

private:
    Ui::YamlGenerator *ui;

    QString load(QString key, QString default_value);
    void set(QString key, QString value);
    QString get(QString key);

    void fileloadset();
    void parseset();
    void queryset();
    void buildset();
  void convertofrom();
    void setGoSaveTemplate(QString key, QString default_value, QToolButton *go, QToolButton *save, QPlainTextEdit *templ, std::function<void()> slot);

signals:
    void updatefileload();

private slots:
    void on_pushButton_clicked();
};

#endif // YAMLGENERATOR_H
