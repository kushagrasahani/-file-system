# -file-system
Running Instructions:
Local Compilation:

Ensure you have CMake and a C++ compiler installed.
Create a new directory and place the source code files (File.h, FileSystem.h, ...), and CMakeLists.txt inside it.
Run the following commands in the terminal:

cmake .
make
./InMemoryFileSystem


Docker Container:

Make sure you have Docker installed.
Place the Dockerfile and source code files in a directory.
Navigate to the directory in the terminal.
Run the following commands:
docker build -t in-memory-file-system .
docker run -it in-memory-file-system

#GOOGLE DOC LINK
https://docs.google.com/document/d/1Us8Kl6BVnUiptYV1u8uJ0kpw0ytp8_ZUF-i_jSgR2Ag/edit?usp=sharing
