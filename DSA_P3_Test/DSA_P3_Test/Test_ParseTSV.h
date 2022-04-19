#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include "Test_MovieObject.h"
using namespace std;

vector<Movie> ParseRatingsTSV(string path);
void ParseBasicsTSV(string path, vector<Movie>& Movies);