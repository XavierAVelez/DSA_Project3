#pragma once
#include "Test_MovieObject.h"
#include "Test_ParseTSV.h"

using namespace std;

void database::ParseRatingsTSV(string path) { //MAKE THIS ACCESS ALREADY CREATED MAP

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

        movieDatabase[movieID].setRating(avgRating);
    }
    fin.close();
}

void database::ParseBasicsTSV(string path) {
    ifstream fin(path);
    string line;
    string movieID;
    string title;
    int year;
    string s_year;
    string genres;
    string unused;

    getline(fin, line);
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
        
        Movie newMovie = Movie(movieID, title, year);
        movieDatabase[movieID] = newMovie;
        movieIDs.push_back(movieID);
        movieDatabase[movieID].setGenre(genres);
    }
    fin.close();
}