#pragma once

#include "paddle.h"
#include "eventhandler.h"

class Player : public Paddle
{
public:
	Player();

protected:
	EventHandler handler;
};
