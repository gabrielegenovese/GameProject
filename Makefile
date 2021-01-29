main: main.o controller.o player.o
	g++ -o main main.o controller.o player.o

main.o: main.cpp ./classes/classes.hpp
	g++ -c main.cpp

controller.o: ./classes/controller.cpp ./classes/classes.hpp
	g++ -c ./classes/controller.cpp

player.o: ./classes/player.cpp ./classes/classes.hpp
	g++ -c ./classes/player.cpp

clean:
	rm *.o