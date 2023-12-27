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
        this->cfg.timeRangeBegin = DEFAULT_RANGE_BEGIN;
        this->cfg.timeRangeEnd = DEFAULT_RANGE_END;
        this->cfg.addingChance = DEFAULT_ADDING_CHANCE;
        this->cfg.addingChanceRange = DEFAULT_ADDING_CHANCE_RANGE;
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
        this->cfg.timeRangeBegin = stoi(config_map.at(RANGE_BEGIN_NAME));
        this->cfg.timeRangeEnd = stoi(config_map.at(RANGE_END_NAME));
        this->cfg.addingChance = stoi(config_map.at(ADDING_NAME));
        this->cfg.addingChanceRange = stoi(config_map.at(ADDING_RANGE_NAME));
    } catch (exception &e) {
        throw InvalidConfigNameException();
    }

    if(this->cfg.timeRangeBegin > this->cfg.timeRangeEnd || this->cfg.addingChance > this->cfg.addingChanceRange){
        throw WrongConfigValueException();
    }
}

//void Config
//void Config::Init() {
//    bool working = true;
//    unsigned int begin,end;
//    while(working){
//        cout<<"Compute time range start: ";
//        cin>>begin;
//        if(!cin.fail()) working= false;
//    }
//
//    working=true;
//    while(working){
//        cout<<"Compute time range end: ";
//        cin>>end;
//        if(!cin.fail()) working= false;
//    }
//
//    getClass().cfg.timeRangeBegin = begin;
//    getClass().cfg.timeRangeEnd = end;
//}

ConfigStruct Config::getConfig() {
    return getClass().cfg;
}


