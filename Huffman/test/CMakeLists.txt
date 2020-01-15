
enable_testing()
add_test(NAME MyTest COMMAND Test_Hash)

include_directories (${CMAKE_SOURCE_DIR}/lib/inc
        ${CMAKE_SOURCE_DIR}/lib/src)

add_executable (Test_Hash test_hash.c)

set_target_properties (Test_Hash PROPERTIES LINK_FLAGS -Wl,-lcunit)

target_link_libraries (Test_Hash HuffLib CUNIT)