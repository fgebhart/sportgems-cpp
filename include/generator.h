#ifndef GENERATOR_H
#define GENERATOR_H

#include <vector>
#include <utility>
#include <ctime>
#include <string>

class Generator {
    public:
        // constructor
        Generator(int length, float velocity);

        // getter / setter
        std::vector<std::pair<float, float>> get_coordinates();
        std::vector<tm> get_times();

        // other methods
        void generate_track();
        void print_track();
    
    private:
        int _length;
        float _velocity;
        std::vector<std::pair<float, float>> _coordinates;
        std::pair<float, float> _start_coordinate;
        std::vector<tm> _times;
        tm _start_time;
};

void AddTime(tm* date, double seconds);

#endif
