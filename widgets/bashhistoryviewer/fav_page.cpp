#include <QtWidgets>
#include <iostream>

#include "./fav_page.h"
#include "./window.h"

using namespace std;

FavPage::FavPage() {}

QWidget* FavPage::get() {
  QWidget* mainWidget = new QWidget();

  proxyModel = new QSortFilterProxyModel;

  proxyView = new QTreeView;
  proxyView->setRootIsDecorated(false);
  proxyView->setAlternatingRowColors(true);
  proxyView->setModel(proxyModel);
  proxyView->setSortingEnabled(true);

  sortCaseSensitivityCheckBox = new QCheckBox(tr("Case sensitive sorting"));
  filterCaseSensitivityCheckBox = new QCheckBox(tr("Case sensitive filter"));

  filterPatternLineEdit = new QLineEdit;
  filterPatternLabel = new QLabel(tr("&Filter pattern:"));
  filterPatternLabel->setBuddy(filterPatternLineEdit);

  filterSyntaxComboBox = new QComboBox;
  filterSyntaxComboBox->addItem(tr("Regular expression"), QRegExp::RegExp);
  filterSyntaxComboBox->addItem(tr("Wildcard"), QRegExp::Wildcard);
  filterSyntaxComboBox->addItem(tr("Fixed string"), QRegExp::FixedString);
  filterSyntaxLabel = new QLabel(tr("Filter &syntax:"));
  filterSyntaxLabel->setBuddy(filterSyntaxComboBox);

  filterColumnComboBox = new QComboBox;
  filterColumnComboBox->addItem(tr("Line"));

  filterColumnLabel = new QLabel(tr("Filter &column:"));
  filterColumnLabel->setBuddy(filterColumnComboBox);

  connect(filterPatternLineEdit, &QLineEdit::textChanged, this,
          &FavPage::filterRegExpChanged);
  connect(filterSyntaxComboBox,
          QOverload<int>::of(&QComboBox::currentIndexChanged), this,
          &FavPage::filterRegExpChanged);
  connect(filterColumnComboBox,
          QOverload<int>::of(&QComboBox::currentIndexChanged), this,
          &FavPage::filterColumnChanged);
  connect(filterCaseSensitivityCheckBox, &QAbstractButton::toggled, this,
          &FavPage::filterRegExpChanged);
  connect(sortCaseSensitivityCheckBox, &QAbstractButton::toggled, this,
          &FavPage::sortChanged);

  favProxyGroupBox = new QGroupBox(tr("Made by Josep Jesus Bigorra Algaba"));

  QGridLayout* favProxyLayout = new QGridLayout;
  favProxyLayout->addWidget(proxyView, 0, 0, 1, 3);
  favProxyLayout->addWidget(filterPatternLabel, 1, 0);
  favProxyLayout->addWidget(filterPatternLineEdit, 1, 1, 1, 2);
  favProxyLayout->addWidget(filterSyntaxLabel, 2, 0);
  favProxyLayout->addWidget(filterSyntaxComboBox, 2, 1, 1, 2);
  favProxyLayout->addWidget(filterColumnLabel, 3, 0);
  favProxyLayout->addWidget(filterColumnComboBox, 3, 1, 1, 2);
  favProxyLayout->addWidget(filterCaseSensitivityCheckBox, 4, 0, 1, 2);
  favProxyLayout->addWidget(sortCaseSensitivityCheckBox, 4, 2);
  favProxyGroupBox->setLayout(favProxyLayout);

  QVBoxLayout* mainLayout = new QVBoxLayout;

  mainLayout->addWidget(favProxyGroupBox);
  mainWidget->setLayout(mainLayout);

  setWindowTitle(tr("Bash History"));
  resize(700, 550);

  proxyView->sortByColumn(1, Qt::AscendingOrder);
  filterColumnComboBox->setCurrentIndex(1);
  filterPatternLineEdit->setText("");

  filterCaseSensitivityCheckBox->setChecked(true);
  sortCaseSensitivityCheckBox->setChecked(true);
  filterColumnComboBox->setCurrentIndex(0);

  return mainWidget;
}

void FavPage::filterRegExpChanged() {
  QRegExp::PatternSyntax syntax = QRegExp::PatternSyntax(
      filterSyntaxComboBox->itemData(filterSyntaxComboBox->currentIndex())
          .toInt());
  Qt::CaseSensitivity caseSensitivity =
      filterCaseSensitivityCheckBox->isChecked() ? Qt::CaseSensitive
                                                 : Qt::CaseInsensitive;

  QRegExp regExp(filterPatternLineEdit->text(), caseSensitivity, syntax);
  proxyModel->setFilterRegExp(regExp);
}

void FavPage::filterColumnChanged() {
  proxyModel->setFilterKeyColumn(filterColumnComboBox->currentIndex());
}

void FavPage::sortChanged() {
  proxyModel->setSortCaseSensitivity(sortCaseSensitivityCheckBox->isChecked()
                                         ? Qt::CaseSensitive
                                         : Qt::CaseInsensitive);
}
