cmake_minimum_required(VERSION 3.27)
project(ProcessSimulation)

set(CMAKE_CXX_STANDARD 23)

add_executable(ProcessSimulation main.cpp
        FCFS/FCFSManager.cpp
        FCFS/FCFSManager.h
        ProcessGenerator/ProcessStruct.h
        Config/Config.h
        Config/Config.cpp
        SJF/SJFManager.cpp
        SJF/SJFManager.h
        Utils/ProgressBar.h
        Utils/FileWriter.h)
