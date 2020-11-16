CXX=g++
ALL: world_clock calendar

world_clock: world_clock_main.o world_clock.o
	$(CXX) -o world_clock  world_clock_main.o world_clock.o

world_clock_main.o: world_clock.h
	$(CXX) -std=c++0x -c world_clock_main.cc

world_clock.o: world_clock.h
	$(CXX) -std=c++0x -c world_clock.cc

calendar: calendar.o calendar_main.o
	$(CXX) -o calendar calendar.o calendar_main.o

calendar_main.o: calendar.h
	$(CXX) -std=c++0x -c calendar_main.cc

calendar.o: calendar.h
	$(CXX) -std=c++0x -c calendar.cc
clean:
	rm -rf world_clock world_clock_main.o world_clock.o
	rm -rf calendar calendar_main.o calendar.o
