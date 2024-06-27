
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
void bubble_sort(int *&a, int size);
void bubble_sort_cmp(int *&a, int size, int &cmp); 
void bubble_sort_time(int *&a, int size, double &dur);

void bubble_sort(int *&a, int size)
{
	bool changed;
	for(int i = 0; i < size - 1; ++i)
	{
		changed = false;
		for(int j = 0; j < size - i - 1; ++j)
		{
			if(a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
				changed = true;
			}
		}
		if(changed == false)
		{
			break;
		}
	}
}
void bubble_sort_cmp(int *&a, int size, int &cmp)
{
    bool changed;
    cmp = 0;
	for(int i = 0; i < size; ++i)
	{ 
		++cmp;
		changed = false;
		for(int j = 0;j < size - i - 1; ++j)
		{
            ++cmp;
			if(++cmp && (a[j] > a[j + 1]))
			{
				swap(a[j], a[j + 1]);
				changed = true;
			}
		}
		++cmp;
		if(++cmp && changed == false) 
		{
			break;
		}
	}
	++cmp;
}
void bubble_sort_time(int *&a, int size, double &dur)
{
	auto start = chrono::high_resolution_clock::now();
    bubble_sort(a, size);
    auto end = chrono::high_resolution_clock::now();
    dur = chrono::duration<double, milli>(end - start).count();
}