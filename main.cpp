#include "Game.h"
#include "Array.h"
#include <locale.h>
#include <algorithm>
#include <fstream>
#include <iostream>
using namespace std;


void sortPlayerList(Array<Player>& userList);


int main(int argc,char *argv[])
{
	_wsetlocale(LC_ALL, L"korean");
	Game newGame;
	
	string human,name,win,lose;
	string  word, hint;
	ifstream indict,inUser;
	int cnt = 0;
	

	indict.open(argv[1]);		//사전	
	while (1)
	{
		if (indict.eof())
			break;
		getline(indict, hint);
		if (hint.length() < 2)
			continue;
	
		hint.erase(0, hint.find_first_not_of(" "));
		cout << hint << endl;
		word = hint.substr(hint.find_first_not_of("["), hint.find_first_of("]") - 1);
		hint.erase(0, hint.find_first_of("]") + 1);
		hint.erase(0, hint.find_first_not_of(" "));
		
		newGame.words.setWord(word,hint);
	}
	

	inUser.open(argv[2]);		//사람
	Array<Player> userList;
	while (1)
	{
		if (inUser.eof())
			break;
		getline(inUser, human);
		if (human.length() < 2)
			continue;
		
		human.erase(0, human.find_first_not_of(" "));
		cout << human << endl;
		name = human.substr(human.find_first_not_of("["), human.find_first_of("]") - 1);

		human.erase(0, human.find_first_of("]") + 1);

		win = human.substr(human.find_first_of("[") + 1, human.find_first_of("]") - 2);

		human.erase(0, human.find_first_of("]") + 1);

		lose = human.substr(human.find_first_of("[") + 1, human.find_first_of("]") - 2);

		userList.setPlayer(name, atoi(win.c_str()), atoi(lose.c_str()));
		//newGame.players.setPlayer(name, atoi(win.c_str()), atoi(lose.c_str()));
		cnt++;
	}

	sortPlayerList(userList);

	for (int i = 0; i < userList.getFill(); i++)
	{
		newGame.players.setPlayer(userList.item[i].getName(), userList.item[i].getWin(), userList.item[i].getLose());
	}

	
	newGame.registerUser();

	newGame.printMenu();


	
	ofstream user;
	
	user.open(argv[2]);
	cnt = newGame.players.getFill();
	while (cnt)
	{
		user << "[" << newGame.players.item[newGame.players.getFill() - cnt].getName() << "]" << " [" << newGame.players.item[newGame.players.getFill() - cnt].getWin() << "]" << " [" << newGame.players.item[newGame.players.getFill() - cnt].getLose() << "]" << endl;
		cnt--;
	}
}


void sortPlayerList(Array<Player>& userList)
{
	float winningRate;
	Player tmp;
	for (int i = 0; i < userList.getFill(); i++)
	{
		
		for (int j = i + 1; j < userList.getFill(); j++)
		{
			if ((float)userList.item[i].getWin() / (float)userList.item[i].getLose() < (float)userList.item[j].getWin() / (float)userList.item[j].getLose())
			{
				tmp = userList.item[i];
				userList.item[i] = userList.item[j];
				userList.item[j] = tmp;
			}
		}
	}
}