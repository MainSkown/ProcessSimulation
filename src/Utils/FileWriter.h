#ifndef PROCESSSIMULATION_FILEWRITER_H
#define PROCESSSIMULATION_FILEWRITER_H

#include <fstream>
#include <vector>
#include "../ProcessGenerator/ProcessStruct.h"
#include <sys/types.h>
#include <sys/stat.h>
#include "../ProcessGenerator/PageStruct.h"

class FileWriter{
public:
    /**
     * @brief Function for saving processes to file
     * @param path Path to file
     * @param processes Vector of processes
     */
    static void SaveProcessesToFile(const char* path, const std::vector<Process>& processes){
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

    /**
     * @brief Function for saving page algorithm results to file
     * @param path Path to file
     * @param results Vector of page algorithm results
     */
    static void SavePageAlgorithmResultsToFile(const char* path, const std::vector<PageAlgorithmResult> results){
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
        file << "Page faults;Page hits;Number of pages;Page hits ratio;Page faults ratio;Average lifetime" << std::endl;

        // Saving data
        for(auto result : results){
            file << result;
        }

        file.close();
    }
};

#endif //PROCESSSIMULATION_FILEWRITER_H
