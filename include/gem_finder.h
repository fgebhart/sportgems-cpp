#ifndef GEM_FINDER_H
#define GEM_FINDER_H

#include <cassert>

#include "../include/types.h"
#include "../include/geo.h"

void find_gems(const Segment& seg, const std::vector<int>& fastest = {1, 2, 3, 5, 10, 15, 20});

Distances get_vector_of_distances(const Coordinates& coordinates);

#endif
