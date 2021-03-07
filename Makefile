main: main.o controller.o player.o printer.o field.o room.o shoots.o misc.o
	g++ -o main main.o controller.o player.o printer.o field.o room.o shoots.o misc.o -lcurses 

main.o: main.cpp ./classes/controller.cpp ./classes/player.cpp ./classes/misc.cpp
	g++ -c -Wall main.cpp

controller.o: ./classes/controller.cpp ./classes/field.cpp 
	g++ -c -Wall ./classes/controller.cpp

room.o: ./classes/room.cpp 
	g++ -c -Wall ./classes/room.cpp

field.o: ./classes/field.cpp 
	g++ -c -Wall ./classes/field.cpp

player.o: ./classes/player.cpp 
	g++ -c -Wall ./classes/player.cpp

printer.o: ./classes/printer.cpp 
	g++ -c -Wall ./classes/printer.cpp

shoots.o: ./classes/shoots.cpp
	g++ -c -Wall ./classes/shoots.cpp

misc.o: ./classes/misc.cpp
	g++ -c -Wall ./classes/misc.cpp

clean:
	rm *.o