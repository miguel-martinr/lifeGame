bin/lifeGame: src/lifeGame.cpp bin/tablero.o bin/cell.o bin/cell_1.o bin/cell_2.o bin/cell_3.o bin/cell_edgeH.o bin/cell_edgeV.o
	g++ -g src/lifeGame.cpp bin/tablero.o bin/cell.o bin/cell_1.o bin/cell_2.o bin/cell_3.o bin/cell_edgeH.o bin/cell_edgeV.o -o bin/lifeGame

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

bin/cell_edgeH.o: include/cell_edgeH.hpp src/cell_edgeH.cpp
	g++	-g -c src/cell_edgeH.cpp -o bin/cell_edgeH.o

bin/cell_edgeV.o: include/cell_edgeV.hpp src/cell_edgeV.cpp
	g++	-g -c src/cell_edgeV.cpp -o bin/cell_edgeV.o

.PHONY:
clean:
	rm bin/*.o bin/lifeGame
