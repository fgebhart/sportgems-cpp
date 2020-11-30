#include <iostream>

#include "../include/Date.h"
#include "../include/generator.h"

void print_vector(std::vector<std::pair<float, float>> input) {
    std::cout << "{";
    for (int i = 0; i < input.size() ; i++)
    {
        std::cout << "(" << input.at(i).first << ", " << input.at(i).second << ")";
        if (i != input.size() -1 )
        {
            std::cout << ", ";
        }
        
    }
    std::cout << "}" << std::endl;
}

int main() {
    std::cout << "Hello World!" << "\n";

    Date myDate(2020, 1, 1);
    std::cout << "mydate day: " << myDate.getDay() << std::endl;

    Generator gen(3);
    auto myVec = gen.get_coordinates();

    print_vector(myVec);

    return 0;
}
