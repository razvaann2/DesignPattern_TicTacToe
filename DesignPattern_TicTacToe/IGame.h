#pragma once
#include <utility>
#include <memory>
#include "IGameListener.h"

using IGamePtr = std::shared_ptr<class IGame>;

class IGame
{
public: 
	virtual int CheckGameStatus() = 0;
	virtual void ChangePlayer() = 0;
	//virtual void AddListener(IGameListenerPtr listener) = 0;
	//virtual void RemoveListener(IGameListenerPtr listener) = 0;
	static IGamePtr Produce();
};
//to do documentie gmock sa folosim interfetele observer(listener) uml de continuat + enum deadline: 3 aprilie
//documentatie, googlemock, enum, dificultate: fara observer si interfata aprox 8,50