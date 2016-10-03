##############################################################################
# M A K E F I L E
#
# NAME: Viatra
#
##############################################################################

##############################     Protobuf     ##############################
PROTOBUF_INCLUDE_DIR=D:\libraries\protobuf-3.0.0\src
##############################################################################


CXX=clang++
CXXWINFLAGS= -fms-compatibility-version=19.00 -Wno-microsoft-include
CXXFLAGS=-O0 -g -std=c++14 -Wall -Wextra -pedantic -fexceptions $(CXXWINFLAGS)
INCLUDEFLAGS=-I. -I../ -I$(PROTOBUF_INCLUDE_DIR)
LFLAGS=
MAKE=make
LIBS=

COMPILE=$(CXX) $(INCLUDEFLAGS) $(CXXFLAGS) -c -o $@ $<
LINK=$(CXX) $(LFLAGS) -o $@ $^ $(LIBS)

.SUFFIXES:
.SUFFIXES: .cpp .h .o

SOURCES := $(wildcard *.cpp) $(wildcard */*.cpp) $(wildcard */*/*.cpp)
HEADERS := $(wildcard *.h) $(wildcard */*.h) $(wildcard */*/*.h)
OBJECTS := $(SOURCES:%.cpp=%.o)

$(OBJECTS): %.o: %.cpp $(HEADERS)
		$(COMPILE)
				
.PHONY: all
all: $(SOURCES) $(OBJECTS)

.PHONY: clean
clean:
	rm -f $(OBJECTS) $(BINARY)
