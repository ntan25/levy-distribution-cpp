CXX := g++
CXXFLAGS := -g -Wall -std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes


levy-dist: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp -o levy-dist

run: levy-dist
	./levy-dist

clean: 
	rm levy-dist
	rm -r levy-dist.dSYM
	rm levy-test.csv
	rm levy-params.csv
	