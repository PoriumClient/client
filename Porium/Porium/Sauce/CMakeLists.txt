set(files "${CMAKE_CURRENT_LIST_DIR}/Porium.cpp{")

target_sources(PoriumClient PRIVATE Porium.cpp)
add_subdirectory(Hooks)
add_subdirectory(Logger)
add_subdirectory(Module)
add_subdirectory(Renderer)
add_subdirectory(SDK)
add_subdirectory(Util)