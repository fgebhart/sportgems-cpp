#include <iostream>
#include <time.h>

#include "../include/generator.h"
#include "../include/geo.h"
#include "../include/parser.h"
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

    // Generate entire Track consisting of multiple segments
    Segment track = generate_track({10, 10, 10}, {1.0, 5.0, 10.0});
    print_segment(track);

    return 0;
}
