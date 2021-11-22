#include <./include/Player.h>

Player::Player()
{
	speed = 2;
	hitbox = 16;

	loadImages();
}

void Player::loadImages()
{
	if (!bodyTexture.loadFromFile("ASSETS/IMAGES/Player.png"))
	{
		std::cout << "Problem 0" << std::endl;
	}

	body.setTexture(bodyTexture);
	body.setOrigin(154, 201);
	body.setScale(0.25f, 0.25f);
	body.setPosition((SCREEN_WIDTH / 2), (SCREEN_HEIGHT / 2));
}

void Player::moveUp()
{
	sf::Vector2f position{ body.getPosition() };
	position.y -= speed;
	body.setPosition(position);
}

void Player::moveDown()
{
	sf::Vector2f position{ body.getPosition() };
	position.y += speed;
	body.setPosition(position);
}

void Player::moveLeft()
{
	sf::Vector2f position{ body.getPosition() };
	position.x -= speed;
	body.setPosition(position);
}

void Player::moveRight()
{
	sf::Vector2f position{ body.getPosition() };
	position.x += speed;
	body.setPosition(position);
}

sf::Sprite Player::returnBody()
{
	return body;
}

float Player::returnHitbox()
{
	return hitbox;
}
