#include "Player.h"
#include "TextureManager.h"
#include "Util.h"

Player::Player()
{
	TextureManager::Instance()->load("../Assets/sprites/teste.png", "player");
	
	auto size = TextureManager::Instance()->getTextureSize("player");
	setWidth(size.x);
	setHeight(size.y);
	setSpeed(0.f);
	setAngle(0.0f);
	setGravity(0.0f);
	m_distance = 0;
	
	getTransform()->position = glm::vec2(30.0f, 600.0f);
	getRigidBody()->velocity = glm::vec2(0.0f, 0.0f);
	getRigidBody()->acceleration = glm::vec2(0.0f, 0.0f);
	getRigidBody()->isColliding = false;
	setType(PLAYER);
}

Player::~Player()
= default;

void Player::draw()
{
	// alias for x and y
	const auto x = getTransform()->position.x;
	const auto y = getTransform()->position.y;

	TextureManager::Instance()->draw("player", x, y, 0, 255, true);
}

void Player::update()
{
	const float deltaTime = 1.0f / 60.f;

	if(getRigidBody()->velocity.y > -m_speed*sin(m_angle))
	{
		getRigidBody()->velocity = {0.0f,0.0f};
		m_gravity = 0.0f;
	}
	
	glm::vec2 pos = getTransform()->position;
	getRigidBody()->velocity.y += m_gravity*deltaTime;
	pos.x += getRigidBody()->velocity.x * deltaTime;
	m_distance += getRigidBody()->velocity.x * deltaTime;
	
	pos.y += getRigidBody()->velocity.y * deltaTime;

	getTransform()->position = pos;

	getTransform()->rotation = glm::vec2(cos(m_angle), sin(m_angle));
}

void Player::clean()
{

}

void Player::setGravity(float gravity)
{
	m_gravity = gravity;
}


void Player::setAngle(float angle)
{
	m_angle = angle * -Util::Deg2Rad;
}


void Player::setSpeed(float speed)
{
	m_speed = speed;
	getRigidBody()->velocity.x = speed * cos(m_angle);
	getRigidBody()->velocity.y = speed * sin(m_angle);
}

void Player::setDistance(float distance)
{
	m_distance = distance;
}

float Player::getSpeedY()
{
	return getRigidBody()->velocity.y;
}

float Player::getDistance()
{
	return  m_distance;
}

float Player::getAngle()
{
	return atan2(getRigidBody()->velocity.y, getRigidBody()->velocity.x)* -Util::Rad2Deg;
}

