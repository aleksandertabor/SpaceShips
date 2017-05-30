#include "stdafx.h"
#include "statek.h"
#include "pocisk.h"


int statek::stworz(int id, int id_skin)
{
	id_statku = id;
	//cout << "Stworzono nowego wroga. ID=" << id_wroga << endl;
	if (!t_statek.loadFromFile(tekstury[id_skin]))
		return EXIT_FAILURE;

	s_statek.setTexture(t_statek);

	if (id_skin == 0)
	{
		hp = 10000;
	}

	if (id_skin == 1)
	{
		hp = 150;
	}

	if (id_skin == 2)
	{
		hp = 300;
	}

	return 0;
}

int statek::pozycja(int a, int b)
{
	s_statek.setPosition((float)a, (float)b);
	x = a;
	y = b;
	return 0;
}

int statek::posx()
{
	return x;
}

int statek::posy()
{
	return y;
}


int statek::wyswietl(sf::RenderWindow & renderWindow)
{
	s_statek.setPosition((float)x, (float)y);
	renderWindow.draw(s_statek);
	return 0;
}

sf::Sprite statek::zwroc()
{
	return s_statek;
}

int statek::strzelaj(sf::RenderWindow & renderWindow, pocisk * bullet_player, int id_pocisku, int x, int y)
{
	/*
	//Stary sposob rysowania
	for (int i = 0; i < 5; i++)
	{
	paczek[i].pozycja(i * 250, 100);
	}
	*/

	//cout << "statek ID=" << id_wroga << ". Strzelil swoim pociskiem ID=" << id_pocisku << endl;


	bullet_player[id_pocisku].pozycja(x, y);



	return 0;
}

//int statek::wystrzal(pocisk ** bullet)
//{
//	bullet[id_statku][id_poc].pozycja(statek::posx() + 85, statek::posy() + 140);
//	zuzyty = 1;
//	//printf("%i", id_poc);
//	id_poc++;
//	return 0;
//}

int statek::ruch()
{
	//int kierunek = w_kierunek;
	//int predkosc = w_predkosc;
	////cout << x << " " << y << endl;
	////kierunki: 0 - stop, 1 - w lewo, 2 - w gore, 3 - w dol, 4 - w prawo
	//if (kierunek == 4)
	//{
	//	pozycja(x + predkosc, y);
	//}
	//if (kierunek == 3)
	//{
	//	pozycja(x, y + predkosc);
	//}
	//if (kierunek == 2)
	//{
	//	pozycja(x, y - predkosc);
	//}
	//if (kierunek == 1)
	//{
	//	pozycja(x - predkosc, y);
	//}
	//if (kierunek == 0)
	//{
	//	pozycja(x, y);
	//}
	return 0;
}

int statek::kolizja_sciana(sf::Sprite sprite1, sf::Sprite sprite2)
{
	//if (Collision::PixelPerfectTest(statek::zwroc(), sprite1, 0))
	//{
	//	cout << "kolizja_sciana_prawa" << endl;
	//	//zmiana kierunku i wysokosci
	//	w_kierunek = 1;
	//	w_predkosc = 10;
	//	y += 41;
	//}

	//if (Collision::PixelPerfectTest(statek::zwroc(), sprite2, 0))
	//{
	//	cout << "kolizja_sciana_lewa" << endl;
	//	//zmiana kierunku i wysokosci
	//	w_kierunek = 4;
	//	w_predkosc = 10;
	//	y += 41;
	//}

	return 0;
}

void statek::autostrzal(sf::RenderWindow & renderWindow, pocisk * bullet_player, int id_pocisku)
{

	//for (int i = 0; i < 50; i++)
	//{
		//cout << "POCISK = " << id_pocisku << " i = " << i << " || (int)uzytypocisk[i] == " << (int)uzytypocisk[i] << endl;
	//}

	for (int i = 0; i < 50; i++)
	{
		if (uzytypocisk[i] == false)
		{
			bullet_player[i].pozycja(x + 25, y - 50);
			uzytypocisk[i] = true;
			i = 90;
		}
	}
}