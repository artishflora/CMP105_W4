#include "Player.h"
#include "Framework/GameObject.h"
#include "Framework/Input.h"

Player::Player()
{
	speed = 100;
}

Player::~Player()
{

}

void Player::handleInput(float dt)
{
	sf::Vector2f playerpos = getPosition();
	sf::Vector2u windowsize = window->getSize();

	if (input->isKeyDown(sf::Keyboard::Left))
	{
		if (playerpos.x > 0) move(-(speed * dt), 0);
	}
	if (input->isKeyDown(sf::Keyboard::Right))
	{
		if (playerpos.x < windowsize.x-getSize().x) move((speed * dt), 0);
	}
	if (input->isKeyDown(sf::Keyboard::Up))
	{
		if (playerpos.y > 0) move(0, -(speed * dt));
	}
	if (input->isKeyDown(sf::Keyboard::Down))
	{
		if (playerpos.y < windowsize.y-getSize().y) move(0, (speed * dt));
	}

}

void Player::setInput(Input* in)
{
	input = in;
}

void Player::setWindow(sf::RenderWindow* win)
{
	window = win;
}