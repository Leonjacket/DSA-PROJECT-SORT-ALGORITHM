#include <iostream>
#include <chrono>
using namespace std;

void count_sort(int a[], int n, int exp)
{
    int output[n];
    int i, count[10] = {0};

    for (i = 0; i < n; i++)
    {
        count[(a[i] / exp) % 10]++;
    }

    for (i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    for (i = n - 1; i >= 0; i--)
    {
        output[count[(a[i] / exp) % 10] - 1] = a[i];
        count[(a[i] / exp) % 10]--;
    }

    for (i = 0; i < n; i++)
    {
        a[i] = output[i];
    }
}

void radix_sort(int a[], int n)
{
    int max = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }

    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        count_sort(a, n, exp);
    }
}

void count_sort_cmp(int a[], int n, int exp, int &cmp)
{
    int output[n];
    int i, count[10] = {0};

    for (i = 0; i < n; i++)
    {
        cmp++;
        count[(a[i] / exp) % 10]++;
    }

    for (i = 1; i < 10; i++)
    {
        cmp++;
        count[i] += count[i - 1];
    }

    for (i = n - 1; i >= 0; i--)
    {
        cmp++;
        output[count[(a[i] / exp) % 10] - 1] = a[i];
        count[(a[i] / exp) % 10]--;
    }

    for (i = 0; i < n; i++)
    {
        cmp++;
        a[i] = output[i];
    }
}

void radix_sort_cmp(int a[], int n, int &cmp)
{
    cmp = 0;
    int max = a[0];

    for (int i = 1; i < n; i++)
    {
        cmp++;
        if (a[i] > max && cmp++)
        {
            max = a[i];
        }
    }

    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        cmp++;
        count_sort_cmp(a, n, exp, cmp);
    }
}

void radix_sort_time(int *&a, int n, double &dur)
{
    auto start = chrono::high_resolution_clock::now();
    radix_sort(a, n);
    auto end = chrono::high_resolution_clock::now();
    dur = chrono::duration<double, milli>(end - start).count();
}