#include <iostream>
#include "src/FCFS/FCFSManager.h"
#include "src/SJF/SJFManager.h"
#include "src/Utils/ProcessCreator.h"
#include "src/Utils/FileWriter.h"

using namespace std;

#define FILE_PATH_DIRECTORY "./results/"

int main() {
    auto FCFS = ProcessCreator::UserCreateSimulations("FCFS");
    for(auto x : FCFS){
        for(int i = 0; i < x.second; i++){
            stringstream ss;
            ss << "FCFS_" << x.first << "_" << i + 1;
            stringstream filepath;
            filepath << FILE_PATH_DIRECTORY;
            filepath << ss.str();
            filepath << ".csv";
            FileWriter::SaveToFile(filepath.str().c_str(), FCFSManager::CreateSimulation(x.first, ss.str()));
        }
    }

    auto SJF = ProcessCreator::UserCreateSimulations("SJF");
    for(auto x : SJF){
        for(int i = 0; i < x.second; i++){
            stringstream ss;
            ss << "SJF_" << x.first << "_" << i + 1;
            stringstream filepath;
            filepath << FILE_PATH_DIRECTORY;
            filepath << ss.str();
            filepath << ".csv";
            FileWriter::SaveToFile(filepath.str().c_str(), SJFManager::CreateSimulation(x.first, ss.str()));
        }
    }

    return 0;
}
