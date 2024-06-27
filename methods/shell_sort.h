#ifndef SHELL_SORT_H
#define SHELL_SORT_H

#include <iostream>
#include <chrono>
using namespace std;

// https://www.youtube.com/watch?v=SHcPqUe2GZM (visualization)
// https://www.geeksforgeeks.org/shellsort/ (code từ đây)
void shell_sort(int *&a, int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int tmp = a[i], j;
            for (j = i; j >= gap && a[j - gap] > tmp; j -= gap)
                a[j] = a[j - gap];
            a[j] = tmp;
        }
    }
}

void shell_sort_cmp(int *&a, int n, int &cmp)
{
    cmp = 1; // trường hợp cuối khi gap < 0
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        ++cmp; // gap > 0
        for (int i = gap; i < n; i++)
        {
            ++cmp; // i < n
            int tmp = a[i], j;
            for (j = i; j >= gap && a[j - gap] > tmp; j -= gap)
            {
                cmp += 2; // j >= gap && a[j-gap] > tmp
                a[j] = a[j - gap];
            }
            if (j >= gap)
                cmp += 2; // j >= gap && a[j-gap] < tmp
            else
                ++cmp; // j < gap
            a[j] = tmp;
        }
        ++cmp; // trường hợp cuối khi i > n
    }
}

void shell_sort_time(int *&a, int n, double &dur)
{
    auto start = chrono::high_resolution_clock::now();
    shell_sort(a, n);
    auto end = chrono::high_resolution_clock::now();
    dur = chrono::duration<double, milli>(end - start).count();
}

#endif