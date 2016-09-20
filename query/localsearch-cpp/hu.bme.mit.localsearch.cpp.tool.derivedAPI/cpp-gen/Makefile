##############################################################################
# M A K E F I L E
#
# NAME: model
#
##############################################################################

CXX=g++
CXXFLAGS=-O3 -std=c++14 -Wall -Wextra -pedantic -I. -I./model/ -I../../../plugins/org.eclipse.viatra.query.tooling.cpp.localsearch/resources/
LFLAGS=
MAKE=make
LIBS=-lgtest

COMPILE=$(CXX) $(CXXFLAGS) -c -o $@ $<
LINK=$(CXX) $(LFLAGS) -o $@ $^ $(LIBS)

.SUFFIXES:
.SUFFIXES: .cpp .h .o

SOURCES := $(wildcard *.cpp)
OBJECTS := $(SOURCES:%.cpp=%.o)
BINARY := model.out

d :=	.
dir := 	$(d)/model
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
