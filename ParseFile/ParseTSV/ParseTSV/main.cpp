#pragma once
#include "Test_MovieObject.h"
#include "Test_ParseTSV.h"

int main() {
	string basicsFilePath = "basics.tsv";
	string ratingsFilePath = "ratings.tsv";

	database allMovies = database(basicsFilePath, ratingsFilePath);

	for (int i = 0; i < 50; i++) {
		string currID = allMovies.movieIDs[i];
		cout << allMovies.movieDatabase[currID].movieID << '\t';
		cout << allMovies.movieDatabase[currID].title << '\t';
		cout << allMovies.movieDatabase[currID].averageRating << '\t';
		for (unsigned int j = 0; j < allMovies.movieDatabase[currID].genres.size(); j++)
			cout << allMovies.movieDatabase[currID].genres[j] << ' ';
	}

	return 0;
}