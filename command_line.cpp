#include "ngoc.h"
//https://www.geeksforgeeks.org/check-string-substring-another/
bool have_extension(string filename)
{
    if (filename.find(".txt") != string::npos || filename.find(".csv") != string::npos)
    {
        return filename.find(".txt");
    }
    return -1;
}
//if(n == "-a" && have_extension(filename) && argc == 5)
void command_line_1(int argc,char* argv[])
{
    if(argc < 5)
    {
        cout << "No command line arguments\n";
    }
    string n = argv[1];
    string algorithm = argv[2];
    string filename = argv[3];
    string output_parameter= argv[argc - 1];
        int* a;
        int size;
        int cmp = 0;
        double dur;
        //command 1
        if(algorithm == "selection-sort")
        {
            readFile(filename, a, size); // hàm đọc file
            int* b = a; 
            selection_sort_cmp(a, size, cmp); 
            dur = selection_sort_time(b, size);
            saveFile(b); //tạo file output
        }
        else if(algorithm == "insertion-sort")
        {
            readFile(filename, a, size); // hàm đọc file
            int* b = a; 
            insertion_sort_cmp(a, size, cmp); 
            dur = insertion_sort_time(b, size);
            saveFile(b); //tạo file output
        }
        else if(algorithm == "bubble-sort")
        {
            readFile(filename, a, size); // hàm đọc file
            int* b = a; 
            bubble_sort_cmp(a, size, cmp); 
            dur = bubble_sort_time(b, size);
            saveFile(b); //tạo file output
        }
        else if(algorithm == "shaker-sort")
        {
            readFile(filename, a, size); // hàm đọc file
            int* b = a; 
            shaker_sort_cmp(a, size, cmp); 
            dur = shaker_sort_time(b, size);
            saveFile(b); //tạo file output
        }
        else if(algorithm == "shell-sort")
        {
            readFile(filename, a, size); // hàm đọc file
            int* b = a; 
            shell_sort_comp(a, size, cmp); 
            dur = shell_sort_time(b, size);
            saveFile(b); //tạo file output
        }
        else if(algorithm == "heap-sort")
        {
            readFile(filename, a, size); // hàm đọc file
            int* b = a; 
            heap_sort_cmp(a, size, cmp); 
            dur = heap_sort_time(b, size);
            saveFile(b); //tạo file output
        }
        else if(algorithm == "merge-sort")
        {
            readFile(filename, a, size); // hàm đọc file
            int* b = a; 
            merge_sort_cmp(a, size, cmp); 
            dur = merge_sort_time(b, size);
            saveFile(b); //tạo file output
        }
        else if(algorithm == "quick-sort")
        {
            readFile(filename, a, size); // hàm đọc file
            int* b = a; 
            quick_sort_cmp(a, size, cmp); 
            dur = quick_sort_time(b, size);
            saveFile(b); //tạo file output
        }
        else if(algorithm == "counting-sort")
        {
            readFile(filename, a, size); // hàm đọc file
            int* b = a; 
            counting_sort_cmp(a, size, cmp); 
            dur = counting_sort_time(b, size);
            saveFile(b); //tạo file output
        
        }
        else if(algorithm == "radix-sort")
        {
            readFile(filename, a, size); // hàm đọc file
            int* b = a; 
            radix_sort_cmp(a, size, cmp); 
            dur = radix_sort_time(b, size);
            saveFile(b); //tạo file output
        }
        else if(algorithm == "flash-sort")
        {
            readFile(filename, a, size); // hàm đọc file
            int* b = a; 
            flash_sort_cmp(a, size, cmp); 
            dur = flash_sort_time(b, size);
            saveFile(b); //tạo file output
        }  
        cout << "AlGORITHM MODE\n";
        cout << "Algorithm: " << algorithm << endl;
        cout << "Input file: " << filename << endl;
        cout << "Output size: " << size << endl;
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
//else if(n == "-a" && argc == 6)
void command_line_2(int argc,char* argv[])
{
    string n = argv[1];
    string algorithm = argv[2];
    string tmp = argv[3];
    int input_size = stoi(tmp);
    string input_order = argv[4];
    string output_parameter= argv[argc - 1];
    int* a;
    a = new int[input_size];
    int *b = a;
    int cmp = 0;
    double dur = 0;
    if(input_order == "-rand")
    {
        GenerateData(a, input_size, 0);
        if(algorithm == "selection-sort")
        {
            selection_sort_cmp(a, input_size, cmp);
            dur = selection_sort_time(b, input_size);
            saveFile(b);
        }
        else if(algorithm == "insertion-sort")
        {
            insertion_sort_cmp(a, input_size, cmp);
            dur = insertion_sort_time(b, input_size);
            saveFile(b);
        }
        else if(algorithm == "bubble-sort")
        {
            bubble_sort_cmp(a, input_size, cmp);
            dur = bubble_sort_time(b, input_size);
            saveFile(b);
        }
        else if(algorithm == "shaker-sort")
        {
            shaker_sort_cmp(a, input_size, cmp);
            dur = shaker_sort_time(b, input_size);
            saveFile(b);
        }
        else if(algorithm == "shell-sort")
        {
            shell_sort_cmp(a, input_size, cmp);
            dur = shell_sort_time(b, input_size);
            saveFile(b);
        }
        else if(algorithm == "heap-sort")
        {
            heap_sort_cmp(a, input_size, cmp);
            dur = heap_sort_time(b, input_size);
            saveFile(b);
        }
        else if(algorithm == "merge-sort")
        {
            merge_sort_cmp(a, input_size, cmp);
            dur = merge_sort_time(b, input_size);
            saveFile(b);
        }
        else if(algorithm == "quick-sort")
        {
            quick_sort_cmp(a, input_size, cmp);
            dur = quick_sort_time(b, input_size);
            saveFile(b);
        }
        else if(algorithm == "counting-sort")
        {
            counting_sort_cmp(a, input_size, cmp);
            dur = counting_sort_time(b, input_size);
            saveFile(b);
        }
        else if(algorithm == "radix-sort")
        {
            radix_sort_cmp(a, input_size, cmp);
            dur = radix_sort_time(b, input_size);
            saveFile(b);
        }
        else if(algorithm == "flash-sort")
        {
            flash_sort_cmp(a, input_size, cmp);
            dur = flash_sort_time(b, input_size);
            saveFile(b);
        }
        cout << "AlGORITHM MODE\n"; 
        cout << "Algorithm: " << algorithm << endl;
        cout << "Input size: " << input_size << endl;
        cout << "Input order: Randomized" << endl;
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
    else if(input_order == "-nsorted")
    {
        GenerateData(a, input_size, 3);
        if(algorithm == "selection-sort")
        {
            selection_sort_cmp(a, input_size, cmp);
            dur = selection_sort_time(b, input_size);
            saveFile(b);
        }
        else if(algorithm == "insertion-sort")
        {
            insertion_sort_cmp(a, input_size, cmp);
            dur = insertion_sort_time(b, input_size);
            saveFile(b);
        }
        else if(algorithm == "bubble-sort")
        {
            bubble_sort_cmp(a, input_size, cmp);
            dur = bubble_sort_time(b, input_size);
            saveFile(b);
        }
        else if(algorithm == "shaker-sort")
        {
            shaker_sort_cmp(a, input_size, cmp);
            dur = shaker_sort_time(b, input_size);
            saveFile(b);
        }
        else if(algorithm == "shell-sort")
        {
            shell_sort_cmp(a, input_size, cmp);
            dur = shell_sort_time(b, input_size);
            saveFile(b);
        }
        else if(algorithm == "heap-sort")
        {
            heap_sort_cmp(a, input_size, cmp);
            dur = heap_sort_time(b, input_size);
            saveFile(b);
        }
        else if(algorithm == "merge-sort")
        {
            merge_sort_cmp(a, input_size, cmp);
            dur = merge_sort_time(b, input_size);
            saveFile(b);
        }
        else if(algorithm == "quick-sort")
        {
            quick_sort_cmp(a, input_size, cmp);
            dur = quick_sort_time(b, input_size);
            saveFile(b);
        }
        else if(algorithm == "counting-sort")
        {
            counting_sort_cmp(a, input_size, cmp);
            dur = counting_sort_time(b, input_size);
            saveFile(b);
        }
        else if(algorithm == "radix-sort")
        {
            radix_sort_cmp(a, input_size, cmp);
            dur = radix_sort_time(b, input_size);
            saveFile(b);
        }
        else if(algorithm == "flash-sort")
        {
            flash_sort_cmp(a, input_size, cmp);
            dur = flash_sort_time(b, input_size);
            saveFile(b);
        }
        cout << "AlGORITHM MODE\n"; 
        cout << "Algorithm: " << algorithm << endl;
        cout << "Input size: " << input_size << endl;
        cout << "Input order: Nearly sorted" << endl;
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
    else if(input_order == "-sorted")
    {
        GenerateData(a, input_size, 1);
        if(algorithm == "selection-sort")
        {
            selection_sort_cmp(a, input_size, cmp);
            dur = selection_sort_time(b, input_size);
            saveFile(b);
        }
        else if(algorithm == "insertion-sort")
        {
            insertion_sort_cmp(a, input_size, cmp);
            dur = insertion_sort_time(b, input_size);
            saveFile(b);
        }
        else if(algorithm == "bubble-sort")
        {
            bubble_sort_cmp(a, input_size, cmp);
            dur = bubble_sort_time(b, input_size);
            saveFile(b);
        }
        else if(algorithm == "shaker-sort")
        {
            shaker_sort_cmp(a, input_size, cmp);
            dur = shaker_sort_time(b, input_size);
            saveFile(b);
        }
        else if(algorithm == "shell-sort")
        {
            shell_sort_cmp(a, input_size, cmp);
            dur = shell_sort_time(b, input_size);
            saveFile(b);
        }
        else if(algorithm == "heap-sort")
        {
            heap_sort_cmp(a, input_size, cmp);
            dur = heap_sort_time(b, input_size);
            saveFile(b);
        }
        else if(algorithm == "merge-sort")
        {
            merge_sort_cmp(a, input_size, cmp);
            dur = merge_sort_time(b, input_size);
            saveFile(b);
        }
        else if(algorithm == "quick-sort")
        {
            quick_sort_cmp(a, input_size, cmp);
            dur = quick_sort_time(b, input_size);
            saveFile(b);
        }
        else if(algorithm == "counting-sort")
        {
            counting_sort_cmp(a, input_size, cmp);
            dur = counting_sort_time(b, input_size);
            saveFile(b);
        }
        else if(algorithm == "radix-sort")
        {
            radix_sort_cmp(a, input_size, cmp);
            dur = radix_sort_time(b, input_size);
            saveFile(b);
        }
        else if(algorithm == "flash-sort")
        {
            flash_sort_cmp(a, input_size, cmp);
            dur = flash_sort_time(b, input_size);
            saveFile(b);
        }
        cout << "AlGORITHM MODE\n"; 
        cout << "Algorithm: " << algorithm << endl;
        cout << "Input size: " << input_size << endl;
        cout << "Input order: Sorted" << endl;
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
    else if(input_order == "-rev")
    {
        GenerateData(a, input_size, 2);
        if(algorithm == "selection-sort")
        {
            selection_sort_cmp(a, input_size, cmp);
            dur = selection_sort_time(b, input_size);
            saveFile(b);
        }
        else if(algorithm == "insertion-sort")
        {
            insertion_sort_cmp(a, input_size, cmp);
            dur = insertion_sort_time(b, input_size);
            saveFile(b);
        }
        else if(algorithm == "bubble-sort")
        {
            bubble_sort_cmp(a, input_size, cmp);
            dur = bubble_sort_time(b, input_size);
            saveFile(b);
        }
        else if(algorithm == "shaker-sort")
        {
            shaker_sort_cmp(a, input_size, cmp);
            dur = shaker_sort_time(b, input_size);
            saveFile(b);
        }
        else if(algorithm == "shell-sort")
        {
            shell_sort_cmp(a, input_size, cmp);
            dur = shell_sort_time(b, input_size);
            saveFile(b);
        }
        else if(algorithm == "heap-sort")
        {
            heap_sort_cmp(a, input_size, cmp);
            dur = heap_sort_time(b, input_size);
            saveFile(b);
        }
        else if(algorithm == "merge-sort")
        {
            merge_sort_cmp(a, input_size, cmp);
            dur = merge_sort_time(b, input_size);
            saveFile(b);
        }
        else if(algorithm == "quick-sort")
        {
            quick_sort_cmp(a, input_size, cmp);
            dur = quick_sort_time(b, input_size);
            saveFile(b);
        }
        else if(algorithm == "counting-sort")
        {
            counting_sort_cmp(a, input_size, cmp);
            dur = counting_sort_time(b, input_size);
            saveFile(b);
        }
        else if(algorithm == "radix-sort")
        {
            radix_sort_cmp(a, input_size, cmp);
            dur = radix_sort_time(b, input_size);
            saveFile(b);
        }
        else if(algorithm == "flash-sort")
        {
            flash_sort_cmp(a, input_size, cmp);
            dur = flash_sort_time(b, input_size);
            saveFile(b);
        }
        cout << "AlGORITHM MODE\n"; 
        cout << "Algorithm: " << algorithm << endl;
        cout << "Input size: " << input_size << endl;
        cout << "Input order: Reversed" << endl;
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
}
//command 3
//else if(n == "-a" && have_extension(filename) == false && argc == 5)
void command_line_3(int argc,char* argv[])
{
    string n = argv[1];
    string algorithm = argv[2];
    string filename = argv[3];
    string output_parameter= argv[argc - 1];
    int input_size = stoi(filename);
    string filename_1 = "input_1.txt"; //random order data
    string filename_2 = "input_2.txt"; //nearly sorted data
    string filename_3 = "input_3.txt"; //sorted data
    string filename_4 = "input_4.txt"; //reversed data
    int *random;
    int *nearly_sorted;
    int *sorted;
    int *reversed;
    int size = stoi(filename);
    GenerateData(random, size, 0);
    GenerateData(nearly_sorted, size, 3);
    GenerateData(sorted, size, 1);
    GenerateData(reversed, size, 2);
    //selection sort
    if(algorithm == "selection-sort")
    {
        //random
        int cmp_random;
        double dur_random;
        selection_sort_cmp(random, size, cmp_random);
        dur_random = selection_sort_time(random, size);
        saveFile(random, filename_1);
        cout << "Algorithm: " << algorithm << endl;
        cout << "Input size: " << size << endl;
        cout << endl;
        cout << "Input order: Randomized" << endl;
        cout << "-------------------------------" << endl;
        if(output_parameter == "-both")
        {
            cout << "Running time: " << dur_random << endl;
            cout << "Comparisons: " << cmp_random << endl;
        }
        else if(output_parameter == "-comp")
        {
            cout << "Comparisons: " << cmp_random << endl;
        }
        else if(output_parameter == "-time")
        {
            cout << "Running time: " << dur_random << endl;
        }
        cout << "-------------------------------" << endl;
        cout << endl;
        //nearly sorted
        int cmp_nearly_sorted;
        double dur_nearly_sorted;
        selection_sort_cmp(nearly_sorted, size, cmp_nearly_sorted);
        dur_nearly_sorted = selection_sort_time(nearly_sorted, size);
        saveFile(nearly_sorted, filename_2);
        cout << "Input order: Nearly sorted" << endl;
        cout << "-------------------------------" << endl;
        if(output_parameter == "-both")
        {
            cout << "Running time: " << dur_nearly_sorted << endl;
            cout << "Comparisons: " << cmp_nearly_sorted << endl;
        }
        else if(output_parameter == "-comp")
        {
            cout << "Comparisons: " << cmp_nearly_sorted << endl;
        }
        else if(output_parameter == "-time")
        {
            cout << "Running time: " << dur_nearly_sorted << endl;
        }
        cout << "-------------------------------" << endl;
        cout << endl;
        //sorted
        int cmp_sorted;
        double dur_sorted;
        selection_sort_cmp(sorted, size, cmp_sorted);
        dur_sorted = selection_sort_time(sorted, size);
        saveFile(sorted, filename_3);
        cout << "Input order: Sorted" << endl;
        cout << "-------------------------------" << endl;
        if(output_parameter == "-both")
        {
            cout << "Running time: " << dur_sorted << endl;
            cout << "Comparisons: " << cmp_sorted << endl;
        }
        else if(output_parameter == "-comp")
        {
            cout << "Comparisons: " << cmp_sorted << endl;
        }
        else if(output_parameter == "-time")
        {
            cout << "Running time: " << dur_sorted << endl;
        }
        cout << "-------------------------------" << endl;
        cout << endl;
        //reversed
        int cmp_reversed;
        double dur_reversed;
        selection_sort_cmp(reversed, size, cmp_reversed);
        dur_reversed = selection_sort_time(reversed, size);
        saveFile(reversed, filename_4);
        cout << "Input order: Reversed" << endl;
        cout << "-------------------------------" << endl;
        if(output_parameter == "-both")
        {
            cout << "Running time: " << dur_reversed << endl;
            cout << "Comparisons: " << cmp_reversed << endl;
        }
        else if(output_parameter == "-comp")
        {
            cout << "Comparisons: " << cmp_reversed << endl;
        }
        else if(output_parameter == "-time")
        {
            cout << "Running time: " << dur_reversed << endl;
        }
    }
    //insertion sort
    if(algorithm == "insertion-sort")
    {
        //random
        int cmp_random;
        double dur_random;
        insertion_sort_cmp(random, size, cmp_random);
        dur_random = insertion_sort_time(random, size);
        saveFile(random, filename_1);
        cout << "Algorithm: " << algorithm << endl;
        cout << "Input size: " << size << endl;
        cout << endl;
        cout << "Input order: Randomized" << endl;
        cout << "-------------------------------" << endl;
        if(output_parameter == "-both")
        {
            cout << "Running time: " << dur_random << endl;
            cout << "Comparisons: " << cmp_random << endl;
        }
        else if(output_parameter == "-comp")
        {
            cout << "Comparisons: " << cmp_random << endl;
        }
        else if(output_parameter == "-time")
        {
            cout << "Running time: " << dur_random << endl;
        }
        cout << "-------------------------------" << endl;
        cout << endl;
        //nearly sorted
        int cmp_nearly_sorted;
        double dur_nearly_sorted;
        insertion_sort_cmp(nearly_sorted, size, cmp_nearly_sorted);
        dur_nearly_sorted = insertion_sort_time(nearly_sorted, size);
        saveFile(nearly_sorted, filename_2);
        cout << "Input order: Nearly sorted" << endl;
        cout << "-------------------------------" << endl;
        if(output_parameter == "-both")
        {
            cout << "Running time: " << dur_nearly_sorted << endl;
            cout << "Comparisons: " << cmp_nearly_sorted << endl;
        }
        else if(output_parameter == "-comp")
        {
            cout << "Comparisons: " << cmp_nearly_sorted << endl;
        }
        else if(output_parameter == "-time")
        {
            cout << "Running time: " << dur_nearly_sorted << endl;
        }
        cout << "-------------------------------" << endl;
        cout << endl;
        //sorted
        int cmp_sorted;
        double dur_sorted;
        insertion_sort_cmp(sorted, size, cmp_sorted);
        dur_sorted = insertion_sort_time(sorted, size);
        saveFile(sorted, filename_3);
        cout << "Input order: Sorted" << endl;
        cout << "-------------------------------" << endl;
        if(output_parameter == "-both")
        {
            cout << "Running time: " << dur_sorted << endl;
            cout << "Comparisons: " << cmp_sorted << endl;
        }
        else if(output_parameter == "-comp")
        {
            cout << "Comparisons: " << cmp_sorted << endl;
        }
        else if(output_parameter == "-time")
        {
            cout << "Running time: " << dur_sorted << endl;
        }
    //bubble sort
    if(algorithm == "bubble-sort")
    {
        //random
        int cmp_random;
        double dur_random;
        bubble_sort_cmp(random, size, cmp_random);
        dur_random = bubble_sort_time(random, size);
        saveFile(random, filename_1);
        cout << "Algorithm: " << algorithm << endl;
        cout << "Input size: " << size << endl;
        cout << endl;
        cout << "Input order: Randomized" << endl;
        cout << "-------------------------------" << endl;
        if(output_parameter == "-both")
        {
            cout << "Running time: " << dur_random << endl;
            cout << "Comparisons: " << cmp_random << endl;
        }
        else if(output_parameter == "-comp")
        {
            cout << "Comparisons: " << cmp_random << endl;
        }
        else if(output_parameter == "-time")
        {
            cout << "Running time: " << dur_random << endl;
        }
        cout << "-------------------------------" << endl;
        cout << endl;
        //nearly sorted
        int cmp_nearly_sorted;
        double dur_nearly_sorted;
        bubble_sort_cmp(nearly_sorted, size, cmp_nearly_sorted);
        dur_nearly_sorted = bubble_sort_time(nearly_sorted, size);
        saveFile(nearly_sorted, filename_2);
        cout << "Input order: Nearly sorted" << endl;
        cout << "-------------------------------" << endl;
        if(output_parameter == "-both")
        {
            cout << "Running time: " << dur_nearly_sorted << endl;
            cout << "Comparisons: " << cmp_nearly_sorted << endl;
        }
        else if(output_parameter == "-comp")
        {
            cout << "Comparisons: " << cmp_nearly_sorted << endl;
        }
        else if(output_parameter == "-time")
        {
            cout << "Running time: " << dur_nearly_sorted << endl;
        }
        cout << "-------------------------------" << endl;
        cout << endl;
        //sorted
        int cmp_sorted;
        double dur_sorted;
        bubble_sort_cmp(sorted, size, cmp_sorted);
        dur_sorted = bubble_sort_time(sorted, size);
        saveFile(sorted, filename_3);
        cout << "Input order: Sorted" << endl;
        cout << "-------------------------------" << endl;
        if(output_parameter == "-both")
        {
            cout << "Running time: " << dur_sorted << endl;
            cout << "Comparisons: " << cmp_sorted << endl;
        }
        else if(output_parameter == "-comp")
        {
            cout << "Comparisons: " << cmp_sorted << endl;
        }
        else if(output_parameter == "-time")
        {
            cout << "Running time: " << dur_sorted << endl;
        }
        cout << "-------------------------------" << endl;
        cout << endl;
        //reversed
        int cmp_reversed;
        double dur_reversed;
        bubble_sort_cmp(reversed, size, cmp_reversed);
        dur_reversed = bubble_sort_time(reversed, size);
        saveFile(reversed, filename_4);
        cout << "Input order: Reversed" << endl;
        cout << "-------------------------------" << endl;
        if(output_parameter == "-both")
        {
            cout << "Running time: " << dur_reversed << endl;
            cout << "Comparisons: " << cmp_reversed << endl;
        }
        else if(output_parameter == "-comp")
        {
            cout << "Comparisons: " << cmp_reversed << endl;
        }
        else if(output_parameter == "-time")
        {
            cout << "Running time: " << dur_reversed << endl;
        }
    }
    //shaker sort
    if(algorithm == "shaker-sort")
    {
        //random
        int cmp_random;
        double dur_random;
        shaker_sort_cmp(random, size, cmp_random);
        dur_random = shaker_sort_time(random, size);
        saveFile(random, filename_1);
        cout << "Algorithm: " << algorithm << endl;
        cout << "Input size: " << size << endl;
        cout << endl;
        cout << "Input order: Randomized" << endl;
        cout << "-------------------------------" << endl;
        if(output_parameter == "-both")
        {
            cout << "Running time: " << dur_random << endl;
            cout << "Comparisons: " << cmp_random << endl;
        }
        else if(output_parameter == "-comp")
        {
            cout << "Comparisons: " << cmp_random << endl;
        }
        else if(output_parameter == "-time")
        {
            cout << "Running time: " << dur_random << endl;
        }
        cout << "-------------------------------" << endl;
        cout << endl;
        //nearly sorted
        int cmp_nearly_sorted;
        double dur_nearly_sorted;
        shaker_sort_cmp(nearly_sorted, size, cmp_nearly_sorted);
        dur_nearly_sorted = shaker_sort_time(nearly_sorted, size);
        saveFile(nearly_sorted, filename_2);
        cout << "Input order: Nearly sorted" << endl;
        cout << "-------------------------------" << endl;
        if(output_parameter == "-both")
        {
            cout << "Running time: " << dur_nearly_sorted << endl;
            cout << "Comparisons: " << cmp_nearly_sorted << endl;
        }
        else if(output_parameter == "-comp")
        {
            cout << "Comparisons: " << cmp_nearly_sorted << endl;
        }
        else if(output_parameter == "-time")
        {
            cout << "Running time: " << dur_nearly_sorted << endl;
        }
        cout << "-------------------------------" << endl;
        cout << endl;
        //sorted
        int cmp_sorted;
        double dur_sorted;
        shaker_sort_cmp(sorted, size, cmp_sorted);
        dur_sorted = shaker_sort_time(sorted, size);
        saveFile(sorted, filename_3);
        cout << "Input order: Sorted" << endl;
        cout << "-------------------------------" << endl;
        if(output_parameter == "-both")
        {
            cout << "Running time: " << dur_sorted << endl;
            cout << "Comparisons: " << cmp_sorted << endl;
        }
        else if(output_parameter == "-comp")
        {
            cout << "Comparisons: " << cmp_sorted << endl;
        }
        else if(output_parameter == "-time")
        {
            cout << "Running time: " << dur_sorted << endl;
        }
        cout << "-------------------------------" << endl;
        cout << endl;
        //reversed
        int cmp_reversed;
        double dur_reversed;
        shaker_sort_cmp(reversed, size, cmp_reversed);
        dur_reversed = shaker_sort_time(reversed, size);
        saveFile(reversed, filename_4);
        cout << "Input order: Reversed" << endl;
        cout << "-------------------------------" << endl;
        if(output_parameter == "-both")
        {
            cout << "Running time: " << dur_reversed << endl;
            cout << "Comparisons: " << cmp_reversed << endl;
        }
        else if(output_parameter == "-comp")
        {
            cout << "Comparisons: " << cmp_reversed << endl;
        }
        else if(output_parameter == "-time")
        {
            cout << "Running time: " << dur_reversed << endl;
        }
    }
    //shell sort
    if(algorithm == "shell-sort")
    {
        //random
        int cmp_random;
        double dur_random;
        shell_sort_cmp(random, size, cmp_random);
        dur_random = shell_sort_time(random, size);
        saveFile(random, filename_1);
        cout << "Algorithm: " << algorithm << endl;
        cout << "Input size: " << size << endl;
        cout << endl;
        cout << "Input order: Randomized" << endl;
        cout << "-------------------------------" << endl;
        if(output_parameter == "-both")
        {
            cout << "Running time: " << dur_random << endl;
            cout << "Comparisons: " << cmp_random << endl;
        }
        else if(output_parameter == "-comp")
        {
            cout << "Comparisons: " << cmp_random << endl;
        }
        else if(output_parameter == "-time")
        {
            cout << "Running time: " << dur_random << endl;
        }
        cout << "-------------------------------" << endl;
        cout << endl;
        //nearly sorted
        int cmp_nearly_sorted;
        double dur_nearly_sorted;
        shell_sort_cmp(nearly_sorted, size, cmp_nearly_sorted);
        dur_nearly_sorted = shell_sort_time(nearly_sorted, size);
        saveFile(nearly_sorted, filename_2);
        cout << "Input order: Nearly sorted" << endl;
        cout << "-------------------------------" << endl;
        if(output_parameter == "-both")
        {
            cout << "Running time: " << dur_nearly_sorted << endl;
            cout << "Comparisons: " << cmp_nearly_sorted << endl;
        }
        else if(output_parameter == "-comp")
        {
            cout << "Comparisons: " << cmp_nearly_sorted << endl;
        }
        else if(output_parameter == "-time")
        {
            cout << "Running time: " << dur_nearly_sorted << endl;
        }
        cout << "-------------------------------" << endl;
        cout << endl;
        //sorted
        int cmp_sorted;
        double dur_sorted;
        shell_sort_cmp(sorted, size, cmp_sorted);
        dur_sorted = shell_sort_time(sorted, size);
        saveFile(sorted, filename_3);
        cout << "Input order: Sorted" << endl;
        cout << "-------------------------------" << endl;
        if(output_parameter == "-both")
        {
            cout << "Running time: " << dur_sorted << endl;
            cout << "Comparisons: " << cmp_sorted << endl;
        }
        else if(output_parameter == "-comp")
        {
            cout << "Comparisons: " << cmp_sorted << endl;
        }
        else if(output_parameter == "-time")
        {
            cout << "Running time: " << dur_sorted << endl;
        }
        cout << "-------------------------------" << endl;
        cout << endl;
        //reversed
        int cmp_reversed;
        double dur_reversed;
        shell_sort_cmp(reversed, size, cmp_reversed);
        dur_reversed = shell_sort_time(reversed, size);
        saveFile(reversed, filename_4);
        cout << "Input order: Reversed" << endl;
        cout << "-------------------------------" << endl;
        if(output_parameter == "-both")
        {
            cout << "Running time: " << dur_reversed << endl;
            cout << "Comparisons: " << cmp_reversed << endl;
        }
        else if(output_parameter == "-comp")
        {
            cout << "Comparisons: " << cmp_reversed << endl;
        }
        else if(output_parameter == "-time")
        {
            cout << "Running time: " << dur_reversed << endl;
        }
    }
    //heap sort
    if(algorithm == "heap-sort")
    {
        //random
        int cmp_random;
        double dur_random;
        heap_sort_cmp(random, size, cmp_random);
        dur_random = heap_sort_time(random, size);
        saveFile(random, filename_1);
        cout << "Algorithm: " << algorithm << endl;
        cout << "Input size: " << size << endl;
        cout << endl;
        cout << "Input order: Randomized" << endl;
        cout << "-------------------------------" << endl;
        if(output_parameter == "-both")
        {
            cout << "Running time: " << dur_random << endl;
            cout << "Comparisons: " << cmp_random << endl;
        }
        else if(output_parameter == "-comp")
        {
            cout << "Comparisons: " << cmp_random << endl;
        }
        else if(output_parameter == "-time")
        {
            cout << "Running time: " << dur_random << endl;
        }
        cout << "-------------------------------" << endl;
        cout << endl;
        //nearly sorted
        int cmp_nearly_sorted;
        double dur_nearly_sorted;
        heap_sort_cmp(nearly_sorted, size, cmp_nearly_sorted);
        dur_nearly_sorted = heap_sort_time(nearly_sorted, size);
        saveFile(nearly_sorted, filename_2);
        cout << "Input order: Nearly sorted" << endl;
        cout << "-------------------------------" << endl;
        if(output_parameter == "-both")
        {
            cout << "Running time: " << dur_nearly_sorted << endl;
            cout << "Comparisons: " << cmp_nearly_sorted << endl;
        }
        else if(output_parameter == "-comp")
        {
            cout << "Comparisons: " << cmp_nearly_sorted << endl;
        }
        else if(output_parameter == "-time")
        {
            cout << "Running time: " << dur_nearly_sorted << endl;
        }
        cout << "-------------------------------" << endl;
        cout << endl;
        //sorted
        int cmp_sorted;
        double dur_sorted;
        heap_sort_cmp(sorted, size, cmp_sorted);
        dur_sorted = heap_sort_time(sorted, size);
        saveFile(sorted, filename_3);
        cout << "Input order: Sorted" << endl;
        cout << "-------------------------------" << endl;
        if(output_parameter == "-both")
        {
            cout << "Running time: " << dur_sorted << endl;
            cout << "Comparisons: " << cmp_sorted << endl;
        }
        else if(output_parameter == "-comp")
        {
            cout << "Comparisons: " << cmp_sorted << endl;
        }
        else if(output_parameter == "-time")
        {
            cout << "Running time: " << dur_sorted << endl;
        }
        cout << "-------------------------------" << endl;
        cout << endl;
        //reversed
        int cmp_reversed;
        double dur_reversed;
        heap_sort_cmp(reversed, size, cmp_reversed);
        dur_reversed = heap_sort_time(reversed, size);
        saveFile(reversed, filename_4);
        cout << "Input order: Reversed" << endl;
        cout << "-------------------------------" << endl;
        if(output_parameter == "-both")
        {
            cout << "Running time: " << dur_reversed << endl;
            cout << "Comparisons: " << cmp_reversed << endl;
        }
        else if(output_parameter == "-comp")
        {
            cout << "Comparisons: " << cmp_reversed << endl;
        }
        else if(output_parameter == "-time")
        {
            cout << "Running time: " << dur_reversed << endl;
        }
    }
    //merge sort
    if(algorithm == "merge-sort")
    {
        //random
        int cmp_random;
        double dur_random;
        merge_sort_cmp(random, size, cmp_random);
        dur_random = merge_sort_time(random, size);
        saveFile(random, filename_1);
        cout << "Algorithm: " << algorithm << endl;
        cout << "Input size: " << size << endl;
        cout << endl;
        cout << "Input order: Randomized" << endl;
        cout << "-------------------------------" << endl;
        if(output_parameter == "-both")
        {
            cout << "Running time: " << dur_random << endl;
            cout << "Comparisons: " << cmp_random << endl;
        }
        else if(output_parameter == "-comp")
        {
            cout << "Comparisons: " << cmp_random << endl;
        }
        else if(output_parameter == "-time")
        {
            cout << "Running time: " << dur_random << endl;
        }
        cout << "-------------------------------" << endl;
        cout << endl;
        //nearly sorted
        int cmp_nearly_sorted;
        double dur_nearly_sorted;
        merge_sort_cmp(nearly_sorted, size, cmp_nearly_sorted);
        dur_nearly_sorted = merge_sort_time(nearly_sorted, size);
        saveFile(nearly_sorted, filename_2);
        cout << "Input order: Nearly sorted" << endl;
        cout << "-------------------------------" << endl;
        if(output_parameter == "-both")
        {
            cout << "Running time: " << dur_nearly_sorted << endl;
            cout << "Comparisons: " << cmp_nearly_sorted << endl;
        }
        else if(output_parameter == "-comp")
        {
            cout << "Comparisons: " << cmp_nearly_sorted << endl;
        }
        else if(output_parameter == "-time")
        {
            cout << "Running time: " << dur_nearly_sorted << endl;
        }
        cout << "-------------------------------" << endl;
        cout << endl;
        //sorted
        int cmp_sorted;
        double dur_sorted;
        merge_sort_cmp(sorted, size, cmp_sorted);
        dur_sorted = merge_sort_time(sorted, size);
        saveFile(sorted, filename_3);
        cout << "Input order: Sorted" << endl;
        cout << "-------------------------------" << endl;
        if(output_parameter == "-both")
        {
            cout << "Running time: " << dur_sorted << endl;
            cout << "Comparisons: " << cmp_sorted << endl;
        }
        else if(output_parameter == "-comp")
        {
            cout << "Comparisons: " << cmp_sorted << endl;
        }
        else if(output_parameter == "-time")
        {
            cout << "Running time: " << dur_sorted << endl;
        }
        cout << "-------------------------------" << endl;
        cout << endl;
        //reversed
        int cmp_reversed;
        double dur_reversed;
        merge_sort_cmp(reversed, size, cmp_reversed);
        dur_reversed = merge_sort_time(reversed, size);
        saveFile(reversed, filename_4);
        cout << "Input order: Reversed" << endl;
        cout << "-------------------------------" << endl;
        if(output_parameter == "-both")
        {
            cout << "Running time: " << dur_reversed << endl;
            cout << "Comparisons: " << cmp_reversed << endl;
        }
        else if(output_parameter == "-comp")
        {
            cout << "Comparisons: " << cmp_reversed << endl;
        }
        else if(output_parameter == "-time")
        {
            cout << "Running time: " << dur_reversed << endl;
        }
    }
    //quick sort
    if(algorithm == "quick-sort")
    {
        //random
        int cmp_random;
        double dur_random;
        quick_sort_cmp(random, size, cmp_random);
        dur_random = quick_sort_time(random, size);
        saveFile(random, filename_1);
        cout << "Algorithm: " << algorithm << endl;
        cout << "Input size: " << size << endl;
        cout << endl;
        cout << "Input order: Randomized" << endl;
        cout << "-------------------------------" << endl;
        if(output_parameter == "-both")
        {
            cout << "Running time: " << dur_random << endl;
            cout << "Comparisons: " << cmp_random << endl;
        }
        else if(output_parameter == "-comp")
        {
            cout << "Comparisons: " << cmp_random << endl;
        }
        else if(output_parameter == "-time")
        {
            cout << "Running time: " << dur_random << endl;
        }
        cout << "-------------------------------" << endl;
        cout << endl;
        //nearly sorted
        int cmp_nearly_sorted;
        double dur_nearly_sorted;
        quick_sort_cmp(nearly_sorted, size, cmp_nearly_sorted);
        dur_nearly_sorted = quick_sort_time(nearly_sorted, size);
        saveFile(nearly_sorted, filename_2);
        cout << "Input order: Nearly sorted" << endl;
        cout << "-------------------------------" << endl;
        if(output_parameter == "-both")
        {
            cout << "Running time: " << dur_nearly_sorted << endl;
            cout << "Comparisons: " << cmp_nearly_sorted << endl;
        }
        else if(output_parameter == "-comp")
        {
            cout << "Comparisons: " << cmp_nearly_sorted << endl;
        }
        else if(output_parameter == "-time")
        {
            cout << "Running time: " << dur_nearly_sorted << endl;
        }
        cout << "-------------------------------" << endl;
        cout << endl;
        //sorted
        int cmp_sorted;
        double dur_sorted;
        quick_sort_cmp(sorted, size, cmp_sorted);
        dur_sorted = quick_sort_time(sorted, size);
        saveFile(sorted, filename_3);
        cout << "Input order: Sorted" << endl;
        cout << "-------------------------------" << endl;
        if(output_parameter == "-both")
        {
            cout << "Running time: " << dur_sorted << endl;
            cout << "Comparisons: " << cmp_sorted << endl;
        }
        else if(output_parameter == "-comp")
        {
            cout << "Comparisons: " << cmp_sorted << endl;
        }
        else if(output_parameter == "-time")
        {
            cout << "Running time: " << dur_sorted << endl;
        }
        cout << "-------------------------------" << endl;
        cout << endl;
        //reversed
        int cmp_reversed;
        double dur_reversed;
        quick_sort_cmp(reversed, size, cmp_reversed);
        dur_reversed = quick_sort_time(reversed, size);
        saveFile(reversed, filename_4);
        cout << "Input order: Reversed" << endl;
        cout << "-------------------------------" << endl;
        if(output_parameter == "-both")
        {
            cout << "Running time: " << dur_reversed << endl;
            cout << "Comparisons: " << cmp_reversed << endl;
        }
        else if(output_parameter == "-comp")
        {
            cout << "Comparisons: " << cmp_reversed << endl;
        }
        else if(output_parameter == "-time")
        {
            cout << "Running time: " << dur_reversed << endl;
        }
    }
    //counting sort
    if(algorithm == "counting-sort")
    {
        //random
        int cmp_random;
        double dur_random;
        counting_sort_cmp(random, size, cmp_random);
        dur_random = counting_sort_time(random, size);
        saveFile(random, filename_1);
        cout << "Algorithm: " << algorithm << endl;
        cout << "Input size: " << size << endl;
        cout << endl;
        cout << "Input order: Randomized" << endl;
        cout << "-------------------------------" << endl;
        if(output_parameter == "-both")
        {
            cout << "Running time: " << dur_random << endl;
            cout << "Comparisons: " << cmp_random << endl;
        }
        else if(output_parameter == "-comp")
        {
            cout << "Comparisons: " << cmp_random << endl;
        }
        else if(output_parameter == "-time")
        {
            cout << "Running time: " << dur_random << endl;
        }
        cout << "-------------------------------" << endl;
        cout << endl;
        //nearly sorted
        int cmp_nearly_sorted;
        double dur_nearly_sorted;
        counting_sort_cmp(nearly_sorted, size, cmp_nearly_sorted);
        dur_nearly_sorted = counting_sort_time(nearly_sorted, size);
        saveFile(nearly_sorted, filename_2);
        cout << "Input order: Nearly sorted" << endl;
        cout << "-------------------------------" << endl;
        if(output_parameter == "-both")
        {
            cout << "Running time: " << dur_nearly_sorted << endl;
            cout << "Comparisons: " << cmp_nearly_sorted << endl;
        }
        else if(output_parameter == "-comp")
        {
            cout << "Comparisons: " << cmp_nearly_sorted << endl;
        }
        else if(output_parameter == "-time")
        {
            cout << "Running time: " << dur_nearly_sorted << endl;
        }
        cout << "-------------------------------" << endl;
        cout << endl;
        //sorted
        int cmp_sorted;
        double dur_sorted;
        counting_sort_cmp(sorted, size, cmp_sorted);
        dur_sorted = counting_sort_time(sorted, size);
        saveFile(sorted, filename_3);
        cout << "Input order: Sorted" << endl;
        cout << "-------------------------------" << endl;
        if(output_parameter == "-both")
        {
            cout << "Running time: " << dur_sorted << endl;
            cout << "Comparisons: " << cmp_sorted << endl;
        }
        else if(output_parameter == "-comp")
        {
            cout << "Comparisons: " << cmp_sorted << endl;
        }
        else if(output_parameter == "-time")
        {
            cout << "Running time: " << dur_sorted << endl;
        }
        cout << "-------------------------------" << endl;
        cout << endl;
        //reversed
        int cmp_reversed;
        double dur_reversed;
        counting_sort_cmp(reversed, size, cmp_reversed);
        dur_reversed = counting_sort_time(reversed, size);
        saveFile(reversed, filename_4);
        cout << "Input order: Reversed" << endl;
        cout << "-------------------------------" << endl;
        if(output_parameter == "-both")
        {
            cout << "Running time: " << dur_reversed << endl;
            cout << "Comparisons: " << cmp_reversed << endl;
        }
        else if(output_parameter == "-comp")
        {
            cout << "Comparisons: " << cmp_reversed << endl;
        }
        else if(output_parameter == "-time")
        {
            cout << "Running time: " << dur_reversed << endl;
        }
    }
    //radix sort
    if(algorithm == "radix-sort")
    {
        //random
        int cmp_random;
        double dur_random;
        radix_sort_cmp(random, size, cmp_random);
        dur_random = radix_sort_time(random, size);
        saveFile(random, filename_1);
        cout << "Algorithm: " << algorithm << endl;
        cout << "Input size: " << size << endl;
        cout << endl;
        cout << "Input order: Randomized" << endl;
        cout << "-------------------------------" << endl;
        if(output_parameter == "-both")
        {
            cout << "Running time: " << dur_random << endl;
            cout << "Comparisons: " << cmp_random << endl;
        }
        else if(output_parameter == "-comp")
        {
            cout << "Comparisons: " << cmp_random << endl;
        }
        else if(output_parameter == "-time")
        {
            cout << "Running time: " << dur_random << endl;
        }
        cout << "-------------------------------" << endl;
        cout << endl;
        //nearly sorted
        int cmp_nearly_sorted;
        double dur_nearly_sorted;
        radix_sort_cmp(nearly_sorted, size, cmp_nearly_sorted);
        dur_nearly_sorted = radix_sort_time(nearly_sorted, size);
        saveFile(nearly_sorted, filename_2);
        cout << "Input order: Nearly sorted" << endl;
        cout << "-------------------------------" << endl;
        if(output_parameter == "-both")
        {
            cout << "Running time: " << dur_nearly_sorted << endl;
            cout << "Comparisons: " << cmp_nearly_sorted << endl;
        }
        else if(output_parameter == "-comp")
        {
            cout << "Comparisons: " << cmp_nearly_sorted << endl;
        }
        else if(output_parameter == "-time")
        {
            cout << "Running time: " << dur_nearly_sorted << endl;
        }
        cout << "-------------------------------" << endl;
        cout << endl;
        //sorted
        int cmp_sorted;
        double dur_sorted;
        radix_sort_cmp(sorted, size, cmp_sorted);
        dur_sorted = radix_sort_time(sorted, size);
        saveFile(sorted, filename_3);
        cout << "Input order: Sorted" << endl;
        cout << "-------------------------------" << endl;
        if(output_parameter == "-both")
        {
            cout << "Running time: " << dur_sorted << endl;
            cout << "Comparisons: " << cmp_sorted << endl;
        }
        else if(output_parameter == "-comp")
        {
            cout << "Comparisons: " << cmp_sorted << endl;
        }
        else if(output_parameter == "-time")
        {
            cout << "Running time: " << dur_sorted << endl;
        }
        cout << "-------------------------------" << endl;
        cout << endl;
        //reversed
        int cmp_reversed;
        double dur_reversed;
        radix_sort_cmp(reversed, size, cmp_reversed);
        dur_reversed = radix_sort_time(reversed, size);
        saveFile(reversed, filename_4);
        cout << "Input order: Reversed" << endl;
        cout << "-------------------------------" << endl;
        if(output_parameter == "-both")
        {
            cout << "Running time: " << dur_reversed << endl;
            cout << "Comparisons: " << cmp_reversed << endl;
        }
        else if(output_parameter == "-comp")
        {
            cout << "Comparisons: " << cmp_reversed << endl;
        }
        else if(output_parameter == "-time")
        {
            cout << "Running time: " << dur_reversed << endl;
        }
    }
    //flash sort
    if(algorithm == "flash-sort")
    {
        //random
        int cmp_random;
        double dur_random;
        flash_sort_cmp(random, size, cmp_random);
        dur_random = flash_sort_time(random, size);
        saveFile(random, filename_1);
        cout << "Algorithm: " << algorithm << endl;
        cout << "Input size: " << size << endl;
        cout << endl;
        cout << "Input order: Randomized" << endl;
        cout << "-------------------------------" << endl;
        if(output_parameter == "-both")
        {
            cout << "Running time: " << dur_random << endl;
            cout << "Comparisons: " << cmp_random << endl;
        }
        else if(output_parameter == "-comp")
        {
            cout << "Comparisons: " << cmp_random << endl;
        }
        else if(output_parameter == "-time")
        {
            cout << "Running time: " << dur_random << endl;
        }
        cout << "-------------------------------" << endl;
        cout << endl;
        //nearly sorted
        int cmp_nearly_sorted;
        double dur_nearly_sorted;
        flash_sort_cmp(nearly_sorted, size, cmp_nearly_sorted);
        dur_nearly_sorted = flash_sort_time(nearly_sorted, size);
        saveFile(nearly_sorted, filename_2);
        cout << "Input order: Nearly sorted" << endl;
        cout << "-------------------------------" << endl;
        if(output_parameter == "-both")
        {
            cout << "Running time: " << dur_nearly_sorted << endl;
            cout << "Comparisons: " << cmp_nearly_sorted << endl;
        }
        else if(output_parameter == "-comp")
        {
            cout << "Comparisons: " << cmp_nearly_sorted << endl;
        }
        else if(output_parameter == "-time")
        {
            cout << "Running time: " << dur_nearly_sorted << endl;
        }
        cout << "-------------------------------" << endl;
        cout << endl;
        //sorted
        int cmp_sorted;
        double dur_sorted;
        flash_sort_cmp(sorted, size, cmp_sorted);
        dur_sorted = flash_sort_time(sorted, size);
        saveFile(sorted, filename_3);
        cout << "Input order: Sorted" << endl;
        cout << "-------------------------------" << endl;
        if(output_parameter == "-both")
        {
            cout << "Running time: " << dur_sorted << endl;
            cout << "Comparisons: " << cmp_sorted << endl;
        }
        else if(output_parameter == "-comp")
        {
            cout << "Comparisons: " << cmp_sorted << endl;
        }
        else if(output_parameter == "-time")
        {
            cout << "Running time: " << dur_sorted << endl;
        }
        cout << "-------------------------------" << endl;
        cout << endl;
        //reversed
        int cmp_reversed;
        double dur_reversed;
        flash_sort_cmp(reversed, size, cmp_reversed);
        dur_reversed = flash_sort_time(reversed, size);
        saveFile(reversed, filename_4);
        cout << "Input order: Reversed" << endl;
        cout << "-------------------------------" << endl;
        if(output_parameter == "-both")
        {
            cout << "Running time: " << dur_reversed << endl;
            cout << "Comparisons: " << cmp_reversed << endl;
        }
        else if(output_parameter == "-comp")
        {
            cout << "Comparisons: " << cmp_reversed << endl;
        }
        else if(output_parameter == "-time")
        {
            cout << "Running time: " << dur_reversed << endl;
        }
    }
}  
}  
//command 4 
//if(argv[1] == "c" && argc == 5)
void command_line_4(int argc, char* argv[])
{
    string algorithm_1 = argv[2];
    string algorithm_2 = argv[3];
    string filename = argv[4];
    int *arr_1, *arr_2;
    int size_1, size_2;
    int cmp_1, cmp_2;
    double dur_1, dur_2;
    //1
    if(algorithm_1 == "selection_sort")
    {
        readFile(filename, arr_1, size_1);
    }
    
}


