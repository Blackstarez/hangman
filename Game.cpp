#include "Game.h"


void Game::printTopBar(int menu)
{
	if (menu == -1)
	{
		cout << "=======================================================================" << endl;
		cout << "             행맨 게임을 시작합니다. 사용자를 등록합니다." << endl;
		cout << "=======================================================================" << endl;

	}
	else if (menu == 0)				//행맨 시작시
	{
		cout << "=======================================================================" << endl;
		cout << "        " << newPlayer.getName() << "이 행맨게임을 수행하고 있습니다. (이번 게임 " << newPlayer.getWin() << "승 " << newPlayer.getLose() << "패)" << endl;
		cout << "=======================================================================" << endl;
	}
	else
	{
		cout << "=======================================================================" << endl;
		cout << "        " << newPlayer.getName() << "의" << menu << "번쨰 행맨게임이 수행중에 있습니다. (이번 게임 " << newPlayer.getWin() << "승 " << newPlayer.getLose() << "패)" << endl;
		cout << "=======================================================================" << endl;
	}
}
void Game::registerUser()
{
	system("cls");

	string newName;
	char ans = 'N';

	printTopBar(-1);

	while (toupper(ans) == 'N')
	{
		cout << "(기록해 둔 게임 성적을 load되거나 새로운 사용자가 등록됩니다.)" << endl;
		cout << "사용자 이름을 입력하세요 : ";
		cin >> newName;



		if (players.playerSearch(newName) != -1)
		{
			cout << "등록된 사용자가 있습니다." << endl;
			cout << "등록된 사용자의 게임 성적을 load하려면 \"L\"을, 새로운 사용자를 등록하려면 \"N\"을 입력하세요. [L/N] :";
			cin >> ans;
		}
		else
		{
			cout << "새로운 사용자 [" << newName << "] 을 등록합니다.";
			newPlayer.setPlayer(newName, 0, 0);
			ans = 'E';
			Sleep(1000);
		}
	}
	if (toupper(ans) == 'L')
	{
		cout << "등록된 사용자 [" << newName << "] 을 load 합니다.";
		newPlayer.setPlayer(newName, 0, 0);
		Sleep(1000);
	}

}
void Game::printMenu()
{
	char choose = 'A';
	int count = 0;
	bool end = false;
	while (!end)
	{
		switch (choose)
		{
		case 'A':
			system("cls");
			printTopBar(0);
			cout << "새 게임을 시작하려면 \"S\"를" << endl;
			cout << "본인의 이번 게임 점수를 보려면 \"I\"를" << endl;
			cout << "본인의 이전 게임 점수를 보려면 \"H\"를" << endl;
			cout << "전체 사용자의 등수를 보려면 \"R\"을" << endl;
			cout << "이번 게임 결과를 저장하고 종료하려면 \"Q\"를" << endl;
			cout << "이번 게임 결과를 저장하지 않고 종료하려면 \"Z\"를 입력하시오 [S/I/H/R/Q/Z] : ";
			cin >> choose;
			if (choose > 'Z')
				choose -= ('a' - 'A');
			break;
		case 'S':
			count++;
			startGame(count);
			system("PAUSE");
			choose = 'A';
			break;
		case 'I':
			printScore(0);
			Sleep(1000);
			choose = 'A';
			break;
		case 'H':
			printScore(1);
			Sleep(1000);
			choose = 'A';
			break;
		case 'R':
			printScore(2);
			Sleep(5000);
			choose = 'A';
			break;
		case 'Q':
			exit(1);
			end = true;
			break;
		case 'Z':
			end = true;
			break;
		default:
			choose = 'A';
			break;
		}
	}
}
void Game::startGame(int count)
{
	if (words.isEmpty())
	{
		cout << "단어장이 존재하지 않습니다. ";
		return;
	}

	int failcount = 0;
	int correctCount = 0;
	bool rightAnswer = false;
	char alpha[26] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
	string tempAns;											//사용자의 답변을 저장하는 string
	srand(time(NULL));
	int problemNum;											//문제번호
	do
	{
		problemNum = (rand() % words.fill);
	} while (words.item[problemNum].getWordSize() < 4);
	char *answer;											//문제 단어와 같은 크기를 갖는 char형 배열
	answer = new char[words.item[problemNum].getWordSize()];
	bool check = false;										//맞은 알파벳 있었는지 체크


	while (rightAnswer == false && failcount <= 7)
	{
		system("cls");
		printTopBar(count);
		printHangman(failcount);
		cout << endl << endl;


		if (failcount < 7)
		{
			cout << "대상 단어 : ";
			for (int i = 0; i < words.item[problemNum].getWordSize(); i++)
			{
				if (answer[i] == words.item[problemNum].getWord()[i])
					cout << answer[i] << " ";
				else
					cout << " _  ";
			}
			cout << words.item[problemNum].getHint() << endl;
			cout << "사용한 문자 : ";
			for (int i = 0; i < 26; i++)
				cout << alpha[i] << " ";
			cout << endl << endl;

			if (correctCount == words.item[problemNum].getWordSize())
			{
				rightAnswer = true;
				continue;
			}
		}
		else
		{
			cout << "대상 단어 : ";
			for (int i = 0; i < words.item[problemNum].getWordSize(); i++)
			{
				cout << words.item[problemNum].getWord()[i] << " ";
			}
			cout << words.item[problemNum].getHint() << endl;
			cout << "사용한 문자 : ";
			for (int i = 0; i < 26; i++)
				cout << alpha[i] << " ";
			cout << endl << endl << "단어찾기에 실패하셨습니다!! ";
			newPlayer.plusScore(0, 1);
			return;
		}

		cout << "알파벳이나 전체 단어를 입력하시오 [A-z] 또는 단어 : ";
		cin >> tempAns;
		if ('A' <= tempAns[0] && tempAns[0] <= 'Z' || 'a' <= tempAns[0] && tempAns[0] <= 'z')
			std::transform(tempAns.begin(), tempAns.end(), tempAns.begin(), ::tolower);
		else
			continue;
		if (tempAns.length() == 1)
		{
			if (alpha[tempAns[0] - 'a'] == '_')
				continue;

			for (int i = 0; i < words.item[problemNum].getWordSize(); i++)
			{
				if (tempAns[0] == words.item[problemNum].getWord()[i])
				{
					answer[i] = tempAns[0];
					correctCount++;

					alpha[tempAns[0] - 'a'] = '_';

					check = true;
				}
				if (i == (words.item[problemNum].getWordSize() - 1))
				{
					alpha[tempAns[0] - 'a'] = '_';
					if (!check)
						failcount++;
					check = false;
				}
			}
		}
		else
		{
			if (tempAns.compare(words.item[problemNum].getWord()) == 0)
			{
				correctCount = words.item[problemNum].getWordSize();
				for (int i = 0; i < words.item[problemNum].getWordSize(); i++)
				{
					answer[i] = tempAns[i];
					alpha[tempAns[i] - 'a'] = '_';
				}
			}
			else
			{
				failcount++;
			}
		}

	}

	cout << endl << endl << "단어찾기에 성공하셨습니다!! ";
	newPlayer.plusScore(1, 0);
}




void Game::printScore(int menu)
{
	if (menu == 0)		//이번 게임 성적
	{
		cout << "이번 게임은 " << newPlayer.getWin() + newPlayer.getLose() << "전 " << newPlayer.getWin() << "승 " << newPlayer.getLose() << "패 입니다.";
	}
	else if (menu == 1)		//이전 게임 성적
	{
		int i = players.playerSearch(newPlayer.getName());
		if (i == -1)
		{
			cout << "이전 게임 기록이 존재하지 않습니다.";
		}
		else
		{
			cout << "이전 게임은 " << players.item[i].getWin() + players.item[i].getLose() << "전 " << players.item[i].getWin() << "승 " << players.item[i].getLose() << "패 입니다.";
		}
	}
	else					//모든 유저 성적
	{
		cout << endl << endl;

		int rank;
		float prevRate=-1;
		cout << fixed;
		cout.precision(2);
		for (int i = 0; i < players.fill; i++)
		{
			rank = i + 1;
			if (prevRate == ((float)players.item[i].getWin() / (float)(players.item[i].getWin() + players.item[i].getLose())) * 100 || prevRate == 0 && players.item[i].getWin() + players.item[i].getLose() == 0)
				rank -= 1;
			if (players.item[i].getWin() + players.item[i].getLose() == 0)
			{
				cout << rank << "등 : " << players.item[i].getName() << " (" << players.item[i].getWin() + players.item[i].getLose() << "전 " << players.item[i].getWin() << "승.  승률 0.00%)" << endl;
				prevRate = 0;
			}
			else
			{
				cout << rank << "등 : " << players.item[i].getName() << " (" << players.item[i].getWin() + players.item[i].getLose() << "전 " << players.item[i].getWin() << "승.  승률 " << ((float)players.item[i].getWin() / (float)(players.item[i].getWin() + players.item[i].getLose())) * 100 << "%)" << endl;
				prevRate = ((float)players.item[i].getWin() / (float)(players.item[i].getWin() + players.item[i].getLose())) * 100;
			}
		}
	}
}
void Game::exit(bool menu)
{

	if (menu)			// 저장후 종료
	{
		int k = players.playerSearch(newPlayer.getName());
		if (k == -1)
		{
			players.item[players.fill].setPlayer(newPlayer.getName(), newPlayer.getWin(), newPlayer.getLose());
			players.fill++;
		}
		else
		{
			players.item[k].plusScore(newPlayer.getWin(), newPlayer.getLose());
		}
	}

}
void Game::printHangman(int count)
{
	cout << "   +-----+" << endl;
	cout << "   l     l" << endl;
	cout << "   l";
	if (count > 0)
		cout << "     O";
	cout << endl << "   l";
	if (count > 1)
		cout << "   ／";
	if (count > 2)
		cout << "｜";
	if (count > 3)
		cout << "＼";
	cout << endl << "   l";
	if (count > 4)
		cout << "     ｜";
	cout << endl << "   l";
	if (count > 5)
		cout << "    ／";
	if (count > 6)
		cout << " ＼";
	cout << endl << "   l";
	cout << endl << "  ___" << endl;
}
