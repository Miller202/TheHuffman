
include_directories (inc src)

add_library(HuffLib inc/hash.h src/hash.c
        inc/heap.h src/heap.c
        inc/utils.h src/utils.c
        inc/huff_tree.h src/huff_tree.c
        inc/compress.h src/compress.c
        inc/decompress.h src/decompress.c
        inc/menu.h src/menu.c)

add_executable(Huffman src/main.c)

target_link_libraries(Huffman HuffLib)