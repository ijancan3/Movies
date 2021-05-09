// Movies.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include "movieDriver.h"

int main()
{
    MovieDriver newMovie;
    newMovie.parseMovies();
    newMovie.runStartLoop();
    /*newMovie.parseMovies();
    cout << "\n\n";
    newMovie.printMovies();*/
    /*std::fstream myfile;
    myfile.open("movies.txt", std::ios::in|std::ios::out|std::ios::app);
    if (myfile.is_open()) {
        std::cout << "Opening..";
    }
    myfile << "First line\n";
    myfile << "Second line";
    myfile.close();
    std::string first;
    std::string second;
    myfile.open("movies.txt", std::ios::in | std::ios::out | std::ios::app);
    getline(myfile, first);
    getline(myfile, second);

    std::cout << first<<std::endl;
    std::cout << second;*/


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
