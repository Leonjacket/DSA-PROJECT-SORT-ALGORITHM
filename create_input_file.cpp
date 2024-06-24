#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void createInputFile(int* a, int size, const char* inName){
    ofstream input(inName);
    if (!input){
        cerr << "Unable to open file!" << endl;
        return;
    }

    input << size << endl;

    for (int i = 0; i < size; i++){
        input << a[i] << " ";
    }
    input << endl;

    input.close();
}