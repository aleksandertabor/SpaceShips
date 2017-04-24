#pragma once

#include "stdatx.h"

class pocisk
{
public:
	int x = 500;
	int y = 500;
	string tekstura = "grafika/pocisk.png";

	sf::Texture t_pocisk;
	sf::Sprite s_pocisk;

	pocisk();
	int pocisk::pozycja(int x, int y);
	int pocisk::wyswietl(sf::RenderWindow & renderWindow);
	int pocisk::usun();
	sf::Sprite pocisk::zwroc();
	int pocisk::ruch();
};