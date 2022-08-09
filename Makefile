CXX := g++
CXXFLAGS := -g -Wall -std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes

levy-dist: gen-levy-dist.cpp
	$(CXX) $(CXXFLAGS) gen-levy-dist.cpp -o gen-levy-dist

run: levy-dist
	./gen-levy-dist

clean: 
	rm gen-levy-dist