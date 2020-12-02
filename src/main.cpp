#include <iostream>

#include "../include/generator.h"
#include "../include/geo.h"


int main() {
    std::cout << "Hello World!" << "\n";

    Generator gen(5, 2.0);
    gen.generate_track();
    gen.print_track();

    std::pair<double, double> coor1 = {48.0, 8.0};
    std::pair<double, double> coor2 = {48.0, 8.0000134};
    double distance = calculate_distance(coor1, coor2);
    std::cout << "my distance: " << distance << std::endl;

    return 0;
}
