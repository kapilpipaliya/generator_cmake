#ifndef ORM_H
#define ORM_H
#include <string>
#include <memory>
#include "sqlite_orm.h"

struct User{
    int id;
    std::string firstName;
    std::string lastName;
    int birthDate;
    std::unique_ptr<std::string> imageUrl;
    int typeId;
};

struct UserType {
    int id;
    std::string name;
};

struct YamlSetting{
    int id;
    std::string key;
    std::string template_string;
};


inline auto initStorage(const std::string &path) {
  using namespace sqlite_orm;
  return make_storage(
      path,
      make_table("users",
                 make_column("id", &User::id, autoincrement(), primary_key()),
                 make_column("first_name", &User::firstName),
                 make_column("last_name", &User::lastName),
                 make_column("birth_date", &User::birthDate),
                 make_column("image_url", &User::imageUrl),
                 make_column("type_id", &User::typeId)),
      make_table(
          "user_types",
          make_column("id", &UserType::id, autoincrement(), primary_key()),
          make_column("name", &UserType::name,
                      default_value("name_placeholder"))),
      make_table(
          "yaml_settings",
          make_column("id", &YamlSetting::id, autoincrement(), primary_key()),
          make_column("key", &YamlSetting::key),
          make_column("template_string", &YamlSetting::template_string)));
}

using Storage = decltype(initStorage(""));

extern Storage storage;

class Orm
{
public:
    Orm();

    static int yamlSaveSetting(std::string key, std::string value);
    static std::string yamlGetValue(std::string key);

};

#endif // ORM_H
