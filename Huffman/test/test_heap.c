//
// Created by MichelT on 15/01/2020.
//

#include "CUnit/Basic.h"
#include "heap.h"

void create_test()
{
    HEAP *h = create_heap();
    CU_ASSERT_PTR_NOT_NULL(h)

    for (int i = 1; i < HEAP_MAX_SIZE; ++i)
    {
        CU_ASSERT_PTR_NULL(h->data[i])
    }

    CU_ASSERT_EQUAL(h->size, 0)
}

void get_parent_index_test()
{
    CU_ASSERT_EQUAL(0, get_parent_index(0))
    CU_ASSERT_EQUAL(0, get_parent_index(1))
    CU_ASSERT_EQUAL(1, get_parent_index(2))
    CU_ASSERT_EQUAL(2, get_parent_index(5))
    CU_ASSERT_EQUAL(5, get_parent_index(10))
}

void get_left_index_test()
{
    CU_ASSERT_EQUAL(0, get_left_index(0))
    CU_ASSERT_EQUAL(2, get_left_index(1))
    CU_ASSERT_EQUAL(4, get_left_index(2))
    CU_ASSERT_EQUAL(10, get_left_index(5))
    CU_ASSERT_EQUAL(20, get_left_index(10))
}

void get_right_index_test()
{
    CU_ASSERT_EQUAL(1, get_right_index(0))
    CU_ASSERT_EQUAL(3, get_right_index(1))
    CU_ASSERT_EQUAL(5, get_right_index(2))
    CU_ASSERT_EQUAL(11, get_right_index(5))
    CU_ASSERT_EQUAL(21, get_right_index(10))
}

void swap_data_test()
{
    HEAP *h = create_heap();

    h->data[1] = "CORLEONE";
    h->data[2] = "BARZINI";

    CU_ASSERT_EQUAL("CORLEONE", h->data[1])
    CU_ASSERT_EQUAL("BARZINI", h->data[2])

    void *p1 = h->data[1];
    void *p2 = h->data[2];

    CU_ASSERT_EQUAL("CORLEONE", p1)
    CU_ASSERT_EQUAL("BARZINI", p2)

    swap_data(&h->data[1], &h->data[2]);

    CU_ASSERT_EQUAL("CORLEONE", h->data[2])
    CU_ASSERT_EQUAL("BARZINI", h->data[1])

    CU_ASSERT_EQUAL(p2, h->data[1])
    CU_ASSERT_EQUAL(p1, h->data[2])
}

void enqueue_test()
{
    HEAP *h = create_heap();

    char s[5][4] = {"p3", "p4", "p5", "p6", "p7"};
    int i;

    for (i = 3; i < 8; ++i)
    {
        enqueue(h, i, s[i - 3]);
    }

    for (i = 0; i < 5; ++i)
    {
        CU_ASSERT_STRING_EQUAL(dequeue(h), s[i])
    }

    CU_ASSERT_PTR_NULL(dequeue(h))

    enqueue(h, 7, "p7");
    enqueue(h, 6, "p6");
    enqueue(h, 5, "p5");
    enqueue(h, 4, "p4");
    enqueue(h, 3, "p3");

    CU_ASSERT_STRING_EQUAL(dequeue(h), "p3")
    CU_ASSERT_STRING_EQUAL(dequeue(h), "p4")
    CU_ASSERT_STRING_EQUAL(dequeue(h), "p5")
    CU_ASSERT_PTR_NOT_NULL(dequeue(h))
    CU_ASSERT_STRING_EQUAL(dequeue(h), "p7")

    CU_ASSERT_PTR_NULL(dequeue(h))

    enqueue(h, 5, "p5");
    enqueue(h, 3, "p3");
    enqueue(h, 7, "p7");
    enqueue(h, 1, "p1");
    enqueue(h, 9, "p9");

    CU_ASSERT_STRING_EQUAL(dequeue(h), "p1")
    CU_ASSERT_STRING_EQUAL(dequeue(h), "p3")
    CU_ASSERT_STRING_EQUAL(dequeue(h), "p5")
    CU_ASSERT_STRING_EQUAL(dequeue(h), "p7")
    CU_ASSERT_STRING_EQUAL(dequeue(h), "p9")

    CU_ASSERT_PTR_NULL(dequeue(h))

    enqueue(h, 1, "p1");
    enqueue(h, 1, "p2");
    enqueue(h, 1, "p3");

    CU_ASSERT_STRING_EQUAL(dequeue(h), "p1")
    CU_ASSERT_STRING_EQUAL(dequeue(h), "p3")
    CU_ASSERT_STRING_EQUAL(dequeue(h), "p2")

    enqueue(h, 5, "p5");
    enqueue(h, 3, "p3");
    enqueue(h, 7, "p7");
    enqueue(h, 1, "p1");
    enqueue(h, 9, "p9");
    enqueue(h, 15, "p15");
    enqueue(h, 7, "p7");

    CU_ASSERT_STRING_EQUAL(dequeue(h), "p1")
    CU_ASSERT_STRING_EQUAL(dequeue(h), "p3")
    CU_ASSERT_STRING_EQUAL(dequeue(h), "p5")
    CU_ASSERT_STRING_EQUAL(dequeue(h), "p7")
    CU_ASSERT_STRING_EQUAL(dequeue(h), "p7")
    CU_ASSERT_STRING_EQUAL(dequeue(h), "p9")
    CU_ASSERT_STRING_EQUAL(dequeue(h), "p15")

    CU_ASSERT_PTR_NULL(dequeue(h))

    enqueue(h, 6, "A");
    enqueue(h, 5, "B");
    enqueue(h, 4, "C");
    enqueue(h, 3, "D");
    enqueue(h, 2, "E");
    enqueue(h, 1, "F");


    CU_ASSERT_STRING_EQUAL(dequeue(h), "F")
    CU_ASSERT_STRING_EQUAL(dequeue(h), "E")

    enqueue(h, 3, "*1");

    CU_ASSERT_STRING_EQUAL(dequeue(h), "D")
    CU_ASSERT_STRING_EQUAL(dequeue(h), "*1")

    enqueue(h, 6, "*2");

    CU_ASSERT_STRING_EQUAL(dequeue(h), "C")
    CU_ASSERT_STRING_EQUAL(dequeue(h), "B")

    enqueue(h, 9, "*3");

    CU_ASSERT_STRING_EQUAL(dequeue(h), "*2")
    CU_ASSERT_STRING_EQUAL(dequeue(h), "A")

    enqueue(h, 12, "*4");

    CU_ASSERT_STRING_EQUAL(dequeue(h), "*3")
    CU_ASSERT_STRING_EQUAL(dequeue(h), "*4")

    enqueue(h, 21, "*5");

    CU_ASSERT_STRING_EQUAL(dequeue(h), "*5")

    CU_ASSERT_PTR_NULL(dequeue(h))

}

int main (int argc, char** argv)
{
    CU_pSuite pSuite = NULL;

    /* initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* add a suite to the registry */
    pSuite = CU_add_suite("Suite_1", NULL, NULL);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* add the tests to the suite */
    if (NULL == CU_add_test(pSuite, "create_heap test", create_test))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if (NULL == CU_add_test(pSuite, "get_parent_index test", get_parent_index_test))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if (NULL == CU_add_test(pSuite, "get_left_index test", get_left_index_test))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if (NULL == CU_add_test(pSuite, "get_right_index test", get_right_index_test))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if (NULL == CU_add_test(pSuite, "swap_data test", swap_data_test))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if (NULL == CU_add_test(pSuite, "enqueue test", enqueue_test))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }


    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
