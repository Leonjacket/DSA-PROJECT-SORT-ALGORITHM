#pragma once

#include "..\sources\utilities.h"

void counting_sort(int *&arr, int n)
{
    if (n <= 1)
        return;

    int max = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    int *count = new int[max + 1]();

    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }

    int t = 0;
    for (int i = 0; i < max; i++)
    {
        if (count[i] > 0)
        {
            arr[t] = i;
            t++;
            count[i]--;
        }
    }

    delete[] count;
}

void counting_sort_cmp(int *&arr, int n, long long &cmp)
{
    cmp = 0;
    if (n <= 1)
        return;

    int max = arr[0];
    for (int i = 0; i < n; i++)
    {
        cmp++;
        if (arr[i] > max)
        {
            cmp++;
            max = arr[i];
        }
    }

    int *count = new int[max + 1]();

    for (int i = 0; i < n; i++)
    {
        cmp++;
        count[arr[i]]++;
    }

    int t = 0;
    for (int i = 0; i < max; i++)
    {
        cmp++;
        if (count[i] > 0)
        {
            arr[t] = i;
            t++;
            count[i]--;
            cmp++;
        }
    }

    delete[] count;
}

void counting_sort_time(int *&a, int n, double &dur)
{
    auto start = chrono::high_resolution_clock::now();
    counting_sort(a, n);
    auto end = chrono::high_resolution_clock::now();
    dur = chrono::duration<double, milli>(end - start).count();
}