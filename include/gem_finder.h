#ifndef GEM_FINDER_H
#define GEM_FINDER_H

#include <cassert>
#include <algorithm>

#include "../include/types.h"
#include "../include/geo.h"

Results find_gems(Segment& seg, std::vector<int> fastest = {1000, 2000, 3000, 5000, 10000, 15000, 20000});

std::pair<int, int> search_corridor(const Segment& seg, const int fastest);

Distances get_vector_of_distances(const Coordinates& coordinates);

std::vector<int> convert_vector_to_meter(const std::vector<int> &input);

#endif
