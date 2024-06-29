#pragma once

#include "..\sources\utilities.h"

void bubble_sort(int *&a, int size)
{
	bool changed;
	for (int i = 0; i < size - 1; ++i)
	{
		changed = false;
		for (int j = 0; j < size - i - 1; ++j)
		{
			if (a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
				changed = true;
			}
		}
		if (changed == false)
		{
			break;
		}
	}
}
void bubble_sort_cmp(int *&a, int size, long long &cmp)
{
	bool changed;
	cmp = 0;
	for (int i = 0; i < size; ++i)
	{
		++cmp;
		changed = false;
		for (int j = 0; j < size - i - 1; ++j)
		{
			++cmp;
			if (++cmp && (a[j] > a[j + 1]))
			{
				swap(a[j], a[j + 1]);
				changed = true;
			}
		}
		++cmp;
		if (++cmp && changed == false)
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