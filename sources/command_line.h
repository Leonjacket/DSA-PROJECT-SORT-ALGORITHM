#pragma once

#include "..\methods\all.h"
#include <map>
#include <unordered_map>
#include <functional>

using sort_function_time = std::function<void(int *&, int, double &)>;
using sort_function_cmp = std::function<void(int *&, int, int &)>;

void order(string tmp)
{
    if(tmp == "-rand")
        printf("Randomised\n");
    if(tmp == "-nsorted")
        printf("Nearly sorted data\n");
    if(tmp == "-sorted")
        printf("Sorted data\n");
    if(tmp == "-rev")
        printf("Reverse sorted data\n");
}

unordered_map<string, pair<sort_function_cmp, sort_function_time>> sort_map = {
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
    {"counting-sort", {counting_sort_cmp, counting_sort_time}}};
// https://www.geeksforgeeks.org/check-string-substring-another/

bool have_extension(string filename)
{
    if (filename.find(".txt") != string::npos || filename.find(".csv") != string::npos)
    {
        return filename.find(".txt");
    }
    return 0;
}

void command_line_1(int argc, char *argv[])
{
    if (argc < 5)
    {
        cout << "No command line arguments\n";
    }
    string algorithm = argv[2];
    string filename = argv[3];
    string output_parameter = argv[argc - 1];
    int *a;
    int size;
    int cmp = 0;
    double dur = 0.0;
    bool read = read_file(a, size, "input.txt");
    if(read == false)
    {
        cout << "Error reading file\n";
        return;
    }
    int *b = new int[size];
    copy(a,a+size,b);
    auto it = sort_map.find(algorithm);
    cout << "1";
    if (it != sort_map.end())
    {
        it->second.first(a, size, cmp);
        it->second.second(b, size, dur);
        bool save = save_file(b, size, "output.txt"); 
        if(save == false)
        {
            cout << "Error saving file\n";
            return;
        }
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
    if (output_parameter == "-both")
    {
        cout << "Running time: " << dur << endl;
        cout << "Comparisons: " << cmp << endl;
    }
    else if (output_parameter == "-time")
    {
        cout << "Running time: " << dur << endl;
    }
    else if (output_parameter == "-comp")
    {
        cout << "Comparisons: " << cmp << endl;
    }
    delete[] a; delete[] b;
}
// command 2
// else if(argv[1] == "-a" && argc == 6)
void command_line_2(int argc, char *argv[])
{
    if (argc < 6)
    {
        cout << "Not enough command line arguments\n";
        return;
    }
    string algorithm = argv[2];
    string tmp = argv[3];
    int input_size = stoi(tmp);
    string input_order = argv[4];
    string output_parameter = argv[argc - 1];
    int *a = new int[input_size];
    int cmp = 0;
    double dur = 0.0;
    auto it = sort_map.find(algorithm);
    if (it != sort_map.end())
    {
        if (input_order == "-rand")
        {
            GenerateData(a, input_size, 0);
            bool save = save_file(a, input_size, "input.txt"); 
            if(save == false)
            {
                cout << "Error saving file\n";
                return;
            }
            int *b = new int[input_size];
            for(int i = 0; i < input_size; i++)
            {
                b[i] = a[i];
            }
            it->second.first(a, input_size, cmp);
            it->second.second(b, input_size, dur);
            bool save_b = save_file(b, input_size, "output.txt"); 
            if(save_b == false)
            {
                cout << "Error saving file\n";
                return;
            }
            delete[] b;
        }
        if (input_order == "-sorted")
        {
            GenerateData(a, input_size, 1);
            bool save = save_file(a, input_size, "input.txt"); 
            if(save == false)
            {
                cout << "Error saving file\n";
                return;
            }
            int *b = new int[input_size];
            for(int i = 0; i < input_size; i++)
            {
                b[i] = a[i];
            }
            it->second.first(a, input_size, cmp);
            it->second.second(b, input_size, dur);
            bool save_b = save_file(b, input_size, "output.txt"); 
            if(save_b == false)
            {
                cout << "Error saving file\n";
                return;
            }
            delete[] b;
        }
        else if (input_order == "-rev")
        {
            GenerateData(a, input_size, 2);
            bool save = save_file(a, input_size, "input.txt");
            if(save == false)
            {
                cout << "Error saving file\n";
                return;
            }
            int *b = new int[input_size];
            for(int i = 0; i < input_size; i++)
            {
                b[i] = a[i];
            }
            it->second.first(a, input_size, cmp);
            it->second.second(b, input_size, dur);
            bool save_b = save_file(b, input_size, "output.txt");
            if(save_b == false)
            {
                cout << "Error saving file\n";
                return;
            }
            delete[] b;
        }
        else if (input_order == "-nsorted")
        {
            GenerateData(a, input_size, 3);
            bool save = save_file(a, input_size, "input.txt");
            if(save == false)
            {
                cout << "Error saving file\n";
                return;
            }
            int *b = new int[input_size];
            for(int i = 0; i < input_size; i++)
            {
                b[i] = a[i];
            }
            it->second.first(a, input_size, cmp);
            it->second.second(b, input_size, dur);
            bool save_b = save_file(b, input_size, "output.txt"); 
            if(save_b == false)
            {
                cout << "Error saving file\n";
                return;
            }
            delete[] b;
        }
    }
    cout << "AlGORITHM MODE\n";
    cout << "Algorithm: " << algorithm << endl;
    cout << "Input size: " << input_size << endl;
    cout << "Input order: "; order(input_order);
    cout << "------------------------" << endl;
    if (output_parameter == "-both")
    {
        cout << "Running time: " << dur << endl;
        cout << "Comparisons: " << cmp << endl;
    }
    else if (output_parameter == "-time")
    {
        cout << "Running time: " << dur << endl;
    }
    else if (output_parameter == "-comp")
    {
        cout << "Comparisons: " << cmp << endl;
    }
    delete[] a;
}
// command 3
// int input_size = stoi(filename);
// else if(argv[1] == "-a" && have_extension(filename) == false && argc == 5)
void command_line_3(int argc, char *argv[])
{
    string algorithm = argv[2];
    string tmp = argv[3];
    string output_parameter = argv[argc - 1];
    int size = stoi(argv[3]);
    string filename_1 = "input_1.txt"; // random order data
    string filename_2 = "input_2.txt"; // nearly sorted data
    string filename_3 = "input_3.txt"; // sorted data
    string filename_4 = "input_4.txt"; // reversed data
    int *random = new int[size];
    int *nearly_sorted = new int[size];
    int *sorted = new int[size];
    int *reversed = new int[size];
    GenerateData(random, size, 0);
    GenerateData(nearly_sorted, size, 3);
    GenerateData(sorted, size, 1);
    GenerateData(reversed, size, 2);
    bool save_1 = save_file(random, size, filename_1); 
    
    bool save_2 = save_file(nearly_sorted, size, filename_2);
    
    bool save_3 = save_file(sorted, size, filename_3);
    
    bool save_4 = save_file(reversed, size, filename_4);
    
    if(save_1 == false || save_2 == false || save_3 == false || save_4 == false)
    {
        cout << "Error saving file\n";
        return;
    }
    int nearly_sorted_cmp = 0;
    double nearly_sorted_dur = 0.0;
    int random_cmp = 0;
    double random_dur = 0.0;
    int sorted_cmp = 0;
    double sorted_dur = 0.0;
    int reversed_cmp = 0;
    double reversed_dur = 0.0;
    auto it = sort_map.find(algorithm);
    if (it != sort_map.end())
    {
        int *a = new int[size];
        for(int i = 0; i < size; i++)
        {
            a[i] = random[i];
        }
        int *b = new int[size];
        for(int i = 0; i < size; i++)
        {
            b[i] = nearly_sorted[i];
        }
        int *c = new int[size];
        for(int i = 0; i < size; i++)
        {
            c[i] = sorted[i];
        }
        int *d = new int[size];
        for(int i = 0; i < size; i++)
        {
            d[i] = reversed[i];
        }
        it->second.first(a, size, random_cmp);
        delete[] a;
        it->second.second(random, size, random_dur);
        delete[] random;
        it->second.first(b, size, nearly_sorted_cmp);
        delete[] b;
        it->second.second(nearly_sorted, size, nearly_sorted_dur);
        delete[] nearly_sorted;
        it->second.first(c, size, sorted_cmp);
        delete[] c;
        it->second.second(sorted, size, sorted_dur);
        delete[] sorted;
        it->second.first(d, size, reversed_cmp);
        delete[] d;
        it->second.second(reversed, size, reversed_dur);
        delete[] reversed;
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
    if (output_parameter == "-both")
    {
        cout << "Running time: " << random_dur << endl;
        cout << "Comparisons: " << random_cmp << endl;
    }
    else if (output_parameter == "-time")
    {
        cout << "Running time: " << random_dur << endl;
    }
    else if (output_parameter == "-comp")
    {
        cout << "Comparisons: " << random_cmp << endl;
    }
    cout << endl;
    cout << "Input order: " << "Nearly sorted" << endl;
    cout << "------------------------" << endl;
    if (output_parameter == "-both")
    {
        cout << "Running time: " << nearly_sorted_dur << endl;
        cout << "Comparisons: " << nearly_sorted_cmp << endl;
    }
    else if (output_parameter == "-time")
    {
        cout << "Running time: " << nearly_sorted_dur << endl;
    }
    else if (output_parameter == "-comp")
    {
        cout << "Comparisons: " << nearly_sorted_cmp << endl;
    }
    cout << endl;
    cout << "Input order: " << "Sorted" << endl;
    cout << "------------------------" << endl;
    if (output_parameter == "-both")
    {
        cout << "Running time: " << sorted_dur << endl;
        cout << "Comparisons: " << sorted_cmp << endl;
    }
    else if (output_parameter == "-time")
    {
        cout << "Running time: " << sorted_dur << endl;
    }
    else if (output_parameter == "-comp")
    {
        cout << "Comparisons: " << sorted_cmp << endl;
    }
    cout << endl;
    cout << "Input order: " << "Reversed" << endl;
    cout << "------------------------" << endl;
    if (output_parameter == "-both")
    {
        cout << "Running time: " << reversed_dur << endl;
        cout << "Comparisons: " << reversed_cmp << endl;
    }
    else if (output_parameter == "-time")
    {
        cout << "Running time: " << reversed_dur << endl;
    }
    else if (output_parameter == "-comp")
    {
        cout << "Comparisons: " << reversed_cmp << endl;
    }
    delete[] random; delete[] nearly_sorted; delete[] sorted; delete[] reversed;
}

// command 4
// if(argv[1] == "-c" && argc == 5)
void command_line_4(int argc, char *argv[])
{
    string algorithm_1 = argv[2];
    string algorithm_2 = argv[3];
    string filename = argv[4];
    int size;
    int *a;
    bool read = read_file(a, size, filename); // d?c file t?o m?ng;
    if(read == false)
    {
        cout << "Error reading file\n";
        return;
    }
    int *arr_1 = new int[size];
    int *arr_2 = new int[size];
    for(int i = 0; i < size; i++)
    {
        arr_1[i] = a[i];
        arr_2[i] = a[i];
    }
    int *arr_1_1 = new int[size];
    int *arr_2_1 = new int[size];
    for(int i = 0; i < size; i++)
    {
        arr_1_1[i] = a[i];
        arr_2_1[i] = a[i];
    }
    int cmp_1 = 0, cmp_2 = 0;
    double dur_1 = 0.0, dur_2 = 0.0;
    auto it_1 = sort_map.find(algorithm_1);
    auto it_2 = sort_map.find(algorithm_2);
    if (it_1 != sort_map.end() && it_2 != sort_map.end())
    {
        it_1->second.first(arr_1, size, cmp_1);
        it_1->second.second(arr_1_1, size, dur_1);
        it_2->second.first(arr_2, size, cmp_2);
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
    delete[] arr_1; delete[] arr_2; delete[] arr_1_1; delete[] arr_2_1;
}
// if(argv[1] == "-c" && argc == 6)
void command_line_5(int argc, char *argv[])
{
    string algorithm_1 = argv[2];
    string algorithm_2 = argv[3];
    string tmp = argv[4];
    int input_size = stoi(tmp);
    string input_order = argv[5];
    int *a = new int[input_size];
    int cmp_1, cmp_2;
    double dur_1, dur_2;
    auto it_1 = sort_map.find(algorithm_1);
    auto it_2 = sort_map.find(algorithm_2);
    if (it_1 != sort_map.end() && it_2 != sort_map.end())
    {
        if (input_order == "-rand")
        {
            GenerateData(a, input_size, 0);
            int *b = new int[input_size];
            int *arr_1 = new int[input_size];
            int *arr_2 = new int[input_size];
            for(int i = 0; i < input_size; i++)
            {
                b[i] = a[i];
                arr_1[i] = a[i];
                arr_2[i] = a[i];
            } 
            bool save =  save_file(a, input_size, "input.txt");
            if(save == false)
            {
                cout << "Error saving file\n";
                return;
            }
            it_1->second.first(a, input_size, cmp_1);
            it_1->second.second(b, input_size, dur_1);
            it_2->second.first(arr_1, input_size, cmp_2);
            it_2->second.second(arr_2, input_size, dur_2);
            delete[] b; delete[] arr_1; delete[] arr_2;
        }
        if (input_order == "-sorted")
        {
            GenerateData(a, input_size, 1);
            int *b = new int[input_size];
            int *arr_1 = new int[input_size];
            int *arr_2 = new int[input_size];
            for(int i = 0; i < input_size; i++)
            {
                b[i] = a[i];
                arr_1[i] = a[i];
                arr_2[i] = a[i];
            } 
            bool save = save_file(a, input_size, "input.txt");
            if(save == false)
            {
                cout << "Error saving file\n";
                return;
            }
            it_1->second.first(a, input_size, cmp_1);
            it_1->second.second(b, input_size, dur_1);
            it_2->second.first(a, input_size, cmp_2);
            it_2->second.second(b, input_size, dur_2);
            delete[] b; delete[] arr_1; delete[] arr_2;
        }
        else if (input_order == "-rev")
        {
            GenerateData(a, input_size, 2);
            int *b = new int[input_size];
            int *arr_1 = new int[input_size];
            int *arr_2 = new int[input_size];
            for(int i = 0; i < input_size; i++)
            {
                b[i] = a[i];
                arr_1[i] = a[i];
                arr_2[i] = a[i];
            } 
            bool save = save_file(a, input_size, "input.txt"); 
            if(save == false)
            {
                cout << "Error saving file\n";
                return;
            }
            it_1->second.first(a, input_size, cmp_1);
            it_1->second.second(b, input_size, dur_1);
            it_2->second.first(a, input_size, cmp_2);
            it_2->second.second(b, input_size, dur_2);
            delete[] b; delete[] arr_1; delete[] arr_2;
        }
        else if (input_order == "-nsorted")
        {
            GenerateData(a, input_size, 3);
            int *b = new int[input_size];
            int *arr_1 = new int[input_size];
            int *arr_2 = new int[input_size];
            for(int i = 0; i < input_size; i++)
            {
                b[i] = a[i];
                arr_1[i] = a[i];
                arr_2[i] = a[i];
            } 
            bool save = save_file(a, input_size, "input.txt");
            if(save == false)
            {
                cout << "Error saving file\n";
                return;
            }
            it_1->second.first(a, input_size, cmp_1);
            it_1->second.second(b, input_size, dur_1);
            it_2->second.first(a, input_size, cmp_2);
            it_2->second.second(b, input_size, dur_2);
            delete[] b; delete[] arr_1; delete[] arr_2;
        }
    }
    cout << endl;
    cout << "COMPARE MODE\n";
    cout << "Algorithm : " << algorithm_1 << " | " << algorithm_2 << endl;
    cout << "Input size: " << input_size << endl;
    cout << "Input order: "; order(input_order);
    cout << "------------------------" << endl;
    cout << "Running time: " << dur_1 << " | " << dur_2 << endl;
    cout << "Comparisons: " << cmp_1 << " | " << cmp_2 << endl;
    delete[] a;
}
