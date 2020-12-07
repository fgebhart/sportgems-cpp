#ifndef GEM_FINDER_H
#define GEM_FINDER_H

#include <cassert>
#include <algorithm>
#include <set>

#include "../include/types.h"
#include "../include/geo.h"
#include "../include/exceptions.h"


Results find_gems(Segment& seg, bool debug = false, std::vector<int> fastest = {1000, 2000, 3000, 5000, 10000, 15000, 20000});

Result search_section(const Segment& seg, const int fastest_distance, bool debug);

void remove_fastest_distance_if_longer_than_total_distance(std::vector<int> & fastest, double total_distance);

Distances get_vector_of_distances(const Coordinates& coordinates);

std::vector<int> convert_vector_to_meter(const std::vector<int> &input);

int get_number_of_unique_elements(const std::vector<double> &input_vec);

void perform_data_quality_checks(const Segment &seg);

void check_if_data_does_change_at_all(const std::vector<double>& vec);

void verify_vectors_equal_size(const Segment &seg);

void print_section(const std::string &name, const Section &sec, const bool debug);

#endif
