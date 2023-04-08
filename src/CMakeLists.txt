cmake_minimum_required(VERSION 3.23)

add_executable(SearchEngine
        main.cpp
        ConverterJSON.cpp
        EngineExceptions.cpp
        InvertedIndex.cpp
        ${MY_INCLUDE_PATH}/ConverterJSON.h
        ${MY_INCLUDE_PATH}/EngineExceptions.h
        ${MY_INCLUDE_PATH}/InvertedIndex.h
        ${MY_INCLUDE_PATH}/version.h
        )

target_include_directories(SearchEngine PUBLIC ${MY_INCLUDE_PATH})