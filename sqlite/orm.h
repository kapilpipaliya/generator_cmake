#ifndef ORM_H
#define ORM_H
#include <QString>
#include <memory>
#include <string>
//#include "./sqlite_orm.h"
struct User
{
  int id;
  std::string firstName;
  std::string lastName;
  int birthDate;
  std::unique_ptr<std::string> imageUrl;
  int typeId;
};
struct UserType
{
  int id;
  std::string name;
};
struct YamlSetting
{
  int id;
  std::string key;
  std::string template_string;
};
struct DrogonModelSetting
{
  int id;
  std::string key;
  std::string template_string;
};
struct SQLCompareSetting
{
  int id;
  std::string key;
  std::string template_string;
};
struct ReminderSetting
{
  int id;
  std::string task;
  std::string started;
  std::string finished;
  std::string duration;
};
struct WsTestSettingSetting
{
  int id;
  int number;
  std::string event_name;
  std::string arg;
  std::string payload;
  std::string result;
};
inline auto initStorage(const std::string &path)
{
  /*using namespace sqlite_orm;
  return make_storage(path,
                      make_table("users",
                                 make_column("id", &User::id, autoincrement(), primary_key()),
                                 make_column("first_name", &User::firstName),
                                 make_column("last_name", &User::lastName),
                                 make_column("birth_date", &User::birthDate),
                                 make_column("image_url", &User::imageUrl),
                                 make_column("type_id", &User::typeId)),
                      make_table("user_types", make_column("id", &UserType::id, autoincrement(), primary_key()), make_column("name", &UserType::name, default_value("name_placeholder"))),
                      make_table("yaml_settings",
                                 make_column("id", &YamlSetting::id, autoincrement(), primary_key()),
                                 make_column("key", &YamlSetting::key),
                                 make_column("template_string", &YamlSetting::template_string)),
                      make_table("drogon_model_settings",
                                 make_column("id", &DrogonModelSetting::id, autoincrement(), primary_key()),
                                 make_column("key", &DrogonModelSetting::key),
                                 make_column("template_string", &DrogonModelSetting::template_string)),
                      make_table("sql_compare_settings",
                                 make_column("id", &SQLCompareSetting::id, autoincrement(), primary_key()),
                                 make_column("key", &SQLCompareSetting::key),
                                 make_column("template_string", &SQLCompareSetting::template_string)),
                      make_table("reminder_settings",
                                 make_column("id", &ReminderSetting::id, autoincrement(), primary_key()),
                                 make_column("task", &ReminderSetting::task),
                                 make_column("started", &ReminderSetting::started),
                                 make_column("finished", &ReminderSetting::finished),
                                 make_column("duration", &ReminderSetting::duration)),
                      make_table("wstest_settings",
                                 make_column("id", &WsTestSettingSetting::id, autoincrement(), primary_key()),
                                 make_column("number", &WsTestSettingSetting::number),
                                 make_column("key", &WsTestSettingSetting::event_name),
                                 make_column("arg", &WsTestSettingSetting::arg),
                                 make_column("payload", &WsTestSettingSetting::payload),
                                 make_column("result", &WsTestSettingSetting::result)));*/
}
using Storage = decltype(initStorage(""));
// extern Storage storage;
class Orm
{
public:
  Orm();
  static int yamlSaveSetting(std::string key, std::string value);
  static std::string yamlGetValue(std::string key);
  static int drogonModelSaveSetting(std::string key, std::string value);
  static std::string drogonModelGetValue(std::string key);
  static bool drogonModelRemoveValue(std::string key);
  static int sqlCompareSaveSetting(std::string key, std::string value);
  static std::string sqlCompareGetValue(std::string key);
  static ReminderSetting taskSaveSetting(std::string task);
  static ReminderSetting taskUpdateSetting(int task);
  static ReminderSetting taskGetValue(int task_id);
  static bool taskRemoveValue(int id);
  static WsTestSettingSetting wstestSaveSetting(int number, std::string event_name, std::string arg, std::string payload, std::string result);
  static WsTestSettingSetting wstestUpdateSetting(int id, int number, std::string event_name, std::string arg, std::string payload, std::string result);
  static WsTestSettingSetting wstestGetValue(int id);
  static bool wstestRemoveValue(int id);
  static std::string timeStringFromSec(qint64 totalNumberOfSeconds);
};
#endif  // ORM_H
