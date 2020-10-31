# samples/linklistdemo
include_directories(${ADSALib_SOURCE_DIR}/Algolib/include)
link_directories(${ADSALib_SOURCE_DIR}/Algolib/src)
add_executable(SearchDemos main.cpp)
target_link_libraries(SearchDemos INTERFACE Algolib)