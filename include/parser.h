#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <fstream>
#include <locale>
#include <codecvt>
#include <cassert>
#include <iterator>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>

#include "types.h"


int get_epoch_ime(const std::wstring &date_time);

template <typename Out>
void split(std::string const &s, char delim, Out result);

std::vector<std::string> split(std::string const &s, char delim);

std::string remove_substring(std::string main_string, std::string const &to_remove);

std::string remove_quotes(std::string main_string);

bool string_starts_with(std::string const &main_string, std::string const starting);

class XMLParser {
    public:
        // constructor
        XMLParser(std::string path_to_file);

        // methods
        Segment parse_file();

    private:
        void add_time_to_vector(std::string const &input);
        void add_coordinates_to_vector(std::string const &input);
        void add_elevation_to_vector(std::string const &input);
        std::string _path_to_file;
        Coordinates _coordinates;
        Times _times;
        Elevation _elevation;
};

#endif
