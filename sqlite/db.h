#ifndef Db_H
#define Db_H

#include <QObject>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlError>
#include <QDateTime>

class Db : public QObject
{
    Q_OBJECT
public:
    explicit Db(QObject *parent = 0);

public:
    bool init();
    bool executeQuery(QString &sql);
    void addUser(QString USERNAME,qint32 adminID);
    void addAdmin(QString UserName,QString PassWd,qint32 createBy);
    void addLog(qint32 USERID);

    bool saveImage45(QString fileName);
    QPixmap getImage();

    qint32 getAdminId(QString UserName,QString PassWd);
    qint32 getUserId(QString UserName);

    QVector<QVariantMap> getAllData();
    QVector<QVariantMap> getALLLog();

private:
    QSqlDatabase database;
    void setTables();
    qint32 getIdByUSERNAME(QString USERNAME);

};

#endif // Db_H
