#include "bach.h"

void counting_sort(int* arr, int n){
    if (n <= 1) return;

    int max = arr[0];
    for (int i = 0; i < n; i++){
        if (arr[i] > max){
            max = arr[i];
        }
    }

    int* count = new int[max + 1]();

    for (int i = 0; i < n; i++){
        count[arr[i]]++;
    }

    int t = 0;
    for (int i = 0; i < max; i++){
        if (count[i] > 0){
            arr[t] = i;
            t++;
            count[i]--;
        }
    }

    delete[] count;
}

void counting_sort_cmp(int*& arr, int n, int& cmp){
    int cmp = 0;
     if (n <= 1) return;

    int max = arr[0];
    for (int i = 0; i < n; i++){
        if (arr[i] > max){
            max = arr[i];
        }
    }

    int* count = new int[max + 1]();

    for (int i = 0; i < n; i++){
        count[arr[i]]++;
    }

    int t = 0;
    for (int i = 0; i < max; i++){
        if (count[i] > 0){
            arr[t] = i;
            t++;
            count[i]--;
            cmp++;
        }
    }

    delete[] count;
}

void counting_sort_time(int*& arr, int n, int& dur) {
    clock_t start, end;
    start = clock();

    counting_sort(arr, n);

    end = clock();
    dur = static_cast<int>(end - start);
}
