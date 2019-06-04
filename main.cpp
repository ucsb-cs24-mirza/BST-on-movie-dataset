// main.cpp
// Danming Wang
// 06/02/2019

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <cstring>
#include <algorithm>
#include "movies.h"

using namespace std;

bool parseLine(string &line, string &movieName, double &movieRating);

int main(int argc, char** argv){
	if(argc < 4){
		cerr << "Usage: " << argv[ 0 ] << "arg1 arg2 arg3" << endl;
		exit(1);
	}

	bool flag = false;
	if(strcmp(argv[1], "true") == 0){
		flag = true;
	} else if(strcmp(argv[1], "false") == 0) {
		flag = false;
        ofstream myfile;
        string filename = argv[2];
        int namel=filename.length();
        filename = filename.substr(0,namel-4)+"_data.csv";
        myfile.open(filename);
        myfile<<"N,N_visited,\n";
        myfile.close();
	} else {
		cerr << "Argument 1 must be a boolean (true/false)" << endl;
		exit(1);
	}
	
	ifstream movieFile (argv[2]);
	string line, movieName;
	double movieRating;
    string filename = argv[2];
    int namel=filename.length();
    filename = filename.substr(0,namel-4)+"_data.csv";

	if (movieFile.fail()){
		cerr << "Could not open file " << argv[2];
		exit(1);
	}

	BST movie;
	// Read each file and store the name and rating
	while (getline (movieFile, line) && parseLine(line, movieName, movieRating)){
        if (flag==true){
            movie.insert(movieName, movieRating);
        }else{
            ofstream myfile;
            myfile.open(filename);
            myfile<<movie.count();
            movie.insert(movieName,movieRating);
            myfile<<","<<movie.visitedNode(movieName)<<endl;
            myfile.close();
        }
	}
	movieFile.close();
    if (flag==true){
        string prefix=argv[3];
        play(movie,prefix);
    }
    else{
        int W = stoi(argv[3]);
        play2(movie,W);
    }


	return 0;
}

bool parseLine(string &line, string &movieName, double &movieRating) {
	if(line.length() <= 0) return false;
	string tempRating = "";

	bool flag = false;
	movieName = tempRating = "", movieRating = 0.0, flag = false;

	for (int i = 0; i < line.length(); i++){
		if(flag) tempRating += line[i];
		else if(line[i]==','&& line[0]!='"') flag = true;
		else {
			if(i==0 && line[0]=='"') continue;
			if(line[i]=='"'){ i++; flag=true; continue;}
			movieName += line[i];
		}
	}
	
	movieRating = stod(tempRating);
	return true;
}

