#include <iostream>
#include <time.h>

#include "../include/generator.h"
#include "../include/geo.h"
#include "../include/parser.h"
#include "../include/gem_finder.h"
#include "../include/types.h"
#include "../include/exceptions.h"


bool is_in_vector(const std::string& lookup_string, const std::vector<std::string>& input_vec) {
    if (std::count(input_vec.begin(), input_vec.end(), lookup_string))
        return true;
    else
        return false;
}


bool string_ends_with(const std::string &main_string, std::string const &ending) {
    if (main_string.length() >= ending.length()) {
        return (0 == main_string.compare(main_string.length() - ending.length(), ending.length(), ending));
    } else {
        return false;
    }
}


int main(int argc, char* argv[]) {

    std::vector<std::string> args(argv, argv+argc);
    if (is_in_vector("--help", args) | argc < 2) {
        std::cout << "Usage: " << argv[0] << " path/to/file.gpx" << std::endl;
        const char * help = 
        "\n"
        "💎 Sportgems is a CLI for finding the fastest sections in your GPX tracks 💎\n"
        "\n"
        "In the default configuration sportgems will search for the fastest:\n"
        "1km, 2km, 3km, 5km, 10km and 20km\n"
        "\n"
        "Optional arguments are:\n"
        "--debug        Enables debugging and makes output more verbose.\n"
        "--help         Prints this help.\n"
        "--demo         Generates and analyzes a dummy track, no input file needed.";
        std::cout << help << std::endl;
        return 0;
    }

    bool DEBUG = false;
    if (is_in_vector("--debug", args)) { DEBUG = true; }

    Segment track;
    std::string input_file;
    if (is_in_vector("--demo", args)) {     // using dummy generated file
        input_file = "dummy-track.gpx";
        track = generate_track({50, 50, 50}, {1.0, 1.5, 1.0});
    } else {        // parsing gpx 
        input_file = argv[1];
        if (string_ends_with(input_file, ".gpx")) {
            XMLParser xml_parser(input_file);
            track = xml_parser.parse_file();
        } else {
            std::cerr << "Input file needs to be a .gpx file." << std::endl;
            return 1;
        }
        
    }
    std::cout << "Hi 👋 from sportgems! Will search for 💎 in " << input_file << std::endl;

    // find gems in track
    Results results;
    try {
        results = find_gems(track, DEBUG);
        if (!results.empty()) {
            print_results(results);
        }
    } catch(const TooLittleDataError& e) {
        std::cerr << e.what() << '\n';
        return 1;
    } catch(const TrackTooShortError& e) {
        std::cerr << e.what() << '\n';
        return 1;
    } catch(const InconsistentDataError& e) {
        std::cerr << e.what() << '\n';
        return 1;
    }
    
    return 0;
}
