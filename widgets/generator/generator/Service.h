#ifndef _SERVICE_H
#define _SERVICE_H

#include <string>
#include <vector>

#include "./mygenerator.h"

class Service : public MyGenerator {
 public:
  Service(const std::vector<std::string> &controllers,
          const std::string &arguments);

  ~Service();

  std::string generate();

 private:
  const std::vector<std::string> &controllers;
  const std::string &arguments;

  static void createFilterHeaderFile(std::ofstream &file,
                                     const std::string &className,
                                     const std::string &fileName,
                                     const std::string &content);
  static void createSourceFile(std::ofstream &file,
                               const std::string &className,
                               const std::string &fileName,
                               const std::string &content);
};
#endif
