#include "../include/types.h"
#include "../include/exceptions.h"


std::vector<double> operator+(std::vector<double>& v1, const std::vector<double>& v2) {
    v1.insert(v1.end(),v2.begin(),v2.end());
    return v1;
};

Coordinates operator+(Coordinates& c1, const Coordinates& c2) {
    c1.insert(c1.end(), c2.begin(), c2.end());
    return c1;
};

Segment::Segment() {};

Segment::Segment(Coordinates c, Times t, Elevation e) : coordinates(c), times(t), elevation(e) {
    length = coordinates.size();
    if (!((elevation.size() == length) && (times.size() == length))) {
        throw InconsistentDataError();
    }
    assert(elevation.size() == length);
    assert(times.size() == length);
    start_time = times.front();
    end_time = times.back();
    start_coordinate = coordinates.front();
    end_coordinate = coordinates.back();
    start_elevation = elevation.front();
    end_elevation = elevation.back();
};

Segment operator+(Segment &seg1, Segment &seg2) {
    Coordinates coordinates_sum = seg1.coordinates + seg2.coordinates;
    Times times_sum = seg1.times + seg2.times;
    Elevation elevation_sum = seg1.elevation + seg2.elevation;
    Segment summed_seg(coordinates_sum, times_sum, elevation_sum);
    return summed_seg;
};

void print_segment(Segment const &segment, const bool debug) {
    if (debug) {
        std::cout << "time coordinates elevation" << std::endl;
        for (int i = 0; i < segment.times.size(); i++) {
            std::cout << segment.times[i] << "    ("
                    << segment.coordinates.at(i).first << "|"
                    << segment.coordinates.at(i).second << ") "
                    << segment.elevation.at(i) << std::endl;
        }
    }
}

void print_results(Results const &results, const bool debug) {
    if (debug) {
        std::cout << "\n" << "========================== Results ==========================" << std::endl;
        std::cout << "Found the following gems: " << std::endl;
        for (int i = 0; i < results.size(); i++) {
        std::cout << "💎 Fastest " << results[i].fastest_distance / 1000
                << "km: start: " << results[i].start_index
                << ", end: " << results[i].end_index
                << ", velocity: " << results[i].velocity_found << " m/s" << std::endl;
        }
    }
}
