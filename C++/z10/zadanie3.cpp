#include <iostream>
#include <chrono>
#include <iomanip>
#include <fstream>
#include <filesystem>

using namespace std;

namespace fs = filesystem;

int main(int argc, char* argv[])
{
    for(int i = 1; i < argc; i++)
    {
        if(fs::exists(argv[i]))
        {
            cout << "Ścieżka: " << fs::path(argv[i]) << endl;
            cout << "Rozmiar: " << fs::file_size(argv[i]) << endl;
            auto ftime = fs::last_write_time(argv[i]);
            std::time_t cftime = decltype(ftime)::clock::to_time_t(ftime);  
            std::cout << "Czas: " << std::asctime(std::localtime(&cftime)) << '\n';
        }
    }
}