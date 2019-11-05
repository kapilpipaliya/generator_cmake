#include "./sqlcompare.h"
#include <drogon/orm/DbClient.h>
#include <QSortFilterProxyModel>
#include <QtDebug>
#include <QtSql>
#include "../modelwriter/data.h"
#include "sqlite/orm.h"
namespace widgets {
SqlCompare::SqlCompare(QWidget* parent)
    : QWidget(parent), ui(new Ui::SqlCompare) {
  ui->setupUi(this);
  this->setAttribute(Qt::WA_DeleteOnClose);

  db1 = ui->lineEdit_db1;
  db2 = ui->lineEdit_db2;
  table = ui->lineEdit_table;
  columns = ui->lineEdit_columns;
  go1 = ui->toolButton_go_1;
  go2 = ui->toolButton_go_2;
  go_all = ui->toolButton_go_all;
  match = ui->toolButton_match;
  count = ui->toolButton_count;
  order_by = ui->lineEdit_order_by;
  where = ui->lineEdit_where;
  result1 = ui->textEdit_1;
  result2 = ui->textEdit_2;

  loadAll();

  sourceModel = new Data(this);
  proxyModel = new QSortFilterProxyModel(this);
  proxyModel->setSourceModel(sourceModel);
  ui->treeView->setModel(proxyModel);

  ui->treeView->resizeColumnToContents(0);
  /*
  connect(ui->toolButton_filter_clear, &QToolButton::clicked, [this]() {
    // Set the string you want to filter on using setFilterFixedString()
    // or setFilterRegExp() in your QSortFilterProxyModel
    proxyModel->setFilterRegExp("");
    ui->lineEdit_filter->setText("");
  });
  */
  connect(ui->treeView, &QTreeView::pressed, [this](const QModelIndex& index) {
    auto text = index.data().toString();
    table->setText(text);
  });
  connect(ui->toolButton_set, &QToolButton::pressed, [this]() {
    auto text = ui->lineEdit_result_columns->text();
    columns->setText(text);
  });
  connect(ui->toolButton_c, &QToolButton::pressed, [this]() {
    auto db = QSqlDatabase::database("client1");
    QSqlDatabase client1;
    if (db.isValid()) {
      client1 = db;
    } else {
      client1 = QSqlDatabase::addDatabase("QPSQL", "client1");
    }
    client1.setDatabaseName(db1->text());
    client1.setHostName("localhost");
    client1.setPort(5432);
    if (!client1.open("postgres", "postgres")) {
      qDebug() << "unsuccess:" << client1.lastError();
      client1 = QSqlDatabase();
      QSqlDatabase::removeDatabase(QString("client1"));
      qDebug() << "unsuc: " << client1.lastError();
    } else {
      auto record = client1.driver()->record(ui->lineEdit_table->text());
      auto c = record.count();
      auto r_column = ui->lineEdit_result_columns;
      r_column->clear();
      QString s;
      for (int i = 0; i < c; ++i) {
        auto f = record.field(i);
        s += f.name();
        s += ", ";
      }
      r_column->setText(s);
    }
  });
  connect(go1, &QToolButton::clicked, [this]() {
    result1->clear();
    getresult(db1->text(), getSql1(), result1);
  });
  connect(go2, &QToolButton::clicked, [this]() {
    result2->clear();
    getresult(db2->text(), getSql2(), result2);
  });
  connect(go_all, &QToolButton::clicked, [this]() {
    result1->clear();
    result2->clear();
    getresult(db1->text(), getSql1(), result1);
    getresult(db2->text(), getSql2(), result2);
    matchresult();
  });
  connect(match, &QToolButton::clicked, [this]() { matchresult(); });
  connect(count, &QToolButton::clicked, [this]() { getcount(); });
  connect(ui->toolButton_save, &QToolButton::clicked, this,
          &SqlCompare::saveAll);
  connect(ui->toolButton_load, &QToolButton::clicked, this,
          &SqlCompare::loadAll);

  connect(ui->toolButton_filter_clear, &QToolButton::clicked, [this]() {
    // Set the string you want to filter on using setFilterFixedString()
    // or setFilterRegExp() in your QSortFilterProxyModel
    proxyModel->setFilterRegExp("");
    ui->lineEdit_filter->setText("");
  });
  connect(ui->toolButton_all, &QToolButton::clicked, [this]() {
    for (int i = 0; i < proxyModel->rowCount(); ++i) {
      // on_treeView_doubleClicked(proxyModel->index(i, 0));
    }
  });
  connect(ui->lineEdit_filter, &QLineEdit::textChanged,
          [this](const QString& arg1) { proxyModel->setFilterRegExp(arg1); });
}

SqlCompare::~SqlCompare() { delete ui; }

void SqlCompare::loadAll() {
  db1->setText(load("db1", db1->text()));
  db2->setText(load("db2", db2->text()));
  table->setText(load("table", table->text()));
  columns->setText(load("columns", columns->text()));
  order_by->setText(load("order_by", order_by->text()));
  where->setText(load("where", where->text()));
}

void SqlCompare::saveAll() {
  set("db1", db1->text());
  set("db2", db2->text());
  set("table", table->text());
  set("columns", columns->text());
  set("order_by", order_by->text());
  set("where", where->text());
}

QString SqlCompare::load(QString key, QString default_value) {
  auto value = get(key);
  if (value.isEmpty()) {
    set(key, default_value);
    return default_value;
  } else {
    return value;
  }
}

void SqlCompare::set(QString key, QString value) {
  Orm::sqlCompareSaveSetting(key.toStdString(), value.toStdString());
}

QString SqlCompare::get(QString key) {
  return QString::fromStdString(Orm::sqlCompareGetValue(key.toStdString()));
}

QString SqlCompare::getSql1() {
  return "SELECT " + columns->text() + " FROM " + table->text() + " " +
         where->text() + " " + order_by->text();
}

QString SqlCompare::getSql2() {
  return "SELECT " + columns->text() + " FROM " + table->text() + " " +
         where->text() + " " + order_by->text();
}

void SqlCompare::getresult(QString database, QString strSql,
                           QTextEdit* result) {
  auto db = QSqlDatabase::database("client1");
  QSqlDatabase client1;
  if (db.isValid()) {
    client1 = db;
  } else {
    client1 = QSqlDatabase::addDatabase("QPSQL", "client1");
  }
  client1.setDatabaseName(database);
  client1.setHostName("localhost");
  client1.setPort(5432);
  if (!client1.open("postgres", "postgres")) {
    qDebug() << "unsuccess:" << client1.lastError();
    client1 = QSqlDatabase();
    QSqlDatabase::removeDatabase(QString("client1"));
    qDebug() << "unsuc: " << client1.lastError();
  } else {
    auto record = client1.driver()->record(ui->lineEdit_table->text());
    auto c = record.count();
    auto r_column = ui->lineEdit_result_columns;
    r_column->clear();
    QString s;
    for (int i = 0; i < c; ++i) {
      auto f = record.field(i);
      s += f.name();
      s += ", ";
    }
    QSqlQuery query("", client1);  // executes query
    query.prepare(strSql);
    if (query.exec()) {
      r_column->setText(s);
      while (query.next()) {
        auto count = query.record().count();
        for (int i = 0; i < count; ++i) {
          auto text = result->toPlainText();
          text += query.value(i).toString();
          text += ", ";
          result->setText(text);
        }
        auto text = result->toPlainText();
        text += "\n";
        result->setText(text);
      }
    } else {
      qDebug() << query.lastError() << ": " << query.lastQuery();
    }
  }
}

void SqlCompare::matchresult() {
  if (result1->toPlainText() == result2->toPlainText()) {
    ui->label_5->setText("Matched");
  } else {
    ui->label_5->setText("Not Matched");
  }
}

void SqlCompare::getcount() {
  result1->clear();
  result2->clear();
  auto count = R"(
select 'announcements' relname ,count(*) from announcements
union
select 'ar_internal_metadata' relname ,count(*) from ar_internal_metadata
union
select 'attachable_journals' relname ,count(*) from attachable_journals
union
select 'attachment_journals' relname ,count(*) from attachment_journals
union
select 'attachments' relname ,count(*) from attachments
union
select 'attribute_help_texts' relname ,count(*) from attribute_help_texts
union
select 'auth_sources' relname ,count(*) from auth_sources
union
select 'categories' relname ,count(*) from categories
union
select 'changes' relname ,count(*) from changes
union
select 'changeset_journals' relname ,count(*) from changeset_journals
union
select 'changesets' relname ,count(*) from changesets
union
select 'changesets_work_packages' relname ,count(*) from changesets_work_packages
union
select 'colors' relname ,count(*) from colors
union
select 'comments' relname ,count(*) from comments
union
select 'cost_entries' relname ,count(*) from cost_entries
union
select 'cost_object_journals' relname ,count(*) from cost_object_journals
union
select 'cost_objects' relname ,count(*) from cost_objects
union
select 'cost_queries' relname ,count(*) from cost_queries
union
select 'cost_types' relname ,count(*) from cost_types
union
select 'custom_actions' relname ,count(*) from custom_actions
union
select 'custom_actions_projects' relname ,count(*) from custom_actions_projects
union
select 'custom_actions_roles' relname ,count(*) from custom_actions_roles
union
select 'custom_actions_statuses' relname ,count(*) from custom_actions_statuses
union
select 'custom_actions_types' relname ,count(*) from custom_actions_types
union
select 'custom_fields' relname ,count(*) from custom_fields
union
select 'custom_fields_projects' relname ,count(*) from custom_fields_projects
union
select 'custom_fields_types' relname ,count(*) from custom_fields_types
union
select 'custom_options' relname ,count(*) from custom_options
union
select 'custom_styles' relname ,count(*) from custom_styles
union
select 'custom_values' relname ,count(*) from custom_values
union
select 'customizable_journals' relname ,count(*) from customizable_journals
union
select 'delayed_jobs' relname ,count(*) from delayed_jobs
union
select 'design_colors' relname ,count(*) from design_colors
union
select 'document_journals' relname ,count(*) from document_journals
union
select 'documents' relname ,count(*) from documents
union
select 'done_statuses_for_project' relname ,count(*) from done_statuses_for_project
union
select 'enabled_modules' relname ,count(*) from enabled_modules
union
select 'enterprise_tokens' relname ,count(*) from enterprise_tokens
union
select 'enumerations' relname ,count(*) from enumerations
union
select 'export_card_configurations' relname ,count(*) from export_card_configurations
union
select 'forums' relname ,count(*) from forums
union
select 'grid_widgets' relname ,count(*) from grid_widgets
union
select 'grids' relname ,count(*) from grids
union
select 'group_users' relname ,count(*) from group_users
union
select 'journal_versions' relname ,count(*) from journal_versions
union
select 'journals' relname ,count(*) from journals
union
select 'labor_budget_items' relname ,count(*) from labor_budget_items
union
select 'ldap_groups_memberships' relname ,count(*) from ldap_groups_memberships
union
select 'ldap_groups_synchronized_groups' relname ,count(*) from ldap_groups_synchronized_groups
union
select 'material_budget_items' relname ,count(*) from material_budget_items
union
select 'meeting_content_journals' relname ,count(*) from meeting_content_journals
union
select 'meeting_contents' relname ,count(*) from meeting_contents
union
select 'meeting_journals' relname ,count(*) from meeting_journals
union
select 'meeting_participants' relname ,count(*) from meeting_participants
union
select 'meetings' relname ,count(*) from meetings
union
select 'member_roles' relname ,count(*) from member_roles
union
select 'members' relname ,count(*) from members
union
select 'menu_items' relname ,count(*) from menu_items
union
select 'message_journals' relname ,count(*) from message_journals
union
select 'messages' relname ,count(*) from messages
union
select 'news' relname ,count(*) from news
union
select 'news_journals' relname ,count(*) from news_journals
union
select 'oauth_access_grants' relname ,count(*) from oauth_access_grants
union
select 'oauth_access_tokens' relname ,count(*) from oauth_access_tokens
union
select 'oauth_applications' relname ,count(*) from oauth_applications
union
select 'ordered_work_packages' relname ,count(*) from ordered_work_packages
union
select 'plaintext_tokens' relname ,count(*) from plaintext_tokens
union
select 'principal_roles' relname ,count(*) from principal_roles
union
select 'project_associations' relname ,count(*) from project_associations
union
select 'projects' relname ,count(*) from projects
union
select 'projects_types' relname ,count(*) from projects_types
union
select 'queries' relname ,count(*) from queries
union
select 'rates' relname ,count(*) from rates
union
select 'recaptcha_entries' relname ,count(*) from recaptcha_entries
union
select 'relations' relname ,count(*) from relations
union
select 'repositories' relname ,count(*) from repositories
union
select 'role_permissions' relname ,count(*) from role_permissions
union
select 'roles' relname ,count(*) from roles
union
select 'schema_migrations' relname ,count(*) from schema_migrations
union
select 'sessions' relname ,count(*) from sessions
union
select 'settings' relname ,count(*) from settings
union
select 'statuses' relname ,count(*) from statuses
union
select 'time_entries' relname ,count(*) from time_entries
union
select 'time_entry_journals' relname ,count(*) from time_entry_journals
union
select 'tokens' relname ,count(*) from tokens
union
select 'two_factor_authentication_devices' relname ,count(*) from two_factor_authentication_devices
union
select 'types' relname ,count(*) from types
union
select 'user_passwords' relname ,count(*) from user_passwords
union
select 'user_preferences' relname ,count(*) from user_preferences
union
select 'users' relname ,count(*) from users
union
select 'version_settings' relname ,count(*) from version_settings
union
select 'versions' relname ,count(*) from versions
union
select 'watchers' relname ,count(*) from watchers
union
select 'webhooks_events' relname ,count(*) from webhooks_events
union
select 'webhooks_logs' relname ,count(*) from webhooks_logs
union
select 'webhooks_projects' relname ,count(*) from webhooks_projects
union
select 'webhooks_webhooks' relname ,count(*) from webhooks_webhooks
union
select 'wiki_content_journals' relname ,count(*) from wiki_content_journals
union
select 'wiki_contents' relname ,count(*) from wiki_contents
union
select 'wiki_pages' relname ,count(*) from wiki_pages
union
select 'wiki_redirects' relname ,count(*) from wiki_redirects
union
select 'wikis' relname ,count(*) from wikis
union
select 'work_package_journals' relname ,count(*) from work_package_journals
union
select 'work_packages' relname ,count(*) from work_packages
union
select 'workflows' relname ,count(*) from workflows
order by relname
)";
  getresult(db1->text(), count, result1);
  getresult(db2->text(), count, result2);
  matchresult();
}
}  // namespace widgets
