#pragma once

#include "stdafx.h"

class pocisk
{
public:
	int x = 500;
	int y = 500;
	int power = 1;
	int id_skin = 0;
	string tekstury[5] = { "grafika/pocisk1.png","grafika/pocisk2.png","","","" };
	int used = 0;

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