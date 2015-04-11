CC = g++
CFLAGS = -Wall -Werror -ansi -pedantic -g

all: TextGenerator

TextGenerator: TextGenerator.o MarkovModel.o
	$(CC) $(FLAGS) -o TextGenerator TextGenerator.o MarkovModel.o

test: mmtest.o MarkovModel.o
	$(CC) $(FLAGS) -o test mmtest.o MarkovModel.o -lboost_unit_test_framework

# ==============================================================================
mmtest.o: mmtest.cpp MarkovModel.cpp MarkovModel.hpp
	$(CC) $(FLAGS) -c mmtest.cpp

TextGenerator.o: TextGenerator.cpp  MarkovModel.cpp MarkovModel.hpp
	$(CC) $(FLAGS) -c TextGenerator.cpp

MarkovModel.o: MarkovModel.cpp MarkovModel.hpp
	$(CC) $(FLAGS) -c MarkovModel.cpp

clean:
	rm -rf test TextGenerator *.o *.~
