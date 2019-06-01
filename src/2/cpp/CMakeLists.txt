add_library( lib2cpp 
    ${PROJECT_SOURCE_DIR}/src/2/cpp/serial_.hpp ${PROJECT_SOURCE_DIR}/src/2/cpp/serial_.cpp 
    ${PROJECT_SOURCE_DIR}/src/2/cpp/std_.hpp ${PROJECT_SOURCE_DIR}/src/2/cpp/std_.cpp 
    ${PROJECT_SOURCE_DIR}/src/2/cpp/tbb_.hpp ${PROJECT_SOURCE_DIR}/src/2/cpp/tbb_.cpp )
target_link_libraries(lib2cpp -lpthread -ltbb)