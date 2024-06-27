#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool saveFile(int* a, unsigned long size, string inName){
    ofstream input(inName);
    if (!input){
        cerr << "Unable to open file!" << endl;
        return false;
    }

    input << size << endl;

    for (int i = 0; i < size; i++){
        input << a[i] << " ";
    }

    input.close();

    return true;
}