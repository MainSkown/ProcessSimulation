#include "RandomStringGenerator.h"
#include "../Config/Config.h"
#include "random"

std::string RandomStringGenerator::GenerateRandomString(unsigned int length) {
    std::string result;
    result.reserve(length);

    static std::random_device rd;
    static std::mt19937 gen(rd());

    for(int i = 0; i < length; i++) {
        switch (Config::getConfig().useLetters) {
            case CAPITALIZE:
                // Use capital letters
                if (gen() % 3 == 0) {
                    result += (char) (gen() % 26 + 65);
                    break;
                }
                // Use small letters
            case TRUE:
                if (gen() % 2 == 0) {
                    result += (char) (gen() % 26 + 97);
                    break;
                }
            case FALSE:
                // Use numbers
                result += (char) (gen() % 10 + 48);
                break;
        }
    }

    return result;
}
