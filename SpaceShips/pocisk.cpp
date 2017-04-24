#include "stdatx.h"
#include "pocisk.h"

pocisk::pocisk()
{
	if (!t_pocisk.loadFromFile(tekstura)) { /*return EXIT_FAILURE;*/ }
	s_pocisk.setTexture(t_pocisk);
}

int pocisk::pozycja(int a, int b)
{
	s_pocisk.setPosition(a, b);
	//s_pocisk.setPosition(300, 300);
	x = a;
	y = b;
	return 0;
}

int pocisk::wyswietl(sf::RenderWindow & renderWindow)
{
	renderWindow.draw(s_pocisk);
	return 0;
}

int pocisk::usun()
{
	return 0;
}
sf::Sprite pocisk::zwroc()
{
	return s_pocisk;
}

int pocisk::ruch()
{
	cout << x << " " <<  y << endl;
	pozycja(x, y + 2);
	return 0;
}