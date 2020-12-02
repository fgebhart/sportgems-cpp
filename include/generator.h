#ifndef GENERATOR_H
#define GENERATOR_H

#include <vector>
#include <utility>
#include <ctime>
#include <string>

class Generator {
    public:
        // constructor
        Generator();

        // getter / setter
        void set_start_coordinate(std::pair<float, float> start_coordinate);
        void set_start_time(tm start_time);
        void set_velocity(double velocity);
        std::pair<float, float> const get_start_coordinate();
        tm const get_start_time();
        std::string const get_start_time_string();
        double const get_velocity();

        // other methods
        void generate_track(int length);
        std::vector<std::pair<float, float>> get_coordinates();
    
    private:
        int _length;
        std::vector<std::pair<float, float>> _coordinates;
        std::pair<float, float> _start_coordinate;
        std::vector<tm> _times;
        tm _start_time;
        double _velocity;
};


#endif
