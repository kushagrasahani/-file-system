# Use an official GCC runtime as a parent image
FROM gcc:latest

# Set the working directory to /app
WORKDIR /app

# Copy the current directory contents into the container at /app
COPY . /app

# Compile the code
RUN g++ -std=c++17 -o InMemoryFileSystem \
    FileSystem.cpp \
    DirectoryOperations.cpp \
    FileOperations.cpp \
    Main.cpp

# Make port 80 available to the world outside this container
EXPOSE 80

# Run the executable
CMD ["./InMemoryFileSystem"]
