#include "FCFSManager.h"
#include "../Utils/ProgressBar.h"
/**
 *
 * @param numProcesses how many processes should be simulated
 * @return return the vector of executed process from first to last
 */
std::vector<Process> FCFSManager::CreateSimulation(unsigned int numProcesses, std::string name) {
    unsigned int savedNumProcesses = numProcesses;
    std::vector<Process> executed;
    std::vector<Process> queue;

    std::random_device rd;
    std::mt19937 gen(rd());

    unsigned long ticks = 0;

    // Stop while loop when reaching -0 and emptying the queue (every process has been completed)
    while(numProcesses > 0 || !queue.empty()){
        if(queue.empty() && numProcesses > 0){
            // make sure there is at least one process
            queue.emplace_back(ticks);
            numProcesses--;
        } else if(numProcesses > 0) {
            // randomize adding processes
            std::uniform_int_distribution<> dis(1, 100);
            // the bigger ratio of queue size to numProcesses the lower the chance of adding process
            if(dis(gen) <= Config::getConfig().addingChance ){
                queue.push_back(Process(ticks));
                numProcesses--;
            }
        }

        if(queue[0].startedTime == -1){
            // if first process hasn't started, start it
            queue[0].startedTime = ticks;
        } else if(queue[0].computationTime <= ticks - queue[0].startedTime){
            // check if process is finished
            queue[0].endOfProcess = ticks;
            executed.push_back(queue[0]);
            // delete when finished from queue
            queue.erase(queue.begin());

            ProgressBar::PrintBar(executed.size(), savedNumProcesses, name);
        }

        ticks++;
    }

    return executed;
}