#include <iostream>
#include <cassert>

#include "../include/generator.h"


Segment Generator::generate_segment(int length, float velocity, Coordinate start_c, int start_t, float start_e) {
    Coordinates _coordinates;
    Times _times;
    Elevation _elevation;
    float coordinates_increment = velocity / 1000;
    float elevation_increment = velocity / 100;
    float times_increment = velocity;
    _start_coordinate = {start_c.first + coordinates_increment, start_c.second};
    _start_time = start_t + times_increment;
    _start_elevation = start_e + elevation_increment;
    _coordinates.push_back(_start_coordinate);
    _times.push_back(_start_time);
    _elevation.push_back(_start_elevation);
    for (int i = 1; i < length; i++) {
        // adding new coordinate
        Coordinate last_coor = _coordinates.back();
        Coordinate new_coor = {last_coor.first + coordinates_increment, last_coor.second};
        _coordinates.push_back(new_coor);

        // adding new time
        int last_time = _times.back();
        _times.push_back(last_time + times_increment);

        // adding new elevation
        float last_elevation = _elevation.back();
        _elevation.push_back(last_elevation + elevation_increment);
    }
    Segment track(_coordinates, _times, _elevation);
    return track;
}

Segment generate_track(std::vector<float> length_list, std::vector<float> velocity_list) {
    assert(length_list.size() == velocity_list.size());
    Segment track;
    Generator gen;
    for (int i = 0; i < velocity_list.size(); i++) {
        Segment seg = gen.generate_segment(length_list.at(i), velocity_list.at(i), track.end_coordinate, track.end_time, track.end_elevation);
        track = track + seg;
    }
    return track;
}

void print_segment(Segment const &segment) {
    std::cout << "time coordinates elevation" << std::endl;
    for (int i = 0; i < segment.times.size(); i++) {
        std::cout << segment.times[i] << "    ("
                  << segment.coordinates.at(i).first << "|"
                  << segment.coordinates.at(i).second << ") "
                  << segment.elevation.at(i) << std::endl;
    }
}
