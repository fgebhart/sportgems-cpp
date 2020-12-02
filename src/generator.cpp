#include <iostream>

#include "../include/generator.h"


Generator::Generator(int length, float velocity) : _length(length), _velocity(velocity) {
    _start_coordinate = {40.001, 10.0};
    int y=2020, m=1, d=1;
    tm t = {};
    t.tm_year = y-1900;
    t.tm_mon  = m-1;
    t.tm_mday = d;
    std::mktime(&t);
    _start_time = t;
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
        tm last_time = _times.back();
        AddTime(&last_time, _velocity);
        _times.push_back(last_time);
    }
    
}

std::vector<std::pair<float, float>> Generator::get_coordinates() {
    return _coordinates;
}

std::vector<tm> Generator::get_times() {
    return _times;
}

void AddTime(tm* date, double seconds) {
    if (date == NULL) return;
    date->tm_sec += seconds;
    mktime(date);
}

void Generator::print_track() {
    std::cout << "coordinates    times  " << std::endl;
    // for (int i = 0; i < coordinates.size() ; i++)
    // {
    //     std::cout << "(" << coordinates.at(i).first << ", " << coordinates.at(i).second << ")";
    //     if (i != coordinates.size() -1 )
    //     {
    //         std::cout << ", ";
    //     }
        
    // }
    for (int i = 0; i < _times.size(); i++)
    {
        std::cout << "(" << _coordinates.at(i).first << ", " << _coordinates.at(i).second << ");  " << asctime(&(_times[i]));
    }
}
