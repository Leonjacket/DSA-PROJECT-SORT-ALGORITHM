#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <chrono>
using namespace std;

void merge(int* l, int* r, int* a, int size);

void merge_sort(int* a, int size);

void merge_cmp(int* l, int* r, int* a, int size, int& cmp);

void merge_sort_cmp(int*& a, int size, int& cmp);

void merge_sort_time(int*& a, int size, int& dur);

