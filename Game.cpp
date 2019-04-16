#include "Game.h"


void Game::printTopBar(int menu)
{
	if (menu == -1)
	{
		cout << "=======================================================================" << endl;
		cout << "             ��� ������ �����մϴ�. ����ڸ� ����մϴ�." << endl;
		cout << "=======================================================================" << endl;

	}
	else if (menu == 0)				//��� ���۽�
	{
		cout << "=======================================================================" << endl;
		cout << "        " << newPlayer.getName() << "�� ��ǰ����� �����ϰ� �ֽ��ϴ�. (�̹� ���� " << newPlayer.getWin() << "�� " << newPlayer.getLose() << "��)" << endl;
		cout << "=======================================================================" << endl;
	}
	else
	{
		cout << "=======================================================================" << endl;
		cout << "        " << newPlayer.getName() << "��" << menu << "���� ��ǰ����� �����߿� �ֽ��ϴ�. (�̹� ���� " << newPlayer.getWin() << "�� " << newPlayer.getLose() << "��)" << endl;
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
		cout << "(����� �� ���� ������ load�ǰų� ���ο� ����ڰ� ��ϵ˴ϴ�.)" << endl;
		cout << "����� �̸��� �Է��ϼ��� : ";
		cin >> newName;



		if (players.playerSearch(newName) != -1)
		{
			cout << "��ϵ� ����ڰ� �ֽ��ϴ�." << endl;
			cout << "��ϵ� ������� ���� ������ load�Ϸ��� \"L\"��, ���ο� ����ڸ� ����Ϸ��� \"N\"�� �Է��ϼ���. [L/N] :";
			cin >> ans;
		}
		else
		{
			cout << "���ο� ����� [" << newName << "] �� ����մϴ�.";
			newPlayer.setPlayer(newName, 0, 0);
			ans = 'E';
			Sleep(1000);
		}
	}
	if (toupper(ans) == 'L')
	{
		cout << "��ϵ� ����� [" << newName << "] �� load �մϴ�.";
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
			cout << "�� ������ �����Ϸ��� \"S\"��" << endl;
			cout << "������ �̹� ���� ������ ������ \"I\"��" << endl;
			cout << "������ ���� ���� ������ ������ \"H\"��" << endl;
			cout << "��ü ������� ����� ������ \"R\"��" << endl;
			cout << "�̹� ���� ����� �����ϰ� �����Ϸ��� \"Q\"��" << endl;
			cout << "�̹� ���� ����� �������� �ʰ� �����Ϸ��� \"Z\"�� �Է��Ͻÿ� [S/I/H/R/Q/Z] : ";
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
		cout << "�ܾ����� �������� �ʽ��ϴ�. ";
		return;
	}

	int failcount = 0;
	int correctCount = 0;
	bool rightAnswer = false;
	char alpha[26] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
	string tempAns;											//������� �亯�� �����ϴ� string
	srand(time(NULL));
	int problemNum;											//������ȣ
	do
	{
		problemNum = (rand() % words.fill);
	} while (words.item[problemNum].getWordSize() < 4);
	char *answer;											//���� �ܾ�� ���� ũ�⸦ ���� char�� �迭
	answer = new char[words.item[problemNum].getWordSize()];
	bool check = false;										//���� ���ĺ� �־����� üũ


	while (rightAnswer == false && failcount <= 7)
	{
		system("cls");
		printTopBar(count);
		printHangman(failcount);
		cout << endl << endl;


		if (failcount < 7)
		{
			cout << "��� �ܾ� : ";
			for (int i = 0; i < words.item[problemNum].getWordSize(); i++)
			{
				if (answer[i] == words.item[problemNum].getWord()[i])
					cout << answer[i] << " ";
				else
					cout << " _  ";
			}
			cout << words.item[problemNum].getHint() << endl;
			cout << "����� ���� : ";
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
			cout << "��� �ܾ� : ";
			for (int i = 0; i < words.item[problemNum].getWordSize(); i++)
			{
				cout << words.item[problemNum].getWord()[i] << " ";
			}
			cout << words.item[problemNum].getHint() << endl;
			cout << "����� ���� : ";
			for (int i = 0; i < 26; i++)
				cout << alpha[i] << " ";
			cout << endl << endl << "�ܾ�ã�⿡ �����ϼ̽��ϴ�!! ";
			newPlayer.plusScore(0, 1);
			return;
		}

		cout << "���ĺ��̳� ��ü �ܾ �Է��Ͻÿ� [A-z] �Ǵ� �ܾ� : ";
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

	cout << endl << endl << "�ܾ�ã�⿡ �����ϼ̽��ϴ�!! ";
	newPlayer.plusScore(1, 0);
}




void Game::printScore(int menu)
{
	if (menu == 0)		//�̹� ���� ����
	{
		cout << "�̹� ������ " << newPlayer.getWin() + newPlayer.getLose() << "�� " << newPlayer.getWin() << "�� " << newPlayer.getLose() << "�� �Դϴ�.";
	}
	else if (menu == 1)		//���� ���� ����
	{
		int i = players.playerSearch(newPlayer.getName());
		if (i == -1)
		{
			cout << "���� ���� ����� �������� �ʽ��ϴ�.";
		}
		else
		{
			cout << "���� ������ " << players.item[i].getWin() + players.item[i].getLose() << "�� " << players.item[i].getWin() << "�� " << players.item[i].getLose() << "�� �Դϴ�.";
		}
	}
	else					//��� ���� ����
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
				cout << rank << "�� : " << players.item[i].getName() << " (" << players.item[i].getWin() + players.item[i].getLose() << "�� " << players.item[i].getWin() << "��.  �·� 0.00%)" << endl;
				prevRate = 0;
			}
			else
			{
				cout << rank << "�� : " << players.item[i].getName() << " (" << players.item[i].getWin() + players.item[i].getLose() << "�� " << players.item[i].getWin() << "��.  �·� " << ((float)players.item[i].getWin() / (float)(players.item[i].getWin() + players.item[i].getLose())) * 100 << "%)" << endl;
				prevRate = ((float)players.item[i].getWin() / (float)(players.item[i].getWin() + players.item[i].getLose())) * 100;
			}
		}
	}
}
void Game::exit(bool menu)
{

	if (menu)			// ������ ����
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
		cout << "   ��";
	if (count > 2)
		cout << "��";
	if (count > 3)
		cout << "��";
	cout << endl << "   l";
	if (count > 4)
		cout << "     ��";
	cout << endl << "   l";
	if (count > 5)
		cout << "    ��";
	if (count > 6)
		cout << " ��";
	cout << endl << "   l";
	cout << endl << "  ___" << endl;
}
