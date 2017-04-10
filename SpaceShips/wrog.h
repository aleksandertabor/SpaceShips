#pragma once

#include "stdatx.h"
#include "pocisk.h"

class wrog
{
public:
	int x = 0;
	int y = 0;
	int tab_x[5];
	int id_wroga = 0;
	int id_pocisku = 0;
	int zuzyty = 0;
	int id_poc = 0;
	string tekstura = "grafika/wrog.png";

	sf::Texture t_wrog;
	sf::Sprite s_wrog;

	int wrog::stworz(int id);
	int wrog::pozycja(int a, int b);
	int wrog::wyswietl(sf::RenderWindow & renderWindow);
	int wrog::strzelaj(sf::RenderWindow & renderWindow, pocisk ** bullet, int id_pocisku, int x, int y);
	int wrog::wystrzal(pocisk ** bullet);
	int wrog::posx();
	int wrog::posy();
	sf::Sprite wrog::zwroc();
};