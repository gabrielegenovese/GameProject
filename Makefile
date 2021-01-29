main: main.o controller.o player.o printer.o
	g++ -o main main.o controller.o player.o printer.o -lcurses

main.o: main.cpp ./classes/controller.hpp ./classes/player.hpp ./classes/printer.hpp
	g++ -c main.cpp

controller.o: ./classes/controller.cpp ./classes/controller.hpp
	g++ -c ./classes/controller.cpp

player.o: ./classes/player.cpp ./classes/player.hpp
	g++ -c ./classes/player.cpp

printer.o: ./classes/printer.cpp ./classes/printer.hpp
	g++ -c ./classes/printer.cpp


clean:
	rm *.o