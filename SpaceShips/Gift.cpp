#include "stdafx.h"
#include "Gift.h"

int Gift::initialized = false;
std::vector<sf::Texture*> Gift::textures;

Gift::Gift()
{

}

Gift::Gift(int x, int y, int idSkin, int points, int hp, int power)
{
	this->x = x;
	this->y = y;
	this->idSkin = idSkin;
	this->points = points;
	this->hp = hp;
	this->power = power;

	loadAssets();
	changeTexture();
	setPosition(x, y);
}

const int Gift::getX()
{
	return x;
}

const int Gift::getY()
{
	return y;
}

const int Gift::getIdSkin()
{
	return idSkin;
}

const int Gift::getPoints()
{
	return points;
}

const int Gift::getHP()
{
	return hp;
}

const int Gift::getPower()
{
	return power;
}

const sf::Sprite Gift::getSprite()
{
	return sprite;
}

void Gift::setX(int x)
{
	this->x = x;
}

void Gift::setY(int y)
{
	this->y = y;
}

void Gift::setPosition(int x, int y)
{
	this->x = x;
	this->y = y;
	sprite.setPosition((float)x, (float)y);
}

void Gift::setIdSkin(int idSkin)
{
	this->idSkin = idSkin;
}

void Gift::setPoints(int points)
{
	this->points = points;
}

void Gift::setHP(int hp)
{
	this->hp = hp;
}

void Gift::setPower(int power)
{
	this->power = power;
}

void Gift::display(sf::RenderWindow & renderWindow)
{
	sprite.setPosition((float)x, (float)y);
	renderWindow.draw(sprite);
}

int Gift::loadAssets()
{
	if (!Gift::initialized) {
		Gift::initialized = true;

		Gift::textures.push_back(new sf::Texture);
		Gift::textures[textures.size() - 1]->loadFromFile("Assets/gift1.png");
		Gift::textures.push_back(new sf::Texture);
		Gift::textures[textures.size() - 1]->loadFromFile("Assets/gift2.png");
		Gift::textures.push_back(new sf::Texture);
		Gift::textures[textures.size() - 1]->loadFromFile("Assets/gift3.png");

		for (sf::Texture * t : Gift::textures)
			if (t->getSize().x == 0)
				return EXIT_FAILURE;

	}
	return 0;
}

void Gift::changeTexture()
{
	sprite.setTexture(*Gift::textures[idSkin]);
}

void Gift::move()
{
	setPosition(x, (int)(y + speed * 0.3));
}
