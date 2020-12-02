#include <iostream>
#include <time.h>

#include "../include/generator.h"
#include "../include/geo.h"


int main(int argc, char* argv[]) {
    // Check the number of parameters
    // if (argc < 2) {
    //     // Tell the user how to run the program
    //     std::cerr << "Usage: " << argv[0] << " GPX-FILE" << std::endl;
    //     /* "Usage messages" are a conventional way of telling the user
    //      * how to run a program if they enter the command incorrectly.
    //      */
    //     return 1;
    // }
    // Print the user's name:
    std::cout << "Hi 👋 from" << argv[0] << "! Will parse " << argv[1] << " ..." << std::endl;

    char buf[100];
    time_t t;
    struct tm *timeptr,result;

    t = time(NULL);
    timeptr = localtime(&t);
    strftime(buf,sizeof(buf), "%Y-%m-%d %H:%M:%S", timeptr);

    if(strptime(buf, "%Y-%m-%d %H:%M:%S",&result) == NULL)
        printf("\nstrptime failed\n");
    else
    {
        printf("tm_hour:  %d\n",result.tm_hour);
        printf("tm_min:  %d\n",result.tm_min);
        printf("tm_sec:  %d\n",result.tm_sec);
        printf("tm_mon:  %d\n",result.tm_mon);
        printf("tm_mday:  %d\n",result.tm_mday);
        printf("tm_year:  %d\n",result.tm_year);
        printf("tm_yday:  %d\n",result.tm_yday);
        printf("tm_wday:  %d\n",result.tm_wday);
    }

    Generator gen(5, 2.0);
    gen.generate_track();
    gen.print_track();

    std::pair<double, double> coor1 = {48.0, 8.0};
    std::pair<double, double> coor2 = {48.0, 8.0000134};
    double distance = calculate_distance(coor1, coor2);
    std::cout << "my distance: " << distance << std::endl;

    return 0;
}
