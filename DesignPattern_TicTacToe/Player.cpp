#include "Player.h"
#include "Human.h"
#include "Computer.h"

Player::Player(char m_Symbol, std::string m_Name)
{
	this->m_name = m_Name;
	this->m_symbol = m_Symbol;
}

Player::Player(Player& player)
{
	this->m_name = player.GetName();
	this->m_symbol = player.GetSymbol();
}

Player::Player()
{
	this->m_name = {};
	this->m_symbol = '\0';
}

Player::~Player()
{
}
void Player::SetName(std::string Name)
{
	this->m_name = Name;
}

std::string Player::GetName()
{
	return std::string();
}

void Player::SetSymbol(char Symbol)
{
	this->m_symbol = Symbol;
}

char Player::GetSymbol()
{
	return this->m_symbol;
}
