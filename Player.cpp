#include "Player.h"


void Player::setPlayer(string name, int win, int lose)
{
	this->name = name;
	this->win = win;
	this->lose = lose;
}
string Player::getName()
{
	return name;
}
int Player::getWin()
{
	return win;
}
int Player::getLose()
{
	return lose;
}
void Player::plusScore(int newWin, int newLose)
{
	win += newWin;
	lose += newLose;
}
Player& Player::operator=(Player& newPlayer)
{
	this->name = newPlayer.getName();
	this->lose = newPlayer.getLose();
	this->win = newPlayer.getWin();

	return *this;
}
