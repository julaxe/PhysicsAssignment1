#include "Arrow.h"

#include "TextureManager.h"

Arrow::Arrow()
{
	TextureManager::Instance()->load("../Assets/textures/circle.png", "circle");
	
	auto size = TextureManager::Instance()->getTextureSize("circle");
	setWidth(size.x);
	setHeight(size.y);
	
	getTransform()->position = glm::vec2(600.0f, 80.0f);
	getRigidBody()->velocity = glm::vec2(0.0f, 0.0f);
	getRigidBody()->acceleration = glm::vec2(0.0f, 0.0f);
	getRigidBody()->isColliding = false;
	setType(NONE);
}

Arrow::~Arrow()
= default;

void Arrow::update()
{
	
}

void Arrow::clean()
{
}

void Arrow::changeTarget(bool IndexVariable)
{
	if(IndexVariable)
	{
		getTransform()->position.y = 40.0f;
	}
	else
	{
		getTransform()->position.y =  80.0f;
	}
}

void Arrow::draw()
{
	// alias for x and y
	const auto x = getTransform()->position.x;
	const auto y = getTransform()->position.y;

	TextureManager::Instance()->draw("circle", x, y, 0, 255, true);
}
