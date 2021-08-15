link_directories(Porium/CasualLibrary1.0/)

add_library(PoriumClient SHARED Main.cpp)

add_subdirectory(Sauce)

target_include_directories(PoriumClient PRIVATE "${CMAKE_CURRENT_LIST_DIR}/Sauce/Lib/minhook/include/")
target_include_directories(PoriumClient PRIVATE "${CMAKE_CURRENT_LIST_DIR}/Sauce/Lib/CasualLibrary1.0")
target_link_libraries(PoriumClient PRIVATE "${CMAKE_CURRENT_LIST_DIR}/Sauce/Lib/CasualLibrary1.0/CasualLibrary.lib")
target_link_libraries(PoriumClient PRIVATE "${CMAKE_CURRENT_LIST_DIR}/Sauce/Lib/minhook/cmake-build-debug/minhook.x64d.lib")