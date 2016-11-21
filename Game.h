#pragma once
#ifndef SFML
	#define SFML
	#include "SFML/Graphics.hpp" 
	#include "SFML/OpenGL.hpp" 
	#include <iostream>
#endif // !SFML
#include "Xbox360Controller.h"
class Game
{
public:
	Game();
	~Game();
	void run();
	void initialise();
	void update();
	void draw();
private:
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
	sf::RenderWindow m_window;
	xbox360Controller gamePad;
};

