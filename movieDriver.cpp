   
#include "movieDriver.h"

#include <sstream>
using std::istringstream;
using std::endl;
void MovieDriver::parseMovies() {
	std::ifstream movieFile;  //Starts an ifstream object to read a text file
	movieFile.open("movies.txt");

	string movie; //create a string to parse a while line which contains all the movie fields
	vector<string> movieFileParse; //creates a vector to place all of the movies as comma delimited strings
	while (getline(movieFile, movie)) { //reads the movie file, puts each line into the string "movie"
		movieFileParse.push_back(movie); //adds each movie string to the vector
	}
	movieFile.close();
	if (movieFileParse.size() == 0) {
		cout << "Sorry, there are no movies in the database.\n"; //In case the text file is empty.

	}
	else {
		for (string movies : movieFileParse) { //if the vector movieFileParse has movies in it
			istringstream ss(movies); //create a stringstream object to parse each movie member of movieFileParse vector
			string parsedString; //this is where the comma delimited strings will be temporarily stored
			vector<string> movieObject; //final movie object will be created from this vector
			while (getline(ss, parsedString, '*')) { //checks each line in ss(which contains the movies member of movieFileParse), until it gets to a comma, and places it into parsedString

				movieObject.push_back(parsedString);
			}
			string ID = movieObject.at(0);
			string title = movieObject.at(1);
			string genre1 = movieObject.at(2);
			string genre2 = movieObject.at(3);
			string summary = movieObject.at(4);
			string commentary = movieObject.at(5);
			int rating = std::stoi(movieObject.at(6));
			int timesWatched = std::stoi(movieObject.at(7));
			Genre gen1 = convertGenre(genre1);
			Genre gen2 = convertGenre(genre2);
			//cout << ID <<"," <<title << "," << genre[gen1] << "," << genre[gen2] << "," << summary << "," << commentary << "," << rating << "," << timesWatched<<endl;
			addMovie(ID, title, gen1, gen2, summary, commentary, rating, timesWatched);
		}
	}
}

Genre MovieDriver::convertGenre(string parsedGenre) {
	if (parsedGenre.compare("Fantasy") == 0)
		return Fantasy;
	if (parsedGenre.compare("Action") == 0)
		return Action;
	if (parsedGenre.compare("Adventure") == 0)
		return Adventure;
	if (parsedGenre.compare("SciFi") == 0)
		return SciFi;
	if (parsedGenre.compare("Horror") == 0)
		return Horror;
	if (parsedGenre.compare("Comedy") == 0)
		return Comedy;
	if (parsedGenre.compare("Drama") == 0)
		return Drama;
	if (parsedGenre.compare("Documentary") == 0)
		return Documentary;
	if(parsedGenre.compare("UNKNOWN")==0)
		return UNKNOWN;
}		

void MovieDriver::addMovie(string ID, string title, Genre genre1, Genre genre2, string summary, string commentary, int rating, int timesWatched) {
	Movie newMovie(ID, title, genre1, genre2, summary, commentary, rating, timesWatched);
	this->movies.push_back(newMovie);
}

void MovieDriver::printMovies() {
	for (Movie movie : this->movies) {
		movie.print();
	}
}

void MovieDriver::runStartLoop() {
	bool endLoop{ false };
	int userInput;
	do {
		cout << "\nWelcome to the movie database!\nPlease select from the following options:\n";
		cout << "1) Print Movie List\n2) Add a movie\n3) Remove a movie\n4) Save changes\n5) Keyword Search\n6) Edit Movie\n7) Quit\nPlease enter your choice: ";
		
		cin >> userInput;
		switch (userInput) {
		case 1:
			printMovies();
			break;
		case 2:
			addNewMovie();
			break;
		case 3:
			removeMovie();
			break;
		case 4:
			setMovieFile();
			break;

		case 5:
			keywordSearch();
			break;
		case 6:
			editMovie();
			break;
			
		case 7:
			endLoop = true;
			break;
		default:
			cout << "That is not a valid option. Please try again.\n";
			break;
		}
	} while (!endLoop);
}
void MovieDriver::removeMovie() {
	string movieID;
	cout << "Enter the ID of the movie you wish to remove: \n";
	cin.clear();
	cin.ignore(1000, '\n');
	getline(cin, movieID);
	bool found = false;
	
	for (int i{ 0 }; i < this->movies.size();++i) {
		
		if (movieID.compare(this->movies.at(i).getID()) == 0) {
			movies.erase(movies.begin() + i);
			found = true;
			cout << "Movie with ID " << movieID << " deleted.";
		}
	}
	if (!found) {
		cout << "Movie not found.";
	}

}
void MovieDriver::addNewMovie() {
	
	Genre genre1;
	Genre genre2;
	genre1 = this->genreSwitch();
	cout << "Is there a second genre? Y/N: ";
	char secondGenre;
	cin >> secondGenre;
	if (secondGenre == 'Y' || secondGenre == 'y') {
		genre2 = this->genreSwitch();
	}
	else {
		genre2 = UNKNOWN;
	}
	cin.clear();
	cin.ignore(1000, '\n');
	string userFields[]{ "title: ", "summary: ", "commentary: ", "rating: ", "number of times viewed: " };
	vector<string> movieFields;
	for (int i{ 0 }; i < 5; ++i) {
		string input;
		cout << "Please enter the " << userFields[i];
		//cin.clear();
		//cin.ignore(1000, '/n');
		getline(cin, input);
		movieFields.push_back(input);
		cout << endl;
		
	}
	string ID = generateID();
	int rating = std::stoi(movieFields.at(3));
	int timesWatched = std::stoi(movieFields.at(4));
	addMovie(ID, movieFields.at(0), genre1, genre2, movieFields.at(1), movieFields.at(2), rating, timesWatched);

}

Genre MovieDriver::genreSwitch() {
	int userInput;
	Genre genre1;
	cout << "What is the genre of the movie?\n1) Fantasy\n2) Horror\n3) Comedy\n4) Drama \n5) SciFi\n6) Action\n7) Adventure\n8) Documentary\n9) Unknown\nEnter a number: ";
	cin >> userInput;
	switch (userInput) {
	case 1:
		genre1 = Fantasy;
		break;
	case 2:
		genre1 = Horror;
		break;
	case 3:
		genre1 = Comedy;
		break;
	case 4:
		genre1 = Drama;
		break;
	case 5:
		genre1 = SciFi;
		break;
	case 6:
		genre1 = Action;
		break;
	case 7:
		genre1 = Adventure;
		break;
	case 8:
		genre1 = Documentary;
		break;
	case 9:
		genre1 = UNKNOWN;
		break;
	default:
		break;

	}
	return genre1;
}

string MovieDriver::generateID() { //Generates a random ID that starts with a letter (from A to Z) and has a number as the second character. 
	bool endLoop{ false };
	string ID;
	do {
		int counter{ 0 };
		srand(time(NULL));
		string alpha = { "ABCDEFGHIJKLMNOPQRSTUVWXYZ" };
		int randomOne = (rand() % 25); //generate the random number 0-25 that will correspond a letter from the string
		char letter = alpha.at(randomOne);
		int randomTwo = (rand() % 9) + 1;
		int randomThree = (rand() % 9) + 1;									//generates the random number between 1 and 9
		std::stringstream ss; //creates a stringstream object
		string number1;
		string number2;
		ss << randomTwo; //stringstream object converts the randomTwo to string and then assigns it to number
		ss >> number1;
		std::stringstream ss2;
		ss2 << randomThree;
		ss2 >> number2;
		ID = string(1, letter) + number1 + number2; //converts two chars into a string

		for (Movie movs : this->movies) { //checks for uniqueness of the ID
			string stdId = movs.getID();
			if (!ID.compare(stdId) == 0) {
				counter++;
			}
		}
		if (counter == this->movies.size()) {
			endLoop = true;
		}

	} while (!endLoop);
	return ID;
}

void MovieDriver::setMovieFile() {
	std::ofstream movieFile;
	movieFile.open("movies.txt", std::ios::trunc);
	
	for (Movie mov : this->movies) {
		string ID = mov.getID();
		string title = mov.getTitle();
		string genre1 = genre[mov.getGenre1()];
		string genre2 = genre[mov.getGenre2()];
		string summary = mov.getSummary();
		string commentary = mov.getCommentary();
		int ratingInt = mov.getRating();
		string rating;
		{std::stringstream ss;
		ss << ratingInt;

		ss >> rating; }
		
		string timesWatched;
		int timesWatchedInt = mov.getTimesWatched();
		{std::stringstream ss;
		ss << timesWatchedInt;
		ss >> timesWatched; }

		movieFile << ID <<"*"<< title << "*" << genre1 << "*" << genre2 << "*" << summary << "*" << commentary << "*" << rating << "*" << timesWatched << "\n";
	}
	movieFile.close();
}

void MovieDriver::keywordSearch() {
	string keyword;
	bool found = false;
	cout << "Enter a keyword to search: ";
	cin.clear();
	cin.ignore(1000, '\n');
	getline(cin, keyword);
	for (Movie mov : this->movies) {
		if (mov.getTitle().find(keyword) != string::npos || mov.getCommentary().find(keyword) != string::npos || mov.getSummary().find(keyword) != string::npos) {
			cout << endl;
			cout << "The following movie contains the keyword " << keyword << ": " << endl;
			mov.print();
			found = true;
		}
	}
	if (!found) {
		cout << "Keyword not found.\n";
	}
}

void MovieDriver::editMovie() {
	cout << "Enter the ID of the movie you wish to edit: ";
	string id;
	bool found = false;
	cin.clear();
	cin.ignore(1000, '\n');
	
	getline(cin, id);
	for (Movie mov : this->movies) {
		if (mov.getID().compare(id) == 0) {
			cout << "Which field do you want to edit:\n1) Title\n 2) Summary\n3) Commentary\n4) Rating\n5) Times Watched\n6) Genre\n7) Return to Menu" << endl;
			cout << "Enter your choice: ";
			Genre genre;
			int choice;
			string newValue;
			int newNumber;

			cin >> choice;
			switch (choice) {
			case 1:
				cout << mov.getTitle() << endl;
				cout << "\nEnter the new title: ";
				cin.clear();
				cin.ignore(1000, '\n');
				getline(cin, newValue);
				mov.setTitle(newValue);
				cout << mov.getTitle();
				break;
			case 2:
				cout << "\nEnter the new summary: " << endl;
				cin.clear();
				cin.ignore(1000, '\n');
				getline(cin, newValue);
				mov.setSummary(newValue);
				break;
			case 3:
				cout << "\nEnter the new commentary: " << endl;
				cin.clear();
				cin.ignore(1000, '\n');
				getline(cin, newValue);
				mov.setCommentary(newValue);
				break;
			case 4:
				cout << "\nEnter the new rating: ";
				cin.clear();
				cin.ignore(1000, '\n');
				cin >> newNumber;
				mov.setRating(newNumber);
				break;
			case 5:
				cout << "\nEnter the new times watched: ";
				cin.clear();
				cin.ignore(1000, '\n');
				cin >> newNumber;
				mov.setTimesWatched(newNumber);
				break;
			case 6:
				genre = genreSwitch();
				mov.setGenre1(genre);
				cout << "Is there a second genre? Y/N " << endl;
				cin.clear();
				cin.ignore(1000, '\n');
				getline(cin, newValue);
				if (newValue == "Y" || newValue == "y") {
					genre = genreSwitch();
					mov.setGenre2(genre);
				}
				break;
			default:
				break;
			}

		}

			
		
	}
	if (!found) {
		cout << "Movie not found." << endl;
	}
	
}
void MovieDriver::setFields(Movie& mov) {
	
}