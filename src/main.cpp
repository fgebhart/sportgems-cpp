#include <iostream>
#include <time.h>

#include "../include/generator.h"
#include "../include/geo.h"
#include "../include/parser.h"
#include "../include/gem_finder.h"
#include "../include/types.h"


bool is_in_vector(const std::string& lookup_string, const std::vector<std::string>& input_vec) {
    if (std::count(input_vec.begin(), input_vec.end(), lookup_string))
        return true;
    else
        return false;
}

int main(int argc, char* argv[]) {
    std::vector<std::string> args(argv, argv+argc);

    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " GPX-FILE" << std::endl;
        return 1;
    }

    if (is_in_vector("--help", args)) {
        std::cout << "printing help here" << std::endl;
        return 0;
    }
    
    // Greetings
    std::string path_to_gpx = argv[1];
    std::cout << "Hi 👋 from " << argv[0] << "! Will search for 💎 in " << path_to_gpx << std::endl;

    // XML parser
    XMLParser xml_parser(path_to_gpx);
    Segment track = xml_parser.parse_file();

    // generate testing track
    // Segment track = generate_track({100, 100, 100}, {1.0, 1.5, 1.0});

    // find gems in track
    Results results;
    results = find_gems(track);
    if (!results.empty()) {
        print_results(results);
    }
    
    return 0;
}
