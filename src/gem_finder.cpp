#include "../include/gem_finder.h"


Results find_gems(Segment& seg, std::vector<int> fastest) {
    if (!((seg.coordinates.size() == seg.times.size()) && (seg.times.size() == seg.elevation.size()))) {
        throw std::length_error("Size of input data vectors needs to be equal.");
    }
    int minimal_fastest = *std::min_element(fastest.begin(), fastest.end());
    seg.distances = get_vector_of_distances(seg.coordinates);
    float total_distance = seg.distances.back();
    if (minimal_fastest > total_distance) {
        std::cerr << "Input track has a total distance of " << total_distance
        << "km, which is less than the minimal fastest item of " << minimal_fastest / 1000
        << "km, thus cannot find any 💎 in this track." << std::endl;
        throw std::logic_error("Input Error");
    }
    Results results;
    print_segment(seg);
    // check which fastest is larger than the total distance and remove if so
    for (auto it=fastest.begin(); it!=fastest.end();) {
        if (*it > total_distance) {
            fastest.erase(it);
        } else { ++it; }
    }
    if (fastest.size() > 0) {
        std::cout << "Input track is " << total_distance / 1000.0 << "km long. Searching for fastest ";
        for (int i = 0; i < fastest.size(); i++) {
            if (i == fastest.size() - 1) {
                std::cout << fastest[i] / 1000 << "km." << std::endl;
            } else {
                std::cout << fastest[i] / 1000 << "km, ";
            }
        }
        // start search_corridor here (use async for scanning through the track concurrently)
        for (int i = 0; i < fastest.size(); i++) {
            results[fastest[i]] = search_corridor(seg, fastest[i]);
        }
    }
    return results;
}

std::pair<int, int> search_corridor(const Segment& seg, const int fastest) {
    return {23, 67};    // TODO implement this function
}

Distances get_vector_of_distances(const Coordinates& coordinates) {
    float distance = 0.0;
    Distances distances = {distance};
    for (int i = 0; i < coordinates.size() - 1; i++) {
        distance += calculate_distance(coordinates[i], coordinates[i+1]);
        distances.push_back(distance);
    }
    assert(coordinates.size() == distances.size());
    return distances;
}

std::vector<int> convert_vector_to_meter(const std::vector<int> &input_in_km) {
    std::vector<int> output_in_m;
    for (int i = 0; i < input_in_km.size(); i++)
    {
        output_in_m.push_back(input_in_km[i] * 1000);
    }
    assert(input_in_km.size() == output_in_m.size());
    return output_in_m;
}