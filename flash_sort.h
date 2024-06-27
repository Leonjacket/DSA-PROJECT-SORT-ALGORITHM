#include <iostream>
#include <chrono>
using namespace std;
// https://www.youtube.com/watch?v=CAaDJJUszvE (giải thích cách sort)
// https://chatgpt.com/c/bb3ec1d8-fc33-4c10-82a0-efc56fa28e33 (code từ chatgpt)
void flash_sort(int*& a, int n)
{
    if(n <= 1) return;
    // find max
    int max = a[0], min = a[0];
    for(int i = 1; i < n; i++)
    {
        if(a[i] > max) max = a[i];
        if(a[i] < min) min = a[i];
    }

    if(max == min) return;
    // tạo bucket
    int m = n * 0.45;
    int* l = new int[m] {0};
    //tính số phần tử có trong mỗi bucket
    int c = (m-1)/(max - min);
    for(int i = 0; i < n; i++)
    {
        int k = c * (a[i] - min);
        ++l[k];
    }
    // chuyển đổi l thành vị trí cuối cùng của mỗi bucket
    for(int i = 1; i < m; i++)
        l[i] += l[i-1];
    // sắp xếp bằng cách đổi chỗ cho các phần tử vào đúng vị trí của bucket
    int move = 0, j = 0, k = m - 1, t, flash;
    while(move < n - 1)
    {
        while(j > l[k] - 1)
        {
            j++;
            k = c * (a[j] - min);
        }
        flash = a[j];
        while(j != l[k])
        {
            k = c * (flash - min);
            t = a[--l[k]];
            a[l[k]] = flash;
            flash = t;
            move++;
        }
    }
    // insertion sort
    for(int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;
        while(j >= 0 && a[j] > key)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
    delete[] l;
}

void flash_sort_cmp(int*& a, int n, int& cmp)
{
    cmp = 0;
    if(++cmp && n <= 1) return;
    // find max
    int max = a[0], min = a[0];
    for(int i = 1; i < n; i++)
    {
        cmp++;
        if(++cmp && a[i] > max) max = a[i];
        if(++cmp && a[i] < min) min = a[i];
    }
    ++cmp;

    if(++cmp && max == min) return;
    // tạo bucket
    int m = n * 0.45;
    int* l = new int[m] {0};
    //tính số phần tử có trong mỗi bucket
    int c = (m-1)/(max - min);
    for(int i = 0; i < n; i++)
    {
        ++cmp;
        int k = c * (a[i] - min);
        ++l[k];
    }
    cmp++;
    // chuyển đổi l thành vị trí cuối cùng của mỗi bucket
    for(int i = 1; i < m; i++)
    {
        ++cmp;
        l[i] += l[i-1];
    }
    ++cmp;
    // sắp xếp bằng cách đổi chỗ cho các phần tử vào đúng vị trí của bucket
    int move = 0, j = 0, k = m - 1, t, flash;
    while(++cmp && (move < n - 1))
    {
        while(++cmp && (j > l[k] - 1))
        {
            j++;
            k = c * (a[j] - min);
        }
        flash = a[j];
        while(++cmp && (j != l[k]))
        {
            k = c * (flash - min);
            t = a[--l[k]];
            a[l[k]] = flash;
            flash = t;
            move++;
        }
        delete[] l;
    }
    // insertion sort
    for(int i = 1; i < n; i++)
    {
        ++cmp;
        int key = a[i];
        int j = i - 1;
        while((cmp+= 2) && (j >= 0) && (a[j] > key))
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
    ++cmp;
}

void flash_sort_time(int*& a, int n, double& dur)
{
    auto start = chrono::high_resolution_clock::now();
    flash_sort(a, n);
    auto end = chrono::high_resolution_clock::now();
    dur = chrono::duration<double, milli>(end - start).count();
}
