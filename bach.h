#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
using namespace std;
#ifndef _CLOCK_T
#define _CLOCK_T
typedef __darwin_clock_t clock_t;
#endif /* _CLOCK_T */
typedef unsigned long __darwin_clock_t; /* clock() */
#define CLOCKS_PER_SEC  1000000    /* [XSI] */

void selectionSort(int arr, int n);

void sortFile(const char* inName, const char*outName);

void merge(int l[], int r[], int a[], int size);

void mergeSort(int a[], int size);

void sortFile(const char* inName, const char*outName);
