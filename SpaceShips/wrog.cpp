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
	bullet[id_wroga][0].pozycja(wrog::posx() + 85, wrog::posy() + 140);

	return 0;
}