#include <iostream>

#include "../include/generator.h"


Generator::Generator() {
    _start_coordinate = {40.0, 10.0};
    int y=1980, m=2, d=5;
    tm t = {};
    t.tm_year = y-1900;
    t.tm_mon  = m-1;
    t.tm_mday = d;
    _start_time = t;
    double _velocity = 1.0;
}

void Generator::set_start_coordinate(std::pair<float, float> start_coordinate) {
    _start_coordinate = start_coordinate;
};

void Generator::set_start_time(tm start_time) {
    _start_time = start_time;
};

void Generator::set_velocity(double velocity) {
    _velocity = velocity;
};

std::pair<float, float> const Generator::get_start_coordinate() {
    return _start_coordinate;
};

tm const Generator::get_start_time(){
    return _start_time;
};

double const Generator::get_velocity() {
    return _velocity;
};


std::string const Generator::get_start_time_string() {
    mktime(&_start_time);
    return asctime(&_start_time);
};

void Generator::generate_track(int length) {
    _length = length;
    for (int i = 0; i < _length; i++)
    {
        std::cout << "adding element..." << std::endl;
        
    }
    
}

std::vector<std::pair<float, float>> Generator::get_coordinates() {
    return {{48.123, 9.456}, {49.678, 9.567}};
}