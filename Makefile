CC = g++
CFLAGS = -Wall -Werror -ansi -pedantic -g

all: TextGenerator

TextGenerator: TextGenerator.o MarkovModel.o
	$(CC) $(FLAGS) -o TextGenerator TextGenerator.o MarkovModel.o

test: mmtest.o MarkovModel.o
	$(CC) $(FLAGS) -o test mmtest.o MarkovModel.o -lboost_unit_test_framework


