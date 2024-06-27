#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <chrono>
using namespace std;

void counting_sort(int*& arr, int n);

void counting_sort_cmp(int*& arr, int n, int& cmp);

void flash_sort_time(int*& a, int n, double& dur);