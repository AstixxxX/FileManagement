#include "FileManagement.h"

FileManagement::FileManagement(const std::string& path, std::ios::openmode mode) : filePath(path), mode(mode) 
{
    file.open(path, mode);

    if (!file.is_open()) 
        throw std::runtime_error("Failed to open file: " + path);
}

FileManagement::FileManagement(FileManagement&& other) : file(std::move(other.file)), filePath(std::move(other.filePath)), mode(other.mode) 
{
    other.mode = static_cast<std::ios::openmode>(0);
}

std::string FileManagement::readLine() 
{
    if (!(mode & std::ios::in)) 
        throw std::runtime_error("File not opened in read mode");
    
    std::string line;

    if (!std::getline(file, line)) 
    {
        if (file.eof()) 
            return ""; 
        
        throw std::runtime_error("Error reading from file");
    }

    return line;
}

void FileManagement::writeLine(const std::string& line) 
{
    if (!(mode & std::ios::out)) 
        throw std::runtime_error("File not opened in write mode");
    
    file << line << std::endl;

    if (file.fail()) 
        throw std::runtime_error("Error writing to file");
}

FileManagement& FileManagement::operator=(FileManagement&& other) noexcept 
{
    if (this != &other) 
    {
        file.close();
        file = std::move(other.file);
        filePath = std::move(other.filePath);
        mode = other.mode;
        other.mode = static_cast<std::ios::openmode>(0);
    }

    return *this;
}
