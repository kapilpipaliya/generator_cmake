#include "./db.h"
#include <QFileInfo>
#include <QMessageBox>
#include <QStringList>

Db::Db(QObject *parent) : QObject(parent) { init(); }

bool Db::init() {
  if (QSqlDatabase::contains("qt_sql_default_connection")) {
    database = QSqlDatabase::database("qt_sql_default_connection");
  } else {
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("config.db");

    // set tables
    if (database.open()) {
      qDebug() << "DB opened successfully";
    } else {
      qDebug() << "DB not opened successfully" << database.lastError();
    }
    if (database.tables().isEmpty()) {
      setTables();
      addAdmin("admin", "admin", 0);
    }
  }
  database.close();
  return 1;
}
bool Db::executeQuery(QString &sql) {
  QSqlQuery sql_query;
  sql_query.prepare(sql);
  if (!sql_query.exec()) {
    qDebug() << "Error: Fail to create create_dataTable."
             << sql_query.lastError();
    return false;
  } else {
    qDebug() << "Table created!";
    return true;
  }
}

void Db::setTables() {
  qDebug() << "setting";
  database.open();
  QString create_dataTable =
      "create table data (ID INTEGER PRIMARY KEY   AUTOINCREMENT , USERID "
      "int(32), FP1 blob(2048),FP2 blob(2048),FP3 blob(2048),FV1 "
      "blob(2048),FV2 blob(2048),FV3 blob(2048))";
  QString create_userTable =
      "create table user (USERID INTEGER PRIMARY KEY   AUTOINCREMENT , name "
      "varchar(32),CREATEBY int(32))";
  QString create_adminTable =
      "create table admin (ID INTEGER PRIMARY KEY   AUTOINCREMENT , USERNAME "
      "varchar(32),PASSWD varchar(32), CREATEBY int(32))";
  QString create_logTable =
      "create table log (ID INTEGER PRIMARY KEY   AUTOINCREMENT , USERID "
      "int(32),DATETIME datetime)";
  QString create_imgTable =
      "CREATE TABLE IF NOT EXISTS imgTable ( filename TEXT, imagedata BLOB )";
  executeQuery(create_dataTable);
  executeQuery(create_userTable);
  executeQuery(create_adminTable);
  executeQuery(create_logTable);
  executeQuery(create_imgTable);
  database.close();
}

void Db::addUser(QString USERNAME, qint32 adminID) {
  qDebug() << "addUser" << USERNAME << adminID;
  database.open();
  QString strSql =
      "INSERT INTO user (USERID,name,CREATEBY) VALUES (null,:v1,:v2);";
  QSqlQuery query;
  query.prepare(strSql);
  query.bindValue(":v1", USERNAME);
  query.bindValue(":v2", adminID);
  query.exec();
  database.close();
}

void Db::addAdmin(QString UserName, QString PassWd, qint32 createBy) {
  database.open();

  QString strSql =
      "INSERT INTO admin (ID,USERNAME,PASSWD,CREATEBY)\
            VALUES (null,:v1,:v2,:v3);";

  QSqlQuery query;
  query.prepare(strSql);
  query.bindValue(":v1", UserName);
  query.bindValue(":v2", PassWd);
  query.bindValue(":v3", createBy);

  query.exec();
  database.close();
}

void Db::addLog(qint32 USERID) {
  qDebug() << "addLog";
  database.open();

  QString strSql =
      "INSERT INTO log (ID,USERID,DATETIME)\
            VALUES (null,:v1,:v2);";

  QSqlQuery query;
  query.prepare(strSql);
  query.bindValue(":v1", USERID);
  query.bindValue(":v2", QDateTime::currentDateTime().toString());

  query.exec();

  database.close();
}

qint32 Db::getAdminId(QString UserName, QString PassWd) {
  database.open();

  QString strSql =
      "SELECT ID FROM admin WHERE USERNAME = :v1 AND PASSWD = :v2 ";

  QSqlQuery query;
  query.prepare(strSql);
  query.bindValue(":v1", UserName);
  query.bindValue(":v2", PassWd);

  query.exec();

  query.first();
  int id = -1;
  if (query.value(0).toString().isEmpty()) {
    database.close();
  } else {
    database.close();
    id = query.value(0).toInt();
  }
  database.close();
  return id;
}

qint32 Db::getUserId(QString UserName) {
  database.open();

  QString strSql = "SELECT USERID FROM user WHERE name = :v1 ";

  QSqlQuery query;
  query.prepare(strSql);
  query.bindValue(":v1", UserName);

  query.exec();

  query.first();
  int id = -1;
  if (query.value(0).toString().isEmpty()) {
    database.close();
  } else {
    database.close();
    id = query.value(0).toInt();
  }
  database.close();
  return id;
}

QVector<QVariantMap> Db::getAllData() {
  qDebug() << "getAllData";
  QVector<QVariantMap> allData;
  QVariantMap oneData;
  database.open();

  QString strSql = "SELECT * FROM data ";
  //*********************************
  // * 有毒，不知道取的数据那个是那个
  QSqlQuery query;
  query.prepare(strSql);
  if (!query.exec()) {
    qDebug() << query.lastError();
  } else {
    while (query.next()) {
      int id = query.value(1).toInt();
      QByteArray FP1 = query.value(2).toByteArray();
      QByteArray FP2 = query.value(3).toByteArray();
      QByteArray FP3 = query.value(4).toByteArray();
      QByteArray FV1 = query.value(5).toByteArray();
      QByteArray FV2 = query.value(6).toByteArray();
      QByteArray FV3 = query.value(7).toByteArray();

      oneData.clear();
      oneData.insert("id", id);
      oneData.insert("FP1", FP1);
      oneData.insert("FP2", FP2);
      oneData.insert("FP3", FP3);
      oneData.insert("FV1", FV1);
      oneData.insert("FV2", FV2);
      oneData.insert("FV3", FV3);

      allData.append(oneData);
    }
  }
  database.close();

  qDebug() << "return allData;";
  return allData;
}

QVector<QVariantMap> Db::getALLLog() {
  qDebug() << "getAllLog";
  QVector<QVariantMap> allLog;
  QVariantMap oneLog;
  database.open();

  QString strSql =
      "SELECT user.name,log.DATETIME FROM user,log WHERE "
      "user.USERID=log.USERID";

  //*********************************
  // * 有毒，不知道取的数据那个是那个
  QSqlQuery query;
  query.prepare(strSql);
  if (!query.exec()) {
    qDebug() << query.lastError();
  } else {
    while (query.next()) {
      QString name = query.value(0).toString();
      QString datetime = query.value(1).toString();
      qDebug() << "QDateTime datetime=query.value(1).toDateTime();" << datetime;

      oneLog.clear();
      oneLog.insert("name", name);
      oneLog.insert("datetime", datetime);

      allLog.append(oneLog);
    }
  }
  database.close();
  qDebug() << "return allLog;";
  return allLog;
}

qint32 Db::getIdByUSERNAME(QString USERNAME) {
  QSqlQuery query;
  QString strSql = "select USERID from user where USERNAME=:name";
  query.prepare(strSql);
  query.bindValue(":name", USERNAME);

  qint32 USERID = query.value(0).toInt();
  return USERID;
}

bool Db::saveImage45(QString fileName) {
  if (database.open()) {
    qDebug() << "DB opened successfully";
  } else {
    qDebug() << "DB not opened successfully" << database.lastError();
  }

  QSqlQuery query = QSqlQuery(database);
  query.prepare(
      "CREATE TABLE IF NOT EXISTS imgTable ( filename TEXT, imagedata BLOB )");
  if (!query.exec()) {
    qDebug() << "Error creating image table:\n" << query.lastError();
  } else {
    qDebug() << "imgTable Exist or Created";
  }

  // load an image file directly into a QByteArray
  QFile file(fileName);
  if (!file.open(QIODevice::ReadOnly)) {
    QMessageBox::information(nullptr, tr("Cant Open Image"),
                             tr("Can not Open Image File.\n"));
    database.close();
    return false;
  }
  QByteArray inByteArray = file.readAll();

  QFileInfo file_info(fileName);
  // Insert image bytes into the database
  // Note: make sure to wrap the :placeholder in parenthesis
  query.prepare("DELETE FROM imgTable");
  if (!query.exec()) {
    qDebug() << "Error deleting image table data:\n" << query.lastError();
  } else {
    qDebug() << "Deleting image table data Successfully";
  }
  query.prepare(
      "INSERT INTO imgTable (filename, imagedata) VALUES (:fileName, "
      ":imageData)");
  query.bindValue(":fileName", file_info.fileName());
  query.bindValue(":imageData", inByteArray);
  if (!query.exec()) {
    qDebug() << "Error inserting image into table:\n" << query.lastError();
    QMessageBox::information(nullptr, tr("Error Inserting Logo"),
                             tr("Error Inserting Logo.\n"));
    database.close();
    return false;
  }
  database.close();
  return true;
}

QPixmap Db::getImage() {
  database.open();
  QSqlQuery query = QSqlQuery(database);
  // Get image data back from database
  if (!query.exec("SELECT imagedata from imgTable")) {
    qDebug() << "Error getting image from table:\n" << query.lastError();
    QMessageBox::warning(nullptr, tr("Error getting logo"),
                         tr("Error getting logo"));
    QPixmap p;
    database.close();
    return p;
  }
  if (query.first()) {
    QByteArray outByteArray = query.value(0).toByteArray();
    QPixmap outPixmap = QPixmap();
    outPixmap.loadFromData(outByteArray);
    database.close();
    return outPixmap;
  }
  database.close();
  QPixmap p;
  return p;
}
