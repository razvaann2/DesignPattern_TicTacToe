#pragma once
#include <utility>
#include <memory>
#include "IGameListener.h"

using IGamePtr = std::shared_ptr<class IGame>;

/// <summary>
/// The IGame class is an interface class used to replace the Game class
/// </summary>
class IGame
{
public: 
	/// <summary>
	/// Checks if the game is over and returns the mode in wich it ended.
	/// </summary>
	/// <returns>
	/// The mode in wich the game ended.
	/// </returns>
	virtual int CheckGameStatus() = 0;
	/// <summary>
	/// Change the current player after a move is made.
	/// </summary>
	virtual void ChangePlayer() = 0;
	//virtual void AddListener(IGameListenerPtr listener) = 0;
	//virtual void RemoveListener(IGameListenerPtr listener) = 0;
	static IGamePtr Produce();
};
//to do documentie gmock sa folosim interfetele observer(listener) uml de continuat + enum deadline: 3 aprilie
//documentatie, googlemock, enum, dificultate: fara observer si interfata aprox 8,50