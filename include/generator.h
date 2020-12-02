#ifndef GENERATOR_H
#define GENERATOR_H

#include <vector>
#include <string>

class Generator {
    public:
        // constructor
        Generator(int length, float velocity);

        // getter / setter
        std::vector<std::pair<float, float>> get_coordinates();
        std::vector<int> get_times();

        // other methods
        void generate_track();
        void print_track();
    
    private:
        int _length;
        float _velocity;
        std::vector<std::pair<float, float>> _coordinates;
        std::pair<float, float> _start_coordinate;
        std::vector<int> _times;
        int _start_time;
};

#endif
