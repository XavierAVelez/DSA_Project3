#pragma once

#include "CharStringLink.h"
#include "HashMap.hpp"
#include <string>

const int MAX_HAN_CODE = 50000;	

class WordSegmentor
{
	// Dictionary and stop dictionary, the value in dict stores word frequency, the value in stopwords is meaningless (actually HashSet)
	HashMap<CharString, int> dict, stopwords;
	
	// Record the number of occurrences of each word as the end of a quantifier to determine whether a word is a quantifier
	int *numeralFreq;
	
	int totalFreq, numWords;		
	int maxWordLen;					

	bool toConcatNumerals;			
	bool hasStopwords;				
	bool hasHMM;					

	// Parameters of HMM (in logarithmic sense)
	double (*probEmit)[4];
	double probStart[4];
	double probTrans[4][4];

	// Arrays used by the viterbi algorithm
	double *logProb; int *jump;
	double(*vit)[4]; int *optState;
	
	static int state2Idx(char s);	

	//Use HMM to process consecutive word sequences to identify unregistered words
	void viterbi(const CharString& sentense);
	CharStringLink cut_HMM(const CharString &sentense);

	// DP solves the maximum probability segmentation
	void calcDAG(const CharString &sentense);
	
	// Called when useHMM==false, directly use DP segmentation
	CharStringLink cut_DAG(const CharString &sentense);
	// Called when useHMM==true, use HMM to identify unregistered words after DP segmentation
	CharStringLink cut_DAG_HMM(const CharString &sentense);

	// Called when toConcatNumerals==true, concatenates numbers and quantifiers
	CharStringLink concatNumerals(const CharStringLink &words);
	// Called when useStopwords==true to remove stop words
	CharStringLink removeStopwords(const CharStringLink& words);
public:
	WordSegmentor();
	~WordSegmentor();

	// Require dictFile, hmmFile, stopwordsFile to be UTF-8 encoded
	bool loadDict(const char *dictFile);
	void loadHMM(const char *hmmFile);
	void loadStopwords(const char *stopwordsFile);
	
	CharStringLink cut(const CharString &passage, bool useHMM = true, bool useStopwords = false);
};
