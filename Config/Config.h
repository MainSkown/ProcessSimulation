#ifndef PROCESSSIMULATION_CONFIG_H
#define PROCESSSIMULATION_CONFIG_H

#include <exception>

#define CONFIG_PATH "./config.cfg"
#define DEFAULT_RANGE_BEGIN 1
#define DEFAULT_RANGE_END 100

#define CONFIG_KEYS ["time_range_begin", "time_range_end"]
#define RANGE_BEGIN_NAME "time_range_begin"
#define RANGE_END_NAME "time_range_end"

class InvalidConfigNameException : public std::exception{};


struct ConfigStruct{
    unsigned int timeRangeBegin;
    unsigned int timeRangeEnd;
};

class Config {
private:
    explicit Config();
    static Config& getClass();
    ConfigStruct cfg;
public:
    static struct ConfigStruct getConfig();

};


#endif //PROCESSSIMULATION_CONFIG_H
