
#ifndef PROCESSSIMULATION_LRUMANAGER_H
#define PROCESSSIMULATION_LRUMANAGER_H

#include "../ProcessGenerator/PageStruct.h"

class LRUManager {
public:
    static PageAlgorithmResult CreateSimulation(std::string reference_string, const std::string& name = "");
};


#endif //PROCESSSIMULATION_LRUMANAGER_H
