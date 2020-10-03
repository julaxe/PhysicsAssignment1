#pragma once
#include "Sprite.h"

class Battlefield final : public Sprite
{
public:
	Battlefield();
	~Battlefield();

	// Life Cycle Methods
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;

};
