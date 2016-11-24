##############################################################################
# M A K E F I L E
#
# NAME: Arch
#
##############################################################################

CXX=clang++
CXXFLAGS=-O0 -g -std=c++14 -Wall -Wextra -pedantic -I. -I./Arch/ -I../../../plugins/org.eclipse.viatra.query.tooling.cpp.localsearch/resources/
LFLAGS=
MAKE=make
LIBS=-lgtest

COMPILE=$(CXX) $(CXXFLAGS) -c -o $@ $<
LINK=$(CXX) $(LFLAGS) -o $@ $^ $(LIBS)

.SUFFIXES:
.SUFFIXES: .cpp .h .o

SOURCES := $(wildcard *.cpp)
OBJECTS := $(SOURCES:%.cpp=%.o)
BINARY := Arch.out

d :=	.
dir := 	$(d)/Arch
include $(dir)/Rules.mk

%.o:	%.cpp
		$(COMPILE)
		
$(BINARY): $(OBJECTS)
		$(LINK)
		
.PHONY: all
all: $(SOURCES) $(OBJECTS) $(BINARY)

.PHONY: clean
clean:
	rm -f $(OBJECTS) $(BINARY)
