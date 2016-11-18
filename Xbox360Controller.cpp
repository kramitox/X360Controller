#include "Xbox360Controller.h"
#include <iostream>
xbox360Controller::xbox360Controller()
{

}
xbox360Controller::~xbox360Controller()
{

}
void xbox360Controller::update()
{
	m_previousState = m_currentState;
	sf::Joystick::update();
	m_currentState.A = sf::Joystick::isButtonPressed(0, 0);
	m_currentState.B = sf::Joystick::isButtonPressed(0, 1);
	m_currentState.X = sf::Joystick::isButtonPressed(0, 2);
	m_currentState.Y = sf::Joystick::isButtonPressed(0, 3);
	m_currentState.LB = sf::Joystick::isButtonPressed(0, 4);
	m_currentState.RB = sf::Joystick::isButtonPressed(0, 5);
	m_currentState.start = sf::Joystick::isButtonPressed(0, 7);
	m_currentState.back = sf::Joystick::isButtonPressed(0, 6);
	m_currentState.RightThumbstickDown = sf::Joystick::isButtonPressed(0, 9);
	m_currentState.LeftThumbstickDown = sf::Joystick::isButtonPressed(0, 8);
	if (sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::PovX) < -50)
	{
		m_currentState.d_Left = true;
	}
	else
	{
		m_currentState.d_Left = false;
	}
	if (sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::PovX) > dpadThreshold)
	{
		m_currentState.d_Right = true;
	}
	else
	{
		m_currentState.d_Right = false;
	}
	if (sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::PovY) < (dpadThreshold * -1))
	{
		m_currentState.d_Up = true;
	}
	else
	{
		m_currentState.d_Up = false;
	}
	if (sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::PovY) > dpadThreshold)
	{
		m_currentState.d_Down = true;
	}
	else
	{
		m_currentState.d_Down = false;
	}
	//axis R = right thumbstick Y
	//U = Rthumbstick X
	//X = LT X
	//Y = LT Y
	//RT && LT = Z
	m_currentState.LeftThumbStick = sf::Vector2f(sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::X), sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::Y));
	m_currentState.RightThumbStick = sf::Vector2f(sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::U), sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::R));
	if (sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::Z) < -10)
	{
		m_currentState.LTrigger = sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::Z);
	}
	else if (sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::Z) < -10)
	{
		m_currentState.RTrigger = sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::Z);
	}
	else
	{
		m_currentState.LTrigger = 0;
		m_currentState.RTrigger = 0;
	}
}