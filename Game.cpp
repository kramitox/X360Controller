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
	if (gamePad.m_currentState.d_Down)
	{
		dPadY.setString("Down");
	}
	else if (gamePad.m_currentState.d_Up)
	{
		dPadY.setString("Up");
	}
	if (gamePad.m_currentState.d_Left)
	{
		dPadX.setString("Left");
	}
	else if (gamePad.m_currentState.d_Right)
	{
		dPadX.setString("Right");
	}
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
	setTextProperties(pressedStartText,760,500);
	setTextProperties(leftAnalogX, 50, 265);
	setTextProperties(leftAnalogY, 50, 285);
	setTextProperties(leftAnalogPress, 50, 310);
	setTextProperties(rightAnalogX, 520, 520);
	setTextProperties(rightAnalogY, 520, 545);
	setTextProperties(rightAnalogPressed, 520, 565);
	setTextProperties(RBPressed, 700, 125);
	setTextProperties(LBPressed, 75, 125);
	setTextProperties(LTrigger, 200, 30);
	setTextProperties(RTrigger, 575, 30);
	setTextProperties(dPadX, 250, 500);
	setTextProperties(dPadY, 250, 525);

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
	m_window.draw(pressedAText);
	m_window.draw(pressedBText);
	m_window.draw(pressedXText);
	m_window.draw(pressedYText);
	m_window.draw(leftAnalogX);
	m_window.draw(leftAnalogY);
	m_window.draw(leftAnalogPress);
	m_window.draw(rightAnalogX);
	m_window.draw(rightAnalogY);
	m_window.draw(rightAnalogPressed);
	m_window.draw(LTrigger);
	m_window.draw(RTrigger); 
	m_window.draw(LBPressed);
	m_window.draw(RBPressed);
	m_window.draw(dPadX);
	m_window.draw(dPadY);
	m_window.draw(pressedStartText);
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