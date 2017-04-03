#include "stdatx.h"
#include "pocisk.h"

pocisk::pocisk()
{
	if (!t_pocisk.loadFromFile(tekstura)) { /*return EXIT_FAILURE;*/ }
	s_pocisk.setTexture(t_pocisk);
}

int pocisk::pozycja(int x, int y)
{
	s_pocisk.setPosition(x, y);
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