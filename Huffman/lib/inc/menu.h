#ifndef HUFFMAN_MENU_H
#define HUFFMAN_MENU_H

/**
 * Loop do menu do programa
 */
void menu_loop ();

/**
 * Lê o nome do arquivo a ser comprimido e chama a função open_file_compress
 */
void compress_option();

/**
 * Lê o nome do arquivo comprimido e o nome do arquivo descomprimido e chama a função open_file_decompress
 */
void decompress_option();

/**
 * Imprime as opções do menu
 */
void print_menu();
/**
 * Abre o arquivo a ser comprimido e o arquivo em que será escrita a compactação (nome do arquivo de entrada + '.huff')
 *
 * @param *input_name      o nome do arquivo a ser comprimido
 */
void open_files_compress (char *input_name);

/**
 * Abre o arquivo comprimido e o arquivo em que serão escritos os bytes descompactados
 *
 * @param *compressed_name         o nome do arquivo comprimido
 * @param *decompressed_name       o nome do arquivo onde serão escritos os bytes descompactados
 */
void open_files_decompress (char *compressed_name, char *decompressed_name);

#endif //HUFFMAN_MENU_H
