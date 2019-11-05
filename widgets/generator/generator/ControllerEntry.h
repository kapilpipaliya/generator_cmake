#ifndef _CONTROLLERENTRY_H
#define _CONTROLLERENTRY_H
#include <string>
#include <vector>

#include "./mygenerator.h"

class ControllerEntry : public MyGenerator {
 public:
  ControllerEntry(const std::vector<std::string>& controllers,
                  const std::string& arguments);

  ~ControllerEntry();

  std::string generate(bool eventadd, bool protoadd);

 private:
  std::string _outputPath;
  const std::vector<std::string>& controllers;
  const std::string& arguments;
};
#endif
