#include "stdafx.h"
#include "Player.h"
#include "Bullet.h"

int Player::initialized = false;
std::vector<sf::Texture*> Player::textures;

Player::Player() {

}

Player::Player(int idSkin, int hp)
{
	this->hp = hp;
	this->idSkin = idSkin;

	loadAssets();
	changeTexture();
}

const int Player::getX()
{
	return x;
}

const int Player::getY()
{
	return y;
}

const int Player::getHP()
{
	return hp;
}

const int Player::getPoints()
{
	return points;
}

const int Player::getPower()
{
	return power;
}

const int Player::getSpeed()
{
	return speed;
}

const sf::Sprite Player::getSprite()
{
	return sprite;
}

void Player::setX(int x)
{
	this->x = x;
}

void Player::setY(int y)
{
	this->y = y;
}

void Player::setHP(int hp)
{
	this->hp = hp;
}

void Player::setPoints(int points)
{
	this->points = points;
}

void Player::setPower(int power)
{
	this->power = power;
}

void Player::setPosition(int x, int y)
{
	this->x = x;
	this->y = y;

	sprite.setPosition((float)x, (float)y);
}

void Player::display(sf::RenderWindow & renderWindow)
{
	sprite.setPosition((float)x, (float)y);
	renderWindow.draw(sprite);
}

int Player::loadAssets()
{
	if (!Player::initialized) {
		Player::initialized = true;

		Player::textures.push_back(new sf::Texture);
		Player::textures[textures.size() - 1]->loadFromFile("Assets/player1.png");

		for (sf::Texture * t : Player::textures)
			if (t->getSize().x == 0)
				return EXIT_FAILURE;

	}
	return 0;
}

void Player::changeTexture()
{
	sprite.setTexture(*Player::textures[idSkin]);
}
