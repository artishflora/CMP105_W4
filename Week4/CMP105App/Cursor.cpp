#include "Cursor.h"
#include <iostream>
#pragma once

Cursor::Cursor()
{

}

Cursor::~Cursor()
{

}

void Cursor::setInput(Input* in)
{
	input = in;
}

void Cursor::update()
{
	setPosition(input->getMouseX(), input->getMouseY());
}

void Cursor::getWindow(sf::RenderWindow* win)
{
	window = win;
}