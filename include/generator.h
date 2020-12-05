#ifndef GENERATOR_H
#define GENERATOR_H

#include <vector>
#include <string>

#include "types.h"


class Generator {
    public:
        Segment generate_segment(
            int length,
            float velocity = 2.0,
            Coordinate start_c = {40.0, 10.0},
            int start_t = 0,
            float start_e = 100.0);
    
    private:
        Coordinate _start_coordinate;
        int _start_time;
        float _start_elevation;
};

Segment generate_track(std::vector<float> length_list, std::vector<float> velocity_list);

void print_segment(Segment const &segment);


#endif
