#ifndef XBOX360CONTROLLER
#define XBOX360CONTROLLER

#include <SFML\Graphics.hpp>

/// <summary>
/// Controller Data that contains infomartion on the gamepads state.
/// </summary>
struct GamePadState
{
	bool A;
	bool B;
	bool X;
	bool Y;
	bool LB;
	bool LT;
	bool RB;
	bool RT;
	bool d_Down;
	bool d_Up;
	bool d_Left;
	bool d_Right;
	bool back;
	bool start;
	bool xboxGuide;
	float LTrigger;
	float RTrigger;
	sf::Vector2f RightThumbStick;
	sf::Vector2f LeftThumbStick;
};
/// <summary>
/// Xbox controller class to check the state of controller
/// </summary>
class xbox360Controller
{
private:
	//Deadzone for the D-Pad
	const int dpadThreshold = 50;
public:
	//ID of the controller that's conected.
	int sf_Joystick_index;
	//State of buttons
	GamePadState m_currentState;
	//State of buttons on controller during last frame.
	GamePadState m_previousState;

	xbox360Controller();
	~xbox360Controller();
	void update();
	bool isConnected();
	bool connect();

};
#endif // !XBOX360CONTROLLER