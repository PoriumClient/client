set(files "${CMAKE_CURRENT_LIST_DIR}/Hooks.cpp")

target_sources(PoriumClient PRIVATE Hooks.cpp)
target_include_directories(PoriumClient PRIVATE Hooks.h)