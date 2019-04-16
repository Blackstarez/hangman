#pragma once
#include "Array.h"
#include "Player.h"
#include "Word.h"
#include <ctime>
#include <string>
#include <locale.h>
#include <algorithm>
#include <Windows.h>
#include <iostream>
using namespace std;

class Game
{
public:
	Array<Player> players;
	Array<Word> words;

private:
	int menu;
	Player newPlayer;
	
public:
	Game()
	{
		menu = 0;		
	}
	void printTopBar(int menu);			// 0: ��� ���۽�  1: �� �̿��� ���
	void registerUser();				//����� ����ϴ°�
	void printMenu();					//�޴��� ǥ���ϴ� �Լ�
	void startGame(int count);			//������ ����
	void printScore(int menu);			//������� ������ ǥ��	0: �̹� ������ ����  1:���� ������ ����  2:��ü������� ����
	void exit(bool menu);				//1 : ������ ���� 
	void printHangman(int count);
	
};
