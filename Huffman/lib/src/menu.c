#include <stdio.h>
#include <stdlib.h>

#include "utils.h"
#include "compress.h"
#include "decompress.h"
#include "menu.h"

#define FILE_PATH "../Testes/"

void menu_loop ()
{
    int choice;
    printf("HUFFMAN:\n");
    while (1)
    {
        print_menu();
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                compress_option();
                break;
            case 2:
                decompress_option();
                break;
            case 3:
                printf("Bye!\n");
                exit(0);
                break;
            default:
                printf("Invalid Command. Please, try again.\n");
                break;
        }
        printf("\n\n");
    }
}

void print_menu()
{
    printf("1 - Compress File\n");
    printf("2 - Decompress File\n");
    printf("3 - Exit\n");
}

void compress_option()
{
    char name[1000];
    printf("Enter a file name to compress:\n");
    scanf("%s", name);
    getchar();

    open_files_compress(concat(FILE_PATH, name));
}
void decompress_option()
{
    char comp_name[1000], decomp_name[1000];
    printf("Enter a file name to decompress:\n");
    scanf("%s", comp_name);
    getchar();

    printf("Enter new file name:\n");
    scanf("%s", decomp_name);
    getchar();

    open_files_decompress(concat(FILE_PATH, comp_name), concat(FILE_PATH, decomp_name));
}

void open_files_compress (char *input_name)
{
    FILE *input = fopen(input_name, "rb");
    if (input == NULL)
    {
        printf("File not found. Please, try again.\n");
    }
    else
    {
        char *output_name = concat(input_name, ".huff");
        FILE *output = fopen(output_name, "w+b");
        check_malloc(output);

        compress_file(input, output);

        fclose(output);

        free(input);
        free(output);

        printf("Successful compress!\n");
    }
    
}

void open_files_decompress (char *compressed_name, char *decompressed_name)
{
    FILE *input = fopen(compressed_name, "rb");
    if (input == NULL)
    {
        printf("File not found. Please, try again.\n");
    }
    else
    {
        FILE *output = fopen(decompressed_name, "w+b");
        check_malloc(output);

        decompress(input, output);

        fclose(output);

        free(input);
        free(output);

        printf("Successful decompress!\n");
    }
    

    
}