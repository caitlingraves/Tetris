#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <dos.h>
#include <vector>

#define _CRT_SECURE_NO_WARNINGS

//sf::Vector2f size(50, 50);

class Square : public sf::RectangleShape
{
public:
	Square() :
		sf::RectangleShape(sf::Vector2f(50, 50))
	{
		sf::Color bl(50, 50, 50);
		sf::Vector2f pos(0, 0);
		this->setFillColor(bl);
		this->setPosition(pos);
	}
};