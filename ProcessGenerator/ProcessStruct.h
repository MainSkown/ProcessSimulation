#ifndef PROCESSSIMULATION_PROCESSSTRUCT_H
#define PROCESSSIMULATION_PROCESSSTRUCT_H

#include "../Config/Config.h"
#include <random>
#include <iostream>

struct Process {
    unsigned long birthTime;
    unsigned long startedTime;
    unsigned long endOfProcess;
    unsigned int computationTime;

    Process(unsigned long birthTime) : birthTime(birthTime) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distr(Config::getConfig().timeRangeBegin, Config::getConfig().timeRangeEnd);

        this->computationTime = distr(gen);
    }

    friend std::ostream& operator<<(std::ostream& o, Process& p){
        return o << p.birthTime << ';'<< p.startedTime << ';'<< p.endOfProcess << ';'<< p.computationTime;
    }
};

#endif //PROCESSSIMULATION_PROCESSSTRUCT_H
