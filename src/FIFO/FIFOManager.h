#ifndef PROCESSSIMULATION_FIFOMANAGER_H
#define PROCESSSIMULATION_FIFOMANAGER_H

#include "../ProcessGenerator/PageStruct.h"

class FIFOManager {
public:
    /**
     * @brief Function for creating simulation of FIFO algorithm
     * @param reference_string Reference string for simulation -> preferably a random string
     * @return Return PageAlgorithmResult struct with results of the simulation
     */
    static PageAlgorithmResult CreateSimulation(std::string reference_string);
};


#endif //PROCESSSIMULATION_FIFOMANAGER_H
