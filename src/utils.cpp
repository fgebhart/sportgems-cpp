#include <iostream>

#include "../include/utils.h"


void print_vector(std::vector<std::pair<float, float>> const &input) {
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