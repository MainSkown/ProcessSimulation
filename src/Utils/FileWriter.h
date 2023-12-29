#ifndef PROCESSSIMULATION_FILEWRITER_H
#define PROCESSSIMULATION_FILEWRITER_H

#include <fstream>
#include <vector>
#include "../ProcessGenerator/ProcessStruct.h"
#include <sys/types.h>
#include <sys/stat.h>

class FileWriter{
public:
    static void SaveToFile(const char* path, const std::vector<Process>& processes){
        // Check if results directory exists if not create it
        struct stat info{};
        if(stat("./results", &info) != 0){
            mkdir("./results", 0777);
        }

        std::ofstream file;
        file.open(path, std::ios::out | std::ios::trunc);

        if(!file.is_open()){
            std::cout << "Error opening file" << std::endl;
            return;
        }

        // Naming columns
        file << "Birth time;Starting time;Computation time;Ending time" << std::endl;

        // Saving data
        for(auto process : processes){
            file << process.birthTime << ";" << process.startedTime << ";" << process.computationTime << ";" << process.endOfProcess << std::endl;
        }

        file.close();
    }
};

#endif //PROCESSSIMULATION_FILEWRITER_H
