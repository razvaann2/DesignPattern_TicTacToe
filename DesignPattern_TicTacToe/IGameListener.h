#pragma once
#include <memory>

class IGameListener
{
public:
	virtual void OnMoveMade() = 0;
	virtual void OnGameOver() = 0;
};

using IGameListenerPtr = std::shared_ptr<IGameListener>;