#pragma once
#include <iostream>
#include <string>
#include <chrono>
#include <algorithm>
#include "DataGenerator.cpp"
using namespace std;
void command_line_1(int argc,char* argv[]);
void command_line_2(int argc,char* argv[]);
void command_line_3(int argc,char* argv[]);
void command_line_4(int argc,char* argv[]);
void command_line_5(int argc,char* argv[]);
bool have_extension(string filename);
int partition(int* &a, int l, int r, int pivot); //hàm phụ cho quick sort
void quick_sort_algo(int *&a, int s, int e); //hàm phụ cho quick sort
void quick_sort(int *&a, int size); // tham khảo ở  https://youtu.be/pM-6r5xsNEY?si=U1rUfohX2kWGmz4M
void quick_sort_cmp(int *&a, int size, int &cmp); //hàm phụ cho quick sort cmp
void partition_cmp(int *&a, int l, int r, int e, int &cmp); //hàm phụ cho quick sort cmp
void quick_sort_time(int *&a, int size, int &dur);
int partition(int* &a, int l, int r, int pivot)
{
    while(l <= r)
    {
        while(a[l] < pivot)
        {
            l++;
        }
        while(a[r] > pivot)
        {
            r--;
        }
        if(l <= r)
        {
            swap(a[l], a[r]);
            l++;
            r--;
        }
    }
    return l;    
}
void quick_sort_algo(int *&a, int s, int e)
{
	if(s < e)
	{
		int mid = (s + e) / 2;
	    int pivot = a[mid];
	    int index = partition(a, s, e, pivot);
	    quick_sort_algo(a, s, index - 1);
	    quick_sort_algo(a, index, e);
	}
}
void quick_sort(int *&a, int size)
{
    quick_sort_algo(a, 0, size - 1);
}
int partition_cmp(int *&a, int l, int r, int pivot, int &cmp)
{
    while(++cmp && l <= r)
    {
        while(++cmp && a[l] < pivot)
        {
            l++;
        }
        while(++cmp && a[r] > pivot)
        {
            r--;
        }
        if(++cmp && l <= r)
        {
            swap(a[l], a[r]);
            l++;
            r--;
        }
    }   
    return l;
}
void quick_sort_algo_cmp(int *&a, int s, int e, int &cmp)
{
	if(s < e)
	{
	    int mid = (s + e) / 2;
	    int pivot = a[mid];
	    int index = partition_cmp(a, s, e, pivot, cmp);
	    quick_sort_algo_cmp(a, s, index - 1, cmp);
	    quick_sort_algo_cmp(a, index, e, cmp);
	}
}
void quick_sort_cmp(int *&a, int size, int &cmp)
{
    quick_sort_algo_cmp(a, 0, size - 1, cmp);
}
void quick_sort_time(int *&a, int size, int &dur)
{
    auto start = chrono::high_resolution_clock::now();
    quick_sort(a, size);
    auto end = chrono::high_resolution_clock::now();
    dur = chrono::duration<double, milli>(end - start).count();
}