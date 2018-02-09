CC=gcc
CXX=g++
RM=rm -f
CPPFLAGS=-g #(shell --cflags)
LBLIBS=$(shell root-config --libs)

SRCS=main.cc data_to_heap.cc financial_data_reader.cc data_to_tree.cc \
  quicksort_searcher.cc

OBJS=$(subst .cc,.o,$(SRCS))

all: main

main: $(OBJS)
	g++ -o main $(OBJS) $(LDLIBS)

main.o: main.cc

financial_data_reader.o: financial_data_reader.h financial_data_reader.cc

data_to_heap.o: data_to_heap.h data_to_heap.cc

data_to_tree.o: data_to_tree.h data_to_tree.cc

quicksort_searcher.o: quicksort_searcher.h quicksort_searcher.cc

clean:
	$(RM) $(OBJS)

distclean: clean
	#(RM) main
