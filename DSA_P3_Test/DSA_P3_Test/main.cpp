#pragma once
#include "Test_MovieObject.h"
#include "Test_ParseTSV.h"

int main() {
	string filePath = "ratings.tsv";
	vector<Movie> Movies = ParseRatingsTSV(filePath);

	filePath = "../../Project3/basics.tsv";
	ParseBasicsTSV(filePath, Movies);

	for (int i = 0; i < 50; i++) {
		cout << Movies[i].movieID << '\t';
		cout << Movies[i].title << '\t';
		cout << Movies[i].year << '\t';
		for (unsigned int j = 0; j < Movies[i].genres.size(); j++)
			cout << Movies[i].genres[j] << ' ';
		
		cout << '\t' << Movies[i].averageRating << endl;
	}

	return 0;
}