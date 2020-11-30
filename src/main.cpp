#include <iostream>

#include "../include/generator.h"
#include "../include/utils.h"


int main() {
    std::cout << "Hello World!" << "\n";

    Generator gen(3);
    auto myVec = gen.get_coordinates();

    print_vector(myVec);

    return 0;
}
