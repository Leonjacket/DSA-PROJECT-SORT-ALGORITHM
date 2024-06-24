#include "ngoc.h"
void shaker_sort(int *&a, int size)
{
    int l = 0, r = size -1;
    while(l < r)
    {
        for(int j = l; j <= r - 1; ++j)
        {
            if(a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
            }
        }
        r--;
        for(int j = r; j >= l + 1; --j)
        {
            if(a[j] < a[j-1])
            {
                swap(a[j], a[j-1]);
            }
        }
        l++;
    }
}

void shaker_sort_cmp(int *&a, int size, int &cmp)
{
    int l = 0, r = size -1;
    cmp = 0;
    while(++cmp && l < r)
    {
        for(int j = l; j <= r - 1; ++j)
        {
        	++cmp;
            if(++cmp && a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
            }
        }
        ++cmp;
        r--;
        for(int j = r; j >= l + 1; --j)
        {
        	++cmp;
            if(++cmp && a[j] < a[j-1])
            {
                swap(a[j], a[j-1]);
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