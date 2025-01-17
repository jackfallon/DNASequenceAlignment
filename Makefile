CC = g++
FLAGS = -Wall -Werror -pedantic -std=c++17 -g
PROGRAM = EditDistance
DEPS = EditDistance.hpp
OBJS = EditDistance.o
LIB = -lsfml-graphics -lsfml-window -lsfml-system

all: $(PROGRAM)

$(PROGRAM): $(OBJS) main.o
		$(CC) $(FLAGS) -o $@ $^ $(LIB)

%.o: %.cpp $(DEPS)
		$(CC) $(FLAGS) -c $<

clean:
		rm *.o $(PROGRAM)

lint:
		cpplint *.cpp *.hpp
