#pragma once

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <chrono>
#include <algorithm>

using namespace std;

void GenerateRandomData(int a[], int n);
void GenerateSortedData(int a[], int n);
void GenerateReverseData(int a[], int n);
void GenerateNearlySortedData(int a[], int n);
void GenerateData(int a[], int n, int dataType);

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}