makCFLAGS= -Wall -Wextra -DDEBUG -g -std=c++14

all: program1.o Star.o Planet.o Vector.o List.o
	g++ $(CFLAGS) program1.o Star.o Planet.o Vector.o List.o -o program4

program4.o: program1.cpp
	g++ $(CFLAGS) -c program4.cpp -o program1.o

Star.o: Star.cpp
	g++ $(CFLAGS) -c Star.cpp -o Star.o

Planet.o:Planet.cpp
	g++ $(CFLAGS) -c Planet.cpp -o Planet.o

Vector.o:Vector.cpp
	g++ $(CFLAGS) -c Vector.cpp -o 	Vector.o

List.o:List.cpp
	g++ $(CFLAGS) -c List.cpp -o List.o

memcheck: all
	valgrind --leak-check=full --show-leak-kinds=all ./program4

run: all
	./program4

clean: 
	rm *.o program4
