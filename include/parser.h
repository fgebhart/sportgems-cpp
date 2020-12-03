#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <fstream>


class XMLParser {
    public:
        // constructor
        XMLParser(std::string path_to_file);

        // methods
        std::string parse_file();

    private:
        std::string _path_to_file;
};

#endif
