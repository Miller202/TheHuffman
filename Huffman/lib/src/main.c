#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "compress.h"
#include "decompress.h"

int main()
{
//    open_files("../../../Testes/test.txt");
    decompress("../../../Testes/test.txt.huff", "../../../Testes/test2.txt");

    return 0;
}