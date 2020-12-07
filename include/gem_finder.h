#ifndef GEM_FINDER_H
#define GEM_FINDER_H

#include <cassert>
#include <algorithm>

#include "../include/types.h"
#include "../include/geo.h"

Results find_gems(Segment& seg, std::vector<int> fastest = {1000, 2000, 3000, 5000, 10000, 15000, 20000});

Result search_section(const Segment& seg, const int fastest_distance);

void remove_fastest_distance_if_longer_than_total_distance(std::vector<int> & fastest, float total_distance);

Distances get_vector_of_distances(const Coordinates& coordinates);

std::vector<int> convert_vector_to_meter(const std::vector<int> &input);

#endif
