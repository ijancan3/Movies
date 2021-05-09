#pragma once
#include "movie.h"
#include <ctime>
class MovieDriver {
private:
	vector<Movie> movies;
public:
	void parseMovies();
	void printMovies();
	Genre convertGenre(string);
	void addMovie(string, string, Genre, Genre, string, string, int, int);
	void setMovieFile();
	void runStartLoop();
	void addNewMovie();
	Genre genreSwitch();
	string generateID();
	void removeMovie();
	void keywordSearch();
	void editMovie();
	void setFields(Movie&);
};