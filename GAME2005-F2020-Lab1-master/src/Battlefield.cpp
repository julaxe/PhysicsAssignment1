#include "Battlefield.h"


#include "Renderer.h"
#include "TextureManager.h"

Battlefield::Battlefield()
{
	TextureManager::Instance()->load("../Assets/sprites/battlefield2.jpg","battlefield");

	const auto size = TextureManager::Instance()->getTextureSize("battlefield");
	setWidth(size.x);
	setHeight(size.y);
	
	getTransform()->position = glm::vec2(0.f, 0.0f);
	getRigidBody()->velocity = glm::vec2(0, 0);
	getRigidBody()->isColliding = false;

	setType(NONE);
}

Battlefield::~Battlefield()
{
}

void Battlefield::draw()
{
	// alias for x and y
	const auto x = getTransform()->position.x;
	const auto y = getTransform()->position.y;

	const SDL_Rect src = {0.f,0.f,1668.f,930.f};
	float scale = 1.0f;
	const SDL_Rect dst = {x,y,1668.f*scale,930.f*scale};
	
	SDL_SetTextureAlphaMod(TextureManager::Instance()->getTexture("battlefield"),0);
	SDL_RenderCopyEx(Renderer::Instance()->getRenderer(),TextureManager::Instance()->getTexture("battlefield"),&src,&dst, 0 , nullptr, SDL_FLIP_NONE);
}

void Battlefield::update()
{
}

void Battlefield::clean()
{
}
