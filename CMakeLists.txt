cmake_minimum_required(VERSION 3.27)
project(ProcessSimulation)

set(CMAKE_CXX_STANDARD 23)

add_executable(ProcessSimulation main.cpp
        src/FCFS/FCFSManager.cpp
        src/FCFS/FCFSManager.h
        src/ProcessGenerator/ProcessStruct.h
        src/Config/Config.h
        src/Config/Config.cpp
        src/SJF/SJFManager.cpp
        src/SJF/SJFManager.h
        src/Utils/ProgressBar.h
        src/Utils/FileWriter.h
        src/Utils/ProcessCreator.h)
        src/ProcessGenerator/PageStruct.h)
