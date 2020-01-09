
/* Structures to be used in the program*/

/* Heap - Priority Queue */
typedef struct heap{
    int size;
    void *data[257];
}HEAP;

/* Hash Table - to store the bits*/
typedef struct HASH hash;
struct HASH{
    void *table[256];
};

/* Huffman Tree */
typedef struct tree TREE;
struct tree{
    int frequency;
    unsigned char c;
    tree *left;
    tree *right;
};
