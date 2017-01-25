#Makefile - Ericka Zuniga Calvo - IE-0217
OBJS= Main.o Polinomio.o
CC=g++
CFLAGS = -c
DEPS = Polinomio.h
SRCS= Main.cpp Polinomio.cpp

build : $(OBJS)
	$(CC) $(OBJS) -o polinomio
	$(CC) $(CFLAGS) $(SRCS)

run :
	  ./polinomio

clean :
	rm polinomio $(OBJS)
