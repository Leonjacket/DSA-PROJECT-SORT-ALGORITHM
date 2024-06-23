#include "header.h"

void merge(int l[], int r[], int a[], int size) {
    int leftSize = size / 2;
    int rightSize = size - leftSize;
    int i = 0, m = 0, n = 0;

    while (m < leftSize && n < rightSize) {
        if (l[m] < r[n]) {
            a[i++] = l[m++];
        } else {
            a[i++] = r[n++];
        }
    }

    while (m < leftSize) {
        a[i++] = l[m++];
    }

    while (n < rightSize) {
        a[i++] = r[n++];
    }
}

void mergeSort(int a[], int size) {
    if (size <= 1) return;

    int mid = size / 2;
    int* l = new int[mid];
    int* r = new int[size - mid];

    for (int i = 0; i < mid; i++) {
        l[i] = a[i];
    }

    for (int i = mid; i < size; i++) {
        r[i - mid] = a[i];
    }

    mergeSort(l, mid);
    mergeSort(r, size - mid);
    merge(l, r, a, size);

    delete[] l;
    delete[] r;
}

void sortFile(const char* inName, const char* outName) {
    ifstream inputFile(inName);
    if (!inputFile) {
        cerr << "Unable to open file: " << inName << endl;
        return;
    }

    int size;
    inputFile >> size;

    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        inputFile >> arr[i];
    }
    inputFile.close();

    mergeSort(arr, size);

    ofstream outputFile(outName);
    if (!outputFile) {
        cerr << "Unable to open file: " << outName << endl;
        delete[] arr;
        return;
    }

    for (int i = 0; i < size; i++) {
        outputFile << arr[i] << " ";
    }
    outputFile.close();

    delete[] arr;
}

// references : NCC ANT & Youtube: Bro Code