#pragma once

#include "paddle.h"
#include "eventhandler.h"

class Player : public Paddle
{
public:
	Player(
		irr::core::vector3df& position,
		irr::core::vector3df& rotation,
		irr::core::vector3df& scale);
	virtual ~Player();
	virtual void run();

	virtual const bool isPlayer() const;

	const int getScore() const;
protected:
	int score;
	int timeKeeping;
	EventHandler *handler;
};
