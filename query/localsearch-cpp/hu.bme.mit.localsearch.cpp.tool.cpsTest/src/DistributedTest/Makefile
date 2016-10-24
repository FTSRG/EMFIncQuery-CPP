##############################################################################
# M A K E F I L E
#
# NAME: model
#
##############################################################################

##############################     Protobuf     ##############################
PROTOBUF_INCLUDE_DIR=D:\libraries\protobuf-3.0.0\src
##############################################################################

VIATRA_DIR=../../../../plugins/org.eclipse.viatra.query.tooling.cpp.localsearch/resources/Viatra/
include $(VIATRA_DIR)/Makefile
VIATRAOBJECTS := $(wildcard $(VIATRA_DIR)*.o) $(wildcard $(VIATRA_DIR)*/*.o) $(wildcard $(VIATRA_DIR)*/*/*.o)

CXXWINFLAGS= -fms-compatibility-version=19.00 -Wno-microsoft-include
INCLUDEFLAGS=-I. -I./model/ -I./../../../../plugins/org.eclipse.viatra.query.tooling.cpp.localsearch/resources/ -I$(PROTOBUF_INCLUDE_DIR)

CXX=clang++
CXXFLAGS=-O0 -g -std=c++14 -Wall -Wextra -pedantic -fexceptions $(INCLUDEFLAGS) $(CXXWINFLAGS)
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


$(VIATRAOBJECTS): %.o:
		
$(OBJECTS): %.o:	%.cpp
		$(COMPILE)
		
$(BINARY): $(OBJECTS) $(VIATRAOBJECTS)
		$(LINK)

.DEFAULT: all
.PHONY: all
all: $(SOURCES) $(OBJECTS) $(BINARY) 

.PHONY: clean
clean:
	rm -f $(OBJECTS) $(BINARY)
