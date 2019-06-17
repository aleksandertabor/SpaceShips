#include "stdafx.h"
#include "Enemy.h"
#include "Bullet.h"

int Enemy::initialized = false;
std::vector<sf::Texture*> Enemy::textures;

Enemy::Enemy() {

}

Enemy::Enemy(int x, int y, int direction, int idSkin, int hp, int points, int power, int changeSkin, int shooting)
{
	this->direction = direction;
	this->idSkin = idSkin;
	this->hp = hp;
	this->points = points;
	this->power = power;
	this->changeSkin = changeSkin;
	this->shooting = shooting;

	loadAssets();
	changeTexture();
	setPosition(x, y);
}

const int Enemy::getSpeed()
{
	return speed;
}

const int Enemy::getX()
{
	return x;
}

const int Enemy::getY()
{
	return y;
}

const int Enemy::getDirection()
{
	return direction;
}

const int Enemy::getIdSkin()
{
	return idSkin;
}

const int Enemy::getHP()
{
	return hp;
}

const int Enemy::getPoints()
{
	return points;
}

const int Enemy::getPower()
{
	return power;
}

const int Enemy::getChangeSkin()
{
	return changeSkin;
}

const int Enemy::getShooting()
{
	return shooting;
}

const sf::Sprite Enemy::getSprite()
{
	return sprite;
}

void Enemy::setX(int x)
{
	this->x = x;
}

void Enemy::setY(int y)
{
	this->y = y;
}

void Enemy::setPosition(int x, int y)
{
	this->x = x;
	this->y = y;
	sprite.setPosition((float)x, (float)y);
}

void Enemy::setDirection(int direction)
{
	this->direction = direction;
}

void Enemy::setIdSkin(int idSkin)
{
	this->idSkin = idSkin;
}

void Enemy::setHP(int hp)
{
	this->hp = hp;
}

void Enemy::display(sf::RenderWindow & renderWindow)
{
	sprite.setPosition((float)x, (float)y);
	renderWindow.draw(sprite);
}

int Enemy::loadAssets()
{
	if (!Enemy::initialized) {
		Enemy::initialized = true;

		Enemy::textures.push_back(new sf::Texture);
		Enemy::textures[textures.size() - 1]->loadFromFile("Assets/enemy1.png");
		Enemy::textures.push_back(new sf::Texture);
		Enemy::textures[textures.size() - 1]->loadFromFile("Assets/enemy2.png");
		Enemy::textures.push_back(new sf::Texture);
		Enemy::textures[textures.size() - 1]->loadFromFile("Assets/enemy2Shot.png");
		Enemy::textures.push_back(new sf::Texture);
		Enemy::textures[textures.size() - 1]->loadFromFile("Assets/asteroid1.png");
		Enemy::textures.push_back(new sf::Texture);
		Enemy::textures[textures.size() - 1]->loadFromFile("Assets/asteroid1Shot.png");

		for (sf::Texture * t : Enemy::textures)
			if (t->getSize().x == 0)
				return EXIT_FAILURE;

	}
	return 0;
}

void Enemy::changeTexture()
{
	sprite.setTexture(*Enemy::textures[idSkin]);
}

void Enemy::move()
{
	// Directions: 0 - STOP, 1 - LEFT, 2 - UP, 3 - DOWN, 4 - RIGHT
	if (direction == 5)
	{
		setPosition(x, (int)(y + speed * 0.3));
	}
	if (direction == 4)
	{
		setPosition(x + speed, y);
	}
	if (direction == 3)
	{
		setPosition(x, y + speed);
	}
	if (direction == 2)
	{
		setPosition(x, y - speed);
	}
	if (direction == 1)
	{
		setPosition(x - speed, y);
	}
	if (direction == 0)
	{
		setPosition(x, y);
	}

}


