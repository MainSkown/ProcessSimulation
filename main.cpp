#include <iostream>
#include "src/src.h"

using namespace std;

#define FILE_PATH_DIRECTORY "./results/"

int main() {
    if(Config::getConfig().skipProcesses && Config::getConfig().skipPageReplacement) {
        cout << "Nothing to do, exiting..." << endl;
        return 0;
    }
    if(!Config::getConfig().skipProcesses) {
        auto FCFS = ProcessCreator::UserCreateSimulations("FCFS");
        for (auto x: FCFS) {
            for (int i = 0; i < x.second; i++) {
                stringstream ss;
                ss << "FCFS_" << x.first << "_" << i + 1;
                stringstream filepath;
                filepath << FILE_PATH_DIRECTORY;
                filepath << ss.str();
                filepath << ".csv";
                FileWriter::SaveProcessesToFile(filepath.str().c_str(),
                                                FCFSManager::CreateSimulation(x.first, ss.str()));
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
                FileWriter::SaveProcessesToFile(filepath.str().c_str(),
                                                SJFManager::CreateSimulation(x.first, ss.str()));
            }
        }
    }

    if(!Config::getConfig().skipPageReplacement) {
        vector<PageAlgorithmResult> FIFO;
        vector<PageAlgorithmResult> LRU;

        if (!Config::getConfig().randomizeString) {
            FIFO.emplace_back(
                    FIFOManager::CreateSimulation(Config::getConfig().referenceString));
            LRU.emplace_back(LRUManager::CreateSimulation(Config::getConfig().referenceString));
        } else {
            for (int i = 1; i <= Config::getConfig().simulationsCount; i++) {
                std::string reference_string = RandomStringGenerator::GenerateRandomString(
                        Config::getConfig().randomizeLength);

                FIFO.emplace_back(FIFOManager::CreateSimulation(
                        reference_string));

                LRU.emplace_back(LRUManager::CreateSimulation(
                        reference_string ));

                ProgressBar::PrintBar(i, Config::getConfig().simulationsCount, "Simulating FIFO and LRU");
            }
        }

        FileWriter::SavePageAlgorithmResultsToFile(FILE_PATH_DIRECTORY "FIFO.csv", FIFO);
        FileWriter::SavePageAlgorithmResultsToFile(FILE_PATH_DIRECTORY "LRU.csv", LRU);
    }
    return 0;
}
