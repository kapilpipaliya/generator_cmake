#ifndef JSONGENERATOR_H
#define JSONGENERATOR_H

#include <QWidget>

namespace Ui {
class JsonGenerator;
}

class JsonGenerator : public QWidget
{
    Q_OBJECT

public:
    explicit JsonGenerator(QWidget *parent = nullptr);
    ~JsonGenerator();

private:
    Ui::JsonGenerator *ui;
};

#endif // JSONGENERATOR_H
