#pragma once
#include "Framework/GameObject.h"
class Cursor :
	public GameObject
{
	Input* input;
	sf::RenderWindow* window;

	public:
		Cursor();
		~Cursor();

		void update();
		void setInput(Input* in);
		void getWindow(sf::RenderWindow* win);
};

