#include <iostream>

#include "../include/generator.h"
#include "../include/geo.h"
#include "../include/utils.h"


int main() {
    std::cout << "Hello World!" << "\n";

    Generator gen;
    auto myVec = gen.get_coordinates();
    print_vector(myVec);

    std::string mytime = gen.get_start_time_string();
    std::cout << "mytime: " << mytime << std::endl;

    std::pair<double, double> coor1 = {48.0, 8.0};
    std::pair<double, double> coor2 = {48.0, 8.0000134};
    double distance = calculate_distance(coor1, coor2);
    std::cout << "my distance: " << distance << std::endl;

    return 0;
}
