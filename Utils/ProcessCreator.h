#ifndef PROCESSSIMULATION_PROCESSCREATOR_H
#define PROCESSSIMULATION_PROCESSCREATOR_H

#include <tuple>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>

class ProcessCreator {
public:
    static std::vector<std::pair<int, int>> UserCreateSimulations(const std::string& name = ""){
        std::string input;
        std::cout << "Creating simulation for: " << name << std::endl;
        std::cout << "Configure simulations (number of processes:number of simulations) (separated by space): ";
        getline(std::cin, input);

        std::stringstream sInput(input);


        // Split input by spaces
        std::vector<std::string> values;
        std::string value;
        while (getline(sInput, value, ' ')) {
            values.push_back(value);
        }

        //Split values by ':'
        std::vector<std::pair<int,int>> result;
        for(const auto& val : values){
            std::stringstream sVal(val);
            std::vector<std::string> valPair;
            std::string valPairVal;
            while (getline(sVal, valPairVal, ':')) {
                valPair.push_back(valPairVal);
            }

            result.emplace_back(std::stoi(valPair[0]), std::stoi(valPair[1]));
        }

        return result;
    }};

#endif //PROCESSSIMULATION_PROCESSCREATOR_H
