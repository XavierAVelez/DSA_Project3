#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <unordered_map>
#include "Test_MovieObject.h"
using namespace std;

struct database
{
	unordered_map<string, Movie> movieDatabase;
	vector<string> movieIDs;

	database(string basicsTSV, string ratingsTSV)
	{
		ParseBasicsTSV(basicsTSV);
		ParseRatingsTSV(ratingsTSV);
	}

	void ParseRatingsTSV(string path);
	void ParseBasicsTSV(string path);


};