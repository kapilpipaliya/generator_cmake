#ifndef EverythingGenerator_H
#define EverythingGenerator_H

#include <QMainWindow>
#include <QtWidgets>
namespace widgets {
namespace generator {
class EverythingGenerator : public QWidget {
 private:
  void init();
  void initAngelScript();
  void runAllGenerators(const QString &filename);
  std::string read_all(const std::string &filename);
  std::string find_section(const std::string &file_read,
                           const std::string &section_name);
  void removeFirstLastLine(std::string &str);

 public:
  EverythingGenerator(QWidget *parent = nullptr);
  QPlainTextEdit *eventresult;
  QPlainTextEdit *protoresult;
  QPlainTextEdit *serviceresult;
  QPlainTextEdit *jsresult;

  QString filename;
  QString namespacename;
  QString reqProtoname;
  QString respProtoname;
  QString jsfilename;

  QPlainTextEdit *focusEditor;
};
}  // namespace generator
}  // namespace widgets
#endif  // EverythingGenerator_H
