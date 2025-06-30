#pragma once
#include <iostream>
#include <fstream>
#include <string>

class FileManagement 
{
private:
    std::fstream file;
    std::string filePath;
    std::ios::openmode mode;

public:
    FileManagement(const FileManagement&) = delete; 
    FileManagement(const std::string& path, std::ios::openmode mode = std::ios::in | std::ios::out);
    FileManagement(FileManagement&& other);
    
    FileManagement& operator=(const FileManagement&) = delete;
    FileManagement& operator=(FileManagement&& other) noexcept; 

    std::string readLine();
    void writeLine(const std::string& line);
};