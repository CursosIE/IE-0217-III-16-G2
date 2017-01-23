#Makefile - Ericka Zuniga Calvo - IE-0217
OBJS= main.o Pokemon.o Electric.o Flying.o Fire.o Water.o Zapdos.o Moltres.o Articuno.o
CC=g++
CFLAGS = -c
DEPS = Pokemon.h Electric.h Flying.h Fire.h Water.h Zapdos.h Moltres.h Articuno.h
SRCS= main.cpp Pokemon.cpp Electric.cpp Flying.cpp Fire.cpp Water.cpp Zapdos.cpp Moltres.cpp Articuno.cpp

build : $(OBJS)
	$(CC) $(OBJS) -o pokemon
	$(CC) $(CFLAGS) $(SRCS)

run :
	  ./pokemon

clean :
	rm pokemon $(OBJS)
