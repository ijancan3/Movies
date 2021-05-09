#include "movie.h"

Movie::Movie(string ID, string title, Genre genre1, Genre genre2, string summary, string commentary, int rating, int timesWatched):
	movieID{ID}, title{title}, genre1{genre1}, genre2{genre2}, summary{summary}, commentary{commentary}, rating{rating}, timesWatched{timesWatched}
{
	//Constructor using initializer list
}

Movie::Movie(): Movie("","",UNKNOWN, UNKNOWN, "","",0,0){
//Constructor using delegating constructor. Sets values to default.
}

Movie::~Movie(){
//Destructor
}

string Movie::getID() {
	return this->movieID;
}
string Movie::getTitle() {
	return this->title;
}
Genre Movie::getGenre1() {
	return this->genre1;
}
Genre Movie::getGenre2() {
	return this->genre2;
}
string Movie::getCommentary() {
	return this->commentary;
}
string Movie::getSummary() {
	return this->summary;
}
int Movie::getRating() {
	return this->rating;
}
int Movie::getTimesWatched() {
	return this->timesWatched;
}
void Movie::setID(string ID) {
	this->movieID = ID;
}
void Movie::setTitle(string title) {
	this->title = title;
}
void Movie::setGenre1(Genre first) {
	this->genre1 = first;
}
void Movie::setGenre2(Genre second) {
	this->genre2 = second;
}
void Movie::setCommentary(string commentary) {
	this->commentary = commentary;
}
void Movie::setSummary(string summary) {
	this->summary = summary;
}
void Movie::setRating(int rating) {
	this->rating = rating;
}
void Movie::setTimesWatched(int times) {
	this->timesWatched = times;
}
void Movie::incrementWatch() {
	this->timesWatched++;
}
string Movie::fullGenre() {
	string fullGenre, genre1, genre2;
	genre1 = genre[this->genre1];
	genre2 = genre[this->genre2];

	if (!genre2.compare("UNKNOWN")==0) {
		fullGenre = genre1 + "-" + genre2;
		return fullGenre;
	}
	else {
		return genre1;
	}



}
void Movie::print() {
	cout << "\n=======================================================================================" << std::endl;
	cout << "Movie ID: " << this->movieID;
	cout << "\nMovie title: " << this->title;
	cout << "\nGenre: " << fullGenre();
	cout << "\nSummary: " << this->summary;
	cout << "\nRating " << this->rating;
	cout << "\nTimes watched: " << this->timesWatched;
	cout << "\nCommentary: " << this->commentary;
	cout << std::endl;
}
