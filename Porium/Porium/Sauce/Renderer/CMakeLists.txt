set(files "${CMAKE_CURRENT_LIST_DIR}/PoriumRender.cpp")

target_sources(PoriumClient PRIVATE PoriumRenderer.cpp)
target_include_directories(PoriumClient PRIVATE ".")