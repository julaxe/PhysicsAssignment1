#include "StartScene.h"
#include <algorithm>
#include "Game.h"
#include "glm/gtx/string_cast.hpp"
#include "EventManager.h"
#include "Config.h"

StartScene::StartScene()
{
	StartScene::start();
}

StartScene::~StartScene()
= default;

void StartScene::draw()
{
	drawDisplayList();
}

void StartScene::update()
{
	updateDisplayList();
}

void StartScene::clean()
{
	removeAllChildren();
}

void StartScene::handleEvents()
{
	EventManager::Instance().update();

	// Keyboard Events
	if(EventManager::Instance().isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		TheGame::Instance()->quit();
	}

	if(EventManager::Instance().isKeyDown(SDL_SCANCODE_1))
	{
		TheGame::Instance()->changeSceneState(PLAY_SCENE);
	}
}

void StartScene::start()
{
	m_pBackground = new Background();
	addChild(m_pBackground);

	const SDL_Color blue = { 0, 0, 255, 255 };
	m_pName1 = new Label("Lucas Krespi - 101289546", "Consolas", 40, blue, glm::vec2(300.f, 40.0f));
	m_pName1->setParent(this);
	addChild(m_pName1);

	m_pName2 = new Label("Julian Escobar - 101286557", "Consolas", 40, blue, glm::vec2(300.f, 80.0f));
	m_pName2->setParent(this);
	addChild(m_pName2);


	m_pShip = new Ship();
	addChild(m_pShip); 

	// Start Button
	m_pStartButton = new Button();
	m_pStartButton->getTransform()->position = glm::vec2(Config::SCREEN_WIDTH>>1, 600.0f); 

	m_pStartButton->addEventListener(CLICK, [&]()-> void
	{
		m_pStartButton->setActive(false);
		TheGame::Instance()->changeSceneState(PLAY_SCENE);
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

	
}

