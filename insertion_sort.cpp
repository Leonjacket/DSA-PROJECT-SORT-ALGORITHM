#include "manh.h"

void insertion_sort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int cur = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > cur)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = cur;
    }
}

void insertion_sort_cmp(int a[], int n, int &cmp)
{
    cmp = 0;
    for (int i = 1; i < n; i++)
    {
        int cur = a[i];
        int j = i - 1;

        while (++cmp && j >= 0 && a[j] > cur)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = cur;
    }
}

void insertion_sort_time(int *&a, int n, double &dur)
{
    auto start = chrono::high_resolution_clock::now();
    insertion_sort(a, n);
    auto end = chrono::high_resolution_clock::now();
    dur = chrono::duration<double, milli>(end - start).count();
}