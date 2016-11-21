#include "Game.h"



Game::Game() : m_window(sf::VideoMode(900, 600, 32), "Controller", sf::Style::Default)
{
	
}
void Game::initialise()
{
	if (!font.loadFromFile("times.ttf"))
	{
	}


	if (!m_background.loadFromFile("controller.jpg"))
	{
		std::cout << "Error Loading Background File" << std::endl;
	}
	m_sprite.setTexture(m_background);
	initialiseText();
	//m_sprite.setScale(0.1, 0.1);
}

Game::~Game()
{

}

void Game::run()
{
	initialise();
	while (m_window.isOpen())
	{
		update();
		draw();
	}
}

void Game::update()
{
	
	gamePad.update();
	leftAnalogX.setString(std::to_string((int)gamePad.m_currentState.LeftThumbStick.x));
	rightAnalogX.setString(std::to_string((int)gamePad.m_currentState.RightThumbStick.y));
	leftAnalogY.setString(std::to_string((int)gamePad.m_currentState.LeftThumbStick.y));
	rightAnalogY.setString(std::to_string((int)gamePad.m_currentState.RightThumbStick.y));
	LTrigger.setString(std::to_string((int)gamePad.m_currentState.LTrigger));
	RTrigger.setString(std::to_string((int)gamePad.m_currentState.RTrigger));
}

void Game::draw()
{
	m_window.clear(sf::Color(1, 1, 1, 1));

	m_window.draw(m_sprite);
	
	drawText();
	m_window.display();
}

void Game::initialiseText()
{
	setTextProperties(pressedAText, 750,425);
	setTextProperties(pressedBText,750,360);
	setTextProperties(pressedXText,750,300);
	setTextProperties(pressedYText,750,240);
	setTextProperties(pressedStartText,720,425);
	setTextProperties(leftAnalogX, 50, 265);
	setTextProperties(leftAnalogY, 50, 285);
	setTextProperties(leftAnalogPress, 720, 425);
	setTextProperties(rightAnalogX, 720, 425);
	setTextProperties(rightAnalogY, 720, 425);
	setTextProperties(rightAnalogPressed, 720, 425);
	setTextProperties(RBPressed, 720, 425);
	setTextProperties(LBPressed, 720, 425);
	setTextProperties(LTrigger, 720, 425);
	setTextProperties(RTrigger, 720, 425);
}
void Game::setTextProperties(sf::Text &text, int x, int y)
{
	text.setFont(font);
	text.setCharacterSize(24);
	text.setColor(sf::Color::Red);
	text.setString("Pressed");
	text.setPosition(x, y);
}
void Game::drawText()
{
	if (gamePad.m_currentState.A)
	{
		m_window.draw(pressedAText);
	}
	if (gamePad.m_currentState.B)
	{
		m_window.draw(pressedBText);
	}
	if (gamePad.m_currentState.X)
	{
		m_window.draw(pressedXText);
	}
	if (gamePad.m_currentState.Y)
	{
		m_window.draw(pressedYText);
	}
	if (gamePad.m_currentState.back)
	{
		m_window.close();
	}
	if (gamePad.m_currentState.LeftThumbStick.x < -25 || gamePad.m_currentState.LeftThumbStick.x > 25)
	{
		m_window.draw(leftAnalogX);
	}
	if (gamePad.m_currentState.LeftThumbStick.y < -25 || gamePad.m_currentState.LeftThumbStick.y > 25)
	{
		m_window.draw(leftAnalogY);
	}
	if (gamePad.m_currentState.RightThumbStick.x < -25 || gamePad.m_currentState.RightThumbStick.x > 25)
	{
		m_window.draw(rightAnalogX);
	}
	if (gamePad.m_currentState.RightThumbStick.y < -25 || gamePad.m_currentState.RightThumbStick.y > 25)
	{
		m_window.draw(rightAnalogY);
	}
	if (gamePad.m_currentState.LTrigger < -10)
	{
		m_window.draw(LTrigger);
	}
	else if (gamePad.m_currentState.LTrigger > 10)
	{
		m_window.draw(RTrigger);
	}
}