#ifndef PROCESSSIMULATION_CONFIG_H
#define PROCESSSIMULATION_CONFIG_H

#include <exception>
#include <string>
#include <map>

#define CONFIG_PATH "./config.cfg"
// Process scheduling algorithm
#define DEFAULT_RANGE_BEGIN 1
#define DEFAULT_RANGE_END 100
#define DEFAULT_ADDING_CHANCE 20
#define DEFAULT_ADDING_CHANCE_RANGE 100
// Page replacement algorithm
#define DEFAULT_FRAME_SIZE 3
#define DEFAULT_RANDOMIZE_STRING true
#define DEFAULT_RANDOMIZE_LENGTH 30
#define DEFAULT_SIMULATIONS_COUNT 3
#define DEFAULT_USE_LETTERS FALSE
// Program config
#define DEFAULT_FLOAT_PRECISION 3

#define RANGE_BEGIN_NAME "time_range_begin"
#define RANGE_END_NAME "time_range_end"
#define ADDING_NAME "adding_chance"
#define ADDING_RANGE_NAME "adding_chance_range"
#define FRAME_SIZE_NAME "frame_size"
#define REFERENCE_STRING_NAME "reference_string"
#define RANDOMIZE_STRING_NAME "randomize_string"
#define RANDOMIZE_LENGTH_NAME "randomize_string_length"
#define SIMULATIONS_COUNT_NAME "simulations_count"
#define USE_LETTERS_NAME "use_letters"
#define FLOAT_PRECISION_NAME "float_precision"

class InvalidConfigNameException : public std::exception{};
class WrongConfigValueException : public std::exception{};
class EmptyReferenceStringException : public std::exception{};

enum USE_LETTERS{
    TRUE, FALSE, CAPITALIZE,
};

const static std::map<std::string, USE_LETTERS> useLettersMap = {
        {"true", TRUE},
        {"false", FALSE},
        {"capitalize", CAPITALIZE},
};

struct ConfigStruct{
    // Process scheduling algorithm
    unsigned int timeRangeBegin = DEFAULT_RANGE_BEGIN;
    unsigned int timeRangeEnd = DEFAULT_RANGE_END;
    short addingChance = DEFAULT_ADDING_CHANCE;
    int addingChanceRange = DEFAULT_ADDING_CHANCE_RANGE;
    // Page replacement algorithm
    int frameSize = DEFAULT_FRAME_SIZE;
    std::string referenceString;
    bool randomizeString = DEFAULT_RANDOMIZE_STRING;
    int randomizeLength = DEFAULT_RANDOMIZE_LENGTH;
    int simulationsCount = DEFAULT_SIMULATIONS_COUNT;
    USE_LETTERS useLetters = DEFAULT_USE_LETTERS;
    // Program config
    int floatPrecision = DEFAULT_FLOAT_PRECISION;
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
