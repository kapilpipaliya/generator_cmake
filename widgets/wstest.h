#ifndef WSTEST_H
#define WSTEST_H

#include <QWidget>
#include <QtWebSockets/QWebSocket>
namespace Ui {
class WsTest;
}

class WsTest : public QWidget
{
    Q_OBJECT

public:
    explicit WsTest(QWidget *parent = nullptr);
    ~WsTest();

Q_SIGNALS:
    void closed();

private Q_SLOTS:
    void onConnected();
    void onTextMessageReceived(QString message);

private:
    Ui::WsTest *ui;
    QWebSocket m_webSocket;
    QUrl m_url;
    bool m_debug;

    QString parseJson();
    void sendJsonMessage();
    void printReply(QString jsondump);
};

#endif // WSTEST_H
