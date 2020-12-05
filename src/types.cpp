#include "../include/types.h"


Times operator+(Times& v1, const Times& v2){
    v1.insert(v1.end(),v2.begin(),v2.end());
    return v1;
};
Elevation operator+(Elevation& e1, const Elevation& e2){
    e1.insert(e1.end(),e2.begin(),e2.end());
    return e1;
};
Coordinates operator+(Coordinates& c1, const Coordinates& c2) {
    c1.insert(c1.end(), c2.begin(), c2.end());
    return c1;
};

Segment::Segment() {};

Segment::Segment(Coordinates c, Times t, Elevation e) : coordinates(c), times(t), elevation(e) {
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
