
enable_testing()
add_test(NAME Hash_Test COMMAND Test_Hash)
add_test(NAME Heap_Test COMMAND Test_Heap)
add_test(NAME Huff_Tree_Test COMMAND Test_Huff_Tree)

include_directories (${CMAKE_SOURCE_DIR}/lib/inc
        ${CMAKE_SOURCE_DIR}/lib/src)

add_executable (Test_Hash test_hash.c)
add_executable (Test_Heap test_heap.c)
add_executable (Test_Huff_Tree test_huff_tree.c)

set_target_properties (Test_Hash Test_Heap Test_Huff_Tree PROPERTIES LINK_FLAGS -Wl,-lcunit)

target_link_libraries (Test_Hash HuffLib CUNIT)
target_link_libraries (Test_Heap HuffLib CUNIT)
target_link_libraries (Test_Huff_Tree HuffLib CUNIT)