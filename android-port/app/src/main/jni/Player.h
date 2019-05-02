#pragma once

#include "stdafx.h"
#include "Bullet.h"

class Player
{
private:
	static const int speed = 5;
	int x = 900;
	int y = 580;
	int idSkin = 0;//0-default

	int points = 0;
	int hp = 100;
	int power = 100;

	sf::Sprite sprite;
	static std::vector<sf::Texture*> textures;
	static int initialized;

public:
	Player();
	Player(int idSkin, int hp);

	std::vector<Bullet*> bullets;

	const int getX();
	const int getY();
	const int getHP();
	const int getPoints();
	const int getPower();
	const int getSpeed();
	const sf::Sprite getSprite();

	void setX(int x);
	void setY(int y);
	void setHP(int hp);
	void setPoints(int points);
	void setPower(int power);
	void setPosition(int x, int y);

	void display(sf::RenderWindow & renderWindow);
	int loadAssets();
	void changeTexture();
};