#include "Enemy.h"

#include "Renderer.h"
#include "TextureManager.h"

Enemy::Enemy() {
	TextureManager::Instance()->load("../Assets/sprites/Enemy.png", "enemy");

	auto size = TextureManager::Instance()->getTextureSize("enemy");
	setWidth(size.x);
	setHeight(size.y);

	getTransform()->position = glm::vec2(450.f, 400.f);
	getRigidBody()->velocity = glm::vec2(0.0f, 0.0f);
	getRigidBody()->acceleration = glm::vec2(0.0f, 0.0f);
	getRigidBody()->isColliding = false;
	setType(ENEMY);
}

Enemy::~Enemy()
= default;

void Enemy::draw() {
	// alias for x and y
	const auto x = getTransform()->position.x;
	const auto y = getTransform()->position.y;
	const SDL_Rect src = {0.f,0.f,1002.f,666.f};
	float scale = 0.2f;
	const SDL_Rect dst = {x,y,1002.f*scale,666.f*scale};
	

	SDL_RenderCopyEx(Renderer::Instance()->getRenderer(),TextureManager::Instance()->getTexture("enemy"),&src,&dst, 0 , nullptr, SDL_FLIP_NONE);
}

void Enemy::update() {

}

void Enemy::clean() {

}