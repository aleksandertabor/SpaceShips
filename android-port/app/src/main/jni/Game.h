#pragma once

#include "stdafx.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Player.h"
#include "Gift.h"

class Game
{
public:
	Game();
	void run();

private:
	//Set name or resolution

	const std::string gameName = "SpaceShips";
	static const int gameWidth = 1280;
	static const int gameHeight = 720;
	int screenWidth = 1280;
	int screenHeight = 720;

	//Declaration of variables
	static const int gameSpeed = 1000;
	static const int playerBulletSpeed = 50;
	static const int enemyBulletSpeed = 80;
	static const int jumpDown = 40;

	bool gameIsStarted = false;
	int currentLevel = 1;//initial level
	int presentState = 0;//cycles
	int actualView = 0;
	int actualViewChoice = 1;
	std::string topHighScoreBackground = "menu";

    #if defined(USE_JNI)
	const std::string highscoresFileName = "highscores.csv";
	const std::string maxLevelFileName = "maxlevel.csv";
    #else
    const std::string highscoresFileName = "Assets/Data/highscores.csv";
	const std::string maxLevelFileName = "Assets/Data/maxlevel.csv";
    #endif
	const int playerIdSkinStart = 0;
	const int playerHPStart = 100;

	sf::RenderWindow renderWindow;
	sf::Music music;
	std::map<std::string, sf::Texture> textures;
	std::map<std::string, sf::Sprite> sprites;
	std::map<std::string, sf::Font> fonts;
    std::map<std::string, sf::Text> texts;
	std::map<std::string, sf::SoundBuffer> soundBuffers;
	std::map<std::string, sf::Sound> sounds;
	std::map<std::string, std::pair<std::string, bool> > tracks;

	Player player;
	std::vector<Enemy*> enemies;
	std::vector<Gift*> gifts;
	std::vector<Bullet*> enemyBullets;
	sf::Event event1;

	Files file2;
	Files file3;

	std::string highscores[5][2];
	std::vector<std::string> characters;
	int currentChar[3] = { 0,0,0 };
	int currentCharPosition = 0;

	Bullet tBullet1;
	Bullet tBullet2;

	//Flags for key pressed
	bool upFlag = false;
	bool downFlag = false;
	bool leftFlag = false;
	bool rightFlag = false;
	bool AFlag = false;
	bool DFlag = false;
	bool returnFlag = false;
	bool escapeFlag = false;

	//Methods
	void processEvents();
	int loadAssets(std::string char1);
	void init(std::string char1);
	void update();
	int loadLevel(int level);
	int playMusic(std::string track = "menu", float speed = 1);
    std::string loadFileAndroid(std::string fileName);
    std::vector<std::string> split(std::string str, char delimiter);
};
