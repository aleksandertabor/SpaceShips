#pragma once

#include "stdafx.h"

class Gift
{
private:
	static const int speed = 4;

	int x = 0;
	int y = 0;
	int idSkin = 0;
	int points = 0;
	int hp = 0;
	int power = 0;

	sf::Sprite sprite;
	static std::vector<sf::Texture*> textures;
	static int initialized;

public:
	Gift();
	Gift(int x, int y, int idSkin, int points, int hp, int power);

	const int getX();
	const int getY();
	const int getIdSkin();
	const int getPoints();
	const int getHP();
	const int getPower();
	const sf::Sprite getSprite();

	void setX(int x);
	void setY(int y);
	void setPosition(int x, int y);
	void setIdSkin(int idSkin);
	void setPoints(int points);
	void setHP(int hp);
	void setPower(int power);

	void display(sf::RenderWindow & renderWindow);
	int loadAssets();
	void changeTexture();
	void move();
};