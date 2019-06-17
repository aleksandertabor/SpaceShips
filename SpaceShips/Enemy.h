#pragma once

#include "stdafx.h"
#include "Bullet.h"

class Enemy
{
private:
	static const int speed = 4;

	int x = 0;
	int y = 0;

	int direction = 0;
	int hp = 100;
	int idSkin = 0;
	int points = 50;
	int power = 50;
	int changeSkin = 0;
	int shooting = 0;

	sf::Sprite sprite;
	static std::vector<sf::Texture*> textures;
	static int initialized;
	
	
public:
	Enemy();
	Enemy(int x, int y, int direction, int idSkin, int hp, int points, int power, int changeSkin, int shooting);

	std::vector<Bullet*> bullets;

	const int getSpeed();
	const int getX();
	const int getY();
	const int getDirection();
	const int getIdSkin();
	const int getHP();
	const int getPoints();
	const int getPower();
	const int getChangeSkin();
	const int getShooting();
	const sf::Sprite getSprite();
	
	void setX(int x);
	void setY(int y);
	void setPosition(int x, int y);
	void setDirection(int x);
	void setIdSkin(int y);
	void setHP(int x);

	void display(sf::RenderWindow & renderWindow);
	int loadAssets();
	void changeTexture();
	void move();
};