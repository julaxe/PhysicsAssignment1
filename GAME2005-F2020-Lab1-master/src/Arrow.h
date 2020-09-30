#pragma once
#ifndef __ARROW__
#define __ARROW__

#include "Sprite.h"

class Arrow final : public Sprite
{
public:
	Arrow();
	~Arrow();

	// Life Cycle Methods
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;

	void changeTarget(bool IndexVariable);
};



#endif /* defined (__ARROW__) */
