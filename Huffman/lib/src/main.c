#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "compress.h"
#include "decompress.h"

int main()
{
    open_files("../../../Testes/DECLARACAO.pdf");
   decompress("../../../Testes/DECLARACAO.pdf.huff", "../../../Testes/DECLARACAO.pdf");

    return 0;
}