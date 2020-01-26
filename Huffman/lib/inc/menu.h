//
// Created by ikkeg on 26/01/2020.
//

#ifndef HUFFMAN_MENU_H
#define HUFFMAN_MENU_H

void menu_loop ();
void compress_option();
void decompress_option();
void print_menu();
/**
*   Abre o arquivo a ser comprimido e o arquivo em que ser? escrita a compacta??o
*   @param: diret?rio do arquivo a ser comprimido
*   @param: arquivo onde ser? escrita a compacta??o
**/
void open_files_compress (char *input_name);

void open_files_decompress (char *compressed_name, char *decompressed_name);
#endif //HUFFMAN_MENU_H
