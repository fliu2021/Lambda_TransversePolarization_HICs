CXX = g++
CXXFLAGS =  -O2 -std=c++11 -pedantic -W -Wall -Wshadow -fPIC


PYTHIA8_BIN = /gpfs01/star/pwg/fliu/Event_Generator/pythia8316/bin
PYTHIA8_INC = -I$(shell $(PYTHIA8_BIN)/pythia8-config --includedir)
PYTHIA8_LIBS = $(shell $(PYTHIA8_BIN)/pythia8-config --libs)

ROOT_INC = -I$(shell root-config --incdir)
ROOT_LIBS = $(shell root-config --libs)

CXXFLAGS += $(ROOT_INC) $(PYTHIA8_INC)
LIBS = $(ROOT_LIBS) $(PYTHIA8_LIBS)

TARGET = Centrality

all: $(TARGET)


$(TARGET): main_Centrality.o
	$(CXX) -o $(TARGET) main_Centrality.o $(LIBS)

main_JAM1Analyzer.o: main_Centrality.C
	$(CXX) $(CXXFLAGS) -c main_Centrality.C -o main_Centrality.o

clean:
	rm -f $(TARGET) *.o

.PHONY: all clean


