#pragma once

#include "stdafx.h"

class Bullet
{
private:
	int x = 500;
	int y = 500;
	int power = 1;
	int idSkin = 0;//0 - enemy, 1 - player
	static const int bulletSpeed = 3;

	sf::Sprite sprite;
	static std::vector<sf::Texture*> textures;
	static int initialized;

public:
	Bullet();
	Bullet(int x, int y, int idSkin, int power);

	const sf::Sprite getSprite();
	const int getX();
	const int getY();
	const int getPower();

	void setX(int x);
	void setY(int y);
	void setPower(int power);
	void setPosition(int x, int y);

	void testInit(int x, int y, int idSkin, int power);
	void display(sf::RenderWindow & renderWindow);
	int loadAssets();
	void changeTexture();
	void move();
};