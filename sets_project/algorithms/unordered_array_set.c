#include "unordered_array_set.h"

static void unordered_array_set_shrinkToFit(unordered_array_set *a) {
    if (a->size != a->capacity) {
        a->data = (int *) realloc(a->data, sizeof(int) * a->size);
        a->capacity = a->size;
    }
}

unordered_array_set unordered_array_set_create(size_t capacity) {
    return (unordered_array_set) {malloc(sizeof(int) * capacity), 0, capacity};
}

unordered_array_set unordered_array_set_create_from_array(const int *a, size_t size) {
    unordered_array_set set = unordered_array_set_create(size);
    for (size_t i = 0; i < size; i++)
        unordered_array_set_insert(&set, a[i]);
    unordered_array_set_shrinkToFit(&set);
    return set;
}

size_t unordered_array_set_in(unordered_array_set *set, int value) {
    return linearSearch_(set->data, set->size, value);
}

int compare_ints(const void *a, const void *b) {
    const char *set1 = (const char *) a;
    const char *set2 = (const char *) b;

    if (*set1 < *set2)
        return -1;
    else if (*set1 > *set2)
        return 1;
    else
        return 0;
}

bool unordered_array_set_isEqual(unordered_array_set set1, unordered_array_set set2) {
    if (set1.size != set2.size)
        return false;
    qsort(set1.data, set1.size, sizeof(int), compare_ints);
    qsort(set2.data, set2.size, sizeof(int), compare_ints);
    return memcmp(set1.data, set2.data, sizeof(int) * set1.size) == 0;
}

void unordered_array_set_isAbleAppend(unordered_array_set *set) {
    assert(set->size < set->capacity);
}

void unordered_array_set_insert(unordered_array_set *set, int value) {
    if (unordered_array_set_in(set, value) == set->size) {
        unordered_array_set_isAbleAppend(set);
        append_(set->data, &set->size, value);
    }
}

void unordered_array_set_deleteElement(unordered_array_set *set, int value) {
    size_t posOfElementToDelete = linearSearch_(set->data, set->size, value);
    assert(posOfElementToDelete < set->size);
    deleteByPosUnsaveOrder_(set->data, &set->size, posOfElementToDelete);
}

unordered_array_set unordered_array_set_union(unordered_array_set set1, unordered_array_set set2) {
    unordered_array_set sum = unordered_array_set_create(set1.size + set2.size);
    sum.size = set1.size;
    memcpy(sum.data, set1.data, set1.size * sizeof(int));
    for (int i = 0; i < set2.size; i++) {
        int value = set2.data[i];
        int pos = linearSearch_(sum.data, sum.size, value);
        if (pos == sum.size)
            append_(sum.data, &sum.size, value);
    }
    return sum;
}

unordered_array_set unordered_array_set_intersection(unordered_array_set set1, unordered_array_set set2) {
    unordered_array_set intersection = unordered_array_set_create(set1.size);
    intersection.size = 0;
    for (int i = 0; i < set2.size; i++) {
        int value = set2.data[i];
        int posSet1 = linearSearch_(set1.data, set1.size, value);
        if (posSet1 != set1.size)
            append_(intersection.data, &intersection.size, value);
    }
    return intersection;
}

unordered_array_set unordered_array_set_difference(unordered_array_set set1, unordered_array_set set2) {
    unordered_array_set difference = unordered_array_set_create(set1.size);
    difference.size = 0;
    for (int i = 0; i < set1.size; i++) {
        int value = set1.data[i];
        int posSet2 = linearSearch_(set2.data, set2.size, value);
        if (posSet2 == set2.size)
            append_(difference.data, &difference.size, value);
    }
    return difference;
}

unordered_array_set unordered_array_set_symmetricDifference(unordered_array_set set1, unordered_array_set set2) {
    unordered_array_set sum = unordered_array_set_create(set1.size + set2.size);
    sum.size = 0;
    unordered_array_set a = unordered_array_set_difference(set1, set2);
    unordered_array_set b = unordered_array_set_difference(set2, set1);
    unordered_array_set c = unordered_array_set_union(a, b);
    unordered_array_set_delete(a);
    unordered_array_set_delete(b);
    return c;
}

bool unordered_array_set_isSubset(unordered_array_set subset, unordered_array_set set) {
    return unordered_array_set_isEqual(unordered_array_set_intersection(subset, set), subset);
}

unordered_array_set unordered_array_set_complement(unordered_array_set set, unordered_array_set universumSet) {
    assert(unordered_array_set_isSubset(set, universumSet));
    return unordered_array_set_difference(universumSet, set);
}

void unordered_array_set_print(unordered_array_set set) {
    printf("{");
    for (size_t i = 0; i < set.size; i++)
        printf("%d ", set.data[i]);
    printf("\b}\n");
}
void unordered_array_set_delete(unordered_array_set set) {
    free(set.data);
}
