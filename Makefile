
RMDIR = rm -rf
MKDIR = mkdir -p

SRCDIR = ./src
INCLDIR ?= ./include
OBJDIR = ./obj
BIN = ./bin

CC = g++
CPPFLAGS := -Wall -g -Wno-switch -I$(INCLDIR)
LD = g++
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

PROG 	:= $(BIN)/InfectSim
SRCS    := $(wildcard $(SRCDIR)/*.cpp)
OBJS 	:= $(SRCS:%.cpp=%.o)
OBJS 	:= $(patsubst $(SRCDIR)/%,$(OBJDIR)/%,$(OBJS))

.PHONY: all run clean

all: $(PROG) run

$(PROG): $(OBJS) | $(BIN)
	$(CC) $^ -o $@ $(LDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp  | $(OBJDIR)
	$(CC) $(CPPFLAGS) -c $< -o $@

$(BIN) $(OBJDIR):
	$(MKDIR) $@

run: $(PROG)
	./$<

clean:
	$(RMDIR) $(OBJDIR) $(BIN)
