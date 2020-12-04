#ifndef GENERATOR_H
#define GENERATOR_H

#include <vector>
#include <string>

#include "types.h"


class Generator {
    public:
        // constructor
        Generator(int length, float velocity);

        // getter / setter
        Coordinates get_coordinates();
        Times get_times();

        // other methods
        Track generate_track();
        void print_track();
    
    private:
        int _length;
        float _velocity;
        Coordinates _coordinates;
        Coordinate _start_coordinate;
        Times _times;
        int _start_time;
        Elevation _elevation;
        float _start_elevation;
};

#endif
