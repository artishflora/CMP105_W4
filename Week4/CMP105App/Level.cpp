#include "Level.h"
#include <iostream>

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	player.setInput(input);
	player.setWindow(window);
	texture.loadFromFile("gfx/Mushroom.png");
	player.setTexture(&texture);
	player.setSize(sf::Vector2f(100, 100));
	player.setPosition(100, 100);
	player.speed = 150;

	enemy.handleWindow(window);
	entext.loadFromFile("gfx/Goomba.png");
	enemy.setTexture(&entext);
	enemy.setSize(sf::Vector2f(150, 150));
	enemy.setPosition(0, 200);
	enemy.speed = 200;

	curtext.loadFromFile("gfx/icon.png");
	cursor.setTexture(&curtext);
	cursor.setSize(sf::Vector2f(60, 60));
	cursor.setPosition(300,300);
	window->setMouseCursorVisible(false);
	cursor.getWindow(window);
	cursor.setInput(input);

	bckgrnd.loadFromFile("gfx/Level1_1.png");
	background.setTexture(&bckgrnd);
	background.setSize(sf::Vector2f(10038, 675));
	sf::View currview = window->getView();
	background.view = &currview;
	background.setInput(input);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	// Close window on Escape pressed.
	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		window->close();
	}

}

// Update game objects
void Level::update(float dt)
{
	player.handleInput(dt);
	enemy.handleInput(dt);
	cursor.update();
	background.handleInput(dt);
}

// Render level
void Level::render()
{
	beginDraw();
	
	window->draw(background);
	window->draw(player);
	window->draw(enemy);
	window->draw(cursor);

	endDraw();
}

// clear back buffer
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}