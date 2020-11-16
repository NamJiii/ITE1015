CXX=g++
ALL: poly_diff

poly_diff: poly_diff_main.o poly_diff.o
	$(CXX) -o poly_diff poly_diff_main.o poly_diff.o

poly_diff_main.o: poly_diff.h
	$(CXX) -std=c++0x -c poly_diff_main.cc

poly_diff.o: poly_diff.h
	$(CXX) -std=c++0x -c poly_diff.cc

clean:
	rm -rf poly_diff poly_diff_main.o poly_diff.o
