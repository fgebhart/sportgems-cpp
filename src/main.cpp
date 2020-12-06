#include <iostream>
#include <time.h>

#include "../include/generator.h"
#include "../include/geo.h"
#include "../include/parser.h"
#include "../include/gem_finder.h"
#include "../include/types.h"


int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " GPX-FILE" << std::endl;
        return 1;
    }
    
    // Greetings
    std::string path_to_gpx = argv[1];
    std::cout << "Hi 👋 from " << argv[0] << "! Will search for 💎 in " << path_to_gpx << std::endl;

    // XML parser
    XMLParser xml_parser(path_to_gpx);
    Segment output = xml_parser.parse_file();

    // find gems in track
    find_gems(output);

    return 0;
}
