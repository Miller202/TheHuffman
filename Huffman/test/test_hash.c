//
// Created by MichelT on 14/01/2020.
//

#include "CUnit/Basic.h"
#include "hash.h"

void create_test() {
    HASH *h = create_hash();
    CU_ASSERT_PTR_NOT_NULL(h);
}

void create_table_test() {
    HASH *h = create_hash();
    for (int i = 0; i < MAX_HASH_ADDRESS_SIZE; ++i) {
        CU_ASSERT_PTR_NULL(h->table[i]);
    }
}

void put_get_test() {
    HASH *h = create_hash();

    int i;
    for (i = 0; i < MAX_HASH_ADDRESS_SIZE; ++i) {
        put(h, i, (char *) i);
    }

    for (i = MAX_HASH_ADDRESS_SIZE * 10; i >= 0; --i) {
        CU_ASSERT_EQUAL((char) get(h, i), (char) i);
    }

}


int main (int argc, char** argv) {
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
    if (NULL == CU_add_test(pSuite, "Create hash test", create_test)) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if (NULL == CU_add_test(pSuite, "Create table test", create_table_test)) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if (NULL == CU_add_test(pSuite, "Put and get test", put_get_test)) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
