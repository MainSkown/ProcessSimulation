#ifndef PROCESSSIMULATION_CONFIG_H
#define PROCESSSIMULATION_CONFIG_H

#include <exception>

#define CONFIG_PATH "./config.cfg"
#define DEFAULT_RANGE_BEGIN 1
#define DEFAULT_RANGE_END 100
#define DEFAULT_ADDING_CHANCE 20
#define DEFAULT_ADDING_CHANCE_RANGE 100

#define RANGE_BEGIN_NAME "time_range_begin"
#define RANGE_END_NAME "time_range_end"
#define ADDING_NAME "adding_chance"
#define ADDING_RANGE_NAME "adding_chance_range"

class InvalidConfigNameException : public std::exception{};
class WrongConfigValueException : public std::exception{};

struct ConfigStruct{
    unsigned int timeRangeBegin;
    unsigned int timeRangeEnd;
    short addingChance;
    int addingChanceRange;
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
