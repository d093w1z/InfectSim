CC = g++
CFLAGS = -Wall -g -Wno-switch
LD = g++
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

PROG = InfectSim
SRCS = main.cpp simObj.cpp
HDRS = conf.hpp Human.hpp simObj.hpp

OBJS = $(SRCS:.cpp=.o)

$(PROG): $(OBJS)
	$(CC) $(OBJS) -o $(PROG) $(LDFLAGS)

main.o: main.cpp simObj.hpp 
	$(CC) $(CFLAGS) -c main.cpp -o main.o

simObj.o: simObj.hpp simObj.cpp Human.hpp conf.hpp
	$(CC) $(CFLAGS) -c simObj.cpp -o simObj.o