#pragma once

#include "stdatx.h"

class pocisk
{
public:
	int x = 500;
	int y = 500;
	int ktory = 0;
	string tekstura = "grafika/pocisk.png";
	string tekstura_2 = "grafika/pocisk2.png";

	sf::Texture t_pocisk;
	sf::Sprite s_pocisk;

	sf::Texture t_pocisk2;
	sf::Sprite s_pocisk2;

	pocisk();
	int pocisk::przydziel(int x);
	int pocisk::pozycja(int x, int y);
	int pocisk::wyswietl(sf::RenderWindow & renderWindow);
	int pocisk::usun();
	sf::Sprite pocisk::zwroc();
	int pocisk::ruch();
};