#include "../include/gem_finder.h"


void find_gems(const Segment& seg, const std::vector<int>& fastest) {
    print_segment(seg);
    std::cout << "size of times: " << seg.times.size() << 
        ", size of ele: " << seg.elevation.size() << 
        ", size of coor: " << seg.coordinates.size() << std::endl;
    if (!((seg.coordinates.size() == seg.times.size()) && (seg.times.size() == seg.elevation.size()))) {
        throw std::length_error("Size of input data vectors needs to be equal.");
    }

    
}


Distances get_vector_of_distances(const Coordinates& coordinates) {
    Distances distances = {0.0};
    float distance;
    for (int i = 0; i < coordinates.size() - 1; i++) {
        distance = calculate_distance(coordinates[i], coordinates[i+1]);
        distances.push_back(distance);
    }
    assert(coordinates.size() == distances.size());
    return distances;
}
