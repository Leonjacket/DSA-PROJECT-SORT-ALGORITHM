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
unordered_map<string, pair<sort_function_cmp, sort_function_time>> sort_map
{
    {"selection-sort", {selection_sort_cmp, selection_sort_time}},
    {"insertion-sort", {insertion_sort_cmp, insertion_sort_time}},
    {"bubble-sort", {bubble_sort_cmp, bubble_sort_time}},
    {"shaker-sort", {shaker_sort_cmp, shaker_sort_time}},
    {"shell-sort", {shell_sort_cmp, shell_sort_time}},
    {"quick-sort", {quick_sort_cmp, quick_sort_time}},
    {"heap-sort", {heap_sort_cmp, heap_sort_time}},
    {"merge-sort", {merge_sort_cmp, merge_sort_time}},
    {"radix-sort", {radix_sort_cmp, radix_sort_time}},
    {"flash-sort", {flash_sort_cmp, flash_sort_time}},
    {"counting-sort", {counting_sort_cmp, counting_sort_time}}
};
//https://www.geeksforgeeks.org/check-string-substring-another/
bool have_extension(string filename)
{
    if (filename.find(".txt") != string::npos || filename.find(".csv") != string::npos)
    {
        return filename.find(".txt");
    }
    return -1;
}

//if(argv[1] == "-a" && have_extension(filename) && argc == 5)
//này viết trong main ikkk, tại đang tách từng command thành từng hàm á
void command_line_1(int argc,char* argv[])
{
    if(argc < 5)
    {
        cout << "No command line arguments\n";
    }
    string algorithm = argv[2];
    string filename = argv[3];
    string output_parameter= argv[argc - 1];
    int* a;
    int size;
    int cmp = 0;
    double dur = 0;
    bool read = read_file(a, size, filename); //đọc file tạo mảng
    int *b = a;
    auto it = sort_map.find(algorithm);
    if(it != sort_map.end())
    {
        it->second.first(a, size, cmp);
        it->second.second(b, size, dur);
        saveFile(b); //tạo file output
    }   
    else
    {
        cout << "Invalid algorithm\n";
        return;
    }    
    cout << "AlGORITHM MODE\n"; 
    cout << "Algorithm: " << algorithm << endl;
    cout << "Input file: " << filename << endl;
    cout << "Input size: " << size << endl;
    cout << "------------------------" << endl;
    if(output_parameter == "-both")
    {
        cout << "Running time: " << dur << endl;
        cout << "Comparisons: " << cmp << endl;
    }
    else if(output_parameter == "-time")
    {
        cout << "Running time: " << dur << endl;
    }
    else if(output_parameter == "-comp")
    {
        cout << "Comparisons: " << cmp << endl;
    }
}
//command 2
//else if(argv[1] == "-a" && argc == 6)
void command_line_2(int argc,char* argv[])
{
    string algorithm = argv[2];
    string tmp = argv[3];
    int input_size = stoi(tmp);
    string input_order = argv[4];
    string output_parameter= argv[argc - 1];
    int* a;
    int cmp = 0;
    double dur = 0;
    auto it = sort_map.find(algorithm);
    if(it != sort_map.end())
    {
        if(input_order == "-rand")
        {
            GenerateData(a, input_size, 0);
            create_input_file(a); //tạo file input
            int* b =a;
            it->second.first(a, input_size, cmp);
            it->second.second(b, input_size, dur);
            saveFile(b); //tạo file output
        }
        if(input_order == "-sorted")
        {
            GenerateData(a, input_size, 1);
            saveFile(a); //tạo file input   
            int* b =a;
            it->second.first(a, input_size, cmp);
            it->second.second(b, input_size, dur);
            saveFile(b); //tạo file output
        }
        else if(input_order == "-rev")
        {
            GenerateData(a, input_size, 2);
            saveFile(a); //tạo file input
            int* b =a;
            it->second.first(a, input_size, cmp);
            it->second.second(b, input_size, dur);
            saveFile(b); //tạo file output
        }
        else if(input_order == "-nsorted")
        {
            GenerateData(a, input_size, 3);
            saveFile(a); //tạo file input
            int* b =a;
            it->second.first(a, input_size, cmp);
            it->second.second(b, input_size, dur);
            saveFile(b); //tạo file output
        }
    }
    cout << "AlGORITHM MODE\n";
    cout << "Algorithm: " << algorithm << endl;
    cout << "Input size: " << input_size << endl;
    cout << "Input order: " << input_order << endl;
    cout << "------------------------" << endl;
    if(output_parameter == "-both")
    {
        cout << "Running time: " << dur << endl;
        cout << "Comparisons: " << cmp << endl;
    }
    else if(output_parameter == "-time")
    {
        cout << "Running time: " << dur << endl;
    }
    else if(output_parameter == "-comp")
    {
        cout << "Comparisons: " << cmp << endl;
    }
}
//command 3
//int input_size = stoi(filename);
//else if(argv[1] == "-a" && have_extension(filename) == false && argc == 5)
void command_line_3(int argc,char* argv[])
{
    string algorithm = argv[2];
    string filename = argv[3];
    string output_parameter= argv[argc - 1];
    string filename_1 = "input_1.txt"; //random order data
    string filename_2 = "input_2.txt"; //nearly sorted data
    string filename_3 = "input_3.txt"; //sorted data
    string filename_4 = "input_4.txt"; //reversed data
    int *random;
    int *nearly_sorted;
    int *sorted;
    int *reversed;
    int size = stoi(argv[3]);
    GenerateData(random, size, 0);
    GenerateData(nearly_sorted, size, 3);
    GenerateData(sorted, size, 1);
    GenerateData(reversed, size, 2);
    writeFile(random, size, filename_1); //ghi file input sau khi generate
    writeFile(nearly_sorted, size, filename_2);
    writeFile(sorted, size, filename_3);
    writeFile(reversed, size, filename_4);
    int nearly_sorted_cmp = 0;
    double nearly_sorted_dur = 0;
    int random_cmp = 0;
    double random_dur = 0;
    int sorted_cmp = 0;
    double sorted_dur = 0;
    int reversed_cmp = 0;
    double reversed_dur = 0;
    auto it = sort_map.find(algorithm);
    if(it != sort_map.end())
    {
        int* a = random;
        int* a_1 = a;
        int* b = nearly_sorted;
        int* b_1 = b;
        int* c = sorted;
        int* c_1 = c;
        int* d = reversed;
        int* d_1 = d;
        it->second.first(a, size, random_cmp);
        it->second.second(a_1, size, random_dur);
        it->second.first(b, size, nearly_sorted_cmp);
        it->second.second(b_1, size, nearly_sorted_dur);
        it->second.first(c, size, sorted_cmp);
        it->second.second(c_1, size, sorted_dur);
        it->second.first(d, size, reversed_cmp);
        it->second.second(d_1, size, reversed_dur);
    }
    else
    {
        cout << "Invalid algorithm\n";
        return;
    }
    cout << "AlGORITHM MODE\n";
    cout << "Algorithm: " << algorithm << endl;
    cout << "Input size: " << size << endl;
    cout << "Input order: " << "Randomised" << endl;
    cout << "------------------------" << endl;
    if(output_parameter == "-both")
    {
        cout << "Running time: " << random_dur << endl;
        cout << "Comparisons: " << random_cmp << endl;
    }
    else if(output_parameter == "-time")
    {
        cout << "Running time: " << random_dur << endl;
    }
    else if(output_parameter == "-comp")
    {
        cout << "Comparisons: " << random_cmp << endl;
    }
    cout << endl;
    cout << "Input order: " << "Nearly sorted" << endl;
    cout << "------------------------" << endl;
    if(output_parameter == "-both")
    {
        cout << "Running time: " << nearly_sorted_dur << endl;
        cout << "Comparisons: " << nearly_sorted_cmp << endl;
    }
    else if(output_parameter == "-time")
    {
        cout << "Running time: " << nearly_sorted_dur << endl;
    }
    else if(output_parameter == "-comp")
    {
        cout << "Comparisons: " << nearly_sorted_cmp << endl;
    }
    cout << endl;
    cout << "Input order: " << "Sorted" << endl;
    cout << "------------------------" << endl;
    if(output_parameter == "-both")
    {
        cout << "Running time: " << sorted_dur << endl;
        cout << "Comparisons: " << sorted_cmp << endl;
    }
    else if(output_parameter == "-time")
    {
        cout << "Running time: " << sorted_dur << endl;
    }
    else if(output_parameter == "-comp")
    {
        cout << "Comparisons: " << sorted_cmp << endl;
    }
    cout << endl;
    cout << "Input order: " << "Reversed" << endl;
    cout << "------------------------" << endl;
    if(output_parameter == "-both")
    {
        cout << "Running time: " << reversed_dur << endl;
        cout << "Comparisons: " << reversed_cmp << endl;
    }
    else if(output_parameter == "-time")
    {
        cout << "Running time: " << reversed_dur << endl;
    }
    else if(output_parameter == "-comp")
    {
        cout << "Comparisons: " << reversed_cmp << endl;
    }
}

//command 4 
//if(argv[1] == "-c" && argc == 5)
void command_line_4(int argc, char* argv[])
{
    string algorithm_1 = argv[2];
    string algorithm_2 = argv[3];
    string filename = argv[4];
    int size;
    int *a;
    bool read = read_file(a, size, filename);//đọc file tạo mảng;
    int *arr_1 = a, *arr_2 = a;
    int *arr_1_1 = a, *arr_2_1 = a;
    int cmp_1, cmp_2;
    double dur_1, dur_2;
    auto it_1 = sort_map.find(algorithm_1);
    auto it_2 = sort_map.find(algorithm_2);
    if(it_1 != sort_map.end() && it_2 != sort_map.end())
    {
        it_1->second.first(a, size, cmp_1);
        it_1->second.second(arr_1_1, size, dur_1);
        it_2->second.first(a, size, cmp_2);
        it_2->second.second(arr_2_1, size, dur_2);
    }
    else
    {
        cout << "Invalid algorithm\n";
        return;
    }
    cout << "COMPARE MODE\n";
    cout << "Algorithm : " << algorithm_1 << " | " << algorithm_2 << endl;
    cout << "Input file: " << filename << endl;
    cout << "Input size: " << size << endl;
    cout << "------------------------" << endl;
    cout << "Running time: " << dur_1 << " | " << dur_2 << endl;
    cout << "Comparisons: " << cmp_1 << " | " << cmp_2 << endl;
}
//if(argv[1] == "-c" && argc == 6)
void command_line_5(int argc,char* argv[])
{
    string algorithm_1 = argv[2];
    string algorithm_2 = argv[3];
    string tmp = argv[4];
    int input_size = stoi(tmp);
    string input_order = argv[5];
    int *a;
    int *b = a;
    int cmp_1, cmp_2;
    double dur_1, dur_2;
    auto it_1 = sort_map.find(algorithm_1);
    auto it_2 = sort_map.find(algorithm_2);
    if(it_1 != sort_map.end() && it_2 != sort_map.end())
    {
        if(input_order == "-rand")
        {
            GenerateData(a, input_size, 0);
            saveFile(a); //tạo file input
            it_1->second.first(a, input_size, cmp_1);
            it_1->second.second(b, input_size, dur_1);
            it_2->second.first(a, input_size, cmp_2);
            it_2->second.second(b, input_size, dur_2);
        }
        if(input_order == "-sorted")
        {
            GenerateData(a, input_size, 1);
            saveFile(a); //tạo file input
            it_1->second.first(a, input_size, cmp_1);
            it_1->second.second(b, input_size, dur_1);
            it_2->second.first(a, input_size, cmp_2);
            it_2->second.second(b, input_size, dur_2);
        }
        else if(input_order == "-rev")
        {
            GenerateData(a, input_size, 2);
            saveFile(a); //tạo file input
            it_1->second.first(a, input_size, cmp_1);
            it_1->second.second(b, input_size, dur_1);
            it_2->second.first(a, input_size, cmp_2);
            it_2->second.second(b, input_size, dur_2);
        }
        else if(input_order == "-nsorted")
        {
            GenerateData(a, input_size, 3);
            saveFile(a); //tạo file input
            it_1->second.first(a, input_size, cmp_1);
            it_1->second.second(b, input_size, dur_1);
            it_2->second.first(a, input_size, cmp_2);
            it_2->second.second(b, input_size, dur_2);
        }
    }
    cout << "COMPARE MODE\n";
    cout << "Algorithm : " << algorithm_1 << " | " << algorithm_2 << endl;
    cout << "Input size: " << input_size << endl;
    cout << "Input order: " << input_order << endl;
    cout << "------------------------" << endl;
    cout << "Running time: " << dur_1 << " | " << dur_2 << endl;
    cout << "Comparisons: " << cmp_1 << " | " << cmp_2 << endl;
}