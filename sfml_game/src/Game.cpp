#include <SFML/Graphics.hpp>
#include <./include/Game.h>

Game::Game() : window(sf::VideoMode(static_cast<int>(SCREEN_WIDTH), static_cast<int>(SCREEN_HEIGHT)), "Joint Project Game", sf::Style::Default)
// Default constructor
{
}

void Game::loadContent()
// Load the font file & setup the message string
{
	if (!m_font.loadFromFile("assets/fonts/BebasNeue.otf"))
	{
		std::cout << "error with font file file";
	}

	// set up the message string 
	m_message.setFont(m_font);  // set the font for the text
	m_message.setCharacterSize(24); // set the text size
	m_message.setFillColor(sf::Color::White); // set the text colour
	m_message.setPosition(10, 10);  // its position on the screen

}


void Game::run()
// This function contains the main game loop which controls the game. 
{

	srand((int)time(nullptr)); // set the seed once

	sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);

	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	// the clock object keeps the time.
	sf::Clock clock;


	clock.restart();

	while (window.isOpen())
	{
		// check if the close window button is clicked on
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//get the time since last update and restart the clock
		timeSinceLastUpdate += clock.restart();

		//update every 60th of a second
		//only when the time since last update is greater than 1/60 update the world.
		if (timeSinceLastUpdate > timePerFrame)
		{
			update();
			draw();

			// reset the timeSinceLastUpdate to 0 
			timeSinceLastUpdate = sf::Time::Zero;
		}
	}  // end while loop

}

void Game::update()
// This function takes the keyboard input and updates the game world
{
	// get keyboard input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		thePlayer.moveLeft();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		thePlayer.moveRight();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		thePlayer.moveUp();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		thePlayer.moveDown();
	}

	// update any game variables here ...
	theEnemy.move(thePlayer.returnBody());
	collisionDetection();
}

void Game::draw()
// This function draws the game world
{
	// Clear the screen and draw your game sprites
	window.clear();

	m_message.setString("Game Play");
	window.draw(m_message);  // write message to the screen

	window.draw(thePlayer.returnBody());
	window.draw(theEnemy.returnBody());

	window.display();
}

void Game::collisionDetection()
{
	sf::Vector2f player{ thePlayer.returnBody().getPosition() };
	sf::Vector2f enemy{ theEnemy.returnBody().getPosition() };

	int distance = std::sqrt(((player.x - enemy.x) * (player.x - enemy.x)) + ((player.y - enemy.y) * (player.y - enemy.y)));

	if (distance < (thePlayer.returnHitbox() + theEnemy.returnHitbox()))
	{
		theEnemy.die();
	}
}
