battleship: main.o player.o aiPlayer.o humanPlayer.o game.o
		g++ -o battleship main.o humanPlayer.o aiPlayer.o player.o game.o -g

main.o: game.h player.h humanPlayer.h aiPlayer.h main.cpp
		g++ -c main.cpp -g

game.o: game.h player.h humanPlayer.h aiPlayer.h game.cpp
		g++ -c game.cpp -g

aiPlayer.o: aiPlayer.h player.h aiPlayer.cpp
		g++ -c aiPlayer.cpp -g

humanPlayer.o: humanPlayer.h player.h humanPlayer.cpp
		g++ -c humanPlayer.cpp -g

player.o: player.h player.cpp
		g++ -c player.cpp -g

clean:
		rm *.o battleship
