#include <iostream>
#include "src/FCFS/FCFSManager.h"
#include "src/SJF/SJFManager.h"
#include "src/Utils/ProcessCreator.h"
#include "src/Utils/FileWriter.h"
#include "src/FIFO/FIFOManager.h"
#include "src/LRU/LRUManager.h"
#include "src/Utils/RandomStringGenerator.h"
#include "src/Utils/ProgressBar.h"

using namespace std;

#define FILE_PATH_DIRECTORY "./results/"

int main() {
    auto FCFS = ProcessCreator::UserCreateSimulations("FCFS");
    for (auto x: FCFS) {
        for (int i = 0; i < x.second; i++) {
            stringstream ss;
            ss << "FCFS_" << x.first << "_" << i + 1;
            stringstream filepath;
            filepath << FILE_PATH_DIRECTORY;
            filepath << ss.str();
            filepath << ".csv";
            FileWriter::SaveProcessesToFile(filepath.str().c_str(), FCFSManager::CreateSimulation(x.first, ss.str()));
        }
    }

    auto SJF = ProcessCreator::UserCreateSimulations("SJF");
    for (auto x: SJF) {
        for (int i = 0; i < x.second; i++) {
            stringstream ss;
            ss << "SJF_" << x.first << "_" << i + 1;
            stringstream filepath;
            filepath << FILE_PATH_DIRECTORY;
            filepath << ss.str();
            filepath << ".csv";
            FileWriter::SaveProcessesToFile(filepath.str().c_str(), SJFManager::CreateSimulation(x.first, ss.str()));
        }
    }

    vector<PageAlgorithmResult> FIFO;
    vector<PageAlgorithmResult> LRU;

    if (!Config::getConfig().randomizeString) {
        FIFO.emplace_back(FIFOManager::CreateSimulation(Config::getConfig().referenceString, "FIFO_ReferenceString"));
        LRU.emplace_back(LRUManager::CreateSimulation(Config::getConfig().referenceString, "LRU_ReferenceString"));
    } else {
        for (int i = 1; i <= Config::getConfig().simulationsCount; i++) {
            std::string reference_string = RandomStringGenerator::GenerateRandomString(Config::getConfig().randomizeLength);
            stringstream ss;
            ss << "FIFO_" << i + 1;
            FIFO.emplace_back(FIFOManager::CreateSimulation(
                    reference_string, ss.str()));
            ss.str("");
            ss << "LRU_" << i + 1;
            LRU.emplace_back(LRUManager::CreateSimulation(
                    reference_string, ss.str()));

            ProgressBar::PrintBar(i, Config::getConfig().simulationsCount, "Simulating FIFO and LRU");
        }
    }

    FileWriter::SavePageAlgorithmResultsToFile(FILE_PATH_DIRECTORY "FIFO.csv", FIFO);
    FileWriter::SavePageAlgorithmResultsToFile(FILE_PATH_DIRECTORY "LRU.csv", LRU);

    return 0;
}
