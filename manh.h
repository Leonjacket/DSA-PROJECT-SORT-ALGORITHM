#include <iostream>
#include <chrono>
using namespace std;

void count_sort(int a[], int n, int exp);
void radix_sort(int a[], int n);

void radix_sort_cmp(int a[], int n, int &cmp);

void radix_sort_time(int *&a, int n, double &dur);