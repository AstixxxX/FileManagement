#include "FileManagement.h"
#include <iostream>

int main()
{
    {
        FileManagement fm = FileManagement("./hello.txt", std::ios::out);
        fm.writeLine("Hello");
        fm.writeLine("World!!!");
    }
    
    FileManagement fm = FileManagement("./hello.txt", std::ios::in);
    std::cout << fm.readLine() << std::endl;
    std::cout << fm.readLine() << std::endl;
    
    return 0;
}