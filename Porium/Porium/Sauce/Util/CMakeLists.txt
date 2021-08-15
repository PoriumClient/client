set(files "${CMAKE_CURRENT_LIST_DIR}/Utils.cpp")

target_sources(PoriumClient PRIVATE ${files})
target_include_directories(PoriumClient PRIVATE ".")