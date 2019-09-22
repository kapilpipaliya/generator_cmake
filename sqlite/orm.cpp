#include "orm.h"
#include <iostream>

Storage storage = initStorage("db.sqlite");

Orm::Orm() {
  using namespace sqlite_orm;

  User user{-1,
            "Jonh",
            "Doe",
            664416000,
            std::make_unique<std::string>("url_to_heaven"),
            3};

  storage.sync_schema();

  auto insertedId = storage.insert(user);
  std::cout << "insertedId = " << insertedId << std::endl;  //  insertedId = 8
  user.id = insertedId;

  User secondUser{-1, "Alice", "Inwonder", 831168000, {}, 2};
  insertedId = storage.insert(secondUser);
  secondUser.id = insertedId;

  auto somePlayers =
      storage.get_all<User>(where(lesser_than(length(&User::firstName), 5)));
  std::cout << "players with length(name) < 5 = " << somePlayers.size()
            << std::endl;
  for (auto &player : somePlayers) {
    std::cout << storage.dump(player) << std::endl;
  }
}

int Orm::yamlSaveSetting(std::string key, std::string value) {
  using namespace sqlite_orm;
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
  }
}

std::string Orm::yamlGetValue(std::string key) {
  using namespace sqlite_orm;
  auto yaml = storage.get_all<YamlSetting>(where(c(&YamlSetting::key) == key));
  if (yaml.size() > 0) {
    return yaml.at(0).template_string;
  } else {
    return "";
  }
}
