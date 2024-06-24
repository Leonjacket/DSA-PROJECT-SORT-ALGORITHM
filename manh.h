#include <iostream>
#include <chrono>
using namespace std;

void swap(int &a, int &b);

void heapify(int a[], int n, int i);
void heap_sort(int a[], int n);

void heapify_cmp(int a[], int n, int i, int &cmp);
void heap_sort_cmp(int a[], int n, int &cmp);

void heap_sort_time(int *&a, int n, double &dur);