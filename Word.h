#pragma once
#include <string>
using namespace std;

class Word
{
	
	string word;
	string hint;
	int wordSize;
public:
	Word() {};
	void insertWord(string word, string hint);
	string getWord();
	string getHint();
	int getWordSize();
	


};

