#ifndef FILE_H
#define FILE_H

#include <string>

class File {
public:
    std::string name;
    bool isDirectory;
    std::string content;
};

#endif // FILE_H
