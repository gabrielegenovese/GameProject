main: main.o controller.o player.o printer.o
	g++ -o main main.o controller.o player.o printer.o room.o -lcurses

main.o: main.cpp ./classes/controller.hpp ./classes/player.hpp ./classes/printer.hpp
	g++ -c main.cpp

controller.o: ./classes/controller.cpp ./classes/controller.hpp room.o
	g++ -c ./classes/controller.cpp

room.o: ./classes/room.cpp ./classes/room.hpp
	g++ -c ./classes/room.cpp

player.o: ./classes/player.cpp ./classes/player.hpp
	g++ -c ./classes/player.cpp

printer.o: ./classes/printer.cpp ./classes/printer.hpp
	g++ -c ./classes/printer.cpp


clean:
	rm *.o