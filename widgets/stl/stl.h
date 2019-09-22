#ifndef STL_H
#define STL_H

#include <QWidget>

namespace Ui {
class Stl;
}

class Stl : public QWidget
{
    Q_OBJECT

public:
    explicit Stl(QWidget *parent = nullptr);
    ~Stl();

private:
    Ui::Stl *ui;
};

#endif // STL_H
