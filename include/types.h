#ifndef TYPES_H
#define TYPES_H

#include <vector>
#include <utility>
#include <iostream>
#include <map>

typedef std::vector<int> Times;
typedef std::vector<std::pair<float, float>> Coordinates;
typedef std::pair<float, float> Coordinate;
typedef std::vector<float> Elevation;
typedef std::vector<float> Distances;
typedef std::map<int, std::pair<int, int>> Results;

Times operator+(Times& v1, const Times& v2);
Elevation operator+(Elevation& e1, const Elevation& e2);
Coordinates operator+(Coordinates& c1, const Coordinates& c2);
struct Segment {
    // constructor
    Segment();
    Segment(Coordinates c, Times t, Elevation e);

    // attributes
    Times times;
    Coordinates coordinates;
    Elevation elevation;
    Distances distances;
    int start_time = 1;
    int end_time = 1;
    Coordinate start_coordinate = {40.001, 10.0};
    Coordinate end_coordinate = {40.001, 10.0};
    float start_elevation = 100.001;
    float end_elevation = 100.001;
};

Segment operator+(Segment &seg1, Segment &seg2);

void print_segment(Segment const &segment);

void print_results(Results const& res);

#endif
