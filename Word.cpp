#include "Word.h"


void Word::insertWord(string word, string hint)
{
	this->word = word;
	this->hint = hint;
	wordSize = word.length();
}
string Word::getWord()
{
	return word;
}
string Word::getHint()
{
	return hint;
}
int Word::getWordSize()
{
	return wordSize;
}