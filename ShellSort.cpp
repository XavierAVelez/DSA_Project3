#include "ShellSort.h"
using namespace std;

void shellSortRatings(unordered_map<string, Movie>& movieDatabase, vector<string>& movieIDs) {
	// iterate through gaps starting with n/2
	int gap = movieIDs.size() / 2;
	while (gap > 0) {
		for (unsigned int i = gap; i < movieIDs.size(); i++) {
			int j = i;

			while (movieDatabase[movieIDs[j]].averageRating > movieDatabase[movieIDs[j - gap]].averageRating) {
				swap(movieIDs[j], movieIDs[j-gap]);
				j -= gap;
				if (j-gap < 0)
					break;
			}
		}

		if (gap == 2)
			gap = 1;
		else
			gap /= 2.2;
	}
}


void shellSortTitles(unordered_map<string, Movie>& movieDatabase, vector<string>& movieIDs) {
	// iterate through gaps starting with n/2
	int gap = movieIDs.size() / 2;
	while (gap > 0) {
		for (unsigned int i = gap; i < movieIDs.size(); i++) {
			int j = i;

			while (movieDatabase[movieIDs[j]].title.compare(movieDatabase[movieIDs[j - gap]].title) < 0) {
				swap(movieIDs[j], movieIDs[j - gap]);
				j -= gap;
				if (j - gap < 0)
					break;
			}
		}

		if (gap == 2)
			gap = 1;
		else
			gap /= 2.2;
	}
}


void shellSortYears(unordered_map<string, Movie>& movieDatabase, vector<string>& movieIDs) {
	// iterate through gaps starting with n/2
	int gap = movieIDs.size() / 2;
	while (gap > 0) {
		for (unsigned int i = gap; i < movieIDs.size(); i++) {
			int j = i;

			while (movieDatabase[movieIDs[j]].year > movieDatabase[movieIDs[j-gap]].year) {
				swap(movieIDs[j], movieIDs[j - gap]);
				j -= gap;
				if (j - gap < 0)
					break;
			}
		}

		if (gap == 2)
			gap = 1;
		else
			gap /= 2.2;
	}
}


vector<string>* shellSortGenres(unordered_map<string, Movie>& movieDatabase, vector<string>& movieIDs, string genre) {
	// create a vector of movies that belong to the specified genre
	vector<string>* genreMovies = new vector<string>;

	for (unsigned int i = 0; i < movieIDs.size(); i++) {
		if (find(movieDatabase[movieIDs[i]].genres.begin(), movieDatabase[movieIDs[i]].genres.end(), genre) != movieDatabase[movieIDs[i]].genres.end()) {
			genreMovies->push_back(movieIDs[i]);
		}
	}

	// iterate through gaps starting with n/2
	int gap = genreMovies->size() / 2;
	while (gap > 0) {
		for (unsigned int i = gap; i < genreMovies->size(); i++) {
			int j = i;

			while (movieDatabase[(*genreMovies)[j]].averageRating > movieDatabase[(*genreMovies)[j - gap]].averageRating) {
				swap((*genreMovies)[j], (*genreMovies)[j - gap]);
				j -= gap;
				if (j - gap < 0)
					break;
			}
		}

		if (gap == 2)
			gap = 1;
		else
			gap /= 2.2;
	}

	return genreMovies;
}