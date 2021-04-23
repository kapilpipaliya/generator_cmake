#include "./orm.h"
#include <QDateTime>
#include <iostream>
// Storage storage = initStorage("db.sqlite");
Orm::Orm()
{ /*storage.sync_schema();*/
}
int Orm::yamlSaveSetting(std::string key, std::string value)
{
  /*using namespace sqlite_orm;
  auto yaml = storage.get_all<YamlSetting>(where(c(&YamlSetting::key) == key));
  if (yaml.size() > 0) {
    auto y = yaml.at(0);
    y.template_string = value;
    storage.update(y);
    return y.id;
  } else {
    YamlSetting y{-1, key, value};
    auto insertedId = storage.insert(y);
    return insertedId;
  }*/
}
std::string Orm::yamlGetValue(std::string key)
{
  /*using namespace sqlite_orm;
  auto yaml = storage.get_all<YamlSetting>(where(c(&YamlSetting::key) == key));
  if (yaml.size() > 0) {
    return yaml.at(0).template_string;
  } else {
    return "";
  }*/
}
int Orm::drogonModelSaveSetting(std::string key, std::string value)
{
  /*using namespace sqlite_orm;
  auto yaml = storage.get_all<DrogonModelSetting>(
      where(c(&DrogonModelSetting::key) == key));
  if (yaml.size() > 0) {
    auto y = yaml.at(0);
    y.template_string = value;
    storage.update(y);
    return y.id;
  } else {
    DrogonModelSetting y{-1, key, value};
    auto insertedId = storage.insert(y);
    return insertedId;
  }*/
}
std::string Orm::drogonModelGetValue(std::string key)
{
  /*using namespace sqlite_orm;
  auto yaml = storage.get_all<DrogonModelSetting>(
      where(c(&DrogonModelSetting::key) == key));
  if (yaml.size() > 0) {
    return yaml.at(0).template_string;
  } else {
    return "";
  }*/
}
bool Orm::drogonModelRemoveValue(std::string key)
{
  /*using namespace sqlite_orm;
  auto yaml = storage.get_all<DrogonModelSetting>(
      where(c(&DrogonModelSetting::key) == key));
  if (yaml.size() > 0) {
    auto y = yaml.at(0);
    storage.remove<DrogonModelSetting>(y.id);
    return true;
  } else {
    return false;
  }*/
}
int Orm::sqlCompareSaveSetting(std::string key, std::string value)
{
  /*using namespace sqlite_orm;
  auto yaml = storage.get_all<SQLCompareSetting>(
      where(c(&SQLCompareSetting::key) == key));
  if (yaml.size() > 0) {
    auto y = yaml.at(0);
    y.template_string = value;
    storage.update(y);
    return y.id;
  } else {
    SQLCompareSetting y{-1, key, value};
    auto insertedId = storage.insert(y);
    return insertedId;
  }*/
}
std::string Orm::sqlCompareGetValue(std::string key)
{
  /* using namespace sqlite_orm;
   auto yaml = storage.get_all<SQLCompareSetting>(
       where(c(&SQLCompareSetting::key) == key));
   if (yaml.size() > 0) {
     return yaml.at(0).template_string;
   } else {
     return "";
   }*/
}
ReminderSetting Orm::taskSaveSetting(std::string task)
{
  /*using namespace sqlite_orm;
  auto timenow = storage.select(datetime("now", "localtime")).front();
  ReminderSetting r{-1, task, timenow, "", ""};
  auto insertedId = storage.insert(r);
  r.id = insertedId;
  return r;*/
}
ReminderSetting Orm::taskUpdateSetting(int task_id)
{
  /*using namespace sqlite_orm;
  auto yaml = storage.get_all<ReminderSetting>(
      where(c(&ReminderSetting::id) == task_id));
  auto timenow = storage.select(datetime("now", "localtime")).front();
  if (yaml.size() > 0) {
    auto y = yaml.at(0);
    y.finished = timenow;
    auto started =
        QDateTime::fromString(QString::fromStdString(y.started), Qt::ISODate);
    auto finished =
        QDateTime::fromString(QString::fromStdString(timenow), Qt::ISODate);
    auto duration = timeStringFromSec(started.msecsTo(finished));
    y.duration = duration;
    storage.update(y);
    return y;
  } else {
    return {};
  }*/
}
ReminderSetting Orm::taskGetValue(int task_id)
{
  /*using namespace sqlite_orm;
  auto yaml = storage.get_all<ReminderSetting>(
      where(c(&ReminderSetting::id) == task_id));
  if (yaml.size() > 0) {
    return yaml.at(0);
  } else {
    return {};
  }*/
}
bool Orm::taskRemoveValue(int id)
{
  /*using namespace sqlite_orm;
  auto yaml =
      storage.get_all<ReminderSetting>(where(c(&ReminderSetting::id) == id));
  if (yaml.size() > 0) {
    auto y = yaml.at(0);
    storage.remove<ReminderSetting>(y.id);
    return true;
  } else {
    return false;
  }*/
}
WsTestSettingSetting Orm::wstestSaveSetting(int number, std::string event_name, std::string arg, std::string payload, std::string result)
{
  /*using namespace sqlite_orm;
  WsTestSettingSetting r{-1, number, event_name, arg, payload, result};
  auto insertedId = storage.insert(r);
  r.id = insertedId;
  return r;*/
}
WsTestSettingSetting Orm::wstestUpdateSetting(int id, int number, std::string event_name, std::string arg, std::string payload, std::string result)
{
  /*using namespace sqlite_orm;
  auto wstest = storage.get_all<WsTestSettingSetting>(
      where(c(&WsTestSettingSetting::id) == id));
  if (wstest.size() > 0) {
    auto y = wstest.at(0);
    y.number = number;
    y.event_name = event_name;
    y.arg = arg;
    y.payload = payload;
    y.result = result;
    storage.update(y);
    return y;
  } else {
    return {};
  }*/
}
WsTestSettingSetting Orm::wstestGetValue(int id)
{
  /*using namespace sqlite_orm;
  auto ws = storage.get_all<WsTestSettingSetting>(
      where(c(&WsTestSettingSetting::id) == id));
  if (ws.size() > 0) {
    return ws.at(0);
  } else {
    return {};
  }*/
}
bool Orm::wstestRemoveValue(int id)
{
  /* using namespace sqlite_orm;
   auto yaml = storage.get_all<WsTestSettingSetting>(
       where(c(&WsTestSettingSetting::id) == id));
   if (yaml.size() > 0) {
     auto y = yaml.at(0);
     storage.remove<WsTestSettingSetting>(y.id);
     return true;
   } else {
     return false;
   }*/
}
std::string Orm::timeStringFromSec(qint64 totalNumberOfSeconds)
{
  // https://stackoverflow.com/a/55761192/4372670
  totalNumberOfSeconds /= 1000;  // 1000 millisecond = 1second
  int seconds = totalNumberOfSeconds % 60;
  int minutes = (totalNumberOfSeconds / 60) % 60;
  int hours = (totalNumberOfSeconds / 60 / 60);
  QString timeString = QString("%1:%2:%3").arg(hours, 2, 10, QChar('0')).arg(minutes, 2, 10, QChar('0')).arg(seconds, 2, 10, QChar('0'));
  return timeString.toStdString();
}
