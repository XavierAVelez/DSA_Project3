#pragma once
#include "Test_MovieObject.h"
#include "Test_ParseTSV.h"
#include "ShellSort.h"

int main() {
	string basicsFilePath = "C:/Users/Xavier Velez/Documents/COP3530/Project3/basics.tsv";
	string ratingsFilePath = "C:/Users/Xavier Velez/Documents/COP3530/Project3/movie_finder/ratings.tsv";
	
	database allMovies = database(basicsFilePath, ratingsFilePath);

	cout << "All movies loaded..." << endl;
	

	cout << "Rating Sort:" << endl;
	shellSortRatings(allMovies.movieDatabase, allMovies.movieIDs);
	for (int i = 0; i < 100; i++) {
		cout << allMovies.movieDatabase[allMovies.movieIDs[i]].title << '\t';
		cout << allMovies.movieDatabase[allMovies.movieIDs[i]].averageRating << '\t';
		cout << allMovies.movieDatabase[allMovies.movieIDs[i]].year << endl;
	}
	cout << "\n\n" << endl;


	cout << "Title Sort:" << endl;
	shellSortTitles(allMovies.movieDatabase, allMovies.movieIDs);
	for (int i = 0; i < 100; i++) {
		cout << allMovies.movieDatabase[allMovies.movieIDs[i]].title << '\t';
		cout << allMovies.movieDatabase[allMovies.movieIDs[i]].averageRating << '\t';
		cout << allMovies.movieDatabase[allMovies.movieIDs[i]].year << endl;
	}
	cout << "\n\n" << endl;


	cout << "Recent Sort:" << endl;
	shellSortYears(allMovies.movieDatabase, allMovies.movieIDs);
	for (int i = 0; i < 100; i++) {
		cout << allMovies.movieDatabase[allMovies.movieIDs[i]].title << '\t';
		cout << allMovies.movieDatabase[allMovies.movieIDs[i]].averageRating << '\t';
		cout << allMovies.movieDatabase[allMovies.movieIDs[i]].year << endl;
	}
	cout << "\n\n" << endl;


	cout << "Genre Sort:" << endl;
	vector<string>* sortedGenres = shellSortGenres(allMovies.movieDatabase, allMovies.movieIDs, "Comedy");
	for (int i = 0; i < 100; i++) {
		cout << allMovies.movieDatabase[(*sortedGenres)[i]].title << '\t';
		cout << allMovies.movieDatabase[(*sortedGenres)[i]].averageRating << '\t';
		cout << allMovies.movieDatabase[(*sortedGenres)[i]].year << endl;
	}
	delete sortedGenres;

	return 0;
}