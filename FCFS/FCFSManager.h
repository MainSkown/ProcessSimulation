#ifndef PROCESSSIMULATION_FCFSMANAGER_H
#define PROCESSSIMULATION_FCFSMANAGER_H

#include "../ProcessGenerator/ProcessStruct.h"
#include <vector>

class FCFSManager {
public:
    /// @param numProcesses Number of processes to be executed
    /// @return Function returns a vector of executed processes in order of first to last
    std::vector<Process> CreateSimulation(unsigned int numProcesses);
};


#endif //PROCESSSIMULATION_FCFSMANAGER_H
