main: main.o controller.o player.o
	g++ -o main main.o controller.o player.o -lcurses

main.o: main.cpp ./classes/controller.hpp ./classes/player.hpp
	g++ -c main.cpp

controller.o: ./classes/controller.cpp ./classes/controller.hpp
	g++ -c ./classes/controller.cpp

player.o: ./classes/player.cpp ./classes/player.hpp
	g++ -c ./classes/player.cpp

clean:
	rm *.o