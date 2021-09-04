cmake_minimum_required(VERSION 3.12.0)
project(MEMacro VERSION 2.0.0 LANGUAGES CXX)

add_executable(MEMacro main.cpp)

target_compile_features(MEMacro PRIVATE cxx_std_17)

if(MSVC)
    target_compile_definitions(MEMacro PRIVATE _CRT_SECURE_NO_WARNINGS)
endif()

target_link_libraries(MEMacro PRIVATE winmm)

install(TARGETS MEMacro
    RUNTIME DESTINATION .
)

install(FILES MEMacro.ini
    DESTINATION .
)
