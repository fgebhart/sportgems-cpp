#ifndef TYPES_H
#define TYPES_H

#include <vector>

typedef std::vector<int> Times;
typedef std::vector<std::pair<float, float>> Coordinates;
typedef std::pair<float, float> Coordinate;
typedef std::vector<float> Elevation;

struct Track
{
    // constructor
    Track(Coordinates c, Times t, Elevation e) : coordinates(c), times(t), elevation(e) {};

    // attributes
    Times times;
    Coordinates coordinates;
    Elevation elevation;
};


#endif
