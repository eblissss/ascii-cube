# Compiler
CXX = g++

# Compile flags
CPPFLAGS=-g

# Source files
SRCS = src/main.cpp src/camera.cpp src/matrix.cpp src/objects.cpp src/vec3.cpp

all: $(SRCS)
		$(CXX) $(SRCS) $(CPPFLAGS) -o main.exe