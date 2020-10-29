# samples/linklistdemo
include_directories(${ADSALib_SOURCE_DIR}/Algolib/include)
link_directories(${ADSALib_SOURCE_DIR}/Algolib/src)
add_executable(QueueDemo1 main.cpp)
target_link_libraries(QueueDemo1 INTERFACE Algolib)