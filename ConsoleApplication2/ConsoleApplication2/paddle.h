#pragma once

#include "object.h"

class Paddle : public Object
{
public:
	static std::vector<Paddle*> allPaddles;
	const float PADDLESPEED = 0.1f;
	Paddle(
		irr::core::vector3df& position,
		irr::core::vector3df& rotation,
		irr::core::vector3df& scale);
	virtual void run();

	virtual const bool isPlayer() const;
protected:
	void runAi();
	virtual void movement();
	int health;
	int maxHealth;

};