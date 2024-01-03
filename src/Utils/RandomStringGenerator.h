#ifndef PROCESSSIMULATION_RANDOMSTRINGGENERATOR_H
#define PROCESSSIMULATION_RANDOMSTRINGGENERATOR_H

#include <string>

class RandomStringGenerator {
public:
    /**
    * @brief Function for generating random string
    * @param length Length of the string
    * @return Return random string
    */
    static std::string GenerateRandomString(unsigned int length);
};


#endif //PROCESSSIMULATION_RANDOMSTRINGGENERATOR_H
