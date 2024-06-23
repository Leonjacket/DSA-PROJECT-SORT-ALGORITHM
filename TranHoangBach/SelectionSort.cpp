#include "header.h"

void selectionSort(int a[], int n){
    for (int i = 0; i < n - 1; i++){
        int min = i;
        for (int j = i + 1; j < n; j++){
            if (a[j] < a[min]){
                min = j;
            }
        }

        int tmp = a[min];
        a[min] = a[i];
        a[i] = tmp;
    }
}

void sortFile(const char* inName, const char* outName){
    ifstream inputFile(inName);
    if (!inputFile){
        cerr << "Unable to open file!";
        return;
    }

    int size;
    inputFile >> size;


    int* arr = new int[size];
    for (int i = 0; i < size; i++){
        inputFile >> arr[i];
    }
    inputFile.close();

    selectionSort(arr, size);

    ofstream outputFile(outName);
    if (!outputFile){
        cerr << "Unable to open file!";
        return;
    }

    for (int i = 0; i < size; i++) {
        outputFile << arr[i] << " ";
    }
    outputFile.close();

    delete[] arr;
}


// references: NCC ANT