#ifndef PROCESSSIMULATION_SJFMANAGER_H
#define PROCESSSIMULATION_SJFMANAGER_H

#include <vector>
#include "../ProcessGenerator/ProcessStruct.h"

class SJFManager {
public:
    static std::vector<Process> CreateSimulation(unsigned int numProcesses);
};


#endif //PROCESSSIMULATION_SJFMANAGER_H
