#pragma once

#include "FilmInfo.h"
#include "WordSegmentor.h"
#include "HtmlParser.h"
#include "Vector.hpp"
#include "InvertedIndex.hpp"
#include "BalancedBST.hpp"

/*------------------------default configuration-----------------------------*/

const char DEFAULT_CONFIG_PATH[] = "FilmContentSystem.config";

const char DEFAULT_INPUT_DIR[] = "input/";
const char DEFAULT_OUTPUT_DIR[] = "output/";

const char DEFAULT_DICT_PATH[] = "dict/dict.txt";
const char DEFAULT_HMM_PATH[] = "dict/HMM.txt";
const char DEFAULT_STOP_PATH[] = "dict/stopwords.txt";

const bool DEFAULT_USE_HMM = true;
const bool DEFAULT_USE_STOP = false;

const char RETRIEVAL_INPUT[] = "query1.txt";
const char RETRIEVAL_OUTPUT[] = "result1.txt";
const char RECOMMEND_INPUT[] = "query2.txt";
const char RECOMMEND_OUTPUT[] = "result2.txt";

const int MAX_FLAG_LEN = 500;	// config中flag的最大长度

/*-------------------------END: default configuration-------------------------*/

/*
FilmContentSystemApplication
Description: The application class of this project, which implements functions such as loading a dictionary, parsing html, and word segmentation
API：	loadConfig, loadDatabase, buildIndex
		initDictionary, extractInfo, divideWords
		retrieve, recommend
		doRetrieve, doRecommend
		run
*/

class FilmContentSystemApplication
{
private:
	WordSegmentor segmentor;	
	HtmlParser parser;		
	
	// The path where the input and output files are stored
	char inputDir[MAX_FLAG_LEN], outputDir[MAX_FLAG_LEN];
	// Batch retrieval of input and output files
	char retrieInput[MAX_FLAG_LEN], retrieOutput[MAX_FLAG_LEN];
	// Batch recommend input and output files
	char recommInput[MAX_FLAG_LEN], recommOutput[MAX_FLAG_LEN];
	// Dictionary, HMM parameters, path to disabled dictionary
	char dictFile[MAX_FLAG_LEN], hmmFile[MAX_FLAG_LEN], stopwordsFile[MAX_FLAG_LEN];
	//Whether word segmentation enables HMM and stop words
	bool useHMM, useStopwords;

	// total number of movies
	int docCnt;

	// Movie information analysis results
	Vector<FilmInfo> filmInfos;
	// Plot synopsis word segmentation results
	Vector<CharStringLink> filmWords;
	// Inverted documents corresponding to word segmentation and type, which are used for retrieval and recommendation respectively
	// Template parameter index_t can be optionally SplayTree or HashMap
	InvertedIndex<SplayTree> wordIndex, genreIndex;
	//Map movie names to movie ids
	HashMap<CharString, int> filmIdMap;
public:
	FilmContentSystemApplication();
	~FilmContentSystemApplication();

	bool init(const char *configFile = nullptr);

	void run(const char *configFile = nullptr);

	// Read config, requiring the config file to be encoded in UTF-8
	void loadConfig(const char *configFile);
	// Load Movie Database
	void loadDatabase();
	//Create an inverted document
	void buildIndex();
	// Bulk retrieval
	void doRetrieve();
	// Bulk recommendation
	void doRecommend();

	// Read dictionary, HMM parameters, disable dictionary
	bool initDictionary(const char *dictFile, const char *hmmFile = nullptr, const char *stopwordsFile = nullptr);
	// Parse Html
	FilmInfo extractInfo(const char *htmlFile);
	// word segmentation
	CharStringLink divideWords(const CharString &passage, bool useHMM, bool useStopwords);
	//Retrieve, return the movie id, the number of keywords and the total number of occurrences of keywords
	Vector<std::pair<int, std::pair<int, int>>> retrieve(const CharStringLink &keywords) const;
	// Recommendation, return the movie id and movie name of topK, the recommendation is mainly based on the movie rating and genre, and refer to the director, starring, label, region
	Vector<std::pair<int, CharString>> recommend(int docId, int topK) const;

	// Query interface for GUI
	bool getUseHMM() const { return useHMM; }
	bool getUseStopwords() const { return useStopwords; }
	bool hasName(const CharString &name) const { return filmIdMap.find(name); }
	int getIdFromName(const CharString& name) const { return filmIdMap.at(name); }
	const FilmInfo& getInfo(int idx) const { return filmInfos[idx]; }
	std::wstring getInputDir() const;
};

// Convert file path to ANSI encoding
extern void filePathCvtCode(char *filepath);
// Read movie parsing result file *.info
extern void readFilmInfo(const char *file, FilmInfo &info);
//Read word segmentation result file *.txt
extern void readFilmWord(const char *file, CharStringLink &cuts);