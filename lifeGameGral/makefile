bin/main: src/main.cpp bin/tablero.o bin/cell.o bin/cell_1.o bin/cell_2.o bin/cell_3.o
	g++ -g src/main.cpp bin/tablero.o bin/cell.o bin/cell_1.o bin/cell_2.o bin/cell_3.o -o bin/main

bin/tablero.o: include/tablero.hpp src/tablero.cpp
	g++ -g -c src/tablero.cpp -o bin/tablero.o

bin/cell.o: include/cell.hpp src/cell.cpp
	g++ -g -c src/cell.cpp -o bin/cell.o

bin/cell_1.o: include/cell_1.hpp src/cell_1.cpp
	g++ -g -c src/cell_1.cpp -o bin/cell_1.o

bin/cell_2.o: include/cell_2.hpp src/cell_2.cpp
	g++ -g -c src/cell_2.cpp -o bin/cell_2.o

bin/cell_3.o: include/cell_3.hpp src/cell_3.cpp
	g++ -g -c src/cell_3.cpp -o bin/cell_3.o

.PHONY:
clean:
	rm bin/*.o bin/main
