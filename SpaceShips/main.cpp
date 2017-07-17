//SpaceShips

//Biblioteki
#include "stdafx.h"
#include "wrog.h"
#include "pocisk.h"
#include "statek.h"

//Deklaracja funkcji
void keyboard();

//Obiekty
//sf::RenderWindow renderWindow(sf::VideoMode(1280, 720), "SpaceShips");
sf::RenderWindow renderWindow(sf::VideoMode(1280, 720), "SpaceShips", sf::Style::Fullscreen);
sf::Event event;

int liczba_statkow = 50;
bool wrog_na_ekranie[50];
bool uzytywrog[50];

int liczba_pociskow_gracza = 100;

wrog* enemy = new wrog[50];//Wrog
statek player;
pocisk** bullet = new pocisk*[60];//Pocisk wroga
pocisk * bullet_player = new pocisk[100];//Pocisk gracza

										 //Zmienne
										 //Statek
int statek_x = 550;
int statek_y = 58;
int numer_pocisku_gracza = -1;
int random = 0;


int mstart = 0;
int wybranaopcja = 1;




int main()
{
	renderWindow.setKeyRepeatEnabled(false);

	sf::Texture background;
	background.loadFromFile("grafika/background.png");

	sf::Sprite transp;
	transp.setTexture(background);
	transp.setColor(sf::Color(255, 255, 255, 128));


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
	if (!t_tlo.loadFromFile("grafika/tlo2.jpeg"))
		return EXIT_FAILURE;
	sf::Sprite tlo;
	tlo.setTexture(t_tlo);

	sf::Texture t_menu;
	if (!t_menu.loadFromFile("grafika/menu.png"))
		return EXIT_FAILURE;
	sf::Sprite smenu;
	smenu.setTexture(t_menu);

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
	if (!font1.loadFromFile("grafika/good times rg.ttf")) {}
	sf::Font font2;
	if (!font2.loadFromFile("grafika/good times rg.ttf")) {}


	sf::Text pauza_t;
	pauza_t.setFont(font2);
	pauza_t.setCharacterSize(60);
	pauza_t.setFillColor(sf::Color::White);
	pauza_t.setStyle(sf::Text::Bold);
	pauza_t.setPosition(500, 250);

	sf::Text points_text;
	points_text.setFont(font1);
	points_text.setCharacterSize(36);
	points_text.setFillColor(sf::Color::Red);
	points_text.setStyle(sf::Text::Bold);
	points_text.setPosition(10, 10);

	sf::Text hp_text;
	hp_text.setFont(font1);
	hp_text.setCharacterSize(36);
	hp_text.setFillColor(sf::Color::Red);
	hp_text.setStyle(sf::Text::Bold);
	hp_text.setPosition(10, 60);

	sf::Text nlevel;
	nlevel.setFont(font1);
	nlevel.setCharacterSize(36);
	nlevel.setFillColor(sf::Color::Red);
	nlevel.setStyle(sf::Text::Bold);
	nlevel.setPosition(10, 110);

	sf::Text menu1;
	menu1.setFont(font1);
	menu1.setCharacterSize(36);
	menu1.setFillColor(sf::Color::Red);
	menu1.setStyle(sf::Text::Bold);
	menu1.setPosition(550, 270);

	sf::Text menu2;
	menu2.setFont(font1);
	menu2.setCharacterSize(36);
	menu2.setFillColor(sf::Color::Red);
	menu2.setStyle(sf::Text::Bold);
	menu2.setPosition(550, 370);

	sf::Text menu3;
	menu3.setFont(font1);
	menu3.setCharacterSize(36);
	menu3.setFillColor(sf::Color::Red);
	menu3.setStyle(sf::Text::Bold);
	menu3.setPosition(550, 470);

	sf::Text logo;
	logo.setFont(font1);
	logo.setCharacterSize(72);
	logo.setFillColor(sf::Color::Green);
	logo.setStyle(sf::Text::Bold);
	logo.setPosition(400, 50);

	sf::Text authors;
	authors.setFont(font1);
	authors.setCharacterSize(72);
	authors.setFillColor(sf::Color::Green);
	authors.setStyle(sf::Text::Bold);
	authors.setPosition(400, 50);

	sf::Text autorzy;
	autorzy.setFont(font1);
	autorzy.setCharacterSize(36);
	autorzy.setFillColor(sf::Color::Yellow);
	autorzy.setStyle(sf::Text::Bold);
	autorzy.setPosition(200, 200);

	logo.setString("SPACE SHIPS");
	authors.setString("AUTHORS");
	menu1.setString("START");
	menu2.setString("AUTHORS");
	menu3.setString("EXIT");
	nlevel.setString("LEVEL: 1");

	//Inicjacja//

	//Tworzenie playera
	player.stworz(0, 0);

	//Tworzenie wrogow

	for (int a = 0; a < 5; a++)
	{
		for (int b = 0; b < 10; b++)
		{
			if (a % 2 == 0)
			{
				enemy[(a * 10) + b].stworz((a * 10) + b, 0);
			}
			else
			{
				enemy[(a * 10) + b].stworz((a * 10) + b, 0);
			}
		}
	}

	for (int a = 0; a < 5; a++)
	{
		for (int b = 0; b < 10; b++)
		{
			enemy[(a * 10) + b].pozycja(b * 80 + 1, a * 80);
		}
	}

	for (int i = 0; i < liczba_statkow; i++)
	{
		enemy[i].w_kierunek = 4;
	}

	//Tworzenie pociskow
	for (int i = 0; i < 60; ++i)
		bullet[i] = new pocisk[60];

	for (int i = 0; i < liczba_statkow; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			bullet[i][j].pozycja(5000, 5000);
			bullet[i][j].przydziel(1);
		}

	}
	//Tworzenie pociskow gracza
	for (int i = 0; i < liczba_pociskow_gracza; i++)
	{
		bullet_player[i].pozycja(-100, -100);
		bullet_player[i].przydziel(2);
	}




	//Fizyka gry---------------------------------------------------------------------------
	while (renderWindow.isOpen())
	{
		if (mstart == 0)
		{

			sf::Time main_time = main_clock.getElapsedTime();
			if (main_time.asMilliseconds() > 1000.0f / 60.0f)
			{
				main_clock.restart();
				renderWindow.clear();
				keyboard();
				renderWindow.draw(smenu);


				menu1.setFillColor(sf::Color::Yellow);
				menu2.setFillColor(sf::Color::Yellow);
				menu3.setFillColor(sf::Color::Yellow);

				if (wybranaopcja == 1)
				{
					menu1.setFillColor(sf::Color::Red);
				}
				if (wybranaopcja == 2)
				{
					menu2.setFillColor(sf::Color::Red);
				}
				if (wybranaopcja == 3)
				{
					menu3.setFillColor(sf::Color::Red);
				}


				//renderWindow.draw(transp);
				renderWindow.draw(logo);
				renderWindow.draw(menu1);
				renderWindow.draw(menu2);
				renderWindow.draw(menu3);
				renderWindow.display();
			}
		}

		if (mstart == 2)
		{
			sf::Time main_time = main_clock.getElapsedTime();
			if (main_time.asMilliseconds() > 1000.0f / 60.0f)
			{
				main_clock.restart();
				renderWindow.clear();
				keyboard();
				renderWindow.draw(smenu);
				autorzy.setString("C++ Developers:\nAleksander Tabor\nTomasz Zurek\n\n\nGame created with SFML Library\n\nGraphics were downloaded from:\nwww.flaticon.com\nwww.freepik.com\n");

				renderWindow.draw(authors);
				renderWindow.draw(autorzy);
				renderWindow.display();
			}
		}

		if (mstart == 3)
		{
			renderWindow.close();
		}


		if (mstart == 1)
		{
			menu1.setString("RETURN");


			sf::Time main_time = main_clock.getElapsedTime();
			if (main_time.asMilliseconds() > 1000.0f / 60.0f)
			{
				main_clock.restart();

				renderWindow.clear();//Czyszczenie ekranu

				sf::Time t1 = clock.getElapsedTime();
				sf::Time t2 = clock2.getElapsedTime();
				sf::Time t3 = clock3.getElapsedTime();
				sf::Time t4 = clock4.getElapsedTime();

				if (t3.asMilliseconds() > 400.0f)
				{
					player.autostrzal(renderWindow, bullet_player, 0);
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

				//Pauza
				ostringstream ss3;
				string pauza = "PAUSE";
				pauza_t.setString(pauza);

				keyboard();//Sprawdzanie klawiatury

				if (player.hp <= 0)
				{

					nlevel.setString("You lost, press ENTER to restart!");
					int dsfg = 0;
					while (dsfg != 90)
					{
						renderWindow.clear();
						renderWindow.draw(tlo);
						renderWindow.draw(nlevel);
						renderWindow.display();

						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
						{
							dsfg = 90;
						}

					}
					nlevel.setString("Level: 1");
					player.hp = 100;
					player.punkty = 0;
					player.pozycja(500, 580);

					for (int a = 0; a < 5; a++)
					{
						for (int b = 0; b < 10; b++)
						{
							enemy[(a * 10) + b].pozycja(b * 80 + 1, a * 80);
						}
					}

					for (int i = 0; i < liczba_statkow; i++)
					{
						enemy[i].w_kierunek = 4;
						enemy[i].id_skin = 0;
						enemy[i].zmien_teksture();
					}

					//Tworzenie pociskow

					for (int i = 0; i < liczba_statkow; i++)
					{
						for (int j = 0; j < 8; j++)
						{
							bullet[i][j].pozycja(5000, 5000);
							bullet[i][j].przydziel(1);
						}

					}
					//Tworzenie pociskow gracza
					for (int i = 0; i < liczba_pociskow_gracza; i++)
					{
						bullet_player[i].pozycja(-100, -100);
						bullet_player[i].przydziel(2);
					}
				}

				player.zwroc().setPosition((float)player.x, (float)player.y);//Ustalenie pozycji statku

				if (player.punkty >= 6499)
				{
					nlevel.setString("You won, press ENTER to restart!");
					int dsfg = 0;
					while (dsfg != 90)
					{
						renderWindow.clear();
						renderWindow.draw(tlo);
						renderWindow.draw(nlevel);
						renderWindow.display();

						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
						{
							dsfg = 90;
						}

					}
					nlevel.setString("Level: 1");
					player.hp = 100;
					player.punkty = 0;
					player.pozycja(500, 580);

					for (int a = 0; a < 5; a++)
					{
						for (int b = 0; b < 10; b++)
						{
							enemy[(a * 10) + b].pozycja(b * 80 + 1, a * 80);
						}
					}

					for (int i = 0; i < liczba_statkow; i++)
					{
						enemy[i].w_kierunek = 4;
						enemy[i].id_skin = 0;
						enemy[i].zmien_teksture();
					}

					//Tworzenie pociskow

					for (int i = 0; i < liczba_statkow; i++)
					{
						for (int j = 0; j < 8; j++)
						{
							bullet[i][j].pozycja(5000, 5000);
							bullet[i][j].przydziel(1);
						}

					}
					//Tworzenie pociskow gracza
					for (int i = 0; i < liczba_pociskow_gracza; i++)
					{
						bullet_player[i].pozycja(-100, -100);
						bullet_player[i].przydziel(2);
					}
				}

				if (player.punkty == 2500)
				{
					nlevel.setString("LEVEL: 2");
					player.punkty += 500;


					for (int a = 0; a < 5; a++)
					{
						for (int b = 0; b < 10; b++)
						{
							if (a % 2 == 0)
							{
								enemy[(a * 10) + b].dodaj(b * 80 + 1, a * 80, 4, 100, 0);
							}
							else
							{
								enemy[(a * 10) + b].dodaj(b * 80 + 1, a * 80, 4, 150, 1);
							}
						}
					}


					//enemy[9].dodaj(200, 0, 4, 150, 1);
					//enemy[3].dodaj(200, 200, 4, 100, 0);
				}

				if (player.punkty == 6500)
				{
					nlevel.setString("LEVEL: 3");
					player.punkty += 500;
					enemy[8].dodaj(200, 0, 4, 150, 1);
					enemy[9].dodaj(400, 0, 4, 150, 1);
					enemy[2].dodaj(200, 200, 4, 100, 0);
					enemy[3].dodaj(400, 200, 4, 100, 0);
				}


				renderWindow.draw(tlo);

				renderWindow.draw(player.zwroc());//
				player.wyswietl(renderWindow);

				sciana1.setPosition(1279, 0);
				renderWindow.draw(sciana1);

				sciana2.setPosition(1, 0);
				renderWindow.draw(sciana2);

				sciana3.setPosition(1, 800);
				renderWindow.draw(sciana3);

				

				if (player.punkty == 7300)
				{
					cout << "Winer!" << endl;
					player.punkty += 1000;
				}


				for (int i = 0; i < liczba_statkow; i++)
				{
					if (enemy[i].x > -2 && enemy[i].x < 1282 && enemy[i].y > -2 && enemy[i].y < 722)
					{
						wrog_na_ekranie[i] = true;
					}
					else
					{
						wrog_na_ekranie[i] = false;
					}
				}

				int vcx = 0;

				if (player.punkty < 7290)
				{
					while (vcx != 90)
					{
						random = rand() % liczba_statkow - 1;
						if (wrog_na_ekranie[random] == true)
						{
							vcx = 90;
							//cout << "TAK " << random << endl;
						}
						else
						{
							//cout << "NIE " << random << endl;
						}
					}
				}


				if (t2.asMilliseconds() > 700.0f)
				{
					enemy[random].wystrzal(bullet);
					uzytywrog[random] = true;

					clock2.restart();
				}



				//Rysowanie sprite'ow

				//Rysowanie wrogow
				for (int i = 0; i < liczba_statkow; i++)
				{
					enemy[i].wyswietl(renderWindow);
				}

				//Wyswietlenie pociskow


				for (int i = 0; i < liczba_pociskow_gracza; i++)
				{
					bullet_player[i].wyswietl(renderWindow);
					bullet_player[i].ruch();
				}


				for (int i = 0; i < liczba_statkow; i++)
				{
					for (int j = 0; j < 8; j++)
					{

						bullet[i][j].wyswietl(renderWindow);
						bullet[i][j].ruch();
					}

				}


				for (int i = 0; i < liczba_statkow; i++)
				{
					enemy[i].ruch();
				}


				// PAUZA I TLO PRZEZROCZYSTE
				//renderWindow.draw(transp);
				//renderWindow.draw(pauza_t);


				renderWindow.draw(hp_text);
				renderWindow.draw(points_text);
				renderWindow.draw(nlevel);


				//Rysowanie calej gry
				renderWindow.display();


				for (int i = 0; i < liczba_statkow; i++)
				{
					enemy[i].kolizja_sciana(sciana1, sciana2);
				}

				for (int i = 0; i < liczba_statkow; i++)
				{
					if (Collision::PixelPerfectTest(player.zwroc(), enemy[i].zwroc(), 0))
					{
						//X//std::cout << "[" << t1.asSeconds() << "] " << "Kolizja statku z wrogiem" << "i" << i << std::endl;
						//player.pozycja(3000, -200);
						player.hp = -1;
					}
				}
				for (int i = 0; i < liczba_statkow; i++)
				{
					for (int j = 0; j < liczba_statkow; j++)
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
								player.pozycja(3000, -200);
							}

							bullet[i][j].pozycja(2500, 500);

						}
					}

				}

				for (int i = 0; i < liczba_statkow; i++)
				{
					for (int j = 0; j < 8; j++)
					{
						//if (Collision::PixelPerfectTest(sciana3, bullet[i][j].zwroc(), 0))
						if (bullet[i][j].y > 730)
						{
							bullet[i][j].pozycja(2500, 500);
							enemy[i].uzytypocisk[j] = false;
						}
					}
				}

				for (int i = 0; i < liczba_statkow; i++)
				{
					if (enemy[i].y > 730)
					{
						enemy[i].pozycja(2500, 500);
						enemy[i].w_kierunek = 0;
					}
				}

				for (int i = 0; i < 30; i++)
				{
					if (bullet_player[i].y < -100)
					{
						bullet_player[i].pozycja(4000, 100);
						player.uzytypocisk[i] = false;
					}
				}

				for (int i = 0; i < liczba_statkow; i++)
				{
					for (int j = 0; j < liczba_pociskow_gracza; j++)
					{
						if (Collision::PixelPerfectTest(enemy[i].zwroc(), bullet_player[j].zwroc(), 0))
						{
							//cout << "S" << endl;
							//X//std::cout << bullet_player[j].used << endl;
							if (player.uzytypocisk[j] == true)
							{
								//cout << "X" << endl;

								enemy[i].hp -= bullet_player[j].power;
								//X//std::cout << "[" << t1.asSeconds() << "] " << "Kolizja wroga z pociskiem playera" << "[i]" << i << "hp: " << enemy[i].hp << std::endl;
								player.punkty += 50;
								enemy[i].id_skin = 3;
								enemy[i].zmien_teksture();




								if (enemy[i].hp <= 0)
								{
									enemy[i].pozycja(3500, 500);
									enemy[i].w_kierunek = 0;
								}

								bullet_player[j].pozycja(2000, 300);
							}
						}
					}

				}


				//_getch();
			}
			//_getch();
		}

	}


}
//zrob kolizje ktore zabijaja wrogow
void keyboard()
{
	while (renderWindow.pollEvent(event)) {
		if (event.type == sf::Event::EventType::Closed)
			renderWindow.close();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			if (mstart == 0)
			{
				renderWindow.close();
			}
			else
			{
				mstart = 0;
				Sleep(250);
			}
		}

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		if (player.x >= 0)
			player.x -= 5;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		if (player.x <= 1220)
			player.x += 5;

	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	player.y -= 5;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	player.y += 5;*/

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
	{
		for (int i = 0; i <= 5; i++)
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

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
	{

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
	{
		enemy[9].dodaj(200, 0, 4, 150, 1);
		enemy[3].dodaj(200, 200, 4, 100, 0);

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if (mstart == 0)
		{
			if (wybranaopcja <= 2)
			{

				wybranaopcja++;
				cout << wybranaopcja << endl;
			}
			Sleep(250);
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if (mstart == 0)
		{
			if (wybranaopcja > 1)
				wybranaopcja--;

			Sleep(250);
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	{
		mstart = wybranaopcja;
	}
}

