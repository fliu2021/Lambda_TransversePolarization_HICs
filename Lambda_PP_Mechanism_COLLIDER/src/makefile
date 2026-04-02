CXX = g++
CXXFLAGS = -std=c++17 -O2 -stdlib=libc++  


PYTHIA8_BIN = /Users/feng/Documents/physics_project/Software/pythia8315_install/bin
PYTHIA8_INC = -I$(shell $(PYTHIA8_BIN)/pythia8-config --includedir)
PYTHIA8_LIBS = $(shell $(PYTHIA8_BIN)/pythia8-config --libs)

ROOT_INC = -I$(shell root-config --incdir)
ROOT_LIBS = $(shell root-config --libs)

CXXFLAGS += $(ROOT_INC) $(PYTHIA8_INC) 
LIBS = $(ROOT_LIBS) $(PYTHIA8_LIBS)

TARGET = JAM1Analyzer 

all: $(TARGET)


$(TARGET): main_JAM1Analyzer.o
	$(CXX) -o $(TARGET) main_JAM1Analyzer.o $(LIBS)

main_JAM1Analyzer.o: main_JAM1Analyzer.C
	$(CXX) $(CXXFLAGS) -c main_JAM1Analyzer.C -o main_JAM1Analyzer.o

clean:
	rm -f $(TARGET) *.o

.PHONY: all clean 
 

