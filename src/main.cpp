#include <iostream>

#include "../include/Date.h"

int main() {
    std::cout << "Hello World!" << "\n";

    Date myDate(2020, 1, 1);
    std::cout << "mydate day: " << myDate.getDay() << std::endl;
    return 0;
}
