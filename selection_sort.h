#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <chrono>
using namespace std;

void selection_sort(int*& a, int n);

void selection_sort_cmp(int*& a, int n, int& cmp);

void selection_sort_time(int*& a, int n, int& dur);