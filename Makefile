# Compiler
CXX = g++

# Compile flags
CPPFLAGS=-g

# Source files
SRCS = main.cpp camera.cpp matrix.cpp objects.cpp vec3.cpp

all: $(SRCS)
		$(CXX) $(SRCS) $(CPPFLAGS) -o main.exe