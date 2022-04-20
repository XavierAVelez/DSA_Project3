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

	Movie()
	{
		movieID = "NULL";
		averageRating = -1;
		title = "NULL";
		genres = {};
		year = -1;
	}

	Movie(string movieID, double avgRating) {
		this->movieID = movieID;
		this->averageRating = avgRating;
	}

	Movie(string movieID, string title, int year) {
		this->movieID = movieID;
		this->title = title;
		this->year = year;
	}

	Movie(const Movie& other)
	{
		this->movieID = other.movieID;
		this->title = other.title;
		this->averageRating = other.averageRating;
		this->year = other.year;
		this->genres = other.genres;
	}

	void setRating(double rating) {
		this->averageRating = rating;
	}

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
