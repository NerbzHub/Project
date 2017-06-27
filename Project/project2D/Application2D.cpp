#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
//#include "Vector2.h"
#include "CollisionManager.h"
#include "Menu.h"
#include "GameState.h"
#include "SplashScreen.h"

#include "StateMachine.h"
#include "State.h"

using namespace aie;

//--------------------------------------------------------------------------------------
// Default Constructor
//--------------------------------------------------------------------------------------
Application2D::Application2D() 
{
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
Application2D::~Application2D() 
{
}

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
bool Application2D::startup() 
{
	ResourceManager<Texture>::Create();
	m_pResourceMan = new ResourceManager<Texture>();
	//This creates the collision manager
	CollisionManager::Create();
	m_2dRenderer = new Renderer2D();


	menu = new Menu();
	splashScreen = new SplashScreen();

	//GameState* gameState = new GameState();
	/*while (EGAMESTATE_SPLASH)
	{
		splashScreen->OnDraw(m_2dRenderer);
	}

	while (EGAMESTATE_MENU)
	{
		menu->OnDraw(m_2dRenderer);
	}
*/
	
	


	// Use this to create the Character Texture
	

	m_pStateMachine = new StateMachine();
	m_pStateMachine->RegisterState(splashScreen, EGAMESTATE_SPLASH);
	m_pStateMachine->RegisterState(menu, EGAMESTATE_MENU);

	m_pStateMachine->PushState(EGAMESTATE_SPLASH);
	//m_pStateMachine->PushState(EGAMESTATE_MENU);

	

	m_font = new Font("./font/consolas.ttf", 32);

	m_audio = new Audio("./audio/powerup.wav");

	m_cameraX = 0;
	m_cameraY = 0;
	m_timer = 0;

	return true;
}

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
void Application2D::shutdown() 
{
	//This deletes the collision manager
	CollisionManager::Destroy();
	delete m_audio;
	delete m_font;
	delete m_2dRenderer;
}

//--------------------------------------------------------------------------------------
// Update function, this happens every frame.
//
// Param:
//		deltaTime: A float value which is the timer of the game.
//--------------------------------------------------------------------------------------
void Application2D::update(float deltaTime) 
{
	m_timer += deltaTime;

	// input example
	Input* input = Input::getInstance();

	// 
	switch (1) {

	case 1: (EGAMESTATE_SPLASH);
		splashScreen->OnUpdate(deltaTime, m_pStateMachine);
		break;

	case 2: (EGAMESTATE_MENU);
		menu->OnUpdate(deltaTime, m_pStateMachine);
		break;

	}

	//example of audio
	if (input->wasKeyPressed(INPUT_KEY_SPACE))
		m_audio->play();

	// exit the application
	if (input->isKeyDown(INPUT_KEY_ESCAPE))
		quit();
}

//--------------------------------------------------------------------------------------
// Draw function, this allows images to be drawn on the screen.
//--------------------------------------------------------------------------------------
void Application2D::draw() 
{
	// wipe the screen to the background colour
	clearScreen();

	// set the camera position before we begin rendering
	m_2dRenderer->setCameraPos(m_cameraX, m_cameraY);

	// begin drawing sprites
	m_2dRenderer->begin();

	m_pStateMachine->Draw(m_2dRenderer);

	//// output some text, uses the last used colour
	//char fps[32];
	//sprintf_s(fps, 32, "FPS: %i", getFPS());
	//m_2dRenderer->drawText(m_font, fps, 0, 720 - 32);
	//m_2dRenderer->drawText(m_font, "Press Space for sound!", 0, 720 - 64);

	// done drawing sprites
	m_2dRenderer->end();
}