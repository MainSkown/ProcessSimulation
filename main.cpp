#include <iostream>
#include "Config/Config.h"

using namespace std;

int main() {
    Config::Init();

    cout << Config::getConfig().timeRangeBegin;

    return 0;
}
