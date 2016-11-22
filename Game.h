#pragma once
#ifndef SFML
	#define SFML
	#include "SFML/Graphics.hpp" 
	#include "SFML/OpenGL.hpp" 
	#include <iostream>
#endif // !SFML
#include "Xbox360Controller.h"

/// <summary>
/// Name: Keenan McEntee
/// Student ID: C00201892
/// Description: Small SFML based game that reads keys from a controller and outputs when they are pressed to the screen.
/// Time taken: Started: Friday 18th/11/2016	Time: 15:30 - 16:55
///				Edited:  Monday 21st/11/2016	Time: 13:00 - 15:00
///				Edited:  Tuesday22nd/11/2016	Time: 13:20 - 
/// </summary>
class Game
{
public:
	//Declaration of all the public methods used in our game.
	Game();
	~Game();
	void run();
	void initialise();
	void update();
	void draw();
private:
	//Declaration of all the private methods and objects used in our game which are not accessible by other classes.
	void initialiseText();
	void setTextProperties(sf::Text &text, int x, int y);
	void drawText();
	sf::Texture m_background;
	sf::Sprite m_sprite;





	sf::Font font;
	sf::Text pressedAText;
	sf::Text pressedBText;
	sf::Text pressedXText;
	sf::Text pressedYText;
	sf::Text pressedStartText;
	sf::Text leftAnalogX;
	sf::Text leftAnalogY;
	sf::Text leftAnalogPress;
	sf::Text rightAnalogX;
	sf::Text rightAnalogY;
	sf::Text rightAnalogPressed;
	sf::Text RBPressed;
	sf::Text LBPressed;
	sf::Text LTrigger;
	sf::Text RTrigger;
	sf::Text dPadX;
	sf::Text dPadY;
	sf::RenderWindow m_window;
	xbox360Controller gamePad;
};

