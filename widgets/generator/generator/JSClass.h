#ifndef _JSCLASS_H
#define _JSCLASS_H

#include <string>
#include <vector>

#include "./mygenerator.h"

class JSClass : public MyGenerator {
 public:
  JSClass(const std::vector<std::string> &controllers,
          const std::string &arguments);

  ~JSClass();

  std::string generate(std::string namespace_, bool commentreq,
                       std::string namespaceres, bool commentres);

 private:
  std::string _outputPath;
  const std::vector<std::string> &controllers;
  const std::string &arguments;

  /*static void createClassFile(std::ofstream &file, const std::string
     &className, const std::string &fileName, const std::string &content,
                              std::string namespacereq, bool commentreq,
                              std::string namespaceres, bool commentres);*/

  static void createRouteFiles(std::ofstream &file,
                               const std::string &className,
                               const std::string &fileName,
                               const std::string &content, long parentno,
                               std::string namespacereq, bool commentreq,
                               std::string namespaceres, bool commentres);
};
#endif
