#include "CUnit/Basic.h"
#include "huff_tree.h"
#include "heap.h"

void create_node_test()
{
    TREE *t = create_node('*', 77, NULL, NULL);

    CU_ASSERT_PTR_NOT_NULL(t);
    CU_ASSERT_EQUAL(t->c, '*');
    CU_ASSERT_EQUAL(t->frequency, 77);
    CU_ASSERT_PTR_NULL(t->left);
    CU_ASSERT_PTR_NULL(t->right);

    t->left = create_node('A', 22, NULL, NULL);

    CU_ASSERT_PTR_NOT_NULL(t->left);
    CU_ASSERT_EQUAL(t->left->c, 'A');
    CU_ASSERT_EQUAL(t->left->frequency, 22);
    CU_ASSERT_PTR_NULL(t->left->left);
    CU_ASSERT_PTR_NULL(t->left->right);

    t->right = create_node('B', 55, NULL, NULL);

    CU_ASSERT_PTR_NOT_NULL(t->right);
    CU_ASSERT_EQUAL(t->right->c, 'B');
    CU_ASSERT_EQUAL(t->right->frequency, 55);
    CU_ASSERT_PTR_NULL(t->right->left);
    CU_ASSERT_PTR_NULL(t->right->right);
}

void is_empty_test()
{
    TREE *t = NULL;

    CU_ASSERT_TRUE(is_empty(t));

    t = create_node('*', 77, NULL, NULL);

    CU_ASSERT_FALSE(is_empty(t));
}

void is_leaf_test()
{
    TREE *t = create_node('*', 77, NULL, NULL);

    CU_ASSERT_TRUE(is_leaf(t));

    t->left = create_node('A', 22, NULL, NULL);

    CU_ASSERT_FALSE(is_leaf(t));
}

void escape_char_test()
{
    TREE *t = create_node('*', 77, NULL, NULL);

    CU_ASSERT_TRUE(is_escape_char(t, '*'));
    CU_ASSERT_FALSE(is_escape_char(t, 'T'));

    t->left = create_node('A', 22, NULL, NULL);

    CU_ASSERT_FALSE(is_escape_char(t, '*'));
}

void tree_size_test()
{
    TREE *t = NULL;
    CU_ASSERT_EQUAL(get_tree_size(t), 0);

    t = create_node('*', 77, NULL, NULL);
    t->left = create_node('A', 22, NULL, NULL);
    t->right = create_node('B', 55, NULL, NULL);
    CU_ASSERT_EQUAL(get_tree_size(t), 3);

    t->left->c = '*';
    CU_ASSERT_EQUAL(get_tree_size(t), 4);

    t->left = NULL;
    CU_ASSERT_EQUAL(get_tree_size(t), 2);

    t->right = NULL;
    t->c = 'C';
    CU_ASSERT_EQUAL(get_tree_size(t), 1);

    t = NULL;
    CU_ASSERT_EQUAL(get_tree_size(t), 0);
}

HEAP* get_aux_heap()
{
    HEAP *h = create_heap();

    enqueue(h, 6, create_node('A', 6, NULL, NULL));
    enqueue(h, 5, create_node('B', 5, NULL, NULL));
    enqueue(h, 4, create_node('C', 4, NULL, NULL));
    enqueue(h, 3, create_node('D', 3, NULL, NULL));
    enqueue(h, 2, create_node('E', 2, NULL, NULL));
    enqueue(h, 1, create_node('F', 1, NULL, NULL));

    return h;
}
void create_huffman_tree_test()
{
    TREE *t = create_huffman_tree(get_aux_heap());

    CU_ASSERT_EQUAL(t->c, '*');
    CU_ASSERT_EQUAL(t->left->c, '*');
    CU_ASSERT_EQUAL(t->left->left->c, 'C');
    CU_ASSERT_EQUAL(t->left->right->c, 'B');

    CU_ASSERT_EQUAL(t->right->c, '*');
    CU_ASSERT_EQUAL(t->right->left->c, '*');
    CU_ASSERT_EQUAL(t->right->left->left->c, 'D');
    CU_ASSERT_EQUAL(t->right->left->right->c, '*');
    CU_ASSERT_EQUAL(t->right->left->right->left->c, 'F');
    CU_ASSERT_EQUAL(t->right->left->right->right->c, 'E');
    CU_ASSERT_EQUAL(t->right->right->c, 'A');
}

void map_paths_test()
{
    HASH *ht = create_hash();
    char path[20];

    map_paths(create_huffman_tree(get_aux_heap()), ht, path, 0);

    CU_ASSERT_STRING_EQUAL(get(ht, 'A'), "11");
    CU_ASSERT_STRING_EQUAL(get(ht, 'B'), "01");
    CU_ASSERT_STRING_EQUAL(get(ht, 'C'), "00");
    CU_ASSERT_STRING_EQUAL(get(ht, 'D'), "100");
    CU_ASSERT_STRING_EQUAL(get(ht, 'E'), "1011");
    CU_ASSERT_STRING_EQUAL(get(ht, 'F'), "1010");
}

void write_pre_order_tree_test()
{
    FILE *f = fopen("test_tree.txt", "w+b");
    write_pre_order_tree(create_huffman_tree(get_aux_heap()), f);

    rewind(f);

    unsigned char c = '0';
    char resp[] = {"**CB**D*FEA"};

    for (int i = 0; i < strlen(resp); ++i)
    {
        fscanf(f, "%c", &c);
        CU_ASSERT_EQUAL(c, resp[i]);
    }
}

int main (int argc, char** argv)
{
    CU_pSuite pSuite = NULL;

    if (CUE_SUCCESS != CU_initialize_registry())
    {
        return CU_get_error();
    }

    pSuite = CU_add_suite("Suite_1", NULL, NULL);
    if (NULL == pSuite)
    {
        CU_cleanup_registry();
        return CU_get_error();
    }


    if (NULL == CU_add_test(pSuite, "create_node test", create_node_test))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if (NULL == CU_add_test(pSuite, "is_empty test", is_empty_test))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if (NULL == CU_add_test(pSuite, "is_leaf test", is_leaf_test))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if (NULL == CU_add_test(pSuite, "is_escape_char test", escape_char_test))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if (NULL == CU_add_test(pSuite, "get_tree_size test", tree_size_test))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if (NULL == CU_add_test(pSuite, "create_huffman_tree test", create_huffman_tree_test))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if (NULL == CU_add_test(pSuite, "map_paths test", map_paths_test))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if (NULL == CU_add_test(pSuite, "write_pre_order_tree test", write_pre_order_tree_test))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }


    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return CU_get_error();
}