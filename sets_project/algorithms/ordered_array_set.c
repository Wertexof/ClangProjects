#include "ordered_array_set.h"

static void ordered_array_set_shrinkToFit(ordered_array_set *a) {
    if (a->size != a->capacity) {
        a->data = (int *) realloc(a->data, sizeof(int) * a->size);
        a->capacity = a->size;
    }
}

ordered_array_set ordered_array_set_create(size_t capacity) {
    return (ordered_array_set) {malloc(sizeof(int) * capacity), 0, capacity};
}

ordered_array_set ordered_array_set_create_from_array(const int *a, size_t size) {
    ordered_array_set set = ordered_array_set_create(size);
    for (size_t i = 0; i < size; i++)
        ordered_array_set_insert(&set, a[i]);
    ordered_array_set_shrinkToFit(&set);
    return set;
}

size_t ordered_array_set_in(ordered_array_set *set, int value) {
    size_t pos = binarySearchMoreOrEqual_(set->data, set->size, value);
    return set->data[pos] == value ? pos : set->size;
}

bool ordered_array_set_isEqual(ordered_array_set set1, ordered_array_set set2) {
    return set1.size == set2.size && memcmp(set1.data, set2.data, sizeof(int) * set1.size) == 0;
}

bool ordered_array_set_isSubset(ordered_array_set subset, ordered_array_set set) {
    return ordered_array_set_isEqual(ordered_array_set_intersection(subset, set), subset);
}

void ordered_array_set_isAbleAppend(ordered_array_set *set) {
    assert(set->size < set->capacity);
}

void insertionSort(int *a, const size_t size) {
    for (size_t i = 1; i < size; i++) {
        int t = a[i];
        int j = i;
        while (j > 0 && a[j - 1] > t) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = t;
    }
}

void ordered_array_set_insert(ordered_array_set *set, int value) {
    ordered_array_set_isAbleAppend(set);
    if (ordered_array_set_in(set, value) == set->size) {
        append_(set->data, &set->size, value);
        insertionSort(set->data, set->size);
    }
}

void ordered_array_set_deleteElement(ordered_array_set *set, int value) {
    size_t posOfElementToDelete = binarySearch_(set->data, set->size, value);
    assert(posOfElementToDelete < set->size);
    deleteByPosSaveOrder_(set->data, &set->size, posOfElementToDelete);
}

ordered_array_set ordered_array_set_union(ordered_array_set set1, ordered_array_set set2) {
    ordered_array_set sum = ordered_array_set_create(set1.size + set2.size);
    sum.size = set1.size;
    memcpy(sum.data, set1.data, set1.size * sizeof(int));
    for (int i = 0; i < set2.size; i++) {
        int value = set2.data[i];
        int pos = binarySearch_(sum.data, sum.size, value);
        if (pos == sum.size)
            append_(sum.data, &sum.size, value);
        insertionSort(sum.data, sum.size);
    }
    return sum;
}

ordered_array_set ordered_array_set_intersection(ordered_array_set set1, ordered_array_set set2) {
    ordered_array_set intersection = ordered_array_set_create(set1.size);
    intersection.size = 0;
    for (int i = 0; i < set2.size; i++) {
        int value = set2.data[i];
        int posSet1 = binarySearch_(set1.data, set1.size, value);
        if (posSet1 != set1.size)
            append_(intersection.data, &intersection.size, value);
        insertionSort(intersection.data, intersection.size);
    }
    return intersection;
}

ordered_array_set ordered_array_set_difference(ordered_array_set set1, ordered_array_set set2) {
    ordered_array_set difference = ordered_array_set_create(set1.size);
    difference.size = 0;
    for (int i = 0; i < set1.size; i++) {
        int value = set1.data[i];
        int posSet2 = binarySearch_(set2.data, set2.size, value);
        if (posSet2 == set2.size)
            append_(difference.data, &difference.size, value);
        insertionSort(difference.data, difference.size);
    }
    return difference;
}

ordered_array_set ordered_array_set_symmetricDifference(ordered_array_set set1, ordered_array_set set2) {
    ordered_array_set sum = ordered_array_set_create(set1.size + set2.size);
    sum.size = 0;
    ordered_array_set a = ordered_array_set_difference(set1, set2);
    ordered_array_set b = ordered_array_set_difference(set2, set1);
    ordered_array_set c = ordered_array_set_union(a, b);
    ordered_array_set_delete(a);
    ordered_array_set_delete(b);
    return c;
}

ordered_array_set ordered_array_set_complement(ordered_array_set set, ordered_array_set universumSet) {
    assert(ordered_array_set_isSubset(set, universumSet));
    return ordered_array_set_difference(universumSet, set);
}

void ordered_array_set_print(ordered_array_set set) {
    printf("{");
    for (size_t i = 0; i < set.size; i++)
        printf("%d ", set.data[i]);
    printf("\b}\n");
}

void ordered_array_set_delete(ordered_array_set set) {
    free(set.data);
}