#pragma once
#include <string>
#include "Player.h"
#include "Word.h"
using namespace std;


template <typename T>
class Array
{
public:
	friend class Game;
	T *item;
private:
	int size;
	int fill;
public:
	Array()
	{
		size = 10;
		fill = 0;
		item = new T[size];
	}
	~Array()
	{
		delete[] item;
	}
	int playerSearch(string itemName);
	bool isEmpty();
	void setWord(string word, string hint);
	
	void setPlayer(string name,int win, int lose);
	void reSize(int newSize);
	int getFill();
};

template <typename T>
int Array<T>::playerSearch(string itemName)
{
	for (int i = 0; i < fill; i++)
	{
		if (item[i].getName().compare(itemName)==0)
			return i;
	}
	return -1;
}

template <typename T>
bool Array<T>::isEmpty()
{
	return !fill;
}

template <typename T>
void Array<T>::setWord(string word, string hint)
{
	if (fill + 1 == size)
		reSize(size * 2);
	item[fill].insertWord(word, hint);
	fill++;
}


template <typename T>
void Array<T>::setPlayer(string name, int win, int lose)
{
	if (fill + 1 == size)
		reSize(size * 2);
	item[fill].setPlayer(name, win, lose);
	fill++;
}

template <typename T>
void Array<T>::reSize(int newSize)
{
	T *tmp = new T[newSize];
	for (int i = 0; i < fill; i++)
	{
		tmp[i] = item[i];
	}
	delete[]item;

	item = tmp;
	
	size = newSize;
	
}

template <typename T>
int Array<T>::getFill()
{
	return fill;
}