//SpaceShips

#include <conio.h>
#include <cstdio>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <chrono>
#include <string>

using namespace std;

int py = 0;
int px = 0;

sf::RenderWindow renderWindow(sf::VideoMode(1280, 720), "SpaceShips");


// pociski

class pocisk
{
public:
	int x = 0;
	int y = 0;
	string tekstura;

	sf::Texture t_pocisk;
	sf::Sprite s_pocisk;
	int pocisk::stworz(string tesktura);
	int pocisk::pozycja(int x, int y);
	int pocisk::wyswietl();
	int pocisk::usun();
};

int pocisk::stworz(string tesktura)
{

	if (!t_pocisk.loadFromFile(tesktura))
		return EXIT_FAILURE;

	s_pocisk.setTexture(t_pocisk);

	return 0;
}

int pocisk::pozycja(int x, int y)
{
	s_pocisk.setPosition(x, y);
	return 0;
}

int pocisk::wyswietl()
{
	renderWindow.draw(s_pocisk);
	return 0;
}

int pocisk::usun()
{

	return 0;
}

pocisk* paczek = new pocisk[5];

// wrogowie

class wrog
{
public:
	int x = 0;
	int y = 0;
	int id_wroga = 0;
	int id_pocisku = 0;
	string tekstura;

	sf::Texture t_wrog;
	sf::Sprite s_wrog;
	int wrog::stworz(string tesktura);
	int wrog::pozycja(int a, int b);
	int wrog::wyswietl();
	int wrog::strzelaj(int id_wroga, int id_pocisku, int x, int y);
};

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


int wrog::wyswietl()
{
	renderWindow.draw(s_wrog);
	return 0;
}

int wrog::strzelaj(int id_wroga, int id_pocisku, int x, int y)
{
	for (int i = 0; i < 5; i++)
	{
		paczek[i].stworz("grafika/pocisk.png");
		paczek[i].pozycja(i * 250, 100);
		//paczek[i].wyswietl();
	}
	/*nalesnik.stworz("grafika/pocisk.png");
	nalesnik.pozycja(x, y);
	nalesnik.wyswietl();*/
	return 0;
}



// zmienne

int x = 0;
int y = 0;

int wrog_x = 0;
int wrog_y = 0;


int main()
{

	printf("Witam\n");
	//sf::RenderWindow renderWindow(sf::VideoMode(1280, 720), "Gra 2D", sf::Style::Fullscreen);
	//sf::RenderWindow renderWindow(sf::VideoMode(1280, 720), "Space");
	renderWindow.setFramerateLimit(60);
	sf::Event event;
	sf::CircleShape circleShape(200);
	circleShape.setFillColor(sf::Color::Green);
	sf::CircleShape triangle(80, 3);
	sf::CircleShape square(80, 4);
	sf::CircleShape octagon(80, 8);
	triangle.setPosition(200, 200);
	square.setPosition(300, 200);
	octagon.setPosition(400, 200);
	triangle.setFillColor(sf::Color::Cyan);
	square.setFillColor(sf::Color::Cyan);
	octagon.setFillColor(sf::Color::Cyan);

	sf::Texture imageSource;
	if (!imageSource.loadFromFile("grafika/tlo.png"))
		return EXIT_FAILURE;
	sf::Sprite imageSprite;
	imageSprite.setTexture(imageSource);

	sf::Texture t_statek;
	if (!t_statek.loadFromFile("grafika/statek.png"))
		return EXIT_FAILURE;
	sf::Sprite statek;
	statek.setTexture(t_statek);

	/*sf::Texture t_wrog;
	if (!t_wrog.loadFromFile("grafika/wrog.png"))
	return EXIT_FAILURE;
	sf::Sprite wrog;
	wrog.setTexture(t_wrog);*/

	wrog pierog;
	pierog.stworz("grafika/wrog.png");
	pierog.pozycja(500, 200);

	wrog* krasnal = new wrog[5];
	for (int i = 0; i < 5; i++)
	{
		krasnal[i].stworz("grafika/wrog.png");
		krasnal[i].pozycja(i * 250, 100);
	}



	/*pocisk* kasztan = new pocisk[5];
	for (int i = 0; i < 5; i++)
	{
	kasztan[i].stworz("grafika/pocisk.png");
	kasztan[i].pozycja(i * 50, i * 50);
	}*/


	x = 500;
	y = 580;
	//wrog_x = 500;
	//wrog_y = 50;


	while (renderWindow.isOpen()) {
		//if(true) {
		while (renderWindow.pollEvent(event)) {
			if (event.type == sf::Event::EventType::Closed)
				renderWindow.close();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				renderWindow.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			x -= 5;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			x += 5;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
			x += 5;


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
		{
			px = rand() % 1280;
			py = rand() % 720;
			cout << px << py << endl;
		}

		statek.setPosition(x, y);
		//wrog.setPosition(100, 100);

		renderWindow.clear();
		renderWindow.draw(imageSprite);
		renderWindow.draw(statek);
		//pierog.wyswietl();
		for (int i = 0; i < 5; i++)
		{
			krasnal[i].wyswietl();
			krasnal[i].strzelaj(0, 0, 0, 0);
		}

		paczek[1].pozycja(50, 50);
		//paczek[1].wyswietl();

		paczek[0].pozycja(px, py);
		//paczek[0].wyswietl();

		for (int i = 0; i < 5; i++)
		{
			paczek[i].wyswietl();
		}


		/*
		for (int i = 0; i < 5; i++)
		{
		krasnal[i].strzelaj(i,0,krasnal[i].x, krasnal[i].y);
		}
		*/
		/*for (int w = 1; w < 3; w++)
		{

		for (int i = 0; i < 5; i++)
		{
		krasnal[i].strzelaj(i, w, krasnal[i].x+85, krasnal[i].y+150*w);
		}
		}*/


		/*for (int i = 0; i < 5; i++)
		{
		kasztan[i].wyswietl();
		}*/

		//renderWindow.draw(wrog);


		renderWindow.display();
	}
	//_getch();
}