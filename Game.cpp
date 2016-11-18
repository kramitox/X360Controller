#include "Game.h"



Game::Game() : m_window(sf::VideoMode(900, 600, 32), "Controller", sf::Style::Default)
{
	
}
void Game::initialise()
{
	if (!m_background.loadFromFile("controller.jpg"))
	{
		std::cout << "Error Loading Background File" << std::endl;
	}
	m_sprite.setTexture(m_background);
	//m_sprite.setScale(0.1, 0.1);
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
	gamePad.update();
}

void Game::draw()
{
	m_window.clear(sf::Color(1, 1, 1, 1));
	m_window.draw(m_sprite);
	m_window.display();
}
