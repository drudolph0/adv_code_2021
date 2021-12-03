add_executable(binary_diagnostic
binary_diagnostic.cpp)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/input.txt
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})