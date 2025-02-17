#ifndef TYPES_H
#define TYPES_H

#include <vector>
#include <utility>
#include <iostream>
#include <map>
#include <cassert>

typedef std::vector<double> Times;
typedef std::vector<std::pair<double, double>> Coordinates;
typedef std::pair<double, double> Coordinate;
typedef std::vector<double> Elevation;
typedef std::vector<double> Distances;


struct Result {
    int fastest_distance;
    double velocity_found;
    int start_index;
    int end_index;
};

typedef std::vector<Result> Results;

// append vector v2 to vector v1
std::vector<double> operator+(std::vector<double>& v1, const std::vector<double>& v2);

// append a vector of coordinates c2 to another vector of coordinates c1
Coordinates operator+(Coordinates& c1, const Coordinates& c2);

struct Section {
    int start_index = 0;
    int end_index = 0;
    double distance = 0.0;   // in meter
    int duration = 0.0;     // time in seconds
    double velocity = 0.0;   // in meter per seconds
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
    double start_elevation = 100.001;
    double end_elevation = 100.001;
};

// append two segments
Segment operator+(Segment &seg1, Segment &seg2);

void print_segment(Segment const &segment, const bool debug=true);

void print_results(Results const &results, const bool debug=true);

#endif
