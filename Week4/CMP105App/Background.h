#pragma once
#include "Framework/GameObject.h"
class Background :
	public GameObject
{
	int speed;

	public:
		Background();
		~Background();

		void handleInput(float dt) override;
		void setInput(Input* in);

		sf::View* view;
};

