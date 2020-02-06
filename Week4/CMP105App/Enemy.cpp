#include "Enemy.h"

Enemy::Enemy()
{
	speed = 100;

	lefttop = true;
	topright = false;
	rightbot = false;
	botleft = false;
}

Enemy::~Enemy()
{

}

void Enemy::handleInput(float dt)
{
	sf::Vector2f enemypos = getPosition();
	sf::Vector2u winsize = window->getSize();

	if (lefttop)
	{
		if (enemypos.y > 0) move(speed * dt, -(speed / 1.75f * dt));
		else
		{
			lefttop = false;
			topright = true;
		}
	}
	else if (topright)
	{
		if (enemypos.x < winsize.x - getSize().x) move(speed * dt, speed / 2 * dt);
		else
		{
			topright = false;
			rightbot = true;
		}

	}
	else if (rightbot)
	{
		if (enemypos.y < winsize.y - getSize().y) move(-(speed * dt), speed / 2 * dt);
		else
		{
			rightbot = false;
			botleft = true;
		}
	}
	else if (botleft)
	{
		if (enemypos.x > 0) move(-(speed * dt), -(speed / 2 * dt));
		else
		{
			botleft = false;
			lefttop = true;
		}

	}
}

void Enemy::handleWindow(sf::RenderWindow* win)
{
	window = win;
}
