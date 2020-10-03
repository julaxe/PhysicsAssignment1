#pragma once
#ifndef __RESETE_BUTTON__
#define __RESETE_BUTTON__

#include "DisplayObject.h"
#include <SDL.h>
#include "UIControl.h"

class ResetButton : public UIControl
{
public:
	explicit ResetButton(const std::string& image_path = "../Assets/textures/restartButton.png",
		std::string button_name = "ResetButton",
		GameObjectType type = START_BUTTON,
		glm::vec2 position = glm::vec2(0.0f, 0.0f), bool is_centered = true);

	~ResetButton();

	// Life Cycle Events
	void draw() override;
	void update() override;
	void clean() override;

	// button setters
	void setAlpha(Uint8 alpha);
	void setActive(bool value);

private:
	Uint8 m_alpha;
	std::string m_name;
	bool m_isCentered;
	bool m_active;
};

#endif /* defined (__RESETE_BUTTON__) */