main: main.o controller.o player.o printer.o field.o room.o
	g++ -o main main.o controller.o player.o printer.o field.o room.o -lcurses 

main.o: main.cpp ./classes/controller.hpp ./classes/player.hpp ./classes/printer.hpp
	g++ -c -Wall main.cpp

controller.o: ./classes/controller.cpp ./classes/controller.hpp 
	g++ -c -Wall ./classes/controller.cpp

room.o: ./classes/room.cpp ./classes/room.hpp
	g++ -c -Wall ./classes/room.cpp

field.o: ./classes/field.cpp ./classes/field.hpp 
	g++ -c -Wall ./classes/field.cpp

player.o: ./classes/player.cpp ./classes/player.hpp
	g++ -c -Wall ./classes/player.cpp

printer.o: ./classes/printer.cpp ./classes/printer.hpp
	g++ -c -Wall ./classes/printer.cpp


clean:
	rm *.o