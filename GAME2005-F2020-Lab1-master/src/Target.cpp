#include "Target.h"

#include "Renderer.h"
#include "TextureManager.h"


Target::Target()
{
	TextureManager::Instance()->load("../Assets/sprites/chewbaca.png","chewbaca");

	const auto size = TextureManager::Instance()->getTextureSize("chewbaca");
	setWidth(size.x);
	setHeight(size.y);
	
	getTransform()->position = glm::vec2(30.0f, 500.f);
	getRigidBody()->velocity = glm::vec2(0, 0);
	getRigidBody()->isColliding = false;

	setType(TARGET);
}

Target::~Target()
= default;

void Target::draw()
{
	// alias for x and y
	const auto x = getTransform()->position.x;
	const auto y = getTransform()->position.y;

	const SDL_Rect src = {0.f,0.f,2913.f,4500.f};
	float scale = 0.05f;
	const SDL_Rect dst = {x,y,2913.f*scale,4500.f*scale};
	

	SDL_RenderCopyEx(Renderer::Instance()->getRenderer(),TextureManager::Instance()->getTexture("chewbaca"),&src,&dst, 0 , nullptr, SDL_FLIP_NONE);
}

void Target::update()
{

}

void Target::clean()
{
}



