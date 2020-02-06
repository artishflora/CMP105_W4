#pragma once
#include "Framework/GameObject.h"
class Enemy :
	public GameObject
{
		sf::RenderWindow* window;
		bool lefttop;
		bool topright;
		bool rightbot;
		bool botleft;

	public:
		Enemy();
		~Enemy();

		void handleInput(float dt);
		void handleWindow(sf::RenderWindow* win);

		int speed;
};

