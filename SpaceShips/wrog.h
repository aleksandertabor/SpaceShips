#pragma once

#include "stdafx.h"
#include "pocisk.h"

class wrog
{
public:
	int x = 0;
	int y = 0;
	int id_wroga = 0;
	int id_pocisku = 0;
	int zuzyty = 0;
	int id_poc = 0;
	int w_kierunek = 4;
	int w_predkosc = 10;
	string tekstury[5] = { "grafika/enemy1.png","grafika/enemy2.png","","","" };
	int hp = 100;

	sf::Texture t_wrog;
	sf::Sprite s_wrog;

	int wrog::stworz(int id, int id_skin);
	int wrog::pozycja(int a, int b);
	int wrog::wyswietl(sf::RenderWindow & renderWindow);
	int wrog::strzelaj(sf::RenderWindow & renderWindow, pocisk ** bullet, int id_pocisku, int x, int y);
	int wrog::wystrzal(pocisk ** bullet);
	int wrog::posx();
	int wrog::posy();
	sf::Sprite wrog::zwroc();
	int wrog::ruch();
	int wrog::kolizja_sciana(sf::Sprite sprite1, sf::Sprite sprite2);
};