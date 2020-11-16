CXX=g++
ALL: minimal_fighter reply_admin simple_int_set binary_search

minimal_fighter: minimal_fighter_main.o minimal_fighter.o
	$(CXX) -o minimal_fighter minimal_fighter_main.o minimal_fighter.o

minimal_fighter_main.o: minimal_fighter.h
	$(CXX) -std=c++0x -c minimal_fighter_main.cc

minimal_fighter.o: minimal_fighter.h
	$(CXX) -std=c++0x -c minimal_fighter.cc

reply_admin: reply_admin_main.o reply_admin.o
	$(CXX) -o reply_admin  reply_admin_main.o reply_admin.o

reply_admin_main.o: reply_admin.h
	$(CXX) -std=c++0x -c reply_admin_main.cc

reply_admin.o: reply_admin.h
	$(CXX) -std=c++0x -c reply_admin.cc

simple_int_set: simple_int_set_main.o simple_int_set.o
	$(CXX) -o simple_int_set simple_int_set_main.o simple_int_set.o

simple_int_set_main.o: simple_int_set.h
	$(CXX) -std=c++0x -c simple_int_set_main.cc

simple_int_set.o: simple_int_set.h
	$(CXX) -std=c++0x -c simple_int_set.cc

binary_search: binary_search_main.o binary_search.o
	$(CXX) -o binary_search binary_search_main.o binary_search.o

binary_search_main.o: binary_search.h
	$(CXX) -std=c++0x -c binary_search_main.cc

binary_search.o: binary_search.h
	$(CXX) -std=c++0x -c binary_search.cc

clean:
	rm -rf minimal_fighter minimal_fighter_main.o minimal_fighter.o
	rm -rf reply_admin reply_admin_main.o reply_admin.o
	rm -rf simple_int_set simple_int_set_main.o simple_int_set.o
	rm -rf binary_search binary_search_main.o binary_search.o
