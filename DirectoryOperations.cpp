#include "DirectoryOperations.h"
#include <iostream>

void DirectoryOperations::mkdir(FileSystem& fs, const std::vector<std::string>& tokens) {
     if (tokens.size() != 2) {
        std::cerr << "Invalid usage. Correct syntax: mkdir <directory_name>\n";
        return;
    }

    std::string dirName = tokens[1];
    std::string newPath = fs.currentPath + dirName;

    if (fs.files.count(newPath) > 0) {
        std::cerr << "Path already exists.\n";
        return;
    }

    File newFile;
    newFile.name = dirName;
    newFile.isDirectory = true;
    fs.files.insert({newPath, newFile});
    std::cout << "Directory created: " << newPath << "\n";
}

void DirectoryOperations::cd(FileSystem& fs, const std::vector<std::string>& tokens) {
    if (tokens.size() != 2) {
        std::cerr << "Invalid usage. Correct syntax: cd <directory_path>\n";
        return;
    }

    std::string newPath = tokens[1];

    if (newPath == "..") {
        // Move to the parent directory
        size_t found = fs.currentPath.find_last_of('/');
        if (found != std::string::npos) {
            fs.currentPath = fs.currentPath.substr(0, found);
        }
    } else if (newPath == "/") {
        // Move to the root directory
        fs.currentPath = "/";
    } else {
        // Move to the specified path
        std::string fullPath = fs.currentPath + newPath;
        if (fs.files.count(fullPath) > 0 && fs.files[fullPath].isDirectory) {
            fs.currentPath = fullPath;
        } else {
            std::cerr << "Invalid path.\n";
        }
    }

    std::cout << "Current directory: " << fs.currentPath << "\n";
}

void DirectoryOperations::ls(FileSystem& fs, const std::vector<std::string>& tokens) {
    if (tokens.size() == 1) {
        // List the contents of the current directory
        listDirectory(fs, fs.currentPath);
    } else if (tokens.size() == 2) {
        // List the contents of the specified directory
        std::string dirPath = tokens[1];
        listDirectory(fs, fs.currentPath + dirPath);
    } else {
        std::cerr << "Invalid usage. Correct syntax: ls [directory_path]\n";
    }
}

void DirectoryOperations::listDirectory(FileSystem& fs, const std::string& dirPath) {
    if (fs.files.count(dirPath) > 0 && fs.files[dirPath].isDirectory) {
        std::cout << "Contents of directory " << dirPath << ":\n";
        for (const auto& entry : fs.files) {
            if (fs::path(entry.first).parent_path() == fs::path(dirPath)) {
                std::cout << "  " << entry.second.name << (entry.second.isDirectory ? "/" : "") << "\n";
            }
        }
    } else {
        std::cerr << "Invalid directory path.\n";
    }
}
