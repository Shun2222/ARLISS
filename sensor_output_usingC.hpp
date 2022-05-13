//#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <direct.h>
#include <sys/stat.h>

struct log{
    double x;
    double y; //あとで追加
};

class SensorOutputTask{
private:
    const std::vector<log> m_logs; 
public:
    explicit SensorOutputTask(std::vector<log> & logs);
    ~SensorOutputTask();

    //csvfileを出力
    void output();
    //logsを書き込み、出力
    void writelogs(std::ostream & os);
};

void sensorOutput(std::vector<log> & logs);