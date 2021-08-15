set(files "${CMAKE_CURRENT_LIST_DIR}/Fullbright.cpp")

target_sources(PoriumClient PRIVATE ${files})
target_include_directories(PoriumClient PRIVATE ".")