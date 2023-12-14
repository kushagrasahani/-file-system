cmake_minimum_required(VERSION 3.15)
project(InMemoryFileSystem)

set(CMAKE_CXX_STANDARD 17)

add_executable(InMemoryFileSystem
        File.h
        FileSystem.h
        FileSystem.cpp
        DirectoryOperations.h
        DirectoryOperations.cpp
        FileOperations.h
        FileOperations.cpp
        Main.cpp)

# If using GCC, uncomment the following line to enable filesystem support
# target_link_libraries(InMemoryFileSystem stdc++fs)
