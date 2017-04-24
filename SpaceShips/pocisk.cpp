#include "stdatx.h"
#include "pocisk.h"

pocisk::pocisk()
{
	if (!t_pocisk.loadFromFile(tekstura)) { /*return EXIT_FAILURE;*/ }
	s_pocisk.setTexture(t_pocisk);
	if (!t_pocisk2.loadFromFile(tekstura_2)) { /*return EXIT_FAILURE;*/ }
	s_pocisk2.setTexture(t_pocisk2);
}

int pocisk::przydziel(int x)
{
	ktory = x;
	return 0;
}

int pocisk::pozycja(int a, int b)
{
	s_pocisk.setPosition(a, b);
	s_pocisk2.setPosition(a, b);
	//s_pocisk.setPosition(300, 300);
	x = a;
	y = b;
	return 0;
}

int pocisk::wyswietl(sf::RenderWindow & renderWindow)
{
	if (ktory == 2)
	renderWindow.draw(s_pocisk2);
	if (ktory == 1)
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
	if (ktory == 1)
	pozycja(x, y + 2);
	if (ktory == 2)
	pozycja(x, y - 2);
	return 0;
}