CXX = g++
CXXFLAGS = -std=c++17 -O2 -stdlib=libc++  


PYTHIA8_BIN = /Users/feng/Documents/physics_project/Software/pythia8315_install/bin
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

main_Centrality.o: main_Centrality.C
	$(CXX) $(CXXFLAGS) -c main_Centrality.C -o main_Centrality.o

clean:
	rm -f $(TARGET) *.o

.PHONY: all clean 
 

