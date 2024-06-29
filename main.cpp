#include "sources/DataGenerator.cpp"
#include ".\methods\all.h"

int main(int argc, char* argv[])
{
    string tmp = argv[1];
    string filename = argv[3];
    string arg1 = argv[2];
    if(tmp == "-a" && have_extension(filename) && argc == 5)
    {
        command_line_1(argc, argv);
    }
    else if(tmp == "-a" && argc == 6)
    {
        command_line_2(argc, argv);
    }
    else if(tmp == "-a" && have_extension(filename) == 0 && argc == 5)
    {
        command_line_3(argc, argv);
    }
    else if(tmp == "-c" && argc == 5)
    {
        command_line_4(argc, argv);
    }
    else if(tmp == "-c" && argc == 6)
    {
        command_line_5(argc, argv);
    }
    return 0;
}