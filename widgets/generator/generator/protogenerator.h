#ifndef PROTOGENERATOR_H
#define PROTOGENERATOR_H

#include <string>
#include <vector>

#include "./mygenerator.h"

class ProtoGenerator : public MyGenerator {
 public:
  ProtoGenerator(const std::vector<std::string>& controllers,
                 const std::string& arguments);

  ~ProtoGenerator();

  std::string generate(std::string suffix, std::string namespace_,
                       bool comment);

 private:
  const std::vector<std::string>& controllers;
  const std::string& arguments;

  void saveProtoFile(const std::string& suffix, std::string namespace_,
                     bool comment);
  std::string protoFile;
  void compileProtoFile(const std::string& suffix, std::string namespace_,
                        bool comment);
};

#endif  // PROTOGENERATOR_H
