#include "stdatx.h"
#include "wrog.h"
#include "pocisk.h"

int wrog::stworz(int id)
{
	id_wroga = id;
	//cout << "Stworzono nowego wroga. ID=" << id_wroga << endl;
	if (!t_wrog.loadFromFile(tekstura))
		return EXIT_FAILURE;

	s_wrog.setTexture(t_wrog);

	return 0;
}

int wrog::pozycja(int a, int b)
{
	s_wrog.setPosition(a, b);
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


int wrog::wyswietl(sf::RenderWindow & renderWindow)
{
	s_wrog.setPosition(x, y);
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


	bullet[id_wroga][id_pocisku].pozycja(x, y);



	return 0;
}

int wrog::wystrzal(pocisk ** bullet)
{
	bullet[id_wroga][id_poc].pozycja(wrog::posx() + 85, wrog::posy() + 140);
	zuzyty = 1;
	//printf("%i", id_poc);
	id_poc++;
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
		cout << "kolizja_sciana_prawa" << endl;
		//zmiana kierunku i wysokosci
		w_kierunek = 1;
		w_predkosc = 10;
		y += 50;
	}

	if (Collision::PixelPerfectTest(wrog::zwroc(), sprite2, 0))
	{
		cout << "kolizja_sciana_lewa" << endl;
		//zmiana kierunku i wysokosci
		w_kierunek = 4;
		w_predkosc = 10;
		y += 50;
	}
	
	return 0;
}