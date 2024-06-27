#pragma once

#include "..\sources\utilities.h"


void max_heapify(int a[], int n, int i)
{

    int largest = i;

    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && a[l] > a[largest])
    {
        largest = l;
    }

    if (r < n && a[r] > a[largest])
    {
        largest = r;
    }

    if (largest != i)
    {
        swap(a[i], a[largest]);
        max_heapify(a, n, largest);
    }
}

void heap_sort(int a[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        max_heapify(a, n, i);
    }

    for (int i = n - 1; i > 0; i--)
    {
        swap(a[0], a[i]);
        max_heapify(a, i, 0);
    }
}

void max_heapify_cmp(int a[], int n, int i, int &cmp)
{

    int largest = i;

    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && a[l] > a[largest] && cmp++)
    {
        largest = l;
    }

    if (r < n && a[r] > a[largest] && cmp++)
    {
        largest = r;
    }

    if (largest != i && cmp++)
    {
        swap(a[i], a[largest]);
        max_heapify_cmp(a, n, largest, cmp);
    }
}

void heap_sort_cmp(int a[], int n, int &cmp)
{
    cmp = 0;
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        cmp++;
        max_heapify_cmp(a, n, i, cmp);
    }

    for (int i = n - 1; i > 0; i--)
    {
        cmp++;
        swap(a[0], a[i]);
        max_heapify_cmp(a, i, 0, cmp);
    }
}

void heap_sort_time(int *&a, int n, double &dur)
{
    auto start = chrono::high_resolution_clock::now();
    heap_sort(a, n);
    auto end = chrono::high_resolution_clock::now();
    dur = chrono::duration<double, milli>(end - start).count();
}