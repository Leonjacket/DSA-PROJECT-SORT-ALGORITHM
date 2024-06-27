#include <iostream>
#include <chrono>
#include <string>
#include <fstream>
using namespace std;

bool read_file(int*& a, int n, string file)
{
    ifstream in(file);
    if(!in.is_open())
    {
        cout << "Error! Can't open file\n";
        return false;
    }

    in >> n;
    for(int i = 0; i < n; i++)
        in >> a[i];
    return true;
}