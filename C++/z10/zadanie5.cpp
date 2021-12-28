#include <fstream>
#include <iostream>
#include <string>
#include <filesystem>
using namespace std;
namespace fs = filesystem;
 
int main()
{
    fs::path p="C:\\Projekty\\C++\\z10";
    int sum=0;
        try
        {
            for(const auto & asda : fs::recursive_directory_iterator(p))
            {
                if(fs::is_regular_file(asda))
                    sum += fs::file_size(asda);
            }
        }
        catch(const std::exception& e)
        {
            cout << "Folder nie istnieje" << endl;
        }   
    std::cout << sum;
}