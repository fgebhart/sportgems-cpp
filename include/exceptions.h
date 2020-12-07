#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>

struct DataQualityError : public std::exception {
    const char * what () const throw () {
        return "poor input data quality";
    }
};

#endif
