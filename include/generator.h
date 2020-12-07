#ifndef GENERATOR_H
#define GENERATOR_H

#include <vector>
#include <string>

#include "types.h"


class Generator {
    public:
        Segment generate_segment(
            int length,
            double velocity = 2.0,
            Coordinate start_c = {40.0, 10.0},
            int start_t = 0,
            double start_e = 100.0);
    
    private:
        Coordinate _start_coordinate;
        int _start_time;
        double _start_elevation;
};

Segment generate_track(std::vector<double> length_list, std::vector<double> velocity_list);



#endif
