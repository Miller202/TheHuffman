
/* Structures to be used in the program*/

/* Heap - Priority Queue */
typedef struct HEAP heap;
struct HEAP{
    int size;
    void *items[257];
};

/* Hash Table - to store the bits*/
typedef struct HASH hash;
struct HASH{
    void *table[256];
};

/* Huffman Tree */
typedef struct TREE tree;
struct TREE{
    int frequency;
    unsigned char c;
    tree *left;
    tree *right;
};
