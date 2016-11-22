#include "Game.h"


/// <summary>
/// Constructor for our game that sets up a window for our game to run in.
/// </summary>
Game::Game() : m_window(sf::VideoMode(900, 600, 32), "Controller", sf::Style::Default)
{
	
}
/// <summary>
/// Initialise method that loads in fonts, textures and sets up everything in our game.
/// </summary>
void Game::initialise()
{
	if (!font.loadFromFile("times.ttf"))
	{
		std::cout << "Error Loading Font File" << std::endl;
	}
	if (!m_background.loadFromFile("controller.jpg"))
	{
		std::cout << "Error Loading Background File" << std::endl;
	}
	m_sprite.setTexture(m_background);
	initialiseText();
	//m_sprite.setScale(0.1, 0.1);
}
/// <summary>
/// Deconstructor method for if we need to destroy anything we may assign to the heap before closing our game.
/// </summary>
Game::~Game()
{

}
/// <summary>
/// Run method. This is the main loop of our game which calls initialise and then loops through update and draw.
/// </summary>
void Game::run()
{
	initialise();
	while (m_window.isOpen())
	{
		update();
		draw();
	}
}
/// <summary>
/// Update method which handles updating the gamepad and updating any strings related to data from the controller.
/// </summary>
void Game::update()
{
	
	gamePad.update();
	// Sets the data to the analog text objects from the gamepad data structure.
	leftAnalogX.setString(std::to_string((int)gamePad.m_currentState.LeftThumbStick.x));			
	rightAnalogX.setString(std::to_string((int)gamePad.m_currentState.RightThumbStick.x));
	leftAnalogY.setString(std::to_string((int)gamePad.m_currentState.LeftThumbStick.y));
	rightAnalogY.setString(std::to_string((int)gamePad.m_currentState.RightThumbStick.y));
	// Depending on the data value from the D-pad joystick, we set the string to up,down and left,right.
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
	if (gamePad.m_currentState.back)
	{
		m_window.close();
	}
	LTrigger.setString(std::to_string((int)gamePad.m_currentState.LTrigger));
	RTrigger.setString(std::to_string((int)gamePad.m_currentState.RTrigger));
}
/// <summary>
/// Draw method which 
/// </summary>
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
	//m_window.draw(leftAnalogX);
	//m_window.draw(leftAnalogY);
	if (gamePad.m_currentState.LeftThumbstickDown)
	{
		m_window.draw(leftAnalogPress);
	}
	//m_window.draw(rightAnalogX);
	//m_window.draw(rightAnalogY);
	if (gamePad.m_currentState.RightThumbstickDown)
	{
		m_window.draw(rightAnalogPressed);
	}
	m_window.draw(LTrigger);
	m_window.draw(RTrigger); 
	if (gamePad.m_currentState.LB)
	{
		m_window.draw(LBPressed);
	}
	if (gamePad.m_currentState.RB)
	{
		m_window.draw(RBPressed);
	}
	if (gamePad.m_currentState.d_Left || gamePad.m_currentState.d_Right)
	{
		m_window.draw(dPadX);
	}
	if (gamePad.m_currentState.d_Up || gamePad.m_currentState.d_Down)
	{
		m_window.draw(dPadY);
	}
	if (gamePad.m_currentState.start)
	{
		m_window.draw(pressedStartText);
	}
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
	if (gamePad.m_currentState.LeftThumbStick.x < -10 || gamePad.m_currentState.LeftThumbStick.x > 10)
	{
		m_window.draw(leftAnalogX);
	}
	if (gamePad.m_currentState.LeftThumbStick.y < -10 || gamePad.m_currentState.LeftThumbStick.y > 10)
	{
		m_window.draw(leftAnalogY);
	}
	if (gamePad.m_currentState.RightThumbStick.x < -10 || gamePad.m_currentState.RightThumbStick.x > 10)
	{
		m_window.draw(rightAnalogX);
	}
	if (gamePad.m_currentState.RightThumbStick.y < -10 || gamePad.m_currentState.RightThumbStick.y > 10)
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