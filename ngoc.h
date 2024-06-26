#pragma once
#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <functional>
#include <chrono>
#include "DataGenerator.cpp"
using namespace std;
using sort_function_time = std::function<void(int*&, int, double&)>;
using sort_function_cmp = std::function<void(int*&, int, int&)>;
unordered_map<string, pair<sort_function_cmp, sort_function_time>> sort_map;
void command_line_1(int argc,char* argv[]);
void command_line_2(int argc,char* argv[]);
void command_line_3(int argc,char* argv[]);
void command_line_4(int argc,char* argv[]);
void command_line_5(int argc,char* argv[]);
bool have_extension(string filename);