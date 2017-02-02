
#Makefile - Ericka Zuniga Calvo-Leonardo Hernandez Chacon - IE-0217
OBJS= main.o Juego.o Matriz.o Animal.o Lobo.o Oveja.o Raton.o Zorro.o
CC=g++
CFLAGS = -c
DEPS = Juego.h Matriz.h Animal.h Lobo.h Oveja.h Raton.h Zorro.h
SRCS= main.cpp Juego.cpp Matriz.cpp Animal.cpp Lobo.cpp Oveja.cpp Raton.cpp Zorro.cpp
FILE=Matriz.txt
DAYS=5
EXECUTABLE=juego

build : $(OBJS)
	$(CC) $(OBJS) -o $(EXECUTABLE)
	$(CC) $(CFLAGS) $(SRCS)

run :
	./$(EXECUTABLE) $(DAYS) $(FILE)

clean :
	rm $(EXECUTABLE) $(OBJS)
