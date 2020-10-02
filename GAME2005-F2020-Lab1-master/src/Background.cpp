#include "Background.h"
#include "TextureManager.h"
#include "Config.h"

Background::Background() {
	TextureManager::Instance()->load("../Assets/sprites/star-trek-background.jpg", "Background");
	glm::vec2 backgroundSize = { Config::SCREEN_WIDTH, Config::SCREEN_HEIGHT };
	auto size = TextureManager::Instance()->getTextureSize("Background");
	setWidth(size.x);
	setHeight(size.y);

	getTransform()->position = glm::vec2(Config::SCREEN_WIDTH >> 1, Config::SCREEN_HEIGHT >> 1);
	getRigidBody()->isColliding = false;
	getTransform()->scale = backgroundSize;
	setType(NONE);
}

Background::~Background()
= default;

void Background::draw() {
	// alias for x and y
	const auto x = getTransform()->position.x;
	const auto y = getTransform()->position.y;

	TextureManager::Instance()->draw("Background", x, y, 0, 255, true);
}

void Background::update() {

}

void Background::clean() {

}