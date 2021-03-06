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
	m_pSpeedLabel->setText("Speed Y = " + std::to_string(m_pGranade->getSpeedY()));
	m_pDistanceLabel->setText("Distance = " + std::to_string(m_pGranade->getDistance()));
	m_pAngleLabel->setText("Angle = " + std::to_string(m_pGranade->getAngle()));

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
	if (EventManager::Instance().isKeyDown(SDL_SCANCODE_UP) && !m_IndexVariable)
	{
		m_IndexVariable = !m_IndexVariable;
		m_pArrow->changeTarget(m_IndexVariable);
	}
	//Down Key
	else if(EventManager::Instance().isKeyDown(SDL_SCANCODE_DOWN) && m_IndexVariable)
	{
		m_IndexVariable = !m_IndexVariable;
		m_pArrow->changeTarget(m_IndexVariable);
	}
	
}

void PlayScene::start()
{
	//Initial values for the specific physic problem - test 
	m_IntialAngle = 15.9077f;
	m_InitialSpeed = 95.0f;
	
	//Background
	m_pBattlefield = new Battlefield();
	addChild(m_pBattlefield);
	
	// Enemy Sprite
	m_pEnemy = new Enemy();
	addChild(m_pEnemy);

	// Chewbaca Sprite
	m_pChewbaca = new Target();
	addChild(m_pChewbaca);
	
	// Player Sprite
	m_pGranade = new Player();
	addChild(m_pGranade);

	//Arrow Sprite
	m_pArrow = new Arrow();
	addChild(m_pArrow);

	// Labels
	const SDL_Color blue = { 255, 255, 255, 255 };
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

	//Instruction label
	m_pInstructions = new Label("Use the arrow keys to navigate the menu and change the variables, then press the throw button ",
		"Consolas", 20, blue, glm::vec2(Config::SCREEN_WIDTH>>1, Config::SCREEN_HEIGHT-80.0f));
	m_pInstructions->setParent(this);
	addChild(m_pInstructions);
	
	//Throw Button
	m_pThrowButton = new Button();
	m_pThrowButton->getTransform()->position = glm::vec2(900.0f, 400.0f); 

	m_pThrowButton->addEventListener(CLICK, [&]()-> void
	{
		m_pThrowButton->setActive(false);
		m_pGranade->setAngle(m_IntialAngle); // in degrees
		m_pGranade->setSpeed(m_InitialSpeed);
		m_pGranade->setGravity(GRAVITY);
		
	});

	m_pThrowButton->addEventListener(MOUSE_OVER, [&]()->void
	{
		m_pThrowButton->setAlpha(128);
	});

	m_pThrowButton->addEventListener(MOUSE_OUT, [&]()->void
	{
		m_pThrowButton->setAlpha(255);
	});
	addChild(m_pThrowButton);

	//Reset Button
	m_pResetButton = new ResetButton();
	m_pResetButton->getTransform()->position = glm::vec2(900.0f, 500.0f);
	
	m_pResetButton->addEventListener(CLICK, [&]()-> void
	{
		m_pResetButton->setActive(false);
		m_pGranade->getTransform()->position = glm::vec2(30.0f, 400.f);
		m_pGranade->getRigidBody()->velocity = glm::vec2(0.0f, 0.0f);
		m_pGranade->setGravity(0.0f);
		m_pGranade->setDistance(0.0f);
		
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
