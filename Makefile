main: main.o controller.o player.o
	g++ -o main main.o controller.o player.o

main.o: main.cpp controller.h player.h
	g++ -c main.cpp

controller.o: controller.cpp controller.h
	g++ -c controller.cpp

player.o: player.cpp player.h
	g++ -c player.cpp

clean:
	rm *.o