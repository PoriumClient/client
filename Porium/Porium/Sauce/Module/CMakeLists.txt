set(files "${CMAKE_CURRENT_LIST_DIR}/Module.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/ModuleMgr.cpp")

target_sources(PoriumClient PRIVATE ${files})
target_include_directories(PoriumClient PRIVATE ".")
add_subdirectory(Mods)