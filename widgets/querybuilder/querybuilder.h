#ifndef QUERYBUILDER_H
#define QUERYBUILDER_H

#include <QWidget>
#include <QtWebSockets/QWebSocket>

class QGroupBox;
class QPlainTextEdit;
class QToolButton;
class QLabel;
class QSpinBox;
class QLineEdit;
namespace widgets{
class QueryBuilder : public QWidget {
  Q_OBJECT

 public:
  explicit QueryBuilder(QWidget *parent = nullptr);
  ~QueryBuilder();

 Q_SIGNALS:
  void closed();

 private Q_SLOTS:
  void onConnected();
  void onTextMessageReceived(QString message);
  void onclosed();
  void reConnect();

 private:
  QWebSocket m_webSocket;
  QUrl m_url;
  bool m_debug;
  void setUrl();
  void connectWs();

  QGroupBox *addTest(int id, int number, QString event_name, QString arg,
                     QString payload, QString result);

  void setGoSaveTemplate(int id, QToolButton *go, QToolButton *save,
                         QToolButton *delete_button, QGroupBox *box,
                         QSpinBox *spinbox, QLineEdit *event_nameEdit,
                         QPlainTextEdit *argEdit, QPlainTextEdit *payload,
                         QPlainTextEdit *templ, std::function<void()> slot);
  QString parseJson(QString text, QLabel *validateJson);
  void sendJsonMessage();
  void printReply(QString jsondump);
  QPlainTextEdit *replyedit;
};
}
#endif  // QUERYBUILDER_H
