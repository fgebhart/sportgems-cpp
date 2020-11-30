#include "../include/generator.h"


Generator::Generator(int length) {
    _length = length;
}

std::vector<std::pair<float, float>> Generator::get_coordinates() {
    return {{48.123, 9.456}, {49.678, 9.567}};
}