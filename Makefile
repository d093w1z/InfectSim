CC = g++
CFLAGS = -Wall -g -Wno-switch
LD = g++
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

PROG = InfectSim
SRCS = conf.cpp main.cpp simObj.cpp Human.cpp
HDRS = conf.hpp Human.hpp simObj.hpp utils.hpp

OBJS = $(SRCS:.cpp=.o)

$(PROG): $(OBJS)
	$(CC) $(OBJS) -o $(PROG) $(LDFLAGS)

main.o: main.cpp simObj.hpp utils.hpp
	$(CC) $(CFLAGS) -c main.cpp -o main.o

simObj.o: simObj.hpp simObj.cpp Human.hpp conf.hpp
	$(CC) $(CFLAGS) -c simObj.cpp -o simObj.o

conf.o: conf.cpp conf.hpp
	$(CC) $(CFLAGS) -c conf.cpp -o conf.o

Human.o: Human.cpp Human.hpp conf.hpp utils.hpp
	$(CC) $(CFLAGS) -c Human.cpp -o Human.o

clean:
	rm -f core $(PROG) $(OBJS)
