#include "stdafx.h"
#include "pocisk.h"

pocisk::pocisk()
{
	
}

int pocisk::przydziel(int x)
{
	if (!t_pocisk.loadFromFile(tekstury[1])) { return EXIT_FAILURE; }
	s_pocisk.setTexture(t_pocisk);
	if (!t_pocisk2.loadFromFile(tekstury[0])) { return EXIT_FAILURE; }
	s_pocisk2.setTexture(t_pocisk2);
	pocisk_w_uzyciu = 1;
	used = 0;
	id_skin = x;
	if (id_skin == 1)
	{
		power = 50;
	}
	if (id_skin == 2)
	{
		power = 110;
	}

	return 0;
}

int pocisk::pozycja(int a, int b)
{
	if (id_skin == 1)
	s_pocisk.setPosition((float)a, (float)b);
	if (id_skin == 2)
	s_pocisk2.setPosition((float)a, (float)b);
	//s_pocisk.setPosition(300, 300);
	x = a;
	y = b;
	return 0;
}

int pocisk::zwolnienie()
{

	cout << "ZWOLNIENIE()" << endl;
	Sleep(200);
	pocisk_w_uzyciu = 0;

	return 0;
}

int pocisk::wyswietl(sf::RenderWindow & renderWindow)
{

	if (id_skin == 2)
	renderWindow.draw(s_pocisk2);
	if (id_skin == 1)
	renderWindow.draw(s_pocisk);


	return 0;
}

int pocisk::usun()
{
	return 0;
}
sf::Sprite pocisk::zwroc()
{
	if (id_skin == 2)
		return s_pocisk2;
	if (id_skin == 1)
		return s_pocisk;
	
	return s_pocisk2;
}

int pocisk::ruch()
{
	if (id_skin == 1)
	pozycja(x, y + 3);
	if (id_skin == 2)
	pozycja(x, y - 3);
	return 0;
}