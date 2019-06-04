# Makefile
# Danming Wang 06/01/2019

CXX_FLAG = --std=c++11 -g

runMovies: movies.o main.o utility.o
	g++ $(CXX_FLAG) -o runMovies movies.o main.o utility.o

movies.o: movies.h movies.cpp
	g++ -c $(CXX_FLAG) movies.cpp

main.o: main.cpp
	g++ -c $(CXX_FLAG) main.cpp

utility.o: utility.cpp
	g++ -c $(CXX_FLAG) utility.cpp

clean: 
	rm -f runMovies *.o
