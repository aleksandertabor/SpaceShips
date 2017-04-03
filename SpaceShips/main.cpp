//SpaceShips

//Biblioteki
#include "stdatx.h"
#include "wrog.h"
#include "pocisk.h"

//Deklaracja funkcji
void keyboard();

//Obiekty
sf::RenderWindow renderWindow(sf::VideoMode(1280, 720), "SpaceShips");
//sf::RenderWindow renderWindow(sf::VideoMode(1280, 720), "Gra 2D", sf::Style::Fullscreen);
sf::Event event;
wrog* enemy = new wrog[5];//Wrog
pocisk* bullet = new pocisk[5];//Pocisk wroga

//Zmienne
//Statek
int statek_x = 500;
int statek_y = 580;

//Testowy pocisk
int t_pocisk_x = 0;
int t_pocisk_y = 0;

int main()
{
	//Inicjacja//
	renderWindow.setFramerateLimit(60);

	//Ladowanie tekstur
	sf::Texture t_tlo;
	if (!t_tlo.loadFromFile("grafika/tlo.png"))
		return EXIT_FAILURE;
	sf::Sprite tlo;
	tlo.setTexture(t_tlo);

	sf::Texture t_statek;
	if (!t_statek.loadFromFile("grafika/statek.png"))
		return EXIT_FAILURE;
	sf::Sprite statek;
	statek.setTexture(t_statek);
	//Inicjacja//

	//Tworzenie wrogow
	for (int i = 0; i < 5; i++)
	{
		enemy[i].stworz("grafika/wrog.png");
		enemy[i].pozycja(i * 250, 100);
	}

	//Fizyka gry---------------------------------------------------------------------------
	while (renderWindow.isOpen()) 
	{
		keyboard();//Sprawdzanie klawiatury

		statek.setPosition(statek_x, statek_y);//Ustalenie pozycji statku

		renderWindow.clear();//Czyszczenie ekranu

		//Rysowanie sprite'ow
		renderWindow.draw(tlo);
		renderWindow.draw(statek);

		//Rysowanie wrogow
		for (int i = 0; i < 5; i++) 
		{
			enemy[i].wyswietl(renderWindow);
		}

		/*
		//Stary sposob rysowania
		for (int i = 0; i < 5; i++)
		{
			enemy[i].strzelaj(renderWindow, &bullet[0], 0, 0, 0, 0);
		}
		*/

		//Zmiana pozycji pociskow
		enemy[0].strzelaj(renderWindow, &bullet[0], 0, 0, 0, 100);
		enemy[0].strzelaj(renderWindow, &bullet[1], 0, 0, 250, 100);
		enemy[0].strzelaj(renderWindow, &bullet[2], 0, 0, 500, 100);
		enemy[0].strzelaj(renderWindow, &bullet[3], 0, 0, 750, 100);
		enemy[0].strzelaj(renderWindow, &bullet[4], 0, 0, 1000, 100);

		//Klawisz B
		bullet[0].pozycja(t_pocisk_x, t_pocisk_y);
		
		//Wyswietlenie pociskow
		for (int i = 0; i < 5; i++)
		{
			bullet[i].wyswietl(renderWindow);
		}

		//Rysowanie calej gry
		renderWindow.display();

		//_getch();
	}
	//_getch();
}

void keyboard()
{
	while (renderWindow.pollEvent(event)) {
		if (event.type == sf::Event::EventType::Closed)
			renderWindow.close();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			renderWindow.close();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		statek_x -= 5;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		statek_x += 5;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
	{
		t_pocisk_x = rand() % 1280;
		t_pocisk_y = rand() % 720;
		cout << t_pocisk_x << "x" << t_pocisk_y << endl;
	}
}
