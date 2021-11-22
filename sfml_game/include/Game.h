// Game class declaration
#pragma once

#include "SFML/Graphics.hpp" 
#include <iostream>
#include <cstdlib>  // include support for randomizing
#include <ctime>   // supports ctime function
#include <cmath>

#include <./include/Globals.h>
#include <./include/Player.h>
#include <./include/NPC.h>

class Game
{
	sf::RenderWindow window;

	Player thePlayer;
	NPC theEnemy;

public:
	sf::Font m_font;  // font for writing text
	sf::Text m_message;  // text to write on the screen

public:	  // declaration of member functions	
	Game(); // default constructor
	void	loadContent();
	void	run();
	void	update();
	void	draw();

	void collisionDetection();
};