#include "bach.h"

void merge(int* l, int* r, int* a, int size) {
    int leftSize = size / 2;
    int rightSize = size - leftSize;
    int i = 0, m = 0, n = 0;

    while (m < leftSize && n < rightSize) {
        if (l[m] < r[n]) {
            a[i] = l[m];
            i++;
            m++;
        } else {
            a[i] = r[n];
            i++;
            n++;
        }
    }

    while (m < leftSize) {
        a[i] = l[m];
        i++;
        m++;
    }

    while (n < rightSize) {
        a[i] = r[n];
        i++;
        n++;
    }
}

void merge_sort(int* a, int size) {
    if (size <= 1) return;

    int mid = size / 2;
    int* l = new int[mid];
    int* r = new int[size - mid];

    memcpy(l, a, mid * sizeof(int));
    memcpy(r, a + mid, (size - mid) * sizeof(int));

    merge_sort(l, mid);
    merge_sort(r, size - mid);
    merge(l, r, a, size);

    delete[] l;
    delete[] r;
}

void merge_cmp(int* l, int* r, int* a, int size, int& cmp){
    int leftSize = size / 2;
    int rightSize = size - leftSize;
    int i = 0, m = 0, n = 0;

    while (m < leftSize && n < rightSize){
        cmp++;  
        if (l[m] < r[n]){
            a[i] = l[m];
            i++;
            m++;
        } else {
            a[i] = r[n];
            i++;
            n++;
        }
    }

    while (m < leftSize){
        cmp++;
        a[i] = l[m];
        i++;
        m++;
    }

    while (n < rightSize){
        cmp++;
        a[i] = r[n];
        i++;
        n++;
    }
}

void merge_sort_cmp(int*& a, int size, int& cmp){
    if (size <= 1) return;

    int mid = size / 2;
    int* l = new int[mid];
    int* r = new int[size - mid];

    memcpy(l, a, mid * sizeof(int));
    memcpy(r, a + mid, (size - mid) * sizeof(int));

    merge_sort_cmp(l , mid, cmp);
    merge_sort_cmp(r, size - mid, cmp);
    merge_cmp(l , r, a, size, cmp);

    delete[] l;
    delete[] r;
}

void merge_sort_time(int*& a, int size, int& dur){
    clock_t start, end;
    start = clock();
    merge_sort(a, size);
    end = clock();
    dur = static_cast<int>(end - start);
}