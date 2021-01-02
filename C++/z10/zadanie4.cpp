#include <iostream>
#include <filesystem>

using namespace std;

namespace fs = filesystem;

int main(int argc, char* argv[])
{
        try
        {
            for(const auto & f : fs::directory_iterator(argv[1]))
            {
                cout << f << endl;
            }
        }
        catch(const std::exception& e)
        {
            cout << "Folder nie istnieje" << endl;
        }
}