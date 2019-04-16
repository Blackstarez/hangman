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
	void printTopBar(int menu);			// 0: 행맨 시작시  1: 그 이외의 경우
	void registerUser();				//사용자 등록하는곳
	void printMenu();					//메뉴를 표시하는 함수
	void startGame(int count);			//새게임 시작
	void printScore(int menu);			//사용자의 점수를 표시	0: 이번 게임의 성적  1:이전 게임의 성적  2:전체사용자의 성적
	void exit(bool menu);				//1 : 저장후 종료 
	void printHangman(int count);
	
};
