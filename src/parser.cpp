#include "../include/parser.h"


XMLParser::XMLParser(std::string path_to_file) : _path_to_file(path_to_file) {}

std::string XMLParser::parse_file() {
  int nth_value = 2;
  std::string item;
  std::string value;
  std::ifstream filestream(_path_to_file);
  if (filestream.is_open()) {
    int counter = 1;
    while (std::getline(filestream, item, ' ')) {
      // e.g. get 22nd value of file, which holds the uptime
      if (counter == nth_value) {
        value = item;
      }
      counter += 1;
    }
  }
  return value;
}