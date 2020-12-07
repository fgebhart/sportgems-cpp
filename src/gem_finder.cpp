#include "../include/gem_finder.h"


Results find_gems(Segment& seg, bool debug, std::vector<int> fastest_distance) {
    print_segment(seg, debug);

    // compute total distance to simplify the algorithm downstream
    seg.distances = get_vector_of_distances(seg.coordinates);
    double total_distance = seg.distances.back();

    // check input segment data quality
    perform_data_quality_checks(seg);

    // keep minimal fastest distance (for informative error message in case of any failure downstream)
    int minimal_fastest = *std::min_element(fastest_distance.begin(), fastest_distance.end());
    
    // drop all fastest distance which are too long for the given input data segment
    remove_fastest_distance_if_longer_than_total_distance(fastest_distance, total_distance);

    std::vector<Result> results;
    if (fastest_distance.size() > 0) {
        // inform user about which fastest distances are being searched in this track
        std::cout << "Input track is " << total_distance / 1000 << "km long - searching for fastest_distance ";
        for (int i = 0; i < fastest_distance.size(); i++) {
            if (i == fastest_distance.size() - 1) {
                std::cout << fastest_distance[i] / 1000 << "km." << std::endl;
            } else {
                std::cout << fastest_distance[i] / 1000 << "km, ";
            }
        }
        // start search_section here to find the fastest_distance X km section
        // TODO: use async for scanning through the track concurrently
        for (int i = 0; i < fastest_distance.size(); i++) {
            results.push_back(search_section(seg, fastest_distance[i], debug));
        }
    } else {
        throw TrackTooShortError(minimal_fastest, total_distance);
    }
    return results;
}

void remove_fastest_distance_if_longer_than_total_distance(std::vector<int> &fastest_distance, double total_distance) {
    // check which fastest_distance is larger than the total distance and remove if so
    for (auto it=fastest_distance.begin(); it!=fastest_distance.end();) {
        if (*it > total_distance) {
            fastest_distance.erase(it);
        } else { ++it; }
    }
}

Distances get_vector_of_distances(const Coordinates& coordinates) {
    double distance = 0.0;
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

Result search_section(const Segment& seg, const int fastest_distance, bool debug) {
    if (debug) { std::cout << ">>> Searching for fastest " << fastest_distance / 1000 << "km..." << std::endl; }
    Section fastest_sec, curr_sec;
    Result result;
    result.fastest_distance = fastest_distance;
    // main loop to scan through track and compare sections to eventually find the fastest section
    while (curr_sec.end_index < seg.length) {
        // build up section to have length of fastest_distance
        print_section("current", curr_sec, debug);
        if (curr_sec.distance < fastest_distance) {
            curr_sec.end_index += 1;
            curr_sec.distance = seg.distances[curr_sec.end_index] - seg.distances[curr_sec.start_index];
        } else {
            // update section distance, duration and velocity
            curr_sec.distance = seg.distances[curr_sec.end_index] - seg.distances[curr_sec.start_index];
            curr_sec.duration = seg.times[curr_sec.end_index] - seg.times[curr_sec.start_index];
            curr_sec.velocity = curr_sec.distance / curr_sec.duration;
            // set fastest section to current section in case current section is faster
            if (curr_sec.velocity > fastest_sec.velocity) {
                fastest_sec = curr_sec;
            }
            // now move the start index further, end index will also be moved if section gets smaller than fastest_distance
            curr_sec.start_index += 1;
        }
    }
    result.start_index = fastest_sec.start_index;
    result.end_index = fastest_sec.end_index;
    result.velocity_found = fastest_sec.velocity;
    return result;
}

int get_number_of_unique_elements(const std::vector<double> &input_vec) {
    int nr = std::set<double>(input_vec.begin(), input_vec.end()).size();
    return nr;
}

void perform_data_quality_checks(const Segment &seg) {
    verify_vectors_equal_size(seg);
    check_if_data_does_change_at_all(seg.times);
    check_if_data_does_change_at_all(seg.distances);
}

void check_if_data_does_change_at_all(const std::vector<double>& vec) {
    if (get_number_of_unique_elements(vec) < 2) {
        throw TooLittleDataError();
    }
}

void verify_vectors_equal_size(const Segment &seg) {
    if (!((seg.length == seg.times.size()) && (seg.length == seg.elevation.size()) && (seg.length == seg.coordinates.size()))) {
        throw InconsistentDataError();
    }
}

void print_section(const std::string &name, const Section &sec, const bool debug) {
    if (debug) {
        std::cout << name
        << " section: " << sec.start_index << " - "<< sec.end_index
        << ", distance: " << sec.distance
        << ", duration: " << sec.duration
        << ", vel: " << sec.velocity << std::endl;
    }
}