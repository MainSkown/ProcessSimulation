#include "Config.h"
#include <iostream>

using namespace std;

Config& Config::getClass() {
    static ConfigStruct cfg{};
    static Config config(cfg);

    return config;
}

void Config::Init() {
    bool working = true;
    unsigned int begin,end;
    while(working){
        cout<<"Compute time range start: ";
        cin>>begin;
        if(!cin.fail()) working= false;
    }

    working=true;
    while(working){
        cout<<"Compute time range end: ";
        cin>>end;
        if(!cin.fail()) working= false;
    }

    getClass().cfg.timeRangeBegin = begin;
    getClass().cfg.timeRangeEnd = end;
}

ConfigStruct Config::getConfig() {
    return getClass().cfg;
}


