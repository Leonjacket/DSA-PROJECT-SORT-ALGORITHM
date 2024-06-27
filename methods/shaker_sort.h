#ifndef SHAKER_SORT_H
#define SHAKER_SORT_H

#include <iostream>
#include <string>
#include <chrono>
#include <algorithm>

using namespace std;
void command_line_1(int argc, char *argv[]);
void command_line_2(int argc, char *argv[]);
void command_line_3(int argc, char *argv[]);
void command_line_4(int argc, char *argv[]);
void command_line_5(int argc, char *argv[]);
bool have_extension(string filename);
int partition(int *&a, int l, int r, int pivot);            // hàm phụ cho quick sort
void quick_sort_algo(int *&a, int s, int e);                // hàm phụ cho quick sort
void quick_sort(int *&a, int size);                         // tham khảo ở  https://youtu.be/pM-6r5xsNEY?si=U1rUfohX2kWGmz4M
void quick_sort_cmp(int *&a, int size, int &cmp);           // hàm phụ cho quick sort cmp
void partition_cmp(int *&a, int l, int r, int e, int &cmp); // hàm phụ cho quick sort cmp
void bubble_sort(int *&a, int size);
void bubble_sort_cmp(int *&a, int size, int &cmp);
void bubble_sort_time(int *&a, int size, double &dur);
void shaker_sort(int *&a, int size); // tham khảo ở https://www.youtube.com/watch?v=dpSxj2Ps7DI
void shaker_sort_cmp(int *&a, int size, int &cmp);
void shaker_sort_time(int *&a, int size, double &dur);
void shaker_sort(int *&a, int size)
{
    int l = 0, r = size - 1;
    while (l < r)
    {
        for (int j = l; j <= r - 1; ++j)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
            }
        }
        r--;
        for (int j = r; j >= l + 1; --j)
        {
            if (a[j] < a[j - 1])
            {
                swap(a[j], a[j - 1]);
            }
        }
        l++;
    }
}

void shaker_sort_cmp(int *&a, int size, int &cmp)
{
    int l = 0, r = size - 1;
    cmp = 0;
    while (++cmp && l < r)
    {
        for (int j = l; j <= r - 1; ++j)
        {
            ++cmp;
            if (++cmp && a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
            }
        }
        ++cmp;
        r--;
        for (int j = r; j >= l + 1; --j)
        {
            ++cmp;
            if (++cmp && a[j] < a[j - 1])
            {
                swap(a[j], a[j - 1]);
            }
        }
        ++cmp;
        l++;
    }
}
void shaker_sort_time(int *&a, int size, double &dur)
{
    auto start = chrono::high_resolution_clock::now();
    shaker_sort(a, size);
    auto end = chrono::high_resolution_clock::now();
    dur = chrono::duration<double, milli>(end - start).count();
}

#endif