CC = g++
CFLAGS = --std=c++17 -Wall -Werror -pedantic -g
LIB = -lsfml-system -lboost_unit_test_framework
# Your .hpp files
DEPS = EDistance.hpp EDistance.cpp
# Your compiled .o files
OBJECTS = EDistance.o
# The name of your program
PROGRAM = EDistance
TEST = test

.PHONY: all clean lint

all: $(PROGRAM).a $(PROGRAM) $(TEST)

# Wildcard recipe to make .o files from corresponding .cpp file
%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $<

$(PROGRAM).a: EDistance.o
	ar rcs $(PROGRAM).a $^

$(PROGRAM): $(OBJECTS) main.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)

$(TEST): $(OBJECTS) test.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)

clean:
	rm -f *.o *.a $(PROGRAM) $(TEST)

lint:
	cpplint *.cpp *.hpp
