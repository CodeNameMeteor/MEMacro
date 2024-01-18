cmake_minimum_required(VERSION 3.12.0)
project(RTNPMacro VERSION 2.0.0 LANGUAGES CXX)

add_executable(RTNPMacro 
    main.cpp
    ini.h
    ini.cpp
)

target_compile_features(RTNPMacro PRIVATE cxx_std_17)

if(MSVC)
    target_compile_definitions(RTNPMacro PRIVATE _CRT_SECURE_NO_WARNINGS)
endif()

target_link_libraries(RTNPMacro PRIVATE winmm)

install(TARGETS RTNPMacro
    RUNTIME DESTINATION .
)

install(FILES RTNPMacro.ini
    DESTINATION .
)
