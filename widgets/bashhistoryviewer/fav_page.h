#ifndef FAV_PAGE_H
#define FAV_PAGE_H


#include <QWidget>


using namespace std;

QT_BEGIN_NAMESPACE
class QAbstractItemModel;
class QPushButton;
class QCheckBox;
class QComboBox;
class QGroupBox;
class QLabel;
class QLineEdit;
class QSortFilterProxyModel;
class QTreeView;
class QTabWidget;
class QToolBar;
QT_END_NAMESPACE

class FavPage : public QWidget
{
    Q_OBJECT

public:
    FavPage();
    QWidget* get();

QSortFilterProxyModel *proxyModel;
QTreeView *proxyView;

private slots:

    //Favourites
    void filterRegExpChanged();
    void filterColumnChanged();
    void sortChanged();

private:
    //Favourites

    QGroupBox *sourceGroupBox;
    QGroupBox *favProxyGroupBox;
    QTreeView *sourceView;

    QCheckBox *filterCaseSensitivityCheckBox;
    QCheckBox *sortCaseSensitivityCheckBox;
    QLabel *filterPatternLabel;
    QLabel *filterSyntaxLabel;
    QLabel *filterColumnLabel;
    QLineEdit *filterPatternLineEdit;
    QComboBox *filterSyntaxComboBox;
    QComboBox *filterColumnComboBox;

};
#endif // FAV_PAGE_H
