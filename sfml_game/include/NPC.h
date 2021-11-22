#pragma once

#include <./include/Globals.h>
#include<SFML/Graphics.hpp>
#include<iostream>

class NPC {
private:
	sf::Sprite body;
	sf::Texture bodyTexture;

	float speed;
	float hitbox;

public:
	NPC();
	void loadImages();

	void die();

	void move(sf::Sprite t_player);

	sf::Sprite returnBody();
	float returnHitbox();
};