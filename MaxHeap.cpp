#pragma once
#include "MaxHeap.h"



void maxHeapAverageRating::heapifyUp(int index) //change int to movie object
{
	int parentIndex = (index - 1) / 2;
	if (index && movies[parentIndex]->averageRating < movies[index]->averageRating)
	{
		swap(*movies[index], *movies[parentIndex]);
		heapifyUp(parentIndex);
	}
}

void maxHeapAverageRating::heapifyDown(int index) //change int to movie object
{
	int left = index * 2 + 1;
	int right = index * 2 + 2;
	int largestIndex = index;

	if (left < numItems && movies[left]->averageRating > movies[index]->averageRating)
		largestIndex = left;
	if (right < numItems && movies[right]->averageRating > movies[largestIndex]->averageRating)
		largestIndex = right;

	if (largestIndex != index)
	{
		swap(*movies[index], *movies[largestIndex]);
		heapifyDown(largestIndex);
	}
}

maxHeapAverageRating::maxHeapAverageRating()
{
	numItems = 0;
}

maxHeapAverageRating::~maxHeapAverageRating()
{
	for (int i = 0; i < numItems; i++)
	{
		delete movies[i];
	}
}

int maxHeapAverageRating::maxHeapAverageRating::size()
{
	return numItems;
}

bool maxHeapAverageRating::empty()
{
	if (numItems == 0)
		return true;
	return false;
}

void maxHeapAverageRating::push(Movie* newMovie)
{
	this->movies.push_back(newMovie);
	int index = numItems++;
	heapifyUp(index);
}

void maxHeapAverageRating::pop()
{
	if (numItems != 0)
	{
		swap(*movies[0], *movies[--numItems]);
		delete movies[numItems];
		heapifyDown(0);
	}
}

Movie* maxHeapAverageRating::top()
{
	if (numItems == 0)
		return nullptr;
	return movies[0];
}






void maxHeapTitle::heapifyUp(int index) //change int to movie object
{
	int parentIndex = (index - 1) / 2;
	if (index && movies[parentIndex]->title > movies[index]->title)
	{
		swap(*movies[index], *movies[parentIndex]);
		heapifyUp(parentIndex);
	}
}

void maxHeapTitle::heapifyDown(int index) //change int to movie object
{
	int left = index * 2 + 1;
	int right = index * 2 + 2;
	int largestIndex = index;

	if (left < numItems && movies[left]->title < movies[index]->title)
		largestIndex = left;
	if (right < numItems && movies[right]->title < movies[largestIndex]->title)
		largestIndex = right;

	if (largestIndex != index)
	{
		swap(*movies[index], *movies[largestIndex]);
		heapifyDown(largestIndex);
	}
}

maxHeapTitle::maxHeapTitle()
{
	numItems = 0;
}

maxHeapTitle::~maxHeapTitle()
{
	for (int i = 0; i < numItems; i++)
	{
		delete movies[i];
	}
}

int maxHeapTitle::size()
{
	return numItems;
}

bool maxHeapTitle::empty()
{
	if (numItems == 0)
		return true;
	return false;
}

void maxHeapTitle::push(Movie* newMovie)
{
	this->movies.push_back(newMovie);
	int index = numItems++;
	heapifyUp(index);
}

void maxHeapTitle::pop()
{
	if (numItems != 0)
	{
		swap(*movies[0], *movies[--numItems]);
		delete movies[numItems];
		heapifyDown(0);
	}
}

Movie* maxHeapTitle::top()
{
	if (numItems == 0)
		return nullptr;
	return movies[0];
}





void maxHeapYear::heapifyUp(int index) //change int to movie object
{
	int parentIndex = (index - 1) / 2;
	if (index && movies[parentIndex]->year < movies[index]->year)
	{
		swap(*movies[index], *movies[parentIndex]);
		heapifyUp(parentIndex);
	}
}

void maxHeapYear::heapifyDown(int index) //change int to movie object
{
	int left = index * 2 + 1;
	int right = index * 2 + 2;
	int largestIndex = index;

	if (left < numItems && movies[left]->year > movies[index]->year)
		largestIndex = left;
	if (right < numItems && movies[right]->year > movies[largestIndex]->year)
		largestIndex = right;

	if (largestIndex != index)
	{
		swap(*movies[index], *movies[largestIndex]);
		heapifyDown(largestIndex);
	}
}

maxHeapYear::maxHeapYear()
{
	numItems = 0;
}

maxHeapYear::~maxHeapYear()
{
	for (int i = 0; i < numItems; i++)
	{
		delete movies[i];
	}
}

int maxHeapYear::size()
{
	return numItems;
}

bool maxHeapYear::empty()
{
	if (numItems == 0)
		return true;
	return false;
}

void maxHeapYear::push(Movie* newMovie)
{
	this->movies.push_back(newMovie);
	int index = numItems++;
	heapifyUp(index);
}

void maxHeapYear::pop()
{
	if (numItems != 0)
	{
		swap(*movies[0], *movies[--numItems]);
		delete movies[numItems];
		heapifyDown(0);
	}
}

Movie* maxHeapYear::top()
{
	if (numItems == 0)
		return nullptr;
	return movies[0];
}
