#ifndef GEO_H
#define GEO_H

#include <utility>

#include <math.h>

#define PI 3.141592653589793

double to_rad(double degree);

float calculate_distance(std::pair<double, double> const &coor1, std::pair<double, double> const &coor2);

#endif
