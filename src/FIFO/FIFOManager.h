#ifndef PROCESSSIMULATION_FIFOMANAGER_H
#define PROCESSSIMULATION_FIFOMANAGER_H

#include "../ProcessGenerator/PageStruct.h"

class FIFOManager {
public:
    static PageAlgorithmResult CreateSimulation(std::string reference_string, const std::string& name = "");
};


#endif //PROCESSSIMULATION_FIFOMANAGER_H
