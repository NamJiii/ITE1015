ALL: draw_shape minesweeper creative_stone

draw_shape: draw_shape_main.o draw_shape.o
	g++ -o draw_shape draw_shape_main.o draw_shape.o

draw_shape_main.o: draw_shape.h
	g++ -std=c++0x -c draw_shape_main.cc

draw_shape.o: draw_shape.h
	g++ -std=c++0x -c draw_shape.cc

minesweeper: minesweeper_main.o minesweeper.o
	g++ -o minesweeper  minesweeper_main.o minesweeper.o

minesweeper_main.o: minesweeper.h
	g++ -std=c++0x -c minesweeper_main.cc

minesweeper.o: minesweeper.h
	g++ -std=c++0x -c minesweeper.cc

creative_stone: creative_stone_main.o creative_stone.o
	g++ -o creative_stone creative_stone_main.o creative_stone.o

creative_stone_main.o: creative_stone.h
	g++ -std=c++0x -c creative_stone_main.cc

creative_stone.o: creative_stone.h
	g++ -std=c++0x -c creative_stone.cc

clean:
	rm -rf draw_shape draw_shape.o draw_shape_main.o minesweeper minesweeper_main.o minesweeper.o creative_stone creative_stone.o creative_stone_main.o
