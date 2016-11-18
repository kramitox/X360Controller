#include "Game.h"



Game::Game() : m_window(sf::VideoMode(1440, 900, 32), "Controller", sf::Style::Default)
{
	
}
void Game::initialise()
{
	if (!m_background.loadFromFile("controller.jpg"))
	{
		std::cout << "Error Loading Background File" << std::endl;
	}
}

Game::~Game()
{
}

void Game::run()
{
	initialise();
	while (true)
	{
		update();
		draw();
	}
}

void Game::update()
{

}

void Game::draw()
{
	m_window.clear(sf::Color(0, 0, 0, 0));
	m_window.draw(m_background);
}
