cmake_minimum_required(VERSION 3.15)
project(Huffman C)

set(CMAKE_C_STANDARD 11)

include_directories(inc src)

add_executable(Huffman src/main.c
        inc/hash.h src/hash.c
        inc/heap.h src/heap.c
        inc/huff_tree.h src/huff_tree.c
        inc/compress.h src/compress.c
        inc/decompress.h src/decompress.c)
