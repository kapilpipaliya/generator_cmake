#include "modelwriter.h"
#include "ui_modelwriter.h"

#include <QCXXHighlighter>
#include <QCodeEditor>
#include <QGLSLCompleter>
#include <QGLSLHighlighter>
#include <QJSONHighlighter>
#include <QSyntaxStyle>
#include <QXMLHighlighter>

#include <QSortFilterProxyModel>
#include <QtDebug>
#include "data.h"
#include "treeitem.h"

ModelWriter::ModelWriter(QWidget *parent)
    : QWidget(parent), ui(new Ui::ModelWriter) {
  ui->setupUi(this);
  // Create a QSortFilterProxyModel and setModel() of the QTableView to it.
  sourceModel = new Data(this);
  proxyModel = new QSortFilterProxyModel(this);
  proxyModel->setSourceModel(sourceModel);
  ui->treeView->setModel(proxyModel);
  //  ui->treeView->setModel(sourceModel);

  //  ui->treeView->setColumnWidth(0, 500);
  ui->treeView->resizeColumnToContents(0);
  //  ui->treeView->resizeColumnToContents(1);
  //  ui->treeView->resizeColumnToContents(2);
  // https://github.com/Megaxela/QCodeEditor/
  ui->textEdit_inter->setHighlighter(new QCXXHighlighter);
  ui->textEdit_final->setHighlighter(new QCXXHighlighter);
  ui->textEdit_inter->setTabReplaceSize(2);
  ui->textEdit_final->setTabReplaceSize(2);
  ui->textEdit_inter->setWordWrapMode(QTextOption::NoWrap);
  ui->textEdit_final->setWordWrapMode(QTextOption::NoWrap);

  connect(ui->treeView, &QTreeView::pressed, this,
          &ModelWriter::on_treeView_doubleClicked);
  connect(ui->toolButton_filter_clear, &QToolButton::clicked, [this]() {
    // Set the string you want to filter on using setFilterFixedString()
    // or setFilterRegExp() in your QSortFilterProxyModel
    proxyModel->setFilterRegExp("");
    ui->lineEdit_filter->setText("");
  });
  connect(ui->toolButton_all, &QToolButton::clicked, [this]() {
    for (int i = 0; i < proxyModel->rowCount(); ++i) {
      on_treeView_doubleClicked(proxyModel->index(i, 0));
    }
    connect(ui->toolButton_lineedit_all_clear, &QToolButton::clicked,
            [this]() { ui->textEdit_final->setText(""); });
    connect(ui->toolButton_textedit_inter_clear, &QToolButton::clicked,
            [this]() { ui->textEdit_inter->setText(""); });
    connect(ui->toolButton_template_clear, &QToolButton::clicked,
            [this]() { ui->plainTextEdit_template->setPlainText(""); });
  });
  auto append = R"(
    #include "models/%1.h"
  long insert_%2() {
    auto clientPtr = drogon::app().getDbClient("sce");
    drogon::orm::Mapper<drogon_model::openproject6::%1> mapper_%2(clientPtr);
    drogon_model::openproject6::%1 %2;
    %3
    mapper_%2.insert(%2);
  }
  long update_%2() {
            auto clientPtr = drogon::app().getDbClient("sce");
            drogon::orm::Mapper<drogon_model::openproject6::%1> mapper_%2(clientPtr);
            auto result_%2 = mapper_%2.findBy( (Criteria(drogon_model::openproject6::Settings::Cols::_name, CompareOperator::EQ, key)));
            if (result_%2.size() > 0) {
              auto settings = result_%2.at(0);
              %3
              mapper_%2.update(%2);
            } else {
              LOG_DEBUG << "no rows found for %2 table";
            }
  }
  long delete_%2() {
            auto clientPtr = drogon::app().getDbClient("sce");
            drogon::orm::Mapper<drogon_model::openproject6::%1> mapper_%2(clientPtr);
            // find_by
            //
                  }
  long find_%2() {
          auto clientPtr = drogon::app().getDbClient("sce");
          drogon::orm::Mapper<drogon_model::openproject6::%1> mapper_%2(clientPtr);

          auto result_%2 = mapper_%2.findBy(
                         (
                         Criteria(drogon_model::openproject6::%1::Cols::_id, CompareOperator::EQ, "name")
                         &&Criteria(drogon_model::openproject6::%1::Cols::_id,CompareOperator::EQ,0)
                         )
                         ||
                         (
                         Criteria(drogon_model::openproject6::%1::Cols::_id, CompareOperator::EQ, "name")
                         &&Criteria(drogon_model::openproject6::%1::Cols::_id,CompareOperator::EQ,0)
                         )
                         );
          auto result_%2 = mapper_%2.orderBy(drogon_model::openproject6::%1::Cols::_id).limit(25).offset(0).findAll();
          if(result_%2.size() > 0) {
              auto id = *result_%2.at(0).getId();
          } else {
               LOG_DEBUG << "no rows found for %2 table";
          }
      }
  )";
  ui->plainTextEdit_template->setPlainText(append);
}

ModelWriter::~ModelWriter() { delete ui; }
QString ModelWriter::toCamelCase(QString &s) {
  // https://wiki.qt.io/Converting_Strings_from_and_to_Camel_Case
  s.replace(0, 1, s[0].toUpper());
  QStringList parts = s.split('_', QString::SkipEmptyParts);
  for (int i = 1; i < parts.size(); ++i)
    parts[i].replace(0, 1, parts[i][0].toUpper());

  return parts.join("");
}

void ModelWriter::on_lineEdit_filter_textEdited(const QString &arg1) {
  // Set the string you want to filter on using setFilterFixedString() or
  // setFilterRegExp() in your QSortFilterProxyModel
  proxyModel->setFilterRegExp(arg1);
}

void ModelWriter::on_treeView_doubleClicked(const QModelIndex &index) {
  auto text = index.data().toString();
  auto rows = index.model()->rowCount(index);

  QString columns;
  for (int i = 0; i < rows; ++i) {
    auto column = proxyModel->index(i, 0, index).data().toString();
    auto type = proxyModel->index(i, 1, index).data().toString();
    auto default_ = proxyModel->index(i, 2, index).data().toString();
    auto isnull = proxyModel->index(i, 3, index).data().toString();
    auto value = "";
    if (type == "timestamp_without_time_zone") {
      value = "trantor::Date::now()";
    }
    columns += text.toLower() + ".set" + toCamelCase(column) + "(" + value +
               "); //" + type + " " + default_ + " " + isnull + ";\n";
  }

  auto append_result = QString(ui->plainTextEdit_template->toPlainText())
                           .arg(toCamelCase(text))
                           .arg(text.toLower())
                           .arg(columns);
  ui->textEdit_final->append(append_result);
  ui->textEdit_inter->setText(append_result);
}

void ModelWriter::on_toolButton_all_clicked() {
  qDebug() << proxyModel->rowCount();
  for (int i = 0; i < proxyModel->rowCount(); ++i) {
    on_treeView_doubleClicked(proxyModel->index(i, 0));
  }
}
