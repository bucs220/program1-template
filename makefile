makCFLAGS= -Wall -Wextra -DDEBUG -g -std=c++14

all: program2.o Star.o Planet.o Vector.o List.o
	g++ $(CFLAGS) program2.o Star.o Planet.o Vector.o List.o -o program2

program2.o: program2.cpp
	g++ $(CFLAGS) -c program2.cpp -o program2.o

Star.o: Star.cpp
	g++ $(CFLAGS) -c Star.cpp -o Star.o

Planet.o:Planet.cpp
	g++ $(CFLAGS) -c Planet.cpp -o Planet.o

Vector.o:Vector.cpp
	g++ $(CFLAGS) -c Vector.cpp -o 	Vector.o

List.o:List.cpp
	g++ $(CFLAGS) -c List.cpp -o List.o

memcheck: all
	valgrind ./program2

run: all
	./program2

clean: 
	rm *.o program2
