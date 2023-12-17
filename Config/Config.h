
#ifndef PROCESSSIMULATION_CONFIG_H
#define PROCESSSIMULATION_CONFIG_H

struct ConfigStruct{
    unsigned int timeRangeBegin;
    unsigned int timeRangeEnd;
};

class Config {
private:
    explicit Config(ConfigStruct cfg): cfg(cfg){}
    static Config& getClass();
    ConfigStruct cfg;
public:
    static void Init();
    static struct ConfigStruct getConfig();

};


#endif //PROCESSSIMULATION_CONFIG_H
