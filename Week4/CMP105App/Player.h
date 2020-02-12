#pragma once
#include "Framework/GameObject.h"
#include "Framework/Input.h"
class Player :
	public GameObject
{
	sf::RenderWindow* window;

	public:
		Player();
		~Player();

		int speed;

		void handleInput(float dt) override;
		void setInput(Input* in);
		void setWindow(sf::RenderWindow* win);
};

