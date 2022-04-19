#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
using namespace std;

struct Movie {
	string movieID;
	double averageRating;
	string title;
	vector<string> genres;
	int year;

	Movie(string movieID, double avgRating) {
		this->movieID = movieID;
		this->averageRating = avgRating;
	}

	void setTitle(string title) { this->title = title; }
	void setYear(int year) { this->year = year; }

	void setGenre(string genres) {
		// input is a comma separated string of genres (max 3)
		// setGenre separates and stores each genre in the genres vector
		stringstream genreStream(genres);
		string newGenre;
		while (getline(genreStream, newGenre, ',')) {
			this->genres.push_back(newGenre);
		}
	}
};