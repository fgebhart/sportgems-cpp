#include "../include/gem_finder.h"


std::vector<Result> find_gems(Segment& seg, std::vector<int> fastest_distance) {
    if (!((seg.coordinates.size() == seg.times.size()) && (seg.times.size() == seg.elevation.size()))) {
        throw std::length_error("Size of input data vectors needs to be equal.");
    }
    int minimal_fastest = *std::min_element(fastest_distance.begin(), fastest_distance.end());
    seg.distances = get_vector_of_distances(seg.coordinates);
    float total_distance = seg.distances.back();
    std::vector<Result> results;
    print_segment(seg);
    remove_fastest_distance_if_longer_than_total_distance(fastest_distance, total_distance);
    if (fastest_distance.size() > 0) {
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
            results.push_back(search_section(seg, fastest_distance[i]));
        }
    } else {
        std::cout << "Input track has a total distance of " << total_distance
        << "km, which is less than the minimal fastest_distance item of " << minimal_fastest / 1000
        << "km, thus cannot find any 💎 in this track." << std::endl;
    }
    return results;
}

void remove_fastest_distance_if_longer_than_total_distance(std::vector<int> & fastest_distance, float total_distance) {
    // check which fastest_distance is larger than the total distance and remove if so
    for (auto it=fastest_distance.begin(); it!=fastest_distance.end();) {
        if (*it > total_distance) {
            fastest_distance.erase(it);
        } else { ++it; }
    }
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

Result search_section(const Segment& seg, const int fastest_distance) {
    Section fastest_sec, curr_sec;
    std::cout << "searching for fastest: " << fastest_distance / 1000 << "km" << std::endl;
    Result result;
    result.fastest_distance = fastest_distance;
    // main loop to scan through track and compare sections
    while (curr_sec.end_index < seg.length) {
        // build up section to have length of fastest_distance
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
        // std::cout << "start: " << curr_sec.start_index
        //             << ", end: " << curr_sec.end_index
        //             << ", distance: " << curr_sec.distance
        //             << ", duration: " << curr_sec.duration
        //             << ", velocity: "<< curr_sec.velocity
        //             << ", fastest sec vel: " << fastest_sec.velocity << std::endl;
        std::this_thread::sleep_for(std::chrono::microseconds(100));
    }

    result.start_index = fastest_sec.start_index;
    result.end_index = fastest_sec.end_index;
    result.velocity_found = fastest_sec.velocity;
    return result;    // TODO implement this function
}
