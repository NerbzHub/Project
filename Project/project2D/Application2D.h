//--------------------------------------------------------------------------------------
// Class for Application 2D
//
//--------------------------------------------------------------------------------------
#pragma once
#include "Application.h"
#include "Renderer2D.h"
#include "Audio.h"
#include "ResourceManager.h"
#include "Define.h"

class Loading;
class Menu;
class GameState;
class SplashScreen;
class StateMachine;
class State;


//--------------------------------------------------------------------------------------
// Application2D class
// Stores functions and data used by the class
//--------------------------------------------------------------------------------------
class Application2D : public aie::Application {
public:

	//--------------------------------------------------------------------------------------
	// Default Constructor
	//--------------------------------------------------------------------------------------
	Application2D();

	//--------------------------------------------------------------------------------------
	// Virtual Destructor
	//--------------------------------------------------------------------------------------
	virtual ~Application2D();

	//--------------------------------------------------------------------------------------
	// Function for the start up of the application.
	//		
	// Initiates:
	//		player
	//		block
	//		background
	//		2dRenderer
	//		Font
	//		Audio
	//		Camera x and y
	//		Timer
	//
	// Return:
	//		true, as it is a bool.
	//--------------------------------------------------------------------------------------
	virtual bool startup();

	//--------------------------------------------------------------------------------------
	// This is the destructor for when the application shutsdown.
	//
	// Deletes:
	//		CollisionManager
	//		player
	//		background
	//		block
	//		audio
	//		font
	//		2dRenderer
	//--------------------------------------------------------------------------------------
	virtual void shutdown();
	
	//--------------------------------------------------------------------------------------
	// Update function, this happens every frame.
	//
	// Param:
	//		deltaTime: A float value which is the timer of the game.
	//--------------------------------------------------------------------------------------
	virtual void update(float deltaTime);

	//--------------------------------------------------------------------------------------
	// Draw function, this allows images to be drawn on the screen.
	//--------------------------------------------------------------------------------------
	virtual void draw();

protected:

	//Pointer to renderer2D class to be used in the application2D
	aie::Renderer2D*	m_2dRenderer;
	//Pointer to the Font class to be used in the application2D
	aie::Font*			m_font;
	//Pointer to the audio class to be used in the application2D
	aie::Audio*			m_audio;
	//Pointer to the resource manager
	ResourceManager<aie::Texture>* m_pResourceMan;
	//Create State Machine
	StateMachine* m_pStateMachine;

	Menu* menu;
	SplashScreen* splashScreen;
	Loading* loading;


	//Creating a float value for the camera's x and y position
	float m_cameraX, m_cameraY;
	//Creating a float for the timer
	float m_timer;

	
};