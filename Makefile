CC := g++ -std=c++17 -pthread

all : Finder

Finder : main.o Finder.o 
		$(CC) main.o Finder.o -o Finder

main.o : main.cpp Finder.hpp
	$(CC) -c main.cpp

Finder.o : Finder.cpp Finder.hpp
	$(CC) -c Finder.cpp

clean:
	rm *.o Finder