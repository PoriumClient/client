link_directories(Porium/CasualLibrary1.0/)

add_library(PoriumClient SHARED Main.cpp)

add_subdirectory(Sauce)

#target_include_directories(PoriumClient PRIVATE "Porium/CasualLibrary1.0")