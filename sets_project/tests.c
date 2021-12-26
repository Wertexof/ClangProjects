#include <assert.h>
#include "c:/users/perso/CLionProjects/sets_project/libs/algorithms/array/array.h"
#include "c:/users/perso/CLionProjects/sets_project/libs/data_structures/bitset/bitset.h"
#include "c:/users/perso/CLionProjects/sets_project/libs/algorithms/unordered_array_set.h"
#include "c:/users/perso/CLionProjects/sets_project/libs/algorithms/ordered_array_set.h"

void test_unordered_array_set_create1() {
    unordered_array_set set1 = unordered_array_set_create(5);
    assert(set1.size == 0);
    assert(set1.capacity == 5);
}

void test_unordered_array_set_create2() {
    unordered_array_set set1 = unordered_array_set_create(3);
    assert(set1.size == 0);
    assert(set1.capacity == 3);
}

void test_unordered_array_set_create() {
    test_unordered_array_set_create1();
    test_unordered_array_set_create2();
}

void test_unordered_array_set_in1() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {1, 2}, 2);
    int value = 1;
    long long resSet = unordered_array_set_in(&set1, value);
    int index = 0;
    assert (resSet == index);
}

void test_unordered_array_set_in2() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {3, 7, 5, 8, 6, 4}, 6);
    int value = 0;
    long long resSet = unordered_array_set_in(&set1, value);
    int index = 6;
    assert (resSet == index);
}

void test_unordered_array_set_in() {
    test_unordered_array_set_in1();
    test_unordered_array_set_in2();
}

void test_unordered_array_set_isEqual1() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {2, 5, 8}, 3);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {2, 5, 8}, 3);

    bool resSet = unordered_array_set_isEqual(set1, set2);
    bool expectedRes = true;
    assert (resSet == expectedRes);
}

void test_unordered_array_set_isEqual2() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {2, 5, 8}, 3);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {5, 8, 2}, 3);

    bool resSet = unordered_array_set_isEqual(set1, set2);
    bool expectedRes = true;
    assert (resSet == expectedRes);
}

void test_unordered_array_set_isEqual() {
    test_unordered_array_set_isEqual1();
    test_unordered_array_set_isEqual2();
}

void test_unordered_array_set_insert1() {
    unordered_array_set set1 = unordered_array_set_create(3);
    unordered_array_set_insert(&set1, 6);
    unordered_array_set_insert(&set1, -1);
    unordered_array_set_insert(&set1, 4);
    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {6, -1, 4}, 3);

    assert(unordered_array_set_isEqual(set1, expectedSet));

    unordered_array_set_delete(set1);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_insert2() {
    unordered_array_set set1 = unordered_array_set_create(2);
    unordered_array_set_insert(&set1, 9);
    unordered_array_set_insert(&set1, 10);
    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {9, 10}, 2);

    assert(unordered_array_set_isEqual(set1, expectedSet));

    unordered_array_set_delete(set1);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_insert() {
    test_unordered_array_set_insert1();
    test_unordered_array_set_insert2();
}

void test_unordered_array_set_deleteElement1() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {4, 5, 6, 7, 9}, 5);
    unordered_array_set_deleteElement(&set1, 7);
    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {4, 5, 6, 9}, 4);

    assert(unordered_array_set_isEqual(set1, expectedSet));

    unordered_array_set_delete(set1);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_deleteElement2() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {8, -6, 6}, 3);
    unordered_array_set_deleteElement(&set1, -6);
    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {8, 6}, 2);

    assert (unordered_array_set_isEqual(set1, expectedSet));

    unordered_array_set_delete(set1);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_deleteElement() {
    test_unordered_array_set_deleteElement1();
    test_unordered_array_set_deleteElement2();
}

void test_unordered_array_set_union1() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {1, 2}, 2);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {2, 3}, 2);
    unordered_array_set resSet = unordered_array_set_union(set1, set2);
    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);

    assert (unordered_array_set_isEqual(resSet, expectedSet));

    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_union2() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {}, 0);
    unordered_array_set resSet = unordered_array_set_union(set1, set2);
    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);

    assert (unordered_array_set_isEqual(resSet, expectedSet));

    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_union() {
    test_unordered_array_set_union1();
    test_unordered_array_set_union2();
}

void test_unordered_array_set_intersection1() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 6, 10}, 6);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {2, 4, 10, 7}, 4);
    unordered_array_set resSet = unordered_array_set_intersection(set1, set2);
    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {2, 4, 10}, 3);

    assert (unordered_array_set_isEqual(resSet, expectedSet));

    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_intersection2() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {4, 6, 7, 2, -3, 0, 44}, 7);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {5, 1, 2}, 3);
    unordered_array_set resSet = unordered_array_set_intersection(set1, set2);
    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {2}, 1);

    assert (unordered_array_set_isEqual(resSet, expectedSet));

    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_intersection() {
    test_unordered_array_set_intersection1();
    test_unordered_array_set_intersection2();
}

void test_unordered_array_set_difference1() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {2, 3, 4, 5}, 4);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {5, 1, 6}, 3);
    unordered_array_set resSet = unordered_array_set_difference(set1, set2);
    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {2, 3, 4}, 3);

    assert (unordered_array_set_isEqual(resSet, expectedSet));

    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_difference2() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {99, 3, 4, 6}, 4);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {0, 3, 4}, 3);
    unordered_array_set resSet = unordered_array_set_difference(set1, set2);
    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {99, 6}, 2);

    assert (unordered_array_set_isEqual(resSet, expectedSet));

    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_difference() {
    test_unordered_array_set_difference1();
    test_unordered_array_set_difference2();
}

void test_unordered_array_set_symmetricDifference1() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {3, 6, 8, 1, 2}, 5);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {-5, 3, 8, 11, 3}, 5);
    unordered_array_set resSet = unordered_array_set_symmetricDifference(set1, set2);
    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {1, -5, 6, 2, 11, 3}, 6);

    assert (unordered_array_set_isEqual(resSet, expectedSet));

    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_symmetricDifference2() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 6, 10}, 6);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {1, 4, 5, 6}, 4);
    unordered_array_set resSet = unordered_array_set_symmetricDifference(set1, set2);
    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {2, 3, 5, 10}, 4);

    assert (unordered_array_set_isEqual(resSet, expectedSet));

    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_symmetricDifference() {
    test_unordered_array_set_symmetricDifference1();
    test_unordered_array_set_symmetricDifference2();
}

void test_unordered_array_set_complement1() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5}, 5);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {1, 3, 2, 4, 5, 6, 8}, 7);
    unordered_array_set resSet = unordered_array_set_complement(set1, set2);

    assert(resSet.data[0] == 6);
    assert(resSet.data[1] == 8);
    assert(resSet.size == 2);

    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
}

void test_unordered_array_set_complement2() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {4, 7, 42, 9}, 4);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {5, 42, 5, 7, -2, -5, 0}, 6);
    unordered_array_set resSet = unordered_array_set_complement(set1, set2);

    assert(resSet.data[0] == -2);
    assert(resSet.data[1] == -5);
    assert(resSet.data[2] == 0);
    assert(resSet.size == 2);

    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
}

void test_unordered_array_set_complement() {
    test_unordered_array_set_complement1();
    test_unordered_array_set_complement2();
}

void test_unordered_array_set_isSubset1() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {}, 0);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {0, 3, 4}, 3);

    assert (unordered_array_set_isSubset(set1, set2));

    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
}

void test_unordered_array_set_isSubset2() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {}, 0);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {}, 0);

    assert (unordered_array_set_isSubset(set1, set2));

    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
}

void test_unordered_array_set_isSubset() {
    test_unordered_array_set_isSubset1();
    test_unordered_array_set_isSubset2();
}


///ORDERED ARRAYS


void test_ordered_array_set_in1() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {1, 2}, 2);
    int value = 1;
    size_t resSet = ordered_array_set_in(&set1, value);
    int index = 0;
    assert (resSet == index);
}

void test_ordered_array_set_in2() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {3, 5, 6, 7, 8, 9}, 6);
    int value = 9;
    size_t resSet = ordered_array_set_in(&set1, value);
    int index = 5;
    assert (resSet == index);
}

void test_ordered_array_set_in3() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {-3, -2, 0, 3, 77}, 5);
    int value = -2;
    size_t resSet = ordered_array_set_in(&set1, value);
    int index = 1;
    assert (resSet == index);
}

void test_ordered_array_set_in() {
    test_ordered_array_set_in1();
    test_ordered_array_set_in2();
    test_ordered_array_set_in3();
}

void test_ordered_array_set_isSubset1() {
    ordered_array_set subset = ordered_array_set_create_from_array((int[]) {0}, 0);
    ordered_array_set set = ordered_array_set_create_from_array((int[]) {0, 3, 4}, 3);

    assert (ordered_array_set_isSubset(subset, set));

    ordered_array_set_delete(subset);
    ordered_array_set_delete(set);
}

void test_ordered_array_set_isSubset2() {
    ordered_array_set subset = ordered_array_set_create_from_array((int[]) {}, 0);
    ordered_array_set set = ordered_array_set_create_from_array((int[]) {}, 0);

    assert (ordered_array_set_isSubset(subset, set));

    ordered_array_set_delete(subset);
    ordered_array_set_delete(set);
}

void test_ordered_array_set_isSubset() {
    test_ordered_array_set_isSubset1();
    test_ordered_array_set_isSubset2();
}

void test_ordered_array_set_insert1() {
    ordered_array_set set1 = ordered_array_set_create(8);
    ordered_array_set_insert(&set1, 10);
    ordered_array_set_insert(&set1, 8);

    ordered_array_set expectedSet = ordered_array_set_create_from_array((int[]) {8, 10}, 2);
    assert(ordered_array_set_isEqual(set1, expectedSet));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_insert2() {
    ordered_array_set set1 = ordered_array_set_create(6);
    ordered_array_set_insert(&set1, 6);
    ordered_array_set_insert(&set1, -1);
    ordered_array_set_insert(&set1, 4);

    ordered_array_set expectedSet = ordered_array_set_create_from_array((int[]) {-1, 4, 6}, 3);
    assert(ordered_array_set_isEqual(set1, expectedSet));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_insert() {
    test_ordered_array_set_insert1();
    test_ordered_array_set_insert2();
}

void test_ordered_array_set_deleteElement1() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {3, 4, 5, 7, 10}, 5);
    ordered_array_set_deleteElement(&set1, 10);
    ordered_array_set expectedSet = ordered_array_set_create_from_array((int[]) {3, 4, 5, 7}, 4);

    assert(ordered_array_set_isEqual(set1, expectedSet));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_deleteElement2() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {-2, -1, 0, 3, 6, 8}, 6);
    ordered_array_set_deleteElement(&set1, 0);
    ordered_array_set expectedSet = ordered_array_set_create_from_array((int[]) {-2, -1, 3, 6, 8}, 5);

    assert (ordered_array_set_isEqual(set1, expectedSet));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_deleteElement() {
    test_ordered_array_set_deleteElement1();
    test_ordered_array_set_deleteElement2();
}

void test_ordered_array_set_union1() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {1, 2}, 2);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {2, 3}, 2);
    ordered_array_set resSet = ordered_array_set_union(set1, set2);
    ordered_array_set expectedSet = ordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);

    assert (ordered_array_set_isEqual(resSet, expectedSet));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_union2() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {2, 6, 7, 8}, 4);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {2, 4, 5, 9, 22}, 5);
    ordered_array_set resSet = ordered_array_set_union(set1, set2);
    ordered_array_set expectedSet = ordered_array_set_create_from_array((int[]) {2, 4, 5, 6, 7, 8, 9, 22}, 8);

    assert (ordered_array_set_isEqual(resSet, expectedSet));


    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_union() {
    test_ordered_array_set_union1();
    test_ordered_array_set_union2();
}

void test_ordered_array_set_intersection1() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 6, 10}, 6);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {1, 4, 5, 6}, 4);
    ordered_array_set resSet = ordered_array_set_intersection(set1, set2);
    ordered_array_set expectedSet = ordered_array_set_create_from_array((int[]) {1, 4, 6}, 3);

    assert (ordered_array_set_isEqual(resSet, expectedSet));


    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_intersection2() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {4, 6, 7, 2, -3, 0, 44}, 7);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {5, 1, 2}, 3);
    ordered_array_set resSet = ordered_array_set_intersection(set1, set2);
    ordered_array_set expectedSet = ordered_array_set_create_from_array((int[]) {2}, 1);
    assert (ordered_array_set_isEqual(resSet, expectedSet));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_intersection() {
    test_ordered_array_set_intersection1();
    test_ordered_array_set_intersection2();
}

void test_ordered_array_set_difference1() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {0, 3, 5, 6}, 4);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {0, 5, 6, 8, 100}, 5);
    ordered_array_set resSet = ordered_array_set_difference(set1, set2);
    ordered_array_set expectedSet = ordered_array_set_create_from_array((int[]) {3}, 1);

    assert (ordered_array_set_isEqual(resSet, expectedSet));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_difference2() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {-1, 0, 8, 9, 33}, 4);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {-1, 33, 34}, 3);
    ordered_array_set resSet = ordered_array_set_difference(set1, set2);
    ordered_array_set expectedSet = ordered_array_set_create_from_array((int[]) {0, 8, 9}, 3);

    assert (ordered_array_set_isEqual(resSet, expectedSet));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_difference() {
    test_ordered_array_set_difference1();
    test_ordered_array_set_difference2();
}

void test_ordered_array_set_symmetricDifference1() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {5, 6, 7, 11, 90}, 5);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {-4, 5, 7, 9, 33}, 5);
    ordered_array_set resSet =
            ordered_array_set_symmetricDifference(set1, set2);
    ordered_array_set expectedSet = ordered_array_set_create_from_array((int[]) {-4, 6, 9, 11, 33, 90}, 6);

    assert (ordered_array_set_isEqual(resSet, expectedSet));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_symmetricDifference2() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 6, 10}, 6);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 6, 10}, 6);
    ordered_array_set resSet = ordered_array_set_symmetricDifference(set1, set2);
    ordered_array_set expectedSet = ordered_array_set_create_from_array((int[]) {}, 0);
    assert (ordered_array_set_isEqual(resSet, expectedSet));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_symmetricDifference() {
    test_ordered_array_set_symmetricDifference1();
    test_ordered_array_set_symmetricDifference2();
}

void test_ordered_array_set_complement1() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5}, 5);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5, 6, 8}, 7);
    ordered_array_set resSet = ordered_array_set_complement(set1, set2);

    assert(resSet.data[0] == 6);
    assert(resSet.data[1] == 8);
    assert(resSet.size == 2);

    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resSet);
}

void test_ordered_array_set_complement2() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {8, 9}, 2);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {-4, -3, 4, 7, 8, 9, 10}, 7);
    ordered_array_set resSet = ordered_array_set_complement(set1, set2);

    assert(resSet.data[0] == -4);
    assert(resSet.data[1] == -3);
    assert(resSet.data[2] == 4);
    assert(resSet.data[3] == 7);
    assert(resSet.data[4] == 10);
    assert(resSet.size == 5);

    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resSet);
}

void test_ordered_array_set_complement() {
    test_ordered_array_set_complement1();
    test_ordered_array_set_complement2();
}

void test() {
    test_unordered_array_set_in();
    test_unordered_array_set_isEqual();
    test_unordered_array_set_create();
    test_unordered_array_set_union();
    test_unordered_array_set_intersection();
    test_unordered_array_set_difference();
    test_unordered_array_set_symmetricDifference();
    test_unordered_array_set_complement();
    test_unordered_array_set_insert();
    test_unordered_array_set_deleteElement();
    test_unordered_array_set_isSubset();
    test_ordered_array_set_in();
    test_ordered_array_set_isSubset();
    test_ordered_array_set_insert();
    test_ordered_array_set_deleteElement();
    test_ordered_array_set_union();
    test_ordered_array_set_intersection();
    test_ordered_array_set_difference();
    test_ordered_array_set_symmetricDifference();
    test_ordered_array_set_complement();
}

int main() {
    test();

    return 0;
}