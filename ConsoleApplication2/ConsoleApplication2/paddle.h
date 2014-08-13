#pragma once

#include "object.h"

class Paddle : public Object
{
public:
	enum AI_STATES
	{
		STATE_INIT,
		STATE_DODGE,
		STATE_DIE
	};

	static std::vector<Paddle*> allPaddles;
	const float PADDLESPEED = 0.1f;
	Paddle(
		irr::core::vector3df& position,
		irr::core::vector3df& rotation,
		irr::core::vector3df& scale);
	virtual void run();
	void takeDamage(int damage);
	virtual const bool isPlayer() const;
protected:
	AI_STATES currentState;
	void runAi();
	virtual void movement();
	int health;
	int maxHealth;
	int index;
};