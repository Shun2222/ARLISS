#include "task/sensor_output_usingC.hpp"
//filesystemがc++17以降のため、dirの存在確認にC言語のファイルを使用 (#include <direct.h> #include <sys/stat.h>)

SensorOutputTask::SensorOutputTask(std::vector<log> & logs)
    :m_logs(logs)
{
}

SensorOutputTask::~SensorOutputTask()
{
}

//logsを書き込み、出力
void SensorOutputTask::writelogs(std::ostream & os)
{
    int logsize = m_logs.size();
    for(int i=0; i<logsize; i++)
    {
        os << std::to_string(m_logs[i].x) << ","
        << std::to_string(m_logs[i].y) 
        << std::endl;
    }
}

// 無駄な処理の消去、例外処理は後で
//csvfileの出力
void SensorOutputTask::output()
{
    
    //日時の取得、filenameの設定
    time_t t = time(nullptr);
    const tm* localTime = localtime(&t);
    std::stringstream s;
    s << "sensor_output_";
    s << std::setw(2) << std::setfill('0') << localTime->tm_hour << "_";
    s << std::setw(2) << std::setfill('0') << localTime->tm_min;
    
    try {
        //ファイルの作成
        std::string filename = "../logs/"+s.str()+".csv";
        struct stat statBuf;
        const char *dir = "../logs";
         if (stat(dir, &statBuf) == 0)
        {
            std::cout<<"not mkdir"<<std::endl;
        }else
        {
            _mkdir(dir);
            std::cout<<"mkdir"<<std::endl;
        }
        std::ofstream ofs(filename);
        std::ostream& os=ofs;
        writelogs(os); 
        ofs.close();
    } catch (...) {
        std::cout << "Failed to create sensor output file." << std::endl;
    }
}


void sensorOutput(std::vector<log> & logs)
{
    SensorOutputTask sensor_output(logs);
    sensor_output.output();
}