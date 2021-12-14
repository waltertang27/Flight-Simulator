
## Executable names:
EXENAME = routes
TEST = test

# Add all object files needed for compiling:
EXE_OBJ = main.o
OBJS = main.o #Point.o FloodFilledImage.o Animation.o

# Object Types
OBJS = main.o

# Compilation Flags
CXX = clang++
CXXFLAGS = $(CS225) -std=c++11 -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++11 -stdlib=libc++ -lc++abi -lm

# Custom Clang Enforcement
include make/customClangEnforcement.mk

# Define Makefile Rules
.PHONY: all test clean output_msg

all : $(EXENAME)

output_msg: ; $(CLANG_VERSION_MSG)

$(EXENAME): output_msg $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)

test: #output_msg catch/catchmain.cpp tests/tests.cpp airport.cc network.cc
	$(LD) catch/catchmain.cpp tests/tests.cpp $(LDFLAGS) -o test