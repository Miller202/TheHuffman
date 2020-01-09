
/* Structures to be used in the program*/

/* Heap - Priority Queue */
typedef struct HEAP HEAP;
struct HEAP{
    int size;
    void *data[257];
};

/* Hash Table - to store the bits*/
typedef struct HASH HASH;
struct HASH{
    void *table[256];
};

/* Huffman Tree */
typedef struct TREE TREE;
struct TREE{
    int frequency;
    unsigned char c;
    TREE *left;
    TREE *right;
};
