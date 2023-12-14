#include "FileSystem.h"
#include "DirectoryOperations.h"
#include "FileOperations.h"
#include <iostream>
#include <sstream>

FileSystem::FileSystem() {
    currentPath = "/";
}

void FileSystem::executeCommand(const std::string& command) {
    std::istringstream iss(command);
    std::vector<std::string> tokens{std::istream_iterator<std::string>{iss},
                                    std::istream_iterator<std::string>{}};

    if (tokens.empty()) {
        std::cerr << "Invalid command\n";
        return;
    }

    std::string cmd = tokens[0];

    if (cmd == "mkdir") {
        DirectoryOperations::mkdir(*this, tokens);
    } else if (cmd == "cd") {
        DirectoryOperations::cd(*this, tokens);
    } else if (cmd == "ls") {
        DirectoryOperations::ls(*this, tokens);
    }  else if (cmd == "cat") {
        FileOperations::cat(*this, tokens);
    } else if (cmd == "touch") {
        FileOperations::touch(*this, tokens);
    } else if (cmd == "echo") {
        FileOperations::echo(*this, tokens);
    }  else if (cmd == "saveState") {
        saveState(tokens);
    } else if (cmd == "loadState") {
        loadState(tokens);
    } else {
        std::cerr << "Unknown command: " << cmd << "\n";
    }
}

void FileSystem::listDirectory(const std::string& dirPath) {
    if (files.count(dirPath) > 0 && files[dirPath].isDirectory) {
        std::cout << "Contents of directory " << dirPath << ":\n";
        for (const auto& entry : files) {
            if (fs::path(entry.first).parent_path() == fs::path(dirPath)) {
                std::cout << "  " << entry.second.name << (entry.second.isDirectory ? "/" : "") << "\n";
            }
        }
    } else {
        std::cerr << "Invalid directory path.\n";
    }
}

void FileSystem::saveState(const std::vector<std::string>& tokens) {
    // Bonus: Implement saveState
    std::cout << "saveState functionality is not implemented (Bonus).\n";
}

void FileSystem::loadState(const std::vector<std::string>& tokens) {
    // Bonus: Implement loadState
    std::cout << "loadState functionality is not implemented (Bonus).\n";
}
