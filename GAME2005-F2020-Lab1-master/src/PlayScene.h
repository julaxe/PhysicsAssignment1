#pragma once
#ifndef __PLAY_SCENE__
#define __PLAY_SCENE__

#include "Scene.h"
#include "Plane.h"
#include "Player.h"
#include "Button.h"
#include "ResetButton.h"
#include "Enemy.h"
#include "Arrow.h"
#include "Target.h"
#include "Battlefield.h"


class PlayScene : public Scene
{
public:
	PlayScene();
	~PlayScene();

	// Scene LifeCycle Functions
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;
	virtual void handleEvents() override;
	virtual void start() override;
private:

	// 1 meter is 1 pixel
	//variables for physics assignment 1
	float const GRAVITY = 9.81f;
	float m_InitialSpeed;
	float m_IntialAngle;
	
	bool m_IndexVariable;
	
	glm::vec2 m_mousePosition;

	Battlefield* m_pBattlefield;
	Plane* m_pPlaneSprite;
	Target* m_pChewbaca;
	Player* m_pGranade;
	Enemy* m_pEnemy;
	Arrow* m_pArrow;
	
	//Display Actual Values;
	Label* m_pSpeedLabel;
	Label* m_pDistanceLabel;
	Label* m_pAngleLabel;

	//Display Initial Values;
	Label* m_pInitialSpeed;
	Label* m_pInitialAngle;

	//Instructions labels
	Label* m_pInstructions;

	Button* m_pThrowButton;
	ResetButton* m_pResetButton;
};

#endif /* defined (__PLAY_SCENE__) */