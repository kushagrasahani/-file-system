#include "FileSystem.h"
#include <iostream>
#include <string>

int main() {
    FileSystem fs;
    std::string command;

    std::cout << "Welcome to the In-Memory File System!\n";

    while (true) {
        std::cout << fs.currentPath << "> ";
        std::getline(std::cin, command);

        // Check for the exit condition
        if (command == "exit") {
            std::cout << "Exiting the file system.\n";
            break;
        }

        // Execute the user command
        fs.executeCommand(command);
    }

    return 0;
}
