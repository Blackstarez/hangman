#pragma once
#include <string>
using namespace std;


class Player
{
	string name;
	int win;
	int lose;
public:
	Player()
	{
		win = 0;
		lose = 0;
	}
	void setPlayer(string name, int win, int lose);
	string getName();
	int getWin();
	int getLose();
	void plusScore(int newWin, int newLose);

	Player& operator=(Player& newPlayer);
	
	
}; 

