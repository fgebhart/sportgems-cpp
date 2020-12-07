#include "../include/parser.h"


XMLParser::XMLParser(std::string path_to_file) : _path_to_file(path_to_file) {}

// convert utc time string to an int timestamp (number of seconds since posix epoch)
int get_epoch_ime(const std::wstring &date_time)
{
    static const std::wstring dateTimeFormat{ L"%Y-%m-%dT%H:%M:%SZ" };
    std::wistringstream ss{ date_time };
    std::tm dt;
    ss >> std::get_time(&dt, dateTimeFormat.c_str());
    return std::mktime(&dt);
}

template <typename Out>
void split(std::string const &s, char delim, Out result) {
    std::istringstream iss(s);
    std::string item;
    while (std::getline(iss, item, delim)) {
        *result++ = item;
    }
}

std::vector<std::string> split(std::string const &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, std::back_inserter(elems));
    return elems;
}

std::string remove_substring(std::string main_string, std::string const &to_remove) {
    // Search for the substring in string
    size_t pos = main_string.find(to_remove);
    if (pos != std::string::npos)
    {
        // If found then erase it from string
        main_string.erase(pos, to_remove.length());
    }
    return main_string;
}

std::string remove_quotes(std::string main_string) {
    main_string = remove_substring(main_string, "\"");
    main_string = remove_substring(main_string, "\"");
    return main_string;
}

bool string_starts_with(std::string const &main_string, std::string const starting) {
    if (main_string.rfind(starting, 0) == 0) {
        return true;
    } else
    {
        return false;
    }
    
}

Segment XMLParser::parse_file() {
    bool in_track_segment;
    std::string token;
    std::ifstream filestream(_path_to_file);
    if (filestream.is_open()) {
        while (std::getline(filestream, token, '<')) {
            if (token.rfind("trkseg>", 0) == 0) {
                in_track_segment = true;
            }
            if (in_track_segment) {
                if (string_starts_with(token, "trkpt")) {
                    add_coordinates_to_vector(token);
                } else if (string_starts_with(token, "time>")) {
                    add_time_to_vector(token);
                } else if (string_starts_with(token, "ele>")) {
                    add_elevation_to_vector(token);
                }
            }
        }
        assert(_times.size() == _elevation.size());
        assert(_times.size() == _coordinates.size());
    }
    Segment track(_coordinates, _times, _elevation);
    return track;
}

void XMLParser::add_time_to_vector(std::string const &input) {
    std::wstring time = std::wstring_convert<std::codecvt_utf8<wchar_t>>().from_bytes(remove_substring(input, "time>"));
    _times.push_back(get_epoch_ime(time));
}

void XMLParser::add_coordinates_to_vector(std::string const &input) {
    std::vector<std::string> lat_and_lon = split(input, ' ');
    Coordinate coordinate;
    for (int i = 0; i < lat_and_lon.size() ; i++) {
        double lat, lon = 0;
        if (string_starts_with(lat_and_lon[i], "lat")) {
            std::string s = remove_substring(remove_substring(lat_and_lon[i], "lat="), ">");
            lat = ::atof(remove_quotes(s).c_str());
        } else if (string_starts_with(lat_and_lon[i], "lon")) {
            std::string s = remove_substring(remove_substring(lat_and_lon[i], "lon="), ">");
            lon = ::atof(remove_quotes(s).c_str());
        } else { 
            // neither lat nor lon found in string - do nothing
        }
        if (lat != 0 && lon != 0)   // bot lat and long were found
        {
            coordinate = {lat, lon};
            _coordinates.push_back(coordinate);
        }
    }
}

void XMLParser::add_elevation_to_vector(std::string const &input) {
    double elevation = ::atof(remove_substring(input, "ele>").c_str());
    _elevation.push_back(elevation);
}
