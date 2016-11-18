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
	sf::Texture m_background;
	sf::Sprite m_sprite;
	sf::RenderWindow m_window;
	xbox360Controller gamePad;
};

