#include "Background.h"

Background::Background()
{
	speed = 100;
}

Background::~Background()
{

}

void Background::setInput(Input* in)
{
	input = in;
}

void Background::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Left))
	{
		view->move(sf::Vector2f(speed*dt,0));
	}
	if (input->isKeyDown(sf::Keyboard::Right))
	{
		view->move(sf::Vector2f(-(speed*dt), 0));
	}
}
