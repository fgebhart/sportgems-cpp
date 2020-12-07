#ifndef TYPES_H
#define TYPES_H

#include <vector>
#include <utility>
#include <iostream>
#include <map>
#include <cassert>

typedef std::vector<int> Times;
typedef std::vector<std::pair<float, float>> Coordinates;
typedef std::pair<float, float> Coordinate;
typedef std::vector<float> Elevation;
typedef std::vector<float> Distances;


Times operator+(Times& v1, const Times& v2);
Elevation operator+(Elevation& e1, const Elevation& e2);
Coordinates operator+(Coordinates& c1, const Coordinates& c2);

struct Result {
    int fastest_distance;
    float velocity_found;
    int start_index;
    int end_index;
};

struct Section {
    int start_index = 0;
    int end_index = 0;
    float distance = 0.0;   // in meter
    int duration = 0;       // time in seconds
    float velocity = 0.0;   // in meter per seconds
};

struct Segment {
    // constructor
    Segment();
    Segment(Coordinates c, Times t, Elevation e);

    // attributes
    Times times;
    Coordinates coordinates;
    Elevation elevation;
    Distances distances;
    int length;
    int start_time = 1;
    int end_time = 1;
    Coordinate start_coordinate = {40.001, 10.0};
    Coordinate end_coordinate = {40.001, 10.0};
    float start_elevation = 100.001;
    float end_elevation = 100.001;
};

Segment operator+(Segment &seg1, Segment &seg2);

void print_segment(Segment const &segment);

void print_results(std::vector<Result> const &results);

#endif
