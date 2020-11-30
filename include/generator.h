#ifndef GENERATOR_H
#define GENERATOR_H

#include <vector>
#include <utility>

class Generator {
    public:
        Generator(int length);
        std::vector<std::pair<float, float>> get_coordinates();
    private:
        int _length;
};


#endif
