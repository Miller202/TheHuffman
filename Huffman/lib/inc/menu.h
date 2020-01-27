//
// Created by ikkeg on 26/01/2020.
//

#ifndef HUFFMAN_MENU_H
#define HUFFMAN_MENU_H

/**
*   Loop onde o usu?rio poder? escolher a op??o do programa desejada,
*   de acordo com as 3 op??es: Compress, Decompress, Exit
**/
void menu_loop ();

/**
*   L? o nome do arquivo a ser comprimido e chama a fun??o open_file_compress
**/
void compress_option();

/**
*   L? o nome do arquivo comprimido e o nome do arquivo descomprimido e chama a fun??o open_file_decompress
**/
void decompress_option();

/**
*   Imprime as op??es de menu
**/
void print_menu();
/**
*   Abre o arquivo a ser comprimido e o arquivo em que ser? escrita a compacta??o
*   O nome do arquivo compactado ? o nome do arquivo a ser compactado + a extens?o .huff
*   @param: diret?rio do arquivo a ser comprimido
**/
void open_files_compress (char *input_name);

/**
*   Abre o arquivo comprimido e o arquivo em que ser?o escritos os bytes descompactados
*   @param: nome do arquivo comprimido
*   @param: nome do arquivo onde ser?o escritos os bytes descompactados
**/
void open_files_decompress (char *compressed_name, char *decompressed_name);
#endif //HUFFMAN_MENU_H
