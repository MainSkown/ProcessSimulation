#include "Config.h"
#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

Config &Config::getClass() {
    static Config config;

    return config;
}

Config::Config() {
    // Open config file
    ifstream config_file;
    config_file.open(CONFIG_PATH, ios::in);

    // If config file does not exist use default values
    if (!config_file.is_open()) {
        cout << "No config file detected, using default values\n";
        return;
    }

    map<string, string> config_map;
    string line;
    while (getline(config_file, line)) {
        // Remove spaces
        line.erase(std::remove_if(line.begin(), line.end(), ::isspace),
                   line.end());
        // Continue if line is a comment
        if (line[0] == '#') continue;

        // Split lines by '=' character
        vector<string> values;
        string value;
        stringstream ssLine(line);
        while (getline(ssLine, value, '=')) {
            values.push_back(value);
        }

        config_map.insert({values[0], values[1].substr(0, values[1].find('#'))});
    }

    config_file.close();

    try {
        // Program config
        this->cfg.floatPrecision = stoi(config_map.at(FLOAT_PRECISION_NAME));
        this->cfg.skipProcesses = config_map.at(SKIP_PROCESS_NAME) == "true";
        this->cfg.skipPageReplacement = config_map.at(SKIP_PAGE_REPLACEMENT_NAME) == "true";
        // Process scheduling algorithm
        this->cfg.processString = config_map.at(PROCESS_STRING_NAME).substr(1, config_map.at(PROCESS_STRING_NAME).length() - 2);
        this->cfg.timeRangeBegin = stoi(config_map.at(RANGE_BEGIN_NAME));
        this->cfg.timeRangeEnd = stoi(config_map.at(RANGE_END_NAME));
        this->cfg.addingChance = stoi(config_map.at(ADDING_NAME));
        this->cfg.addingChanceRange = stoi(config_map.at(ADDING_RANGE_NAME));
        // Page replacement algorithm
        this->cfg.frameSize = stoi(config_map.at(FRAME_SIZE_NAME));
        this->cfg.randomizeString = config_map.at(RANDOMIZE_STRING_NAME) == "true";
        if(this->cfg.randomizeString){
            this->cfg.randomizeLength = stoi(config_map.at(RANDOMIZE_LENGTH_NAME));
            this->cfg.useLetters = useLettersMap.at(config_map.at(USE_LETTERS_NAME));
            this->cfg.simulationsCount = stoi(config_map.at(SIMULATIONS_COUNT_NAME));
        } else {
            // Substring to remove quotes
            this->cfg.referenceString = config_map.at(REFERENCE_STRING_NAME)
                    .substr(1, config_map.at(REFERENCE_STRING_NAME).length() - 2);
        }
    } catch (exception &e) {
        throw InvalidConfigNameException();
    }

    if(this->cfg.timeRangeBegin > this->cfg.timeRangeEnd || this->cfg.addingChance > this->cfg.addingChanceRange){
        throw WrongConfigValueException();
    }
    if(this->cfg.randomizeString && this->cfg.randomizeLength <= 0){
        throw WrongConfigValueException();
    }
    if(!this->cfg.randomizeString && this->cfg.referenceString.empty()){
        throw EmptyReferenceStringException();
    }
}

ConfigStruct Config::getConfig() {
    return getClass().cfg;
}


