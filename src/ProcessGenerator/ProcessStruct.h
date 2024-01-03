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

    /**
     * @brief Constructor for Process struct
     * @param birthTime when was the process created
     */
    Process(unsigned long birthTime) : birthTime(birthTime) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distr(Config::getConfig().timeRangeBegin, Config::getConfig().timeRangeEnd);
        // set start time to -1 to know that process hasn't started
        // due to it being an unsigned long, the -1 is converted to the highest possible value of unsigned long
        // it isn't a concern, because even if simulation gets to those numbers, program will stop working
        startedTime = -1;

        this->computationTime = distr(gen);
    }

    friend std::ostream& operator<<(std::ostream& o, Process& p){
        return o << p.birthTime << ';'<< p.startedTime << ';'<< p.endOfProcess << ';'<< p.computationTime;
    }
};

#endif //PROCESSSIMULATION_PROCESSSTRUCT_H
