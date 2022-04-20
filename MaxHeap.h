#pragma once
#include<iostream>
#include<vector>
#include<string>
#include"Movie.h"

using namespace std;

/*
if this string appending doesnt work just get rid of template and make 3 heaps with differnt
names ex: maxHeapRating, maxHeapTitle, maxHeapYear and copy paste code hard code movies[index].rating etc
*/

class maxHeapAverageRating
{
private:
	vector<Movie*> movies; //change int to movie object once working
	int numItems;

	void heapifyUp(int index); //change int to movie object


	void heapifyDown(int index); //change int to movie object


public:
	maxHeapAverageRating();

	~maxHeapAverageRating();

	int size();

	bool empty();

	void push(Movie* newMovie);

	void pop();

	Movie* top();
};



class maxHeapTitle
{
private:
	vector<Movie*> movies; //change int to movie object once working
	int numItems;

	void heapifyUp(int index); //change int to movie object


	void heapifyDown(int index); //change int to movie object


public:
	maxHeapTitle();

	~maxHeapTitle();

	int size();

	bool empty();

	void push(Movie* newMovie);

	void pop();

	Movie* top();
};



class maxHeapYear
{
private:
	vector<Movie*> movies; //change int to movie object once working
	int numItems;

	void heapifyUp(int index); //change int to movie object


	void heapifyDown(int index); //change int to movie object


public:
	maxHeapYear();

	~maxHeapYear();

	int size();

	bool empty();

	void push(Movie* newMovie);

	void pop();

	Movie* top();
};

