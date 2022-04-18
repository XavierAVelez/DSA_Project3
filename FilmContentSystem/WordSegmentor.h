#pragma once

#include "CharStringLink.h"
#include "HashMap.hpp"
#include <string>

const int MAX_HAN_CODE = 50000;	

class WordSegmentor
{
	// 词典和停用词典，dict中的value存储词频，stopwords中的value无意义（实际上是 HashSet）
	HashMap<CharString, int> dict, stopwords;
	
	// 记录每个字作为量词结尾的出现次数，用于判断某一词是否为量词
	int *numeralFreq;
	
	int totalFreq, numWords;		// 总词频，总词数
	int maxWordLen;					// 最长的词长

	bool toConcatNumerals;			// 是否连接数字和量词，默认为true
	bool hasStopwords;				// 是否载入停用词典
	bool hasHMM;					// 是否载入HMM参数

	// HMM的参数（对数意义下）
	double (*probEmit)[4];
	double probStart[4];
	double probTrans[4][4];

	// viterbi算法使用的数组
	double *logProb; int *jump;
	double(*vit)[4]; int *optState;
	
	static int state2Idx(char s);	// 将BEMS分别转化为0123

	// 使用HMM来处理连续的单字序列，以识别未登录词
	void viterbi(const CharString& sentense);
	CharStringLink cut_HMM(const CharString &sentense);

	// DP求解最大概率分割
	void calcDAG(const CharString &sentense);
	
	// useHMM==false 时调用，直接使用DP分割
	CharStringLink cut_DAG(const CharString &sentense);
	// useHMM==true 时调用，DP分割后用HMM识别未登录词
	CharStringLink cut_DAG_HMM(const CharString &sentense);

	// toConcatNumerals==true 时调用，连接数字和量词
	CharStringLink concatNumerals(const CharStringLink &words);
	// useStopwords==true 时调用，移除停用词
	CharStringLink removeStopwords(const CharStringLink& words);
public:
	WordSegmentor();
	~WordSegmentor();

	// 要求 dictFile，hmmFile，stopwordsFile 都为 UTF-8 编码
	bool loadDict(const char *dictFile);
	void loadHMM(const char *hmmFile);
	void loadStopwords(const char *stopwordsFile);
	
	CharStringLink cut(const CharString &passage, bool useHMM = true, bool useStopwords = false);
};
