#include "FileOperations.h"
#include <iostream>
#include <fstream>

void FileOperations::touch(FileSystem& fs, const std::vector<std::string>& tokens) {
    if (tokens.size() != 2) {
        std::cerr << "Invalid usage. Correct syntax: touch <file_name>\n";
        return;
    }

    std::string fileName = tokens[1];
    std::string filePath = fs.currentPath + fileName;

    if (fs.files.count(filePath) > 0) {
        std::cerr << "File already exists.\n";
        return;
    }

    File newFile;
    newFile.name = fileName;
    newFile.isDirectory = false;
    fs.files.insert({filePath, newFile});
    std::cout << "File created: " << filePath << "\n";
}

void FileOperations::echo(FileSystem& fs, const std::vector<std::string>& tokens) {
    if (tokens.size() < 4 || tokens[2] != ">") {
        std::cerr << "Invalid usage. Correct syntax: echo 'text' > file.txt\n";
        return;
    }

    std::string text = tokens[1];
    std::string filePath = fs.currentPath + tokens[3];

    if (fs.files.count(filePath) > 0 && !fs.files[filePath].isDirectory) {
        fs.files[filePath].content = text;
        std::cout << "Text written to file " << filePath << "\n";
    } else {
        std::cerr << "Invalid file path.\n";
    }
}

void FileOperations::cat(FileSystem& fs, const std::vector<std::string>& tokens) {
    if (tokens.size() != 2) {
        std::cerr << "Invalid usage. Correct syntax: cat <file_path>\n";
        return;
    }

    std::string filePath = fs.currentPath + tokens[1];

    if (fs.files.count(filePath) > 0 && !fs.files[filePath].isDirectory) {
        std::cout << "Contents of file " << filePath << ":\n";
        std::cout << fs.files[filePath].content << "\n";
    } else {
        std::cerr << "Invalid file path.\n";
    }
}
