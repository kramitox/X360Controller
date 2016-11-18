#pragma once
#ifndef SFML
	#define SFML
	#include "SFML/Graphics.hpp" 
	#include "SFML/OpenGL.hpp" 
	#include <iostream>
#endif // !SFML
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
};

