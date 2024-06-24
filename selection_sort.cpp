#include "bach.h"

void selection_sort(int*& a, int n){
    for (int i = 0; i < n - 1; i++){
        int min = i;
        for (int j = i + 1; j < n; j++){
            if (a[j] < a[min]){
                min = j;
            }
        }

        int tmp = a[min];
        a[min] = a[i];
        a[i] = tmp;
    }
}

void selection_sort_cmp(int*& a, int n, int& cmp) {
    cmp = 0;
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            cmp++;
            if (a[j] < a[min]) {
                min = j;
            }
        }
        int tmp = a[min];
        a[min] = a[i];
        a[i] = tmp;
    }
}

void selection_sort_time(int*& a, int n, int& dur) {
    clock_t start, end;
    start = clock(); 
    selection_sort(a, n);
    end = clock(); 
    dur = static_cast<int>(end - start); 
}