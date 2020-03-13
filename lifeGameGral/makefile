bin/main: src/main.cpp bin/tablero.o bin/cell.o
	g++ -g src/main.cpp bin/tablero.o bin/cell.o -o bin/main

bin/tablero.o: include/tablero.hpp src/tablero.cpp
	g++ -g -c src/tablero.cpp -o bin/tablero.o

bin/cell.o: include/cell.hpp src/cell.cpp
	g++ -g -c src/cell.cpp -o bin/cell.o



.PHONY:
clean:
	rm bin/*.o bin/main
