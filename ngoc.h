#pragma once
#include <iostream>
#include <string>
#include <time.h>
#include "DataGenerator.cpp"
using namespace std;
void command_line_1(int argc,char* argv[]);
void command_line_2(int argc,char* argv[]);
void command_line_3(int argc,char* argv[]);
void command_line_4(int argc,char* argv[]);
void command_line_5(int argc,char* argv[]);
bool have_extension(string filename);
void quick_sort(int *&a, int size);
void quick_sort_cmp(int *&a, int size, int &cmp);
double quick_sort_time(int *&a, int size, int &dur);