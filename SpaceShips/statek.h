#pragma once

#include "stdafx.h"
#include "pocisk.h"

class statek
{
public:
	int x = 500;
	int y = 580;
	int id_statku = 0;
	string tekstury[5] = { "grafika/player1.png","","","","" };
	int hp = 100;
	int zuzyty = 0;
	int id_poc = 0;
	int w_kierunek = 4;
	int w_predkosc = 10;
	int numer_pocisku_gracza = -1;
	int punkty = 0;

	sf::Texture t_statek;
	sf::Sprite s_statek;

	int statek::stworz(int id, int id_skin);
	int statek::pozycja(int a, int b);
	int statek::wyswietl(sf::RenderWindow & renderWindow);
	int statek::strzelaj(sf::RenderWindow & renderWindow, pocisk * bullet_player, int id_pocisku, int x, int y);
	int statek::wystrzal(pocisk ** bullet);
	int statek::posx();
	int statek::posy();
	sf::Sprite statek::zwroc();
	int statek::ruch();
	int statek::kolizja_sciana(sf::Sprite sprite1, sf::Sprite sprite2);
	void statek::autostrzal(sf::RenderWindow & renderWindow, pocisk * bullet_player, int id_pocisku);
};