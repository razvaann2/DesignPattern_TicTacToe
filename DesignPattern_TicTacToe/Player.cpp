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

void Player::SetName(std::string Name)
{
	this->m_Name = Name;
}

std::string Player::GetName()
{
	return m_Name;
}

void Player::SetSymbol(char Symbol)
{
	this->m_Symbol = Symbol;
}

char Player::GetSymbol()
{
	return m_Symbol;
}

bool Player::operator==(const Player& player1)
{
	return (player1.m_Name==this->m_Name && player1.m_Symbol==this->m_Symbol);
}


