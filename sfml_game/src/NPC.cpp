#include <./include/NPC.h>

NPC::NPC()
{
	speed = 1;
	hitbox = 8;

	loadImages();
}

void NPC::loadImages()
{
	if (!bodyTexture.loadFromFile("ASSETS/IMAGES/NPC.png"))
	{
		std::cout << "Problem 0" << std::endl;
	}

	body.setTexture(bodyTexture);
	body.setOrigin(16, 16);
	body.setScale(.5f, .5f);
	body.setPosition(100, 100);
}

void NPC::die()
{
	int newX = (std::rand() % SCREEN_WIDTH) + 1;
	int newY = (std::rand() % SCREEN_HEIGHT) + 1;
	body.setPosition(newX, newY);
}

void NPC::move(sf::Sprite t_player)
{
	sf::Vector2f position = { body.getPosition() };
	sf::Vector2f player = { t_player.getPosition() };

	if (player.x > position.x)
	{
		position.x += 1;
	}
	if (player.x < position.x)
	{
		position.x -= 1;
	}
	if (player.y > position.y)
	{
		position.y += 1;
	}
	if (player.y < position.y)
	{
		position.y -= 1;
	}

	body.setPosition(position);
}

sf::Sprite NPC::returnBody()
{
	return body;
}

float NPC::returnHitbox()
{
	return hitbox;
}

