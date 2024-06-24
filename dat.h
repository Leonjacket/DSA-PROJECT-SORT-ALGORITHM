#include <iostream>
#include <chrono>
using namespace std;

void inputArray(int* &a, int &n);
void printArray(int* a, int n);
void flash_sort(int*& a, int n);
void flash_sort_cmp(int*& a, int n, int& cmp);
void flash_sort_time(int*& a, int n, double& dur);
void shell_sort(int*& a, int n);
void shell_sort_cmp(int*& a, int n, int& cmp);
void shell_sort_time(int*& a, int n, float& dur);