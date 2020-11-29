#include <iostream>
#include "rlutil.h"
int main()
{
    for (int i = 0; i < 16; i++)
    {
        rlutil::setColor(i);
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}