#pragma once
#include <iostream>
#include <string>
#include <chrono>
#include <algorithm>
#include "DataGenerator.cpp"
using namespace std;
void command_line_1(int argc,char* argv[]);
void command_line_2(int argc,char* argv[]);
void command_line_3(int argc,char* argv[]);
void command_line_4(int argc,char* argv[]);
void command_line_5(int argc,char* argv[]);
bool have_extension(string filename);
int partition(int* &a, int l, int r, int pivot); //hàm phụ cho quick sort
void quick_sort_algo(int *&a, int s, int e); //hàm phụ cho quick sort
void quick_sort(int *&a, int size); // tham khảo ở  https://youtu.be/pM-6r5xsNEY?si=U1rUfohX2kWGmz4M
void quick_sort_cmp(int *&a, int size, int &cmp); //hàm phụ cho quick sort cmp
void partition_cmp(int *&a, int l, int r, int e, int &cmp); //hàm phụ cho quick sort cmp
void bubble_sort(int *&a, int size);
void bubble_sort_cmp(int *&a, int size, int &cmp); 
void bubble_sort_time(int *&a, int size, double &dur);
void shaker_sort(int *&a, int size); //tham khảo ở https://www.youtube.com/watch?v=dpSxj2Ps7DI
void shaker_sort_cmp(int *&a, int size, int &cmp);
void shaker_sort_time(int *&a, int size, double &dur);
