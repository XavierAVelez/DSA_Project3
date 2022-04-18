#pragma once

#include "CharStringLink.h"
#include "HashMap.hpp"
#include <string>

const int MAX_HAN_CODE = 50000;	

class WordSegmentor
{
	// �ʵ��ͣ�ôʵ䣬dict�е�value�洢��Ƶ��stopwords�е�value�����壨ʵ������ HashSet��
	HashMap<CharString, int> dict, stopwords;
	
	// ��¼ÿ������Ϊ���ʽ�β�ĳ��ִ����������ж�ĳһ���Ƿ�Ϊ����
	int *numeralFreq;
	
	int totalFreq, numWords;		// �ܴ�Ƶ���ܴ���
	int maxWordLen;					// ��Ĵʳ�

	bool toConcatNumerals;			// �Ƿ��������ֺ����ʣ�Ĭ��Ϊtrue
	bool hasStopwords;				// �Ƿ�����ͣ�ôʵ�
	bool hasHMM;					// �Ƿ�����HMM����

	// HMM�Ĳ��������������£�
	double (*probEmit)[4];
	double probStart[4];
	double probTrans[4][4];

	// viterbi�㷨ʹ�õ�����
	double *logProb; int *jump;
	double(*vit)[4]; int *optState;
	
	static int state2Idx(char s);	// ��BEMS�ֱ�ת��Ϊ0123

	// ʹ��HMM�����������ĵ������У���ʶ��δ��¼��
	void viterbi(const CharString& sentense);
	CharStringLink cut_HMM(const CharString &sentense);

	// DP��������ʷָ�
	void calcDAG(const CharString &sentense);
	
	// useHMM==false ʱ���ã�ֱ��ʹ��DP�ָ�
	CharStringLink cut_DAG(const CharString &sentense);
	// useHMM==true ʱ���ã�DP�ָ����HMMʶ��δ��¼��
	CharStringLink cut_DAG_HMM(const CharString &sentense);

	// toConcatNumerals==true ʱ���ã��������ֺ�����
	CharStringLink concatNumerals(const CharStringLink &words);
	// useStopwords==true ʱ���ã��Ƴ�ͣ�ô�
	CharStringLink removeStopwords(const CharStringLink& words);
public:
	WordSegmentor();
	~WordSegmentor();

	// Ҫ�� dictFile��hmmFile��stopwordsFile ��Ϊ UTF-8 ����
	bool loadDict(const char *dictFile);
	void loadHMM(const char *hmmFile);
	void loadStopwords(const char *stopwordsFile);
	
	CharStringLink cut(const CharString &passage, bool useHMM = true, bool useStopwords = false);
};
