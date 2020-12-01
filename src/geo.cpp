
#include "../include/geo.h"

double to_rad(double degree) {
    return degree/180 * PI;
}

float calculate_distance(std::pair<double, double> const &coor1, std::pair<double, double> const &coor2) {
    float dist;
    dist = sin(to_rad(coor1.first)) * sin(to_rad(coor2.first)) + cos(to_rad(coor1.first)) * cos(to_rad(coor2.first)) * cos(to_rad(coor1.second - coor2.second));
    dist = acos(dist);
    // multiply by earth radius (nominal "zero tide" equatorial ) in meter
    dist = 6378100 * dist;

    // returns distance in meter
    return dist;
}
