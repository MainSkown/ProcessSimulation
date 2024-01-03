
#ifndef PROCESSSIMULATION_LRUMANAGER_H
#define PROCESSSIMULATION_LRUMANAGER_H

#include "../ProcessGenerator/PageStruct.h"

class LRUManager {
public:
    /**
     * @brief Function for creating simulation of LRU algorithm
     * @param reference_string Reference string for simulation -> preferably a random string
     * @return Return PageAlgorithmResult struct with results of the simulation
     */
    static PageAlgorithmResult CreateSimulation(std::string reference_string);
};


#endif //PROCESSSIMULATION_LRUMANAGER_H
