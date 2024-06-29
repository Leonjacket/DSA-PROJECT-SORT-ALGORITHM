#pragma once

#include ".\utilities.h"

bool read_file(int *&a, int& n, string file)
{
    ifstream in(file);
    if (!in.is_open())
    {
        cout << "Error! Can't open file\n";
        return false;
    }

    in >> n;
    a = new int[n];
    for (int i = 0; i < n; i++)
        in >> a[i];
    in.close();
    return true;
}