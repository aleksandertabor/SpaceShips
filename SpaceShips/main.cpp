//SpaceShips

//Biblioteki
#include "stdafx.h"
#include "wrog.h"
#include "pocisk.h"
#include "statek.h"

//Deklaracja funkcji
void keyboard();
void autostrzal();

//Obiekty
sf::RenderWindow renderWindow(sf::VideoMode(1280, 720), "SpaceShips");
//sf::RenderWindow renderWindow(sf::VideoMode(1280, 720), "Gra 2D", sf::Style::Fullscreen);
sf::Event event;
wrog* enemy = new wrog[12];//Wrog
statek player;
pocisk** bullet = new pocisk*[60];//Pocisk wroga
pocisk * bullet_player = new pocisk[50];//Pocisk gracza

										 //Zmienne
										 //Statek
int statek_x = 500;
int statek_y = 580;
int numer_pocisku_gracza = -1;
int huj = 0;



int main()
{
	sf::Clock main_clock;
	sf::Time main_time = main_clock.getElapsedTime();


	sf::Clock clock;
	sf::Time t1 = clock.getElapsedTime();

	sf::Clock clock2;
	sf::Time t2 = clock2.getElapsedTime();

	sf::Clock clock3;
	sf::Time t3 = clock3.getElapsedTime();

	sf::Clock clock4;
	sf::Time t4 = clock4.getElapsedTime();

	sf::Clock clock5;
	sf::Time t5 = clock5.getElapsedTime();

	//Inicjacja//
	renderWindow.setFramerateLimit(60);

	//Ladowanie tekstur
	sf::Texture t_tlo;
	if (!t_tlo.loadFromFile("grafika/tlo.png"))
		return EXIT_FAILURE;
	sf::Sprite tlo;
	tlo.setTexture(t_tlo);

	/*sf::Texture t_statek;
	if (!t_statek.loadFromFile("grafika/player1.png"))
		return EXIT_FAILURE;
	sf::Sprite statek;
	statek.setTexture(t_statek);*/

	sf::Texture t_sciana1;
	if (!t_sciana1.loadFromFile("grafika/sciana_lewa_prawa.png"))
		return EXIT_FAILURE;
	sf::Sprite sciana1;
	sciana1.setTexture(t_sciana1);

	sf::Sprite sciana2;
	sciana2.setTexture(t_sciana1);

	sf::Texture t_sciana3;
	if (!t_sciana3.loadFromFile("grafika/sciana_dolna.png"))
		return EXIT_FAILURE;
	sf::Sprite sciana3;
	sciana3.setTexture(t_sciana3);

	sf::Font font1;
	if (!font1.loadFromFile("grafika/arial.ttf")) {}
	sf::Text hp_text;
	hp_text.setFont(font1);
	hp_text.setCharacterSize(36);
	hp_text.setFillColor(sf::Color::Red);
	hp_text.setStyle(sf::Text::Bold);
	hp_text.setPosition(10, 10);

	sf::Text points_text;
	points_text.setFont(font1);
	points_text.setCharacterSize(36);
	points_text.setFillColor(sf::Color::Red);
	points_text.setStyle(sf::Text::Bold);
	points_text.setPosition(10, 100);

	//Inicjacja//

	//Tworzenie playera
	player.stworz(0,0);

	//Tworzenie wrogow
	for (int i = 0; i < 6; i++)
	{
		enemy[i].stworz(i,0);
	}
	for (int i = 6; i < 12; i++)
	{
		enemy[i].stworz(i,1);
	}


	enemy[0].pozycja(1 * 180 + 1, 100);
	enemy[1].pozycja(2 * 180 + 1, 100);
	enemy[2].pozycja(3 * 180 + 1, 100);
	enemy[3].pozycja(4 * 180 + 1, 100);
	enemy[4].pozycja(5 * 180 + 1, 100);
	enemy[5].pozycja(6 * 180 + 1, 100);
	enemy[6].pozycja(1 * 180 + 1, 210);
	enemy[7].pozycja(2 * 180 + 1, 210);
	enemy[8].pozycja(3 * 180 + 1, 210);
	enemy[9].pozycja(4 * 180 + 1, 210);
	enemy[10].pozycja(5 * 180 + 1, 210);
	enemy[11].pozycja(6 * 180 + 1, 210);

	/*
	//Tworzenie wrogow
	for (int i = 0; i < 12; i++)
	{
		enemy[i].stworz(i);
		if (i < 5)
		{
			enemy[i].pozycja(i * 180 + 1, 100);
		}
		else
		{
			enemy[i].pozycja(i * 180 + 1, 210);
		}
		//enemy[i].w_kierunek = 4;
	}
	*/

	//Tworzenie pociskow
	for (int i = 0; i < 60; ++i)
		bullet[i] = new pocisk[60];

	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			bullet[i][j].pozycja(5000, 5000);
			bullet[i][j].przydziel(1);
		}

	}
	//Tworzenie pociskow gracza
	for (int i = 0; i < 50; i++)
	{
		bullet_player[i].pozycja(-100, -100);
		bullet_player[i].przydziel(2);
	}


	/*

	bullet[0][0].pozycja(0, 100);
	bullet[0][1].pozycja(250, 100);
	bullet[0][2].pozycja(500, 100);
	bullet[0][3].pozycja(750, 100);
	bullet[0][4].pozycja(1000, 100);

	bullet[1][0].pozycja(0, 200);
	bullet[1][1].pozycja(250, 200);
	bullet[1][2].pozycja(500, 200);
	bullet[1][3].pozycja(750, 200);
	bullet[1][4].pozycja(1000, 200);

	bullet[2][0].pozycja(0, 300);
	bullet[2][1].pozycja(250, 300);
	bullet[2][2].pozycja(500, 300);
	bullet[2][3].pozycja(750, 300);
	bullet[2][4].pozycja(1000, 300);

	bullet[3][0].pozycja(0, 400);
	bullet[3][1].pozycja(250, 400);
	bullet[3][2].pozycja(500, 400);
	bullet[3][3].pozycja(750, 400);
	bullet[3][4].pozycja(1000, 400);

	bullet[4][0].pozycja(0, 500);
	bullet[4][1].pozycja(250, 500);
	bullet[4][2].pozycja(500, 500);
	bullet[4][3].pozycja(750, 500);
	bullet[4][4].pozycja(1000, 500);

	*/



	//Fizyka gry---------------------------------------------------------------------------
	while (renderWindow.isOpen())
	{
		sf::Time main_time = main_clock.getElapsedTime();
		if (main_time.asMilliseconds() > 1000.0f / 60.0f)
		{
			main_clock.restart();

			renderWindow.clear();//Czyszczenie ekranu

			sf::Time t1 = clock.getElapsedTime();
			sf::Time t2 = clock2.getElapsedTime();
			sf::Time t3 = clock3.getElapsedTime();
			sf::Time t4 = clock4.getElapsedTime();


			if (t2.asMilliseconds() > 1000.0f)
			{

				//enemy[rand() % 11].wystrzal(bullet);

				for (int i = 0; i < 11; i++)
				{
					enemy[i].wystrzal(bullet);
				}

				clock2.restart();
				
			}

			if (t3.asMilliseconds() > 1000.0f)
			{
				player.autostrzal(renderWindow,bullet_player, 0);
				clock3.restart();
			}

			//Licznik hp
			ostringstream ss1;
			ss1 << player.hp;
			string hp_stext = "HP: " + ss1.str();
			hp_text.setString(hp_stext);

			//Punkty
			ostringstream ss2;
			ss2 << player.punkty;
			string points_stext = "Points: " + ss2.str();
			points_text.setString(points_stext);

			keyboard();//Sprawdzanie klawiatury

			

			player.zwroc().setPosition((float)player.x, (float)player.y);//Ustalenie pozycji statku



												   //Rysowanie sprite'ow
			renderWindow.draw(tlo);

			renderWindow.draw(player.zwroc());//
			player.wyswietl(renderWindow);

			sciana1.setPosition(1279, 0);
			renderWindow.draw(sciana1);

			sciana2.setPosition(1, 0);
			renderWindow.draw(sciana2);

			sciana3.setPosition(1, 800);
			renderWindow.draw(sciana3);

			renderWindow.draw(hp_text);
			renderWindow.draw(points_text);


			//Rysowanie wrogow
			for (int i = 0; i < 12; i++)
			{
				enemy[i].wyswietl(renderWindow);
			}
			


			//Zmiana pozycji pociskow

			//enemy[3].pozycja(750, 400);

			//if(pocisk wystrzelony to nie strzelaj nim wiecej) etc
			/*
			for (int i = 0; i < 5; i++)
			{
			enemy[i].strzelaj(renderWindow, bullet, 0, enemy[i].posx() + 85, enemy[i].posy() + 140);
			}

			for (int i = 0; i < 5; i++)
			{
			enemy[i].strzelaj(renderWindow, bullet, 1, enemy[i].posx() + 85, enemy[i].posy() + 240);
			}

			for (int i = 0; i < 5; i++)
			{
			enemy[i].strzelaj(renderWindow, bullet, 2, enemy[i].posx() + 85, enemy[i].posy() + 340);
			}

			bullet[2][0].pozycja(sf::Mouse::getPosition(renderWindow).x, sf::Mouse::getPosition(renderWindow).y);
			*/




			//sf::Mouse::GetPosition(TestWindow).x;

			//system("cls");
			for (int i = 0; i < 6; i++)
			{
				//cout << i<< ":" << enemy[i].posx() << "x" << enemy[i].posy() << endl;
			}
			//cout << "Pocisk" << t_pocisk_x << "x" << t_pocisk_y << endl;
			//cout << "Statek" << statek_x << "x" << statek_y << endl;

			/*


			*/

			//Wyswietlenie pociskow


			for (int i = 0; i < 50; i++)
			{
				bullet_player[i].wyswietl(renderWindow);
				bullet_player[i].ruch();
			}


			for (int i = 0; i < 11; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					bullet[i][j].wyswietl(renderWindow);
					bullet[i][j].ruch();
				}

			}





			for (int i = 0; i < 12; i++)
			{
				enemy[i].ruch();
			}



			//Rysowanie calej gry
			renderWindow.display();


			for (int i = 0; i < 12; i++)
			{
				enemy[i].kolizja_sciana(sciana1, sciana2);
			}

			for (int i = 0; i < 12; i++)
			{
				if (Collision::PixelPerfectTest(player.zwroc(), enemy[i].zwroc(), 0))
				{
					//X//std::cout << "[" << t1.asSeconds() << "] " << "Kolizja statku z wrogiem" << "i" << i << std::endl;
					player.pozycja(13000, 13000);
				}
			}
			for (int i = 0; i < 12; i++)
			{
				for (int j = 0; j < 12; j++)
				{
					

					if (Collision::PixelPerfectTest(player.zwroc(), bullet[i][j].zwroc(), 0))
					{
						//system("pause>nul");
						
						player.hp -= bullet[i][j].power;

						//X//std::cout << "[" << t1.asSeconds() << "] " << "Kolizja statku z pociskiem wroga " << "[i]" << i  << " [j]" << j << std::endl;
						//exit(1);

						
						//X//cout << "player.hp = " << player.hp << endl;
						
						if (player.hp <= 0)
						{
							player.pozycja(13000, 13000);
						}

						bullet[i][j].pozycja(5000, 10);

					}
				}

			}

			for (int i = 0; i < 12; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					if (Collision::PixelPerfectTest(sciana3, bullet[i][j].zwroc(), 0))
					{
						bullet[i][j].pozycja(4000, 10);
						//bullet[i][j].zwolnienie();
						enemy[i].uzytypocisk[j] = false;
						cout << "Zwalniam [" << i << "][" << j << "]" << endl;
						cout << "||" << endl;
						cout << "enemy[i].uzytypocisk[j] = " << enemy[i].uzytypocisk[j] << endl;
						//Sleep(100);
						//bullet[i][j].pocisk_w_uzyciu = 0;


					}
				}
			}

			for (int i = 0; i < 12; i++)
			{
				for (int j = 0; j < 30; j++)
				{
						if (Collision::PixelPerfectTest(enemy[i].zwroc(), bullet_player[j].zwroc(), 0))
						{
							//X//std::cout << bullet_player[j].used << endl;
							if (bullet_player[j].used == 0)
							{
								

								enemy[i].hp -= bullet_player[j].power;
								//X//std::cout << "[" << t1.asSeconds() << "] " << "Kolizja wroga z pociskiem playera" << "[i]" << i << "hp: " << enemy[i].hp << std::endl;
								player.punkty += 50;
								enemy[i].id_skin = 3;
								enemy[i].zmien_teksture();




								if (enemy[i].hp <= 0)
								{
									enemy[i].pozycja(10000, 10000);
								}

								bullet_player[j].used = 1;
								bullet_player[j].pozycja(2000, 2000);
							}	
					 }
				}

			}


			//_getch();
		}
		//_getch();
	}
}
//zrob kolizje ktore zabijaja wrogow
void keyboard()
{
	while (renderWindow.pollEvent(event)) {
		if (event.type == sf::Event::EventType::Closed)
			renderWindow.close();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			renderWindow.close();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		player.x -= 5;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		player.x += 5;

	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		player.y -= 5;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		player.y += 5;*/

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
	{
		for(int i = 0; i <= 5; i++)
		{ 
			enemy[i].wystrzal(bullet);
		}

		Sleep(200);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		bullet_player[0].pozycja(500, 500);
		Sleep(200);
	}
}

void autostrzal()
{
	//numer_pocisku_gracza++;
	//bullet_player[numer_pocisku_gracza].pozycja(player.x + 80, player.y - 80);
}
