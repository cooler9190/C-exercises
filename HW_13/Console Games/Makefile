CC = g++
CFLAGS = -std=c++11 -Wall

TARGET = build/runApplication.out

SRC = src/main.cpp src/gameMenu.cpp src/ticTacToe.cpp src/hangMan.cpp src/boggle.cpp

OBJ = $(SRC:src/%.cpp=bin/%.o)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

bin/main.o: src/main.cpp
	$(CC) $(CFLAGS) -c $< -o $@

bin/gameMenu.o: src/gameMenu.cpp header/game_menu.hpp
	$(CC) $(CFLAGS) -c $< -o $@

bin/ticTacToe.o: src/ticTacToe.cpp header/tic_tac_toe.hpp
	$(CC) $(CFLAGS) -c $< -o $@

bin/hangMan.o: src/hangMan.cpp header/hangman.hpp
	$(CC) $(CFLAGS) -c $< -o $@

bin/boggle.o: src/boggle.cpp header/boggle.hpp
	$(CC) $(CFLAGS) -c $< -o $@

bin/%.o: \src/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
