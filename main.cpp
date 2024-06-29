#include "sources/DataGenerator.cpp"
#include ".\methods\all.h"

int main(int argc, char* argv[])
{
    string tmp = argv[1];
    string filename = argv[2];
    string arg1 = argv[2];
    cout << "Argument 2 received: " << arg1 << endl;
    if(tmp == "-a" && have_extension(filename) && argc == 5)
    {
        command_line_1(argc, argv);
    }
    else if(tmp == "-a" && argc == 6)
    {
        command_line_2(argc, argv);
    }
    else if(tmp == "-a" && have_extension(filename) == false && argc == 5)
    {
        cout << 3 << endl;
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