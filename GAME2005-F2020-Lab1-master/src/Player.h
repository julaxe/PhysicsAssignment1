#pragma once
#ifndef __PLAYER__
#define __PLAYER__

#include "Sprite.h"
#include "Label.h"

class Player final : public Sprite
{
public:
	Player();
	~Player();

	// Life Cycle Methods
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;

	//setters
	void setGravity(float gravity);
	void setAngle(float angle);
	void setSpeed(float speed);
	void setDistance(float distance);

	//getters
	float getSpeedY();
	float getDistance();
	float getAngle();

private:
	
	float m_distance;
	float m_gravity;
	float m_angle;
	float m_speed;
};

#endif /* defined (__PLAYER__) */