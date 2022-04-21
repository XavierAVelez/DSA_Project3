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

    //int limit = 100000; // delete limit to run through entire movie database

    getline(fin, line);
    while (getline(fin, line)) {
        stringstream lineStream(line);
        // Split line into tab-separated parts
        getline(lineStream, movieID, '\t');
        getline(lineStream, s_avgRating, '\t');
        avgRating = stod(s_avgRating);
        getline(lineStream, votes, '\t');
        
        if (!movieDatabase.count(movieID))
            continue;

        movieDatabase[movieID].setRating(avgRating);

        /*
        limit--;
        if (limit == 0)
            break;
        */
    }
    fin.close();
}

void database::ParseBasicsTSV(string path) {
    ifstream fin(path);
    string line;
    string movieID;
    string title;
    string title_type;
    int year;
    string s_year;
    string genres;
    string unused;

    //int limit = 100000; // delete limit to run through entire movie database

    getline(fin, line);
    while (getline(fin, line)) {
        stringstream lineStream(line);
        // Split line into tab-separated parts
        getline(lineStream, movieID, '\t');
        getline(lineStream, title_type, '\t');
        getline(lineStream, title, '\t');
        getline(lineStream, unused, '\t');
        getline(lineStream, unused, '\t');
        getline(lineStream, s_year, '\t');
        getline(lineStream, unused, '\t');
        getline(lineStream, unused, '\t');
        getline(lineStream, genres, '\t');

        if (title_type.compare("movie"))
            continue;

        // update the movie object with the title, year, and associated genres
        if (!s_year.compare("\\N"))
            year = 0;
        else
            year = stoi(s_year);

        Movie newMovie = Movie(movieID, title, year);
        movieDatabase[movieID] = newMovie;
        movieIDs.push_back(movieID);
        movieDatabase[movieID].setGenre(genres);
        movieDatabase[movieID].setRating(0.0);
        
        /*
        limit--;
        if (limit == 0)
            break;
        */
    }
    fin.close();
}