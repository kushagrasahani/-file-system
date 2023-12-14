#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <unordered_map>
#include <vector>
#include <string>

#include "File.h"

class FileSystem {
private:
    std::unordered_map<std::string, File> files;
    std::string currentPath;

public:
    FileSystem();

    // Function to execute a command
    void executeCommand(const std::string& command);

private:
    // Helper function to list the contents of a directory
    void listDirectory(const std::string& dirPath);

    // Bonus: Function to save the state of the file system
    void saveState(const std::vector<std::string>& tokens);

    // Bonus: Function to load the state of the file system
    void loadState(const std::vector<std::string>& tokens);

};

#endif // FILESYSTEM_H
