#include <iostream>
#include <iomanip>
#include <math.h>

#include "../include/geo.h"

double to_rad(double degree) {
    return degree/180 * PI;
}

double calculate_distance(std::pair<double, double> const &coor1, std::pair<double, double> const &coor2) {
    double dist;
    if (coor1 == coor2)
    {
        dist = 0.0;
    } else {
        dist = acos(
            sin(to_rad(coor1.first)) * sin(to_rad(coor2.first)) 
            + cos(to_rad(coor1.first)) * cos(to_rad(coor2.first))
            * cos(to_rad(coor1.second - coor2.second))
            );
        // multiply by earth radius (nominal "zero tide" equatorial) in centimeter
        dist = 6378100 * dist;
    }
    // returns distance in meter
    return dist;
}
