#include "Game.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Player.h"
#include "Gift.h"
Game::Game() : renderWindow(sf::VideoMode(gameWidth, gameHeight), ""), player(playerIdSkinStart, playerHPStart), file2(highscoresFileName, ','), file3(maxLevelFileName, ',')
{
	screenWidth = sf::VideoMode::getDesktopMode().width;
	screenHeight = sf::VideoMode::getDesktopMode().height;

    __android_log_print(ANDROID_LOG_INFO, "Width", "Width is %d", screenWidth);
    __android_log_print(ANDROID_LOG_INFO, "Height", "Height is %d", screenHeight);


    //renderWindow.create(sf::VideoMode(gameWidth, gameHeight), gameName);//Don't use
	renderWindow.setTitle(gameName);

	renderWindow.create(sf::VideoMode(gameWidth, gameHeight), gameName, sf::Style::Fullscreen);
	renderWindow.setMouseCursorVisible(false);

	renderWindow.setFramerateLimit(60);
	renderWindow.setKeyRepeatEnabled(false);

	sf::View view1(sf::FloatRect(0.f, 0.f, (float)gameWidth, (float)gameHeight));
    view1.setSize(gameWidth, gameHeight);
    //view1.setCenter(screenWidth/2, screenHeight/2);
	renderWindow.setView(view1);
}

void Game::run()
{
    std::string char1 = loadFileAndroid("highscores.csv");
	init(char1);
	while (renderWindow.isOpen())
	{
		processEvents();
		update();
	}
}

void Game::init(std::string char1)
{
	loadAssets(char1);
}

void Game::update()
{
	renderWindow.clear();
	switch (actualView)
	{
		//Menu
	case 0:
	{
		if (!gameIsStarted) {
			playMusic("menu");
			texts["menuOption1"].setString("START");
		}
		else
			texts["menuOption1"].setString("RETURN");

		texts["menuOption1"].setFillColor(sf::Color(94, 201, 134));
		texts["menuOption2"].setFillColor(sf::Color(94, 201, 134));
		texts["menuOption3"].setFillColor(sf::Color(94, 201, 134));
		texts["menuOption4"].setFillColor(sf::Color(94, 201, 134));

		if (actualViewChoice == 1)
			texts["menuOption1"].setFillColor(sf::Color(164, 246, 68));

		if (actualViewChoice == 2)
			texts["menuOption2"].setFillColor(sf::Color(164, 246, 68));

		if (actualViewChoice == 3)
			texts["menuOption3"].setFillColor(sf::Color(164, 246, 68));

		if (actualViewChoice == 4)
			texts["menuOption4"].setFillColor(sf::Color(164, 246, 68));

		renderWindow.draw(sprites["menu"]);
		renderWindow.draw(texts["logo"]);
		renderWindow.draw(texts["menuOption1"]);
		renderWindow.draw(texts["menuOption2"]);
		renderWindow.draw(texts["menuOption3"]);
		renderWindow.draw(texts["menuOption4"]);

		topHighScoreBackground = "menu";
		//actualView = 3;
		returnFlag = true;
	}
	break;


	case 1:
	{
		gameIsStarted = true;
		presentState++;

		if (presentState % playerBulletSpeed == 0) {
			sounds["shootingPlayer"].play();
			player.bullets.push_back(new Bullet(player.getX() + (int)(player.getSprite().getTexture()->getSize().x / 2) - (int)(tBullet2.getSprite().getTexture()->getSize().x / 2), player.getY() - (int)(player.getSprite().getTexture()->getSize().y * 0.4), 1, player.getPower()));
		}

		if (presentState % enemyBulletSpeed == 0)
			if (!enemies.empty()) {
				int random = rand() % enemies.size();

				if (enemies[random]->getShooting())
					enemyBullets.push_back(new Bullet(enemies[random]->getX() + (int)(enemies[random]->getSprite().getTexture()->getSize().x / 2) - (int)(tBullet1.getSprite().getTexture()->getSize().x / 2), (int)enemies[random]->getY() + (int)enemies[random]->getSprite().getTexture()->getSize().y + (int)(enemies[random]->getSprite().getTexture()->getSize().y * 0.05), 0, enemies[random]->getPower()));

			}


		playMusic("levels");

		texts["hp"].setString("HP: " + std::to_string(player.getHP()));
		texts["points"].setString("Points: " + std::to_string(player.getPoints()));
		texts["pause"].setString("PAUSE");

		renderWindow.draw(sprites["background"]);

		renderWindow.draw(texts["hp"]);
		renderWindow.draw(texts["points"]);
		renderWindow.draw(texts["level"]);


		//Draw player
		renderWindow.draw(player.getSprite());
		player.display(renderWindow);


		//Draw enemy
		for (auto enemy : enemies)
		{
			enemy->move();
			enemy->display(renderWindow);
		}

		for (auto gift : gifts)
		{
			gift->move();
			gift->display(renderWindow);
		}

		for (auto bullet : enemyBullets)
		{
			bullet->move();
			bullet->display(renderWindow);
		}

		for (auto bullet : player.bullets)
		{
			bullet->move();
			bullet->display(renderWindow);
		}


		for (auto gift : gifts)
		{
			//Colision player with gift
			if (Collision::PixelPerfectTest(player.getSprite(), gift->getSprite(), 0))
			{
				player.setPoints(player.getPoints() + gift->getPoints());
				player.setPower(player.getPower() + gift->getPower());
				player.setHP(player.getHP() + gift->getHP());

				auto findGift = find(begin(gifts), end(gifts), gift);
				if (findGift != gifts.end())
				{
					gifts.erase(findGift);
					break;
				}
			}
		}


		//Remove player ammunition
		for (auto bullet : player.bullets)
		{
			if ((int)bullet->getY() <= (int)0 - (int)bullet->getSprite().getTexture()->getSize().y)
			{
				auto findBullet = find(begin(player.bullets), end(player.bullets), bullet);
				if (findBullet != player.bullets.end())
				{
					player.bullets.erase(findBullet);
					break;
				}
			}
		}

		for (auto enemy : enemies)
		{
			//Collision of enemy with walls
			if (static_cast<int>(enemy->getX()) + static_cast<int>(enemy->getSprite().getTexture()->getSize().x) >= static_cast<int>(gameWidth))
			{
				enemy->setDirection(1);
				enemy->setX(enemy->getX() - enemy->getSpeed());
				enemy->setY(enemy->getY() + jumpDown);
				break;
			}

			if ((int)enemy->getX() <= (int)0)
			{
				enemy->setDirection(4);
				enemy->setX(enemy->getX() + enemy->getSpeed());
				enemy->setY(enemy->getY() + jumpDown);
				break;
			}

			if ((int)enemy->getY() >= (int)gameHeight + (int)enemy->getSprite().getTexture()->getSize().y)
			{
				player.setPoints(player.getPoints() + enemy->getPoints());

				auto findEnemy = find(begin(enemies), end(enemies), enemy);
				if (findEnemy != enemies.end())
				{
					enemies.erase(findEnemy);
					break;
				}
			}

			//Colision enemies with player ammunition
			for (auto bullet : player.bullets) {
				if (Collision::PixelPerfectTest(enemy->getSprite(), bullet->getSprite(), 0))
				{
					sounds["explosion"].play();
					enemy->setHP(enemy->getHP() - bullet->getPower());
					player.setPoints(player.getPoints() + enemy->getPoints());
					bullet->setPower(0);

					auto findBullet = find(begin(player.bullets), end(player.bullets), bullet);
					if (findBullet != player.bullets.end())
					{
						player.bullets.erase(findBullet);

					}

					if (enemy->getHP() <= 0)
					{
						auto findEnemy = find(begin(enemies), end(enemies), enemy);
						if (findEnemy != enemies.end())
						{
							enemies.erase(findEnemy);
							break;
						}
					}

					if (enemy->getChangeSkin() == 1)
					{
						enemy->setIdSkin(enemy->getIdSkin() + 1);
						enemy->changeTexture();
					}

				}
			}


			for (auto bullet : enemyBullets)
			{
				//Enemies ammunition below space
				if ((int)bullet->getY() >= (int)gameHeight + (int)bullet->getSprite().getTexture()->getSize().y)
				{
					auto findBullet = find(begin(enemyBullets), end(enemyBullets), bullet);
					if (findBullet != enemyBullets.end())
					{
						enemyBullets.erase(findBullet);
						break;
					}
					break;
				}

				//Colision player with enemies ammunition
				if (Collision::PixelPerfectTest(player.getSprite(), bullet->getSprite(), 0))
				{
					sounds["explosion"].play();
					player.setHP(player.getHP() - bullet->getPower());

					auto findBullet = find(begin(enemyBullets), end(enemyBullets), bullet);
					if (findBullet != enemyBullets.end())
					{
						enemyBullets.erase(findBullet);
						break;
					}
					break;
				}
			}

			//Colision player with enemies spaceships
			if (Collision::PixelPerfectTest(player.getSprite(), enemy->getSprite(), 0))
			{
				player.setHP(0);
			}
		}

		if (player.getHP() <= 0)//You lost
			actualView = 5;

		if (enemies.empty())//Lack of enemies
		{
			currentLevel++;

			if (loadLevel(currentLevel) == -1)
				actualView = 6;
		}

	}//End of actualView==1
	break;

	case 2:
	{
		renderWindow.draw(sprites["menu"]);
		renderWindow.draw(texts["authorsTitle"]);
		renderWindow.draw(texts["authorsContent"]);
	}
	break;

	case 3:
	{
		// Highscores
		std::string scores = "TOP 5 HIGHSCORES\n\n";
		for (int i = 0; i < sizeof(highscores) / sizeof(highscores[0]); i++)
			scores += highscores[i][0] + " " + highscores[i][1] + "\n";

		texts["highscores"].setString(scores);
		renderWindow.draw(sprites[topHighScoreBackground]);
		renderWindow.draw(texts["highscores"]);
	}
	break;

	case 4:
	{
		renderWindow.close();
	}
	break;

	case 5://You lost
	{
		playMusic("lose");
		texts["message"].setString("You lost, press 'N' key on keyboard!");
		renderWindow.draw(sprites["background"]);
		renderWindow.draw(texts["message"]);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::N))
			actualView = 7;

	} break;

	case 6://You win
	{
		playMusic("win");
		texts["message"].setString("You won, press 'N' key on keyboard!");
		renderWindow.draw(sprites["background"]);
		renderWindow.draw(texts["message"]);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::N))
			actualView = 7;
	} break;

	case 7://Clear
	{
		gameIsStarted = false;
		currentLevel = 1;

		// Reset tracks history
		for (auto t : tracks) {
			tracks[t.first].second = false;
		}

		actualView = 8;
	} break;

	case 8://If top 5
	{
		int smallestHighscore = stoi(highscores[0][1]);
		int smallestHighscoreTabIndex = 0;
		for (int i = 0; i < sizeof(highscores) / sizeof(highscores[0]); i++)
		{
			if (stoi(highscores[i][1]) <= smallestHighscore)
			{
				smallestHighscore = stoi(highscores[i][1]);
				smallestHighscoreTabIndex = i;
			}
		}


		if (player.getPoints() > smallestHighscore)
			actualView = 9;
		else
			actualView = 0;

	} break;

	case 9://Save score name//Warning part of code in processEvents
	{
		texts["char1"].setString(characters[currentChar[0]]);
		texts["char2"].setString(characters[currentChar[1]]);
		texts["char3"].setString(characters[currentChar[2]]);

		renderWindow.draw(sprites["background"]);
		renderWindow.draw(texts["char1"]);
		renderWindow.draw(texts["char2"]);
		renderWindow.draw(texts["char3"]);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
			actualView = 10;


	} break;

	case 10://Save score
	{
		int smallestHighscore = stoi(highscores[0][1]);
		int smallestHighscoreTabIndex = 0;
		for (int i = 0; i < sizeof(highscores) / sizeof(highscores[0]); i++)
		{
			if (stoi(highscores[i][1]) <= smallestHighscore)
			{
				smallestHighscore = stoi(highscores[i][1]);
				smallestHighscoreTabIndex = i;
			}
		}

		std::string newPlayerName = texts["char1"].getString() + texts["char2"].getString() + texts["char3"].getString();
		highscores[smallestHighscoreTabIndex][0] = newPlayerName;
		highscores[smallestHighscoreTabIndex][1] = std::to_string(player.getPoints());

		std::string sortTemp = "";
		int sortChange = 0;
		int sortCounter = 0;
		int i = 0;
		do
		{
			sortCounter = sizeof(highscores) / sizeof(highscores[0]) - 1;
			sortChange = 0;
			do
			{
				sortCounter--;
				if (stoi(highscores[sortCounter][1]) < stoi(highscores[sortCounter + 1][1]))
				{
					sortTemp = highscores[sortCounter + 1][0];
					highscores[sortCounter + 1][0] = highscores[sortCounter][0];
					highscores[sortCounter][0] = sortTemp;

					sortTemp = highscores[sortCounter + 1][1];
					highscores[sortCounter + 1][1] = highscores[sortCounter][1];
					highscores[sortCounter][1] = sortTemp;
					sortChange++;
				}
			} while (sortCounter != 0);
		} while (sortChange != 0);

		std::ofstream file_save;
		file_save.open(highscoresFileName);

		for (int i = 0; i < sizeof(highscores) / sizeof(highscores[0]); i++)
			file_save << highscores[i][0] << "," << highscores[i][1] << ",\n";

		file_save.close();

		topHighScoreBackground = "background";

		actualView = 3;
	} break;

	default:
		break;

	}


	//Speed of game
	if (presentState % gameSpeed == 0)
		presentState = 0;


	renderWindow.display();
}


void Game::processEvents()
{
	while (renderWindow.pollEvent(event1))
	{
		if (event1.type == sf::Event::EventType::Closed)
			renderWindow.close();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
		{
			player.setHP(0);
		}
		
		if (event1.type == sf::Event::Resized) {
//			screenWidth = sf::VideoMode::getDesktopMode().width;
//			screenHeight = sf::VideoMode::getDesktopMode().height;
//			//renderWindow.create(sf::VideoMode(screenWidth, screenHeight), "SpaceShips", sf::Style::Fullscreen);
			//sf::View view2(renderWindow.getDefaultView());

//			renderWindow.setView(view2);
            //renderWindow.create(sf::VideoMode::getDesktopMode(), "SpaceShips");
            //renderWindow.setView(view2);
        }
			

		//******* Android's touch
		if (event1.type == sf::Event::TouchBegan)
		{

			if (event1.touch.finger == 0)
			{
				//actualViewChoice = 3;
				if (event1.touch.x < player.getX())
				{
					AFlag = true;
				}

				if (event1.touch.x > player.getX())
				{
					DFlag = true;
				}


				if (texts["menuOption1"].getGlobalBounds().contains(event1.touch.x, event1.touch.y))
				{
					actualViewChoice = 1;
					returnFlag = true;
				}
				if (texts["menuOption2"].getGlobalBounds().contains(event1.touch.x, event1.touch.y))
				{
					actualViewChoice = 2;
					returnFlag = true;
				}
				if (texts["menuOption3"].getGlobalBounds().contains(event1.touch.x, event1.touch.y))
				{
					actualViewChoice = 3;
					returnFlag = true;
				}
				if (texts["menuOption4"].getGlobalBounds().contains(event1.touch.x, event1.touch.y))
				{
					actualViewChoice = 4;
					returnFlag = true;
				}


			}
		}

		if (event1.type == sf::Event::TouchEnded)
		{
			if (event1.touch.finger == 0)
			{
				AFlag = false;
				DFlag = false;

				//texts["menuOption1"].setPosition(event1.touch.x - 200, event1.touch.y);
				//texts["menuOption1"].setPosition(event1.touch.x, event1.touch.y);
				//actualViewChoice = 3;
				// if (event1.touch.x == texts["menuOption1"].getPosition().y)
				// {
				// 	actualViewChoice = 1;
				// 	//returnFlag = true;
				// }
				// if (event1.touch.x == texts["menuOption2"].getPosition().y)
				// {
				// 	actualViewChoice = 2;
				// 	//returnFlag = true;
				// }
				// if (event1.touch.x == texts["menuOption3"].getPosition().y)
				// {
				// 	actualViewChoice = 3;
				// 	//returnFlag = true;
				// }
				// if (event1.touch.x == texts["menuOption4"].getPosition().y)
				// {
				// 	actualViewChoice = 4;
				// 	//returnFlag = true;
				// }


			}
		}

		//******* End Android's touch

		// If a key is pressed
		if (event1.type == sf::Event::KeyPressed)
		{
			switch (event1.key.code)
			{
			case sf::Keyboard::A:	AFlag = true; break;
			case sf::Keyboard::D:	DFlag = true; break;

			default: break;
			}
		}

		// If a key is released
		if (event1.type == sf::Event::KeyReleased)
		{
			switch (event1.key.code)
			{
			case sf::Keyboard::A:	AFlag = false; break;
			case sf::Keyboard::D:	DFlag = false; break;
			case sf::Keyboard::Up:	upFlag = true; break;
			case sf::Keyboard::Down:	downFlag = true; break;
			case sf::Keyboard::Left:	leftFlag = true; break;
			case sf::Keyboard::Right:	rightFlag = true; break;
			case sf::Keyboard::Return:	returnFlag = true; break;
			case sf::Keyboard::Escape:	escapeFlag = true; break;

			default: break;
			}
		}
	}

	//Player control
	if (AFlag) {
		if (actualView == 1)
			sounds["move"].play();
		if (player.getX() >= 0) {
			player.setX(player.getX() - player.getSpeed());
		}
	}



	int rightEnd = gameWidth - player.getSprite().getTexture()->getSize().x;

	if (DFlag) {
		if (actualView == 1)
			sounds["move"].play();
		if (player.getX() <= rightEnd) {
			player.setX(player.getX() + player.getSpeed());
		}
	}


	//Choose name to save score and control in main menu
	if (upFlag) {
		if (actualView == 0) {
			if (actualViewChoice > 1)
				actualViewChoice--;
		}
		if (actualView == 9) {
			if (currentChar[currentCharPosition] > 0) {
				std::string temp1 = "char" + std::to_string(currentCharPosition + 1);
				texts[temp1].setString(characters[currentChar[currentCharPosition]]);
				renderWindow.draw(texts[temp1]);
				currentChar[currentCharPosition]--;
			}

		}
		upFlag = false;
	}

	if (downFlag) {
		if (actualView == 0) {
			if (actualViewChoice <= 3)
				actualViewChoice++;
		}
		if (actualView == 9) {
			if (currentChar[currentCharPosition] < int(characters.size()) - 1) {
				std::string temp1 = "char" + std::to_string(currentCharPosition + 1);
				texts[temp1].setString(characters[currentChar[currentCharPosition]]);
				renderWindow.draw(texts[temp1]);
				currentChar[currentCharPosition]++;
			}
		}
		downFlag = false;
	}

	if (leftFlag) {
		if (currentCharPosition > 0) {
			std::string temp1 = "char" + std::to_string(currentCharPosition + 1);
			texts[temp1].setFillColor(sf::Color(94, 201, 134));
			renderWindow.draw(texts[temp1]);
			currentCharPosition--;
			std::string temp2 = "char" + std::to_string(currentCharPosition + 1);
			texts[temp2].setFillColor(sf::Color(164, 246, 68));
			renderWindow.draw(texts[temp2]);
			leftFlag = false;
		}
	}

	if (rightFlag) {
		if (currentCharPosition < 2) {
			std::string temp1 = "char" + std::to_string(currentCharPosition + 1);
			texts[temp1].setFillColor(sf::Color(94, 201, 134));
			renderWindow.draw(texts[temp1]);
			currentCharPosition++;
			std::string temp2 = "char" + std::to_string(currentCharPosition + 1);
			texts[temp2].setFillColor(sf::Color(164, 246, 68));
			renderWindow.draw(texts[temp2]);
			rightFlag = false;
		}
	}

	//returnFlag
	if (returnFlag) {
		if (actualView == 0) {

			actualView = actualViewChoice;

			if (!gameIsStarted)
				loadLevel(currentLevel);
		}

		returnFlag = false;
	}

	//escapeFlag
	if (escapeFlag)
	{
		if (actualView == 0)
			renderWindow.close();

		if (!actualView == 0)
			actualView = 0;

		escapeFlag = false;
	}
}

int Game::loadAssets(std::string char1)
{
	//Load textures
	sf::Texture texture;
	textures["background"] = texture;
	textures["background"].loadFromFile("Assets/background.png");

	textures["menu"] = texture;
	textures["menu"].loadFromFile("Assets/menu.png");

	for (auto t : textures)
		if (t.second.getSize().x == 0)
			return EXIT_FAILURE;

	//Load sprites
	sf::Sprite sprite;
	sprites["background"] = sprite;
	sprites["background"].setTexture(textures["background"]);

	sprites["menu"] = sprite;
	sprites["menu"].setTexture(textures["menu"]);

	//Load fonts
	sf::Font font;
	fonts["font"] = font;
	if (!fonts["font"].loadFromFile("Assets/good_times_rg.ttf"))
		return EXIT_FAILURE;

	//Load soundBuffers
	sf::SoundBuffer soundBuffer;
	soundBuffers["move"] = soundBuffer;
	soundBuffers["shootingPlayer"] = soundBuffer;
	soundBuffers["explosion"] = soundBuffer;
	soundBuffers["move"].loadFromFile("Assets/Audio/move.ogg");
	soundBuffers["shootingPlayer"].loadFromFile("Assets/Audio/boom.ogg");
	soundBuffers["explosion"].loadFromFile("Assets/Audio/explosion.ogg");

	for (auto sb : soundBuffers)
		if (sb.second.getDuration().asSeconds() == 0)
			return EXIT_FAILURE;


	//Load sounds
	sf::Sound sound;
	sounds["move"] = sound;
	sounds["move"].setBuffer(soundBuffers["move"]);
	sounds["shootingPlayer"] = sound;
	sounds["shootingPlayer"].setBuffer(soundBuffers["shootingPlayer"]);
	sounds["explosion"] = sound;
	sounds["explosion"].setBuffer(soundBuffers["explosion"]);
	sounds["shootingPlayer"].setVolume(15.f);
	sounds["explosion"].setVolume(35.f);
	sounds["move"].setVolume(50.f);

	//Get tracklist
	tracks["menu"] = std::make_pair("Assets/Audio/menu.ogg", false);
	tracks["levels"] = std::make_pair("Assets/Audio/levels.ogg", false);
	tracks["lose"] = std::make_pair("Assets/Audio/lose.ogg", false);
	tracks["win"] = std::make_pair("Assets/Audio/win.ogg", false);


	//Load texts
	sf::Text text;
	texts["pause"] = text;
	texts["pause"].setFont(fonts["font"]);
	texts["pause"].setCharacterSize(60);
	texts["pause"].setFillColor(sf::Color::White);
	texts["pause"].setStyle(sf::Text::Bold);
	texts["pause"].setPosition(500, 250);

	texts["points"] = text;
	texts["points"].setFont(fonts["font"]);
	texts["points"].setCharacterSize(36);
	texts["points"].setFillColor(sf::Color(100, 216, 107));
	texts["points"].setStyle(sf::Text::Bold);
	texts["points"].setPosition(10, 10);

	texts["hp"] = texts["points"];
	texts["hp"].setPosition(10, 60);

	texts["level"] = texts["points"];
	texts["level"].setPosition(10, 110);

	texts["message"] = texts["points"];
	texts["message"].setPosition(10, 160);

	texts["menuOption1"] = text;
	texts["menuOption1"].setFont(fonts["font"]);
	texts["menuOption1"].setCharacterSize(36);
	texts["menuOption1"].setFillColor(sf::Color(100, 216, 107));
	texts["menuOption1"].setStyle(sf::Text::Bold);
	texts["menuOption1"].setPosition(550, 270);

	texts["menuOption2"] = texts["menuOption1"];
	texts["menuOption2"].setPosition(550, 370);

	texts["menuOption3"] = texts["menuOption1"];
	texts["menuOption3"].setPosition(550, 470);

	texts["menuOption4"] = texts["menuOption1"];
	texts["menuOption4"].setPosition(550, 570);

	texts["logo"] = text;
	texts["logo"].setFont(fonts["font"]);
	texts["logo"].setCharacterSize(72);
	texts["logo"].setFillColor(sf::Color(164, 246, 68));
	texts["logo"].setStyle(sf::Text::Bold);
	texts["logo"].setPosition(400, 50);

	texts["authorsTitle"] = text;
	texts["authorsTitle"].setFont(fonts["font"]);
	texts["authorsTitle"].setCharacterSize(72);
	texts["authorsTitle"].setFillColor(sf::Color(164, 246, 68));
	texts["authorsTitle"].setStyle(sf::Text::Bold);
	texts["authorsTitle"].setPosition(400, 50);

	texts["authorsContent"] = text;
	texts["authorsContent"].setFont(fonts["font"]);
	texts["authorsContent"].setCharacterSize(24);
	texts["authorsContent"].setFillColor(sf::Color(94, 201, 134));
	texts["authorsContent"].setStyle(sf::Text::Bold);
	texts["authorsContent"].setPosition(200, 200);

	texts["logo"].setString("SPACE SHIPS");
	texts["menuOption1"].setString("START");
	texts["menuOption2"].setString("AUTHORS");
	texts["menuOption3"].setString("HIGHSCORES");
	texts["menuOption4"].setString("EXIT");
	texts["authorsTitle"].setString("AUTHORS");
	texts["authorsContent"].setString("C++ Developers:\nAleksander Tabor\nTomasz Zurek\n\nGame created with SFML Library\n\nGraphics were downloaded from:\nwww.freepik.com\nwww.flaticon.com\n\nAudio files were downloaded from:\nwww.opengameart.org\nwww.freesound.org\n\nSources (links & authors):\nSpaceShips\\Assets\\ASSETS_LICENSE.txt");
	texts["level"].setString("LEVEL: 1");

	texts["highscores"] = text;
	texts["highscores"].setFont(fonts["font"]);
	texts["highscores"].setCharacterSize(36);
	texts["highscores"].setFillColor(sf::Color(100, 216, 107));
	texts["highscores"].setStyle(sf::Text::Bold);
	texts["highscores"].setPosition(gameWidth / 3, gameHeight / 4);

	texts["char"] = text;
	texts["char"].setFont(fonts["font"]);
	texts["char"].setCharacterSize(60);
	texts["char"].setFillColor(sf::Color(94, 201, 134));
	texts["char"].setStyle(sf::Text::Bold);
	texts["char"].setPosition(gameWidth / 2 - 65, gameHeight / 2 - 65);

	texts["char1"] = texts["char"];
	texts["char2"] = texts["char"];
	texts["char3"] = texts["char"];

	texts["char2"].setPosition(gameWidth / 2, gameHeight / 2 - 65);
	texts["char3"].setPosition(gameWidth / 2 + 65, gameHeight / 2 - 65);

	texts["char1"].setFillColor(sf::Color(164, 246, 68));

	tBullet1.testInit(-100, -100, 0, 100);
	tBullet2.testInit(-100, -100, 1, 100);

	for (size_t i = 'A'; i <= 'Z'; i++)
	{
		characters.push_back(std::string("") + static_cast<char>(i));
	}

	highscores[0][0] = char1;

//	file2.load();
//	for (int i = 0; i < sizeof(highscores) / sizeof(highscores[0]); i++)
//	{
//		for (int j = 0; j < 2; j++)
//		{
//			if (i < int(file2.matrix.size()))
//			{
//				highscores[i][j] = file2.matrix[i][j];
//			}
//			else
//			{
//				// highscores[i][0] = "AAA";
//				// highscores[i][1] = "0";
//			}
//		}
//	}

//	std::string line;
//	std::ifstream myfile("highscores.txt");
//	if (myfile.is_open())
//	{
//		highscores[0][0] = "znajduje";
//		// while ( myfile.good() )
//		// {
//		//   std::getline (myfile,line);
//		// }
//		myfile.close();
//	}
//
//	std::string line2;
//	std::ifstream myfile2("Assets/Data/highscores.txt");
//	if (myfile2.is_open())
//	{
//		highscores[0][0] = "znajdujezpath";
//		// while ( myfile.good() )
//		// {
//		//   std::getline (myfile,line);
//		// }
//		myfile2.close();
//	}
//	else {
//		highscores[1][1] = "nieznajdujezpath";
//	}


	return 0;
}

int Game::loadLevel(int level)
{




	if (level > std::stoi(loadFileAndroid(maxLevelFileName)) )
	    return -1;

	if (level == 3)
		playMusic("levels", 2.5);

	if (level == 1)
		player.setPoints(0);


	player.setHP(100);
	player.setPower(100);
	player.bullets.clear();
	player.setPosition((int)(gameWidth / 2) - (int)(player.getSprite().getTexture()->getSize().x / 2), (int)gameHeight - (int)(player.getSprite().getTexture()->getSize().y * 1.25));
	enemies.clear();
	enemyBullets.clear();
	gifts.clear();

	std::string strLevelLabel = "LEVEL: " + std::to_string(level);
	texts["level"].setString(strLevelLabel);

	std::string strLevelFile = "Assets/Data/level" + std::to_string(level) + ".csv";


	//enemies.push_back(new Enemy(0, 10, 4, 0, 100, 50, 50, 0, 1));
	//enemies.push_back(new Enemy(400, 160, 4, 0, 100, 50, 50, 0, 1));
	//enemies.push_back(new Enemy(500, 160, 4, 0, 100, 50, 50, 0, 1));
	//enemies.push_back(new Enemy(700, 160, 4, 0, 100, 50, 50, 0, 1));


	// Files file1(strLevelFile, ',');
	// file1.load();//Load map

	std::string loadedLevel = loadFileAndroid("level" + std::to_string(level) + ".csv");
    std::vector<std::string> seperatedEnemies = split(loadedLevel, '\n');

    for(std::string seperatedEnemy : seperatedEnemies) {
        std::vector<std::string> seperatedEnemyConfig = split(seperatedEnemy, ',');
        if (std::stoi(seperatedEnemyConfig[0]) == 0)
        {
            enemies.push_back(new Enemy(std::stoi(seperatedEnemyConfig[1]), std::stoi(seperatedEnemyConfig[2]), std::stoi(seperatedEnemyConfig[3]), std::stoi(seperatedEnemyConfig[4]), std::stoi(seperatedEnemyConfig[5]), std::stoi(seperatedEnemyConfig[6]), std::stoi(seperatedEnemyConfig[7]), std::stoi(seperatedEnemyConfig[8]), std::stoi(seperatedEnemyConfig[9])));
        }
        if (std::stoi(seperatedEnemyConfig[0]) == 1)
        {
            gifts.push_back(new Gift(std::stoi(seperatedEnemyConfig[1]), std::stoi(seperatedEnemyConfig[2]), std::stoi(seperatedEnemyConfig[3]), std::stoi(seperatedEnemyConfig[4]), std::stoi(seperatedEnemyConfig[5]), std::stoi(seperatedEnemyConfig[6])));
        }
    }


	// for (size_t i = 0; i < file1.matrix.size(); i++)
	// {
	// 	if (stoi(file1.matrix[i][0]) == 0)
	// 	{
	// 		enemies.push_back(new Enemy(stoi(file1.matrix[i][1]), stoi(file1.matrix[i][2]), stoi(file1.matrix[i][3]), stoi(file1.matrix[i][4]), stoi(file1.matrix[i][5]), stoi(file1.matrix[i][6]), stoi(file1.matrix[i][7]), stoi(file1.matrix[i][8]), stoi(file1.matrix[i][9])));
	// 	}

	// 	if (stoi(file1.matrix[i][0]) == 1)
	// 	{
	// 		gifts.push_back(new Gift(stoi(file1.matrix[i][1]), stoi(file1.matrix[i][2]), stoi(file1.matrix[i][3]), stoi(file1.matrix[i][4]), stoi(file1.matrix[i][5]), stoi(file1.matrix[i][6])));
	// 	}
	// }

	return 0;
}

int Game::playMusic(std::string track, float speed)
{
	// if current track tries to play
	if (tracks[track].second)
		if (speed != 1)
			music.openFromFile(tracks[track].first);
		else
			return 0;

	// if new track tries to play
	if (!music.openFromFile(tracks[track].first))
		return EXIT_FAILURE;
	else
		tracks[track].second = true;

	music.stop();
	music.setLoop(true);

	music.setPitch(speed);

	music.play();

	return 0;
}

extern "C" {
std::string Game::loadFileAndroid(std::string fileName) {

    ANativeActivity *activity = sf::getNativeActivity();
    JavaVM *vm = activity->vm;
    JNIEnv *env = activity->env;

    std::string filePath = "/Assets/Data/" + fileName;

    const char *internalPath = activity->internalDataPath;
    std::string dataPath(internalPath);
    std::string configFile = dataPath + filePath;

    filePath.erase(0,1);
    const char * filePathCC = filePath.c_str();
    AAssetManager *assetManager = activity->assetManager;
    AAsset *configFileAsset = AAssetManager_open(assetManager, filePathCC,
                                                 AASSET_MODE_BUFFER);
    std::string highscores = "";

    if (configFileAsset)
    {
        assert(configFileAsset);
//
        size_t assetLength = AAsset_getLength(configFileAsset);

        char* buffer = (char*) malloc(assetLength + 1);
        AAsset_read(configFileAsset, buffer, assetLength);
        buffer[assetLength] = 0;


        AAsset_close(configFileAsset);
        highscores = buffer;
        __android_log_print(ANDROID_LOG_INFO, "Test Asset Manager", "The value is %s", highscores.c_str());
        __android_log_print(ANDROID_LOG_INFO, "Test Asset Manager", "String size is %d", highscores.size());
        char lastOne = highscores[26];
        __android_log_print(ANDROID_LOG_INFO, "Test Asset Manager", "Last string char is %c", lastOne);
        char lastOne2 = highscores[27];
        __android_log_print(ANDROID_LOG_INFO, "Test Asset Manager", "Last string char is %c", lastOne2);
        char lastOne3 = highscores[28];
        __android_log_print(ANDROID_LOG_INFO, "Test Asset Manager", "Last string char is %c", lastOne3);
        //__android_log_print(ANDROID_LOG_INFO, "Test Asset Manager", "First enemy %s", highscores.c_str()[0]);
        free(buffer);
    }
    else
    {
        __android_log_print(ANDROID_LOG_ERROR, "Test Asset Manager", "Cannot open file");
    }



    return highscores;
}
}

std::vector<std::string> Game::split(std::string str, char delimiter) {
    std::vector<std::string> internal;
    std::stringstream ss(str); // Turn the string into a stream.
    std::string tok;

    while(getline(ss, tok, delimiter)) {
        internal.push_back(tok);
    }

    return internal;
}
