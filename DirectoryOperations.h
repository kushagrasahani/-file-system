#ifndef DIRECTORYOPERATIONS_H
#define DIRECTORYOPERATIONS_H

#include <vector>
#include <string>

#include "FileSystem.h"

class DirectoryOperations {
public:
    static void mkdir(FileSystem& fs, const std::vector<std::string>& tokens);
    static void cd(FileSystem& fs, const std::vector<std::string>& tokens);
    static void ls(FileSystem& fs, const std::vector<std::string>& tokens);
};

#endif // DIRECTORYOPERATIONS_H
