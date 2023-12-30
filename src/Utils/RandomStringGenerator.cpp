#include "RandomStringGenerator.h"
#include "../Config/Config.h"
#include "random"

std::string RandomStringGenerator::GenerateRandomString(unsigned int length) {
    std::string result;
    result.reserve(length);

    std::random_device rd;
    std::mt19937 gen(rd());

    for(int i = 0; i < length; i++) {
        switch (Config::getConfig().useLetters) {
            case CAPITALIZE:
                if (gen() % 3 == 0) {
                    result += (char) (gen() % 26 + 65);
                    break;
                }
            case TRUE:
                if (gen() % 2 == 0) {
                    result += (char) (gen() % 26 + 97);
                    break;
                }
            case FALSE:
                result += (char) (gen() % 26 + 97);
                break;
        }
    }

    return result;
}
