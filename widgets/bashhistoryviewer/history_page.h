#ifndef HISTORY_PAGE_H
#define HISTORY_PAGE_H

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

class HistoryPage : public QWidget
{
    Q_OBJECT

public:
    HistoryPage();
    QWidget* get();

    QSortFilterProxyModel *proxyModel;
    QTreeView *proxyView;


private slots:

    //History
    void filterRegExpChanged();
    void filterColumnChanged();
    void sortChanged();


private:

    //History

    QGroupBox *sourceGroupBox;
    QGroupBox *proxyGroupBox;
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

#endif // HISTORY_PAGE_H
