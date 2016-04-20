CPPFILES = 4.cpp
FLAGS = -std=c++11 -pedantic -Wall -g -lm
EXE = main
CC = g++
all: $(EXE)
$(EXE): $(CPPFILES)
	$(CC) $(FLAGS) -o $(EXE) $(CPPFILES)
clear:
	rm -rf $(EXE) *.o input output *.tmp *.temp file *.out *.in
	rm -rf test.cpp
	rm -rf $(EXE1) $(EXE2) $(EXE3) $(EXE4)

CPP1 = 1.cpp
EXE1 = 1.out
c1: $(EXE1)
$(EXE1): $(CPP1)
	$(CC) $(FLAGS) -o $(EXE1) $(CPP1)

CPP2 = 2.cpp
EXE2 = 2.out
c2: $(EXE2)
$(EXE2): $(CPP2)
	$(CC) $(FLAGS) -o $(EXE2) $(CPP2)

CPP3 = 3.cpp
EXE3 = 3.out
c3: $(EXE3)
$(EXE3): $(CPP3)
	$(CC) $(FLAGS) -o $(EXE3) $(CPP3)

CPP4 = 4.cpp
EXE4 = 4.out
c4: $(EXE4)
$(EXE4): $(CPP4)
	$(CC) $(FLAGS) -o $(EXE4) $(CPP4)
