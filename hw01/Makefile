ALL: hello_world fibonacci magic_square sort_int

hello_world:hello_world.o
	g++ -o hello_world hello_world.o

hello_world.o: hello_world.cc
	g++ -c hello_world.cc

fibonacci:fibonacci.o
	g++ -o fibonacci fibonacci.o

fibonacci.o: fibonacci.cc
	g++ -c fibonacci.cc

magic_square:magic_square.o
	g++ -o magic_square magic_square.o

magic_square.o:magic_square.cc
	g++ -c magic_square.cc

sort_int:sort_int.o
	g++ -o sort_int sort_int.o

sort_int.o:sort_int.cc
	g++ -c sort_int.cc

clean:
	rm hello_world
	rm fibonacci
	rm magic_square
	rm sort_int
