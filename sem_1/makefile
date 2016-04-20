CPPFILES = 4.cpp
FLAGS = -std=c++11 -pedantic -Wall -g -static -lm
EXE = main
CC = g++
all: $(EXE)
main: $(CPPFILES)
	$(CC) $(FLAGS) -o $(EXE) $(CPPFILES)
clear:
	rm -rf $(EXE) *.o input output *.tmp *.temp file *.out *.in
	rm -rf test.cpp
