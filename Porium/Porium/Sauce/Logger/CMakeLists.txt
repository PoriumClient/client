set(files "${CMAKE_CURRENT_LIST_DIR}/Logger.cpp")

target_sources(PoriumClient PRIVATE ${files})
target_include_directories(PoriumClient PRIVATE ".")