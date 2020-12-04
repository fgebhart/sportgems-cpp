#include <iostream>
#include <time.h>

#include "../include/generator.h"
#include "../include/geo.h"
#include "../include/parser.h"


int main(int argc, char* argv[]) {
    // Check the number of parameters
    if (argc < 2) {
        // Tell the user how to run the program
        std::cerr << "Usage: " << argv[0] << " GPX-FILE" << std::endl;
        /* "Usage messages" are a conventional way of telling the user
         * how to run a program if they enter the command incorrectly.
         */
        return 1;
    }

    Generator gen(5, 2.0);
    gen.generate_track();
    gen.print_track();

    std::pair<double, double> coor1 = {48.0, 8.0};
    std::pair<double, double> coor2 = {48.0, 8.0000134};
    double distance = calculate_distance(coor1, coor2);
    std::cout << "my distance: " << distance << std::endl;


    std::string path_to_gpx = argv[1];
    // Print the user's name:
    std::cout << "Hi 👋 from " << argv[0] << "! Will parse " << path_to_gpx << std::endl;

    XMLParser xml_parser(path_to_gpx);
    xml_parser.parse_file();
    
    return 0;
}
