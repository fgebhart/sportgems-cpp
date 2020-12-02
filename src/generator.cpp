#include <iostream>

#include "../include/generator.h"


Generator::Generator(int length, float velocity) : _length(length), _velocity(velocity) {
    _start_coordinate = {40.001, 10.0};
    int y=2020, m=1, d=1;
    _start_time = 1;
}

void Generator::generate_track() {
    _coordinates.push_back(_start_coordinate);
    _times.push_back(_start_time);
    float coor_increment = _velocity / 1000;
    for (int i = 0; i < _length - 1; i++)
    {
        // adding new coordinate
        std::pair<float, float> last_coor = _coordinates.back();
        std::pair<float, float> new_coor = {last_coor.first + coor_increment, last_coor.second};
        _coordinates.push_back(new_coor);

        // adding new time
        int last_time = _times.back();
        _times.push_back(last_time + _velocity);
    }
    
}

std::vector<std::pair<float, float>> Generator::get_coordinates() {
    return _coordinates;
}

std::vector<int> Generator::get_times() {
    return _times;
}

void AddTime(tm* date, double seconds) {
    if (date == NULL) return;
    date->tm_sec += seconds;
    mktime(date);
}

void Generator::print_track() {
    std::cout << "times coordinates" << std::endl;
    for (int i = 0; i < _times.size(); i++)
    {
        std::cout << _times[i] << "     (" << _coordinates.at(i).first << ", " << _coordinates.at(i).second << ")" << std::endl;
    }
}
