#pragma once

#include <./include/Globals.h>
#include<SFML/Graphics.hpp>
#include<iostream>

class Player {
private:
	sf::Sprite body;
	sf::Texture bodyTexture;
	
	float speed;
	float hitbox;

public:
	Player();
	void loadImages();
	
	// Movement
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();

	sf::Sprite returnBody();
	float returnHitbox();
};