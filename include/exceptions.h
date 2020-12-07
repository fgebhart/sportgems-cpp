#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>

struct TooLittleDataError : public std::exception {
    const char * what () const throw () {
        return "TooLittleDataError: Input Track contains too little data for computing properly. Ensure that "
               "both the coordinates and the time tag contain at least two different values.";
    }
};

struct InconsistentDataError : public std::exception {
    const char * what () const throw () {
        return "InconsistentDataError: Input data consists of vectors with different lengths. Ensure that "
               "all vectors have the same length.";
    }
};

struct TrackTooShortError : public std::exception {
    TrackTooShortError(const int &min_fastest_distance, const double &track_distance) : minimal_configured_fastest_distance(min_fastest_distance), total_track_distance(track_distance) {
        msg = "TrackTooShortError: Input track has a total distance of " + std::to_string(total_track_distance / 1000)
            + "km, which is shorter than the minimal configured fastest distance of " + std::to_string(minimal_configured_fastest_distance / 1000)
            + "km, thus cannot find any 💎 in this track.";
    };
    const char * what () const throw () {
        return msg.c_str();
    }
    int minimal_configured_fastest_distance;
    double total_track_distance;
    std::string msg;
};

#endif
