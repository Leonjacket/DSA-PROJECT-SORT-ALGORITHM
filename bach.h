#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <time.h>
using namespace std;
#ifndef _CLOCK_T
#define _CLOCK_T
typedef __darwin_clock_t clock_t;
#endif /* _CLOCK_T */
typedef unsigned long __darwin_clock_t; /* clock() */
#define CLOCKS_PER_SEC  1000000    /* [XSI] */

void selection_sort(int*& a, int n);

void selection_sort_cmp(int*& a, int n, int& cmp);

void selection_sort_time(int*& a, int n, int& dur);