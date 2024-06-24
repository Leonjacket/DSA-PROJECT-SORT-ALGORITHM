#include <iostream>
#include <chrono>
using namespace std;

void insertion_sort(int a[], int n);
void insertion_sort_cmp(int a[], int n, int &cmp);

void insertion_sort_time(int *&a, int n, double &dur);