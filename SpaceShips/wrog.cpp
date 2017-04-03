#include "stdatx.h"
#include "wrog.h"
#include "pocisk.h"

int wrog::stworz(string tesktura)
{

	if (!t_wrog.loadFromFile(tesktura))
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


int wrog::wyswietl(sf::RenderWindow & renderWindow)
{
	renderWindow.draw(s_wrog);
	return 0;
}

int wrog::strzelaj(sf::RenderWindow & renderWindow, pocisk * paczek, int id_wroga, int id_pocisku, int x, int y)
{
	/*
	//Stary sposob rysowania
	for (int i = 0; i < 5; i++)
	{
		paczek[i].pozycja(i * 250, 100);
	}
	*/

	//cout << id_wroga << endl;
	paczek[id_wroga].pozycja(x,y);
	

	return 0;
}