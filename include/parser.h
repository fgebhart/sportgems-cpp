#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <fstream>
#include <vector>

class XMLParser {
    public:
        // constructor
        XMLParser(std::string path_to_file);

        // methods
        void parse_file();
        void add_time_to_vector(std::string const &input);
        void add_coordinates_to_vector(std::string const &input);
        void add_elevation_to_vector(std::string const &input);

    private:
        std::string _path_to_file;
        std::vector<std::pair<float, float>> _coordinates;
        std::vector<int> _times;
        std::vector<float> _elevation;
};

#endif
