CC=gcc
CXX=g++
RM=rm -f
CPPFLAGS=-g #(shell --cflags)
LBLIBS=$(shell root-config --libs)

SRCS=main.cc data_to_heap.cc financial_data_reader.cc
OBJS=$(subst .cc,.o,$(SRCS))

all: main

main: $(OBJS)
	g++ -o main $(OBJS) $(LDLIBS)

main.o: main.cc

financial_data_reader.o: financial_data_reader.h financial_data_reader.cc

data_to_heap.o: data_to_heap.h data_to_heap.cc

clean:
	$(RM) $(OBJS)

distclean: clean
	#(RM) main
