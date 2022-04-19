#pragma once
#include "Test_MovieObject.h"
#include "Test_ParseTSV.h"

using namespace std;

vector<Movie> ParseRatingsTSV(string path) {
    vector<Movie> Movies;

    ifstream fin(path);
    string line;
    string movieID;
    double avgRating;
    string s_avgRating;
    string votes;

    getline(fin, line);
    while (getline(fin, line)) {
        stringstream lineStream(line);
        // Split line into tab-separated parts
        getline(lineStream, movieID, '\t');
        getline(lineStream, s_avgRating, '\t');
        avgRating = stod(s_avgRating);
        getline(lineStream, votes, '\t');

        Movies.push_back(Movie(movieID, avgRating));
    }
    fin.close();

    return Movies;
}


void ParseBasicsTSV(string path, vector<Movie>& Movies) {
    ifstream fin(path);
    string line;
    string movieID;
    string title;
    int year;
    string s_year;
    string genres;
    string unused;

    getline(fin, line);
    int i = 0;
    while (getline(fin, line)) {
        stringstream lineStream(line);
        // Split line into tab-separated parts
        getline(lineStream, movieID, '\t');
        getline(lineStream, unused, '\t');
        getline(lineStream, title, '\t');
        getline(lineStream, unused, '\t');
        getline(lineStream, unused, '\t');
        getline(lineStream, s_year, '\t');
        getline(lineStream, unused, '\t');
        getline(lineStream, unused, '\t');
        getline(lineStream, genres, '\t');

        // update the movie object with the title, year, and associated genres
        year = stoi(s_year);
        Movies[i].setTitle(title);
        Movies[i].setYear(year);
        Movies[i].setGenre(genres);
    }
    fin.close();
}