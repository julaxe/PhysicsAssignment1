#include "Player.h"

#include "Renderer.h"
#include "TextureManager.h"
#include "Util.h"

Player::Player()
{
	TextureManager::Instance()->load("../Assets/sprites/Granade.png", "player");
	
	auto size = TextureManager::Instance()->getTextureSize("player");
	setWidth(size.x);
	setHeight(size.y);
	setSpeed(0.f); //initial speed
	setAngle(0.0f); //initial angle
	setGravity(0.0f); //gravity
	m_distance = 0;
	
	getTransform()->position = glm::vec2(30.0f, 400.f);
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
	const SDL_Rect src = {0.f,0,512,512};
	const SDL_Rect dst = {x,y,100,100};
	

	SDL_RenderCopyEx(Renderer::Instance()->getRenderer(),TextureManager::Instance()->getTexture("player"),&src,&dst, 0 , nullptr, SDL_FLIP_NONE);
}

void Player::update()
{
	//define deltatime
	const float deltaTime = 1.0f / 60.f;

	//Check if Throw finished.
	//if velocity Y is less than the start velocity (but negative) stop.
	if(getRigidBody()->velocity.y > -m_speed*sin(m_angle))
	{
		getRigidBody()->velocity = {0.0f,0.0f};
		m_gravity = 0.0f;
		return;
	}

	//temporal variable for position (new position)
	glm::vec2 temppos = getTransform()->position;

	//apply gravity
	getRigidBody()->velocity.y += m_gravity*deltaTime;

	//apply velocity to position in the Y Axis
	temppos.y += getRigidBody()->velocity.y * deltaTime;
	
	//apply velocity to position in the X axis
	temppos.x += getRigidBody()->velocity.x * deltaTime;

	//Label - update distance
	m_distance += getRigidBody()->velocity.x * deltaTime;

	

	//Update actual position with the new one.
	getTransform()->position = temppos;

	
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
	//degree to rad
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

