#pragma once
#include <algorithm>
#include "Test_MovieObject.h"
#include "Test_ParseTSV.h"

void shellSortRatings(unordered_map<string, Movie>& movieDatabase, vector<string>& movieIDs);
void shellSortTitles(unordered_map<string, Movie>& movieDatabase, vector<string>& movieIDs);
void shellSortYears(unordered_map<string, Movie>& movieDatabase, vector<string>& movieIDs);
vector<string>* shellSortGenres(unordered_map<string, Movie>& movieDatabase, vector<string>& movieIDs, string genre);