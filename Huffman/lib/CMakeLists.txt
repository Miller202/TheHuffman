
include_directories (inc src)

add_library(HuffLib inc/hash.h src/hash.c
        inc/heap.h src/heap.c
        inc/huff_tree.h src/huff_tree.c
        inc/compress.h src/compress.c
        inc/decompress.h src/decompress.c)

add_executable(Huffman src/main.c)

target_link_libraries(Huffman HuffLib)