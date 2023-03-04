#include "Player.h"

Player::Player(char m_Symbol, std::string m_Name)
{
	this->m_Name = m_Name;
	this->m_Symbol = m_Symbol;
}

Player::Player(Player& player)
{
	this->m_Name = player.GetName();
	this->m_Symbol = player.GetSymbol();
}

Player::Player()
{
}

Player::~Player()
{
}



