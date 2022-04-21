#pragma once
#include "Test_MovieObject.h"
#include "Test_ParseTSV.h"
#include "ShellSort.h"
#include "MaxHeap.h"

int main() {
	string basicsFilePath = "C:/Users/Xavier Velez/Documents/COP3530/Project3/basics.tsv";
	string ratingsFilePath = "C:/Users/Xavier Velez/Documents/COP3530/Project3/movie_finder/ratings.tsv";
	
	cout << "Initializing Movie Database. Please Wait..." << endl;
	database allMovies = database(basicsFilePath, ratingsFilePath);

	cout << "All movies loaded..." << endl;

	int choice = 0;
	while (choice != 5) {
		cout << "Welcome to Movie Finder!" << endl;
		cout << "Please select an option from the menu below by entering a number 1-5" << endl;
		cout << "1. Find 100 Top Rated Movies Using Both Methods" << endl;
		cout << "2. Find First 100 Movies In Alphabetical Order Using Both Methods" << endl;
		cout << "3. Find 100 Most Recent Movies" << endl;
		cout << "4. Find 100 Top Rated Movies by Genre using Both Methods" << endl;
		cout << "5. Quit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		if (choice == 1) {
			// load and display top rated movies and times using heap
			// create the heap of average ratings
			maxHeapAverageRating avgHeap;
			for (int i = 0; i < allMovies.movieIDs.size(); i++) {
				Movie tempMovie = allMovies.movieDatabase[allMovies.movieIDs[i]];
				Movie* newMovie = new Movie(tempMovie);
				avgHeap.push(newMovie);
			}

			// display the heap of average ratings
			cout << "\nRating Heap:" << endl;
			Movie* displayMovie;
			for (int i = 0; i < 100; i++) {
				displayMovie = avgHeap.top();
				cout << displayMovie->title << '\t';
				cout << displayMovie->averageRating << '\t';
				cout << displayMovie->year << endl;
				avgHeap.pop();
			}
			// delete the rest of the heap
			for (int i = 0; i < avgHeap.size(); i++) {
				avgHeap.pop();
			}


			// load and display top rated movies using shell sort
			shellSortRatings(allMovies.movieDatabase, allMovies.movieIDs);
			cout << "\nRating Sort:" << endl;
			for (int i = 0; i < 100; i++) {
				cout << allMovies.movieDatabase[allMovies.movieIDs[i]].title << '\t';
				cout << allMovies.movieDatabase[allMovies.movieIDs[i]].averageRating << '\t';
				cout << allMovies.movieDatabase[allMovies.movieIDs[i]].year << endl;
			}
			cout << "\n\n" << endl;
		}
		else if (choice == 2) {
			// load and display movies in alphabetical order using heap
			// create the heap of titles
			maxHeapTitle titleHeap;
			for (int i = 0; i < allMovies.movieIDs.size(); i++) {
				Movie tempMovie = allMovies.movieDatabase[allMovies.movieIDs[i]];
				Movie* newMovie = new Movie(tempMovie);
				titleHeap.push(newMovie);
			}

			// display the heap of titles
			cout << "\nTitle Heap:" << endl;
			Movie* displayMovie;
			for (int i = 0; i < 100; i++) {
				displayMovie = titleHeap.top();
				cout << displayMovie->title << '\t';
				cout << displayMovie->averageRating << '\t';
				cout << displayMovie->year << endl;
				titleHeap.pop();
			}
			// delete the rest of the heap
			for (int i = 0; i < titleHeap.size(); i++) {
				titleHeap.pop();
			}
			
			// load and display movies in alphabetical order using shell sort
			shellSortTitles(allMovies.movieDatabase, allMovies.movieIDs);
			cout << "\nTitle Sort:" << endl;
			for (int i = 0; i < 100; i++) {
				cout << allMovies.movieDatabase[allMovies.movieIDs[i]].title << '\t';
				cout << allMovies.movieDatabase[allMovies.movieIDs[i]].averageRating << '\t';
				cout << allMovies.movieDatabase[allMovies.movieIDs[i]].year << endl;
			}
			cout << "\n\n" << endl;
		}
		else if (choice == 3) {
			// load and display most recent movies with heap
			// create the heap of years
			maxHeapYear yearHeap;
			for (int i = 0; i < allMovies.movieIDs.size(); i++) {
				Movie tempMovie = allMovies.movieDatabase[allMovies.movieIDs[i]];
				Movie* newMovie = new Movie(tempMovie);
				yearHeap.push(newMovie);
			}

			// display the heap of average ratings
			cout << "\nYear Heap:" << endl;
			Movie* displayMovie;
			for (int i = 0; i < 100; i++) {
				displayMovie = yearHeap.top();
				cout << displayMovie->title << '\t';
				cout << displayMovie->averageRating << '\t';
				cout << displayMovie->year << endl;
				yearHeap.pop();
			}
			// delete the rest of the heap
			for (int i = 0; i < yearHeap.size(); i++) {
				yearHeap.pop();
			}

			// load and display most recent movies with shell sort
			shellSortYears(allMovies.movieDatabase, allMovies.movieIDs);
			cout << "\nRecent Sort:" << endl;
			for (int i = 0; i < 100; i++) {
				cout << allMovies.movieDatabase[allMovies.movieIDs[i]].title << '\t';
				cout << allMovies.movieDatabase[allMovies.movieIDs[i]].averageRating << '\t';
				cout << allMovies.movieDatabase[allMovies.movieIDs[i]].year << endl;
			}
			cout << "\n\n" << endl;
		}
		else if (choice == 4) {
			// ask for user input on the genre
			string inputGenre;
			cout << "Input the genre of movie";
			cin >> inputGenre;

			// load top rated movies by genre using heap
			maxHeapAverageRating avgHeap;
			for (int i = 0; i < allMovies.movieIDs.size(); i++) {
				Movie tempMovie = allMovies.movieDatabase[allMovies.movieIDs[i]];
				if (find(tempMovie.genres.begin(), tempMovie.genres.end(), inputGenre) != tempMovie.genres.end()) {
					Movie* newMovie = new Movie(tempMovie);
					avgHeap.push(newMovie);
				}
			}

			// display the heap of average ratings
			cout << "\nRating By Genre Heap:" << endl;
			Movie* displayMovie;
			for (int i = 0; i < 100; i++) {
				displayMovie = avgHeap.top();
				cout << displayMovie->title << '\t';
				cout << displayMovie->averageRating << '\t';
				cout << displayMovie->year << endl;
				avgHeap.pop();
			}
			// delete the rest of the heap
			for (int i = 0; i < avgHeap.size(); i++) {
				avgHeap.pop();
			}

			
			// load top rated movies by genre using shell sort
			vector<string>* sortedGenres = shellSortGenres(allMovies.movieDatabase, allMovies.movieIDs, inputGenre);
			cout << "\nRating By Genre Sort:" << endl;
			for (int i = 0; i < 100; i++) {
				cout << allMovies.movieDatabase[(*sortedGenres)[i]].title << '\t';
				cout << allMovies.movieDatabase[(*sortedGenres)[i]].averageRating << '\t';
				cout << allMovies.movieDatabase[(*sortedGenres)[i]].year << endl;
			}
			delete sortedGenres;
			cout << "\n\n" << endl;
		}
	}

	return 0;
}