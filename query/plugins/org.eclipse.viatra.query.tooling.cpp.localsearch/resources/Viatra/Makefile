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
SOURCES2 := $(subst /,_FD_,$(SOURCES))
OBJECTS := $(SOURCES2:%.cpp=../bin/%.o)

$(OBJECTS): ../bin/%.o: $(subst _FD_,/,%).cpp
		$(COMPILE)
		
$(BINARY): $(OBJECTS)
		$(LINK)
		
.PHONY: all
all: $(SOURCES) $(OBJECTS) $(BINARY)

.PHONY: clean
clean:
	rm -f $(OBJECTS) $(BINARY)
