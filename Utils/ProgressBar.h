#ifndef PROCESSSIMULATION_PROGRESSBAR_H
#define PROCESSSIMULATION_PROGRESSBAR_H

#include <cmath>
#include <iostream>
#include <string>

#define BAR_LENGTH 40

class ProgressBar{
public:
    static void PrintBar(unsigned int point, unsigned int end, const std::string& message = ""){
        double progress = (double)point/(double)end;
        int progressChars = std::floor(BAR_LENGTH * progress);
        int spaces = BAR_LENGTH - progressChars;
        std::cout << message << " ";
        std::cout<<"[";
        for(int i = 0; i < progressChars;i++) std::cout << "#";
        for(int i = 0; i < spaces;i++) std::cout<<" ";
        std::cout << "] ";
        if(point != end) {
            std::cout << point << "/" << end << "\r";
            std::cout.flush();
        } else {
            // A couple tabs to clear the line, it's eye soring but who cares?
            std::cout << "completed                                    \n";
        }
    }
};

#endif //PROCESSSIMULATION_PROGRESSBAR_H
