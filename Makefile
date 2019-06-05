# Makefile
# Danming Wang 06/01/2019

CXX_FLAG = --std=c++11 -g
all: runMovies tests

runF: runMovies
	./runMovies false input_20_ordered.csv 10
	./runMovies false input_20_random.csv 10
	./runMovies false input_100_ordered.csv 10
	./runMovies false input_100_random.csv 10
	./runMovies false input_1000_ordered.csv 10
	./runMovies false input_1000_random.csv 10

runMovies: movies.o main.o utility.o
	g++ $(CXX_FLAG) -o runMovies movies.o main.o utility.o

tests: tests.o movies.o utility.o
	g++ $(CXX_FLAG) -o tests tests.o movies.o utility.o 

movies.o: movies.h movies.cpp
	g++ -c $(CXX_FLAG) movies.cpp

main.o: main.cpp
	g++ -c $(CXX_FLAG) main.cpp

utility.o: utility.cpp
	g++ -c $(CXX_FLAG) utility.cpp

tests.o: tests.cpp
	g++ -c $(CXX_FLAG) tests.cpp

clean: 
	rm -f runMovies *.o *data.csv
