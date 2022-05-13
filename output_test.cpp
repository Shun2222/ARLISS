#include "sensor_output_usingC.hpp"
#include <iostream>
#include <vector>
#include <direct.h>
#include <sys/stat.h>

int main(){
    struct log a={1,2}, b={3,4};
    std::vector<log> logs = {a, b};
    SensorOutputTask sop(logs);
    sop.output();
    const char *dir = "../logs";
    struct stat statBuf;
    if (stat(dir, &statBuf) == 0)
        std::cout<<"y"<<std::endl;
    else
        std::cout<<"n"<<std::endl;

    return 0;
}