#ifndef GEO_H
#define GEO_H

#include <utility>
#include <math.h>

#include "types.h"


#define PI 3.141592653589793

double to_rad(double degree);

double calculate_distance(Coordinate const &coor1, Coordinate const &coor2);

#endif
