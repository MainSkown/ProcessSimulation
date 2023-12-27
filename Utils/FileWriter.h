#ifndef PROCESSSIMULATION_FILEWRITER_H
#define PROCESSSIMULATION_FILEWRITER_H

#include <fstream>
#include <vector>
#include "../ProcessGenerator/ProcessStruct.h"

class FileWriter{
public:
    static void SaveToFile(const char* path, const std::vector<Process>& processes){
        std::ofstream file;
        file.open(path, std::ios::out | std::ios::trunc);

        if(!file.is_open()){
            std::cout << "Error opening file" << std::endl;
            return;
        }

        // Naming columns
        file << "Czas powstania;Czas rozpoczęcia;Czas obliczeń;Czas zakończenia" << std::endl;

        // Saving data
        for(auto process : processes){
            file << process.birthTime << ";" << process.startedTime << ";" << process.computationTime << ";" << process.endOfProcess << std::endl;
        }

        file.close();
    }
};

#endif //PROCESSSIMULATION_FILEWRITER_H
