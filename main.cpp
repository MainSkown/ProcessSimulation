#include <iostream>
#include "FCFS/FCFSManager.h"

using namespace std;

int main() {
    FCFSManager::CreateSimulation(1000, "Pierwszy proces");
    FCFSManager::CreateSimulation(1000, "Drugi proces");

    return 0;
}
