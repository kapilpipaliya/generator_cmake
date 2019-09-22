#ifndef NAMESPACEGENERATOR_H
#define NAMESPACEGENERATOR_H

#include <QWidget>

namespace Ui {
class NameSpaceGenerator;
}

class NameSpaceGenerator : public QWidget
{
    Q_OBJECT

public:
    explicit NameSpaceGenerator(QWidget *parent = nullptr);
    ~NameSpaceGenerator();

private:
    Ui::NameSpaceGenerator *ui;
};

#endif // NAMESPACEGENERATOR_H
