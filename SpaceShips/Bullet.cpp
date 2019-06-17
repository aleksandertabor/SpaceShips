#include "stdafx.h"
#include "Bullet.h"

int Bullet::initialized = false;
std::vector<sf::Texture*> Bullet::textures;

Bullet::Bullet()
{

}

Bullet::Bullet(int x, int y, int idSkin, int power)
{
	this->x = x;
	this->y = y;
	this->idSkin = idSkin;
	this->power = power;

	loadAssets();
	changeTexture();
}

const sf::Sprite Bullet::getSprite()
{
	return sprite;
}

const int Bullet::getX()
{
	return x;
}

const int Bullet::getY()
{
	return y;
}

const int Bullet::getPower()
{
	return power;
}

void Bullet::setX(int x)
{
	this->x = x;
}

void Bullet::setY(int y)
{
	this->y = y;
}

void Bullet::setPower(int power)
{
	this->power = power;
}

void Bullet::setPosition(int x, int y)
{
	this->x = x;
	this->y = y;
	sprite.setPosition((float)x, (float)y);
}

void Bullet::testInit(int x, int y, int idSkin, int power)
{
	this->x = x;
	this->y = y;
	this->idSkin = idSkin;
	this->power = power;

	loadAssets();
	changeTexture();
}

void Bullet::display(sf::RenderWindow & renderWindow)
{
	sprite.setPosition((float)x, (float)y);
	renderWindow.draw(sprite);
}

int Bullet::loadAssets()
{
	if (!Bullet::initialized) {
		Bullet::initialized = true;

		Bullet::textures.push_back(new sf::Texture);
		Bullet::textures[textures.size() - 1]->loadFromFile("Assets/bullet1.png");
		Bullet::textures.push_back(new sf::Texture);
		Bullet::textures[textures.size() - 1]->loadFromFile("Assets/bullet2.png");

		for (sf::Texture * t : Bullet::textures)
			if (t->getSize().x == 0)
				return EXIT_FAILURE;

	}
	return 0;
}

void Bullet::changeTexture()
{
	sprite.setTexture(*Bullet::textures[idSkin]);
}


void Bullet::move()
{
	if (idSkin == 0)
		setPosition(x, y + bulletSpeed);
	if (idSkin == 1)
		setPosition(x, y - bulletSpeed);
}
