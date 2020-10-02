#include "PlayScene.h"
#include "Game.h"
#include "EventManager.h"

PlayScene::PlayScene()
{
	PlayScene::start();
}

PlayScene::~PlayScene()
= default;

void PlayScene::draw()
{
	
	drawDisplayList();
}

void PlayScene::update()
{
	updateDisplayList();
	m_pSpeedLabel->setText("Speed Y = " + std::to_string(m_pPlayer->getSpeedY()));
	m_pDistanceLabel->setText("Distance = " + std::to_string(m_pPlayer->getDistance()));
	m_pAngleLabel->setText("Angle = " + std::to_string(m_pPlayer->getAngle()));

	m_pInitialSpeed->setText("Initial Speed = " + std::to_string(m_InitialSpeed));
	m_pInitialAngle->setText("Initial Angle = " + std::to_string(m_IntialAngle));	

}

void PlayScene::clean()
{
	removeAllChildren();
}

void PlayScene::handleEvents()
{

	EventManager::Instance().update();
	
	if (EventManager::Instance().isKeyDown(SDL_SCANCODE_S))
	{
		//We apply initial velocity to the player
		m_pPlayer->setAngle(m_IntialAngle);
		m_pPlayer->setSpeed(m_InitialSpeed);
		m_pPlayer->setGravity(GRAVITY);
	}
	

	if (EventManager::Instance().isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		TheGame::Instance()->quit();
	}
	
	//Controller for variables
	//Right key
	if (EventManager::Instance().isKeyDown(SDL_SCANCODE_RIGHT))
	{
		if(m_IndexVariable)
		{
			m_InitialSpeed += 0.1f;
		}
		else
		{
			m_IntialAngle += 0.1f;
		}
	}
	//Left Key
	else if(EventManager::Instance().isKeyDown(SDL_SCANCODE_LEFT))
	{
		if(m_IndexVariable)
		{
			m_InitialSpeed -= 0.1f;
		}
		else
		{
			m_IntialAngle -= 0.1f;
		}
	}
	//Up Key
	if (EventManager::Instance().isKeyDown(SDL_SCANCODE_UP))
	{
		m_IndexVariable = !m_IndexVariable;
		m_pArrow->changeTarget(m_IndexVariable);
	}
	//Down Key
	else if(EventManager::Instance().isKeyDown(SDL_SCANCODE_DOWN))
	{
		m_IndexVariable = !m_IndexVariable;
		m_pArrow->changeTarget(m_IndexVariable);
	}
	
}

void PlayScene::start()
{
	m_IntialAngle = 15.9077f;
	m_InitialSpeed = 95.0f;
	// Player Sprite
	m_pPlayer = new Player();
	addChild(m_pPlayer);
	
	// Enemy Sprite
	m_pEnemy = new Enemy();
	addChild(m_pEnemy);

	//Arrow Sprite
	m_pArrow = new Arrow();
	addChild(m_pArrow);

	// Labels
	const SDL_Color blue = { 0, 0, 255, 255 };
	m_pSpeedLabel = new Label("SpeedY = ", "Consolas", 40, blue, glm::vec2(300.0f, 40.0f));
	m_pSpeedLabel->setParent(this);
	addChild(m_pSpeedLabel);

	m_pDistanceLabel = new Label("Distance = ", "Consolas", 40, blue, glm::vec2(300.0f, 80.0f));
	m_pDistanceLabel->setParent(this);
	addChild(m_pDistanceLabel);

	m_pAngleLabel = new Label("Angle = ", "Consolas", 40, blue, glm::vec2(300.0f, 120.0f));
	m_pAngleLabel->setParent(this);
	addChild(m_pAngleLabel);

	//setting labels
	m_pInitialSpeed = new Label("Initial Speed = ", "Consolas", 40, blue, glm::vec2(905.0f, 40.0f));
	m_pInitialSpeed->setParent(this);
	addChild(m_pInitialSpeed);

	m_pInitialAngle = new Label("Initial Angle = ", "Consolas", 40, blue, glm::vec2(900.0f, 80.0f));
	m_pInitialAngle->setParent(this);
	addChild(m_pInitialAngle);

	//Start Button
	m_pStartButton = new Button();
	m_pStartButton->getTransform()->position = glm::vec2(900.0f, 400.0f); 

	m_pStartButton->addEventListener(CLICK, [&]()-> void
	{
		m_pStartButton->setActive(false);
		m_pPlayer->setAngle(m_IntialAngle);
		m_pPlayer->setSpeed(m_InitialSpeed);
		m_pPlayer->setGravity(GRAVITY);
		
	});
	
	m_pStartButton->addEventListener(MOUSE_OVER, [&]()->void
	{
		m_pStartButton->setAlpha(128);
	});

	m_pStartButton->addEventListener(MOUSE_OUT, [&]()->void
	{
		m_pStartButton->setAlpha(255);
	});
	addChild(m_pStartButton);

	//Reset Button
	m_pResetButton = new Button();
	m_pResetButton->getTransform()->position = glm::vec2(900.0f, 500.0f);
	
	m_pResetButton->addEventListener(CLICK, [&]()-> void
	{
		m_pResetButton->setActive(false);
		m_pPlayer->getTransform()->position = glm::vec2(30.0f, 600.0f);
		m_pPlayer->getRigidBody()->velocity = glm::vec2(0.0f, 0.0f);
		m_pPlayer->setGravity(0.0f);
		m_pPlayer->setDistance(0.0f);
		
	});
	
	m_pResetButton->addEventListener(MOUSE_OVER, [&]()->void
	{
		m_pResetButton->setAlpha(128);
	});

	m_pResetButton->addEventListener(MOUSE_OUT, [&]()->void
	{
		m_pResetButton->setAlpha(255);
	});
	addChild(m_pResetButton);
	
}
