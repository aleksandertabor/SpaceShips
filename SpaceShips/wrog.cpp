#include "stdafx.h"
#include "wrog.h"
#include "pocisk.h"

int wrog::stworz(int id, int id_fskin)
{
	id_wroga = id;
	id_skin = id_fskin;
	//cout << "Stworzono nowego wroga. ID=" << id_wroga << endl;
	if (!t_wrog.loadFromFile(tekstury[id_skin]))
		return EXIT_FAILURE;

	s_wrog.setTexture(t_wrog);

	if (id_skin == 0)
	{
		hp = 100;
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

int wrog::zmien_teksture()
{
	if (!t_wrog.loadFromFile(tekstury[id_skin]))
		return EXIT_FAILURE;

	s_wrog.setTexture(t_wrog);

	return 0;
}

int wrog::pozycja(int a, int b)
{
	s_wrog.setPosition((float)a, (float)b);
	x = a;
	y = b;
	return 0;
}

int wrog::posx()
{
	return x;
}

int wrog::posy()
{
	return y;
}

int wrog::dodaj(int a, int b, int c, int d, int e)
{
	pozycja(a, b);
	w_kierunek = c;
	hp = d;
	id_skin = e;
	zmien_teksture();
	return 0;
}


int wrog::wyswietl(sf::RenderWindow & renderWindow)
{
	s_wrog.setPosition((float)x, (float)y);
	renderWindow.draw(s_wrog);
	return 0;
}

sf::Sprite wrog::zwroc()
{
	return s_wrog;
}

int wrog::strzelaj(sf::RenderWindow & renderWindow, pocisk ** bullet, int id_pocisku, int x, int y)
{
	/*
	//Stary sposob rysowania
	for (int i = 0; i < 5; i++)
	{
	paczek[i].pozycja(i * 250, 100);
	}
	*/

	//cout << "Wrog ID=" << id_wroga << ". Strzelil swoim pociskiem ID=" << id_pocisku << endl;


	//bullet[id_wroga][id_pocisku].pozycja(x, y);



	return 0;
}

int wrog::wystrzal(pocisk ** bullet)
{


	for (int i = 0; i < 8; i++)
	{
		//cout << "WROG = " << id_wroga << " i = " << i << " || (int)uzytypocisk[i] == " << (int)uzytypocisk[i] << endl;	
	}

	for (int i = 0; i < 8; i++)
	{
		if (uzytypocisk[i] == false)
		{
			bullet[id_wroga][i].pozycja(wrog::posx() + 14, wrog::posy() + 80);
			uzytypocisk[i] = true;
			i = 90;
		}
	}

	return 0;
}

int wrog::ruch()
{
	int kierunek = w_kierunek;
	int predkosc = w_predkosc;
	//cout << x << " " << y << endl;
	//kierunki: 0 - stop, 1 - w lewo, 2 - w gore, 3 - w dol, 4 - w prawo
	if (kierunek == 4)
	{
		pozycja(x + predkosc, y);
	}	
	if (kierunek == 3)
	{
		pozycja(x, y + predkosc);
	}
	if (kierunek == 2)
	{
		pozycja(x, y - predkosc);
	}
	if (kierunek == 1)
	{
		pozycja(x - predkosc, y);
	}
	if (kierunek == 0)
	{
		pozycja(x, y);
	}
	return 0;
}

int wrog::kolizja_sciana(sf::Sprite sprite1, sf::Sprite sprite2)
{
	if (Collision::PixelPerfectTest(wrog::zwroc(), sprite1, 0))
	{
		//X//cout << "kolizja_sciana_prawa" << endl;
		//zmiana kierunku i wysokosci
		w_kierunek = 1;
		//w_predkosc = 5;
		y += 40;
	}

	if (Collision::PixelPerfectTest(wrog::zwroc(), sprite2, 0))
	{
		//X//cout << "kolizja_sciana_lewa" << endl;
		//zmiana kierunku i wysokosci
		w_kierunek = 4;
		//w_predkosc = 5;
		y += 40;
	}
	
	return 0;
}

