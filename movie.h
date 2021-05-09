#pragma once

#include <fstream>
#include <iostream>
#include "genre.h"
#include <vector>
using std::cin; using std::cout; using std::vector; using std::fstream;

class Movie {
private:
	string movieID;
	string title;
	string summary;
	Genre genre1;
	Genre genre2;
	string commentary;
	int timesWatched;
	int rating;

public:
	Movie();
	Movie(string, string, Genre, Genre, string,string, int, int);
	~Movie();
	string getID();
	string getTitle();
	string getSummary();
	Genre getGenre1();
	Genre getGenre2();
	string getCommentary();
	int getTimesWatched();
	int getRating();
	string fullGenre();
	void setID(string);
	void setTitle(string);
	void setSummary(string);
	void setGenre1(Genre);
	void setGenre2(Genre);
	void setCommentary(string);
	void setTimesWatched(int);
	void setRating(int);
	void print();
	void incrementWatch();
};