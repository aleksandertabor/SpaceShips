#pragma once

#include "stdatx.h"
#include "pocisk.h"

class wrog
{
public:
	int x = 0;
	int y = 0;
	int id_wroga = 0;
	int id_pocisku = 0;
	string tekstura;

	sf::Texture t_wrog;
	sf::Sprite s_wrog;

	int wrog::stworz(string tesktura);
	int wrog::pozycja(int a, int b);
	int wrog::wyswietl(sf::RenderWindow & renderWindow);
	int wrog::strzelaj(sf::RenderWindow & renderWindow, pocisk * paczek, int id_wroga, int id_pocisku, int x, int y);
};