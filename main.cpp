#include "sources/DataGenerator.cpp"
#include ".\methods\all.h"

int main(int argc, char *argv[])
{
    system("cls");
    if (argc < 2)
    {
        cerr << "Error: Not enough arguments provided." << endl;
        return 1;
    }

    string tmp = argv[1];
    if (argc >= 4)
    {
        string filename = argv[3];
    }

    if (argc >= 3)
    {
        string arg1 = argv[2];
    }

    if (tmp == "-a" && argc >= 4 && have_extension(argv[3]) && argc == 5)
    {
        command_line_1(argc, argv);
    }
    else if (tmp == "-a" && argc == 6)
    {
        command_line_2(argc, argv);
    }
    else if (tmp == "-a" && argc >= 4 && have_extension(argv[3]) == 0 && argc == 5)
    {
        command_line_3(argc, argv);
    }
    else if (tmp == "-c" && argc == 5)
    {
        command_line_4(argc, argv);
    }
    else if (tmp == "-c" && argc == 6)
    {
        command_line_5(argc, argv);
    }
    else
    {
        cerr << "Error: Invalid arguments provided." << endl;
        return 1;
    }

    return 0;
}
