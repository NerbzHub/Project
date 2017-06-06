#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Vector2.h"
#include "CollisionManager.h"
#include "Player.h"
#include "Block.h"
#include "ResourceManager.h"
#include "Menu.h"
#include "GameState.h"

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
	// Use this to create the Character Texture
	m_pResourceMan = new ResourceManager<Texture>();

	m_pStateMachine = new StateMachine();
	m_pStateMachine->AddState(new Menu(), EGAMESTATE_MENU);
	m_pStateMachine->AddState(new GameState(), EGAMESTATE_MENU);

	//This creates the collision manager
	CollisionManager::Create();

	player = new Player();

	block = new Block();

	bg = new Environment();

	m_2dRenderer = new Renderer2D();

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
	delete player;
	delete bg;
	delete block;
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

	player->Update(deltaTime);
	block->Update(deltaTime);

	// input example
	Input* input = Input::getInstance();

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

	//draw background
	bg->Draw(m_2dRenderer);

	//draw player
	player->Draw(m_2dRenderer);

	//draw car
	block->Draw(m_2dRenderer);
	
	// output some text, uses the last used colour
	char fps[32];
	sprintf_s(fps, 32, "FPS: %i", getFPS());
	m_2dRenderer->drawText(m_font, fps, 0, 720 - 32);
	m_2dRenderer->drawText(m_font, "Press Space for sound!", 0, 720 - 64);

	// done drawing sprites
	m_2dRenderer->end();
}