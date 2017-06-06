#include "Environment.h"

#include "Matrix3.h"

//--------------------------------------------------------------------------------------
// Constructor
//--------------------------------------------------------------------------------------
Environment::Environment()
{
	m_backgroundTexture = new Texture("./textures/racetrack.png");

	Matrix3 translate;
	translate.M[2][0] = 600; //x
	translate.M[2][1] = 300; //y

	localTransform = translate * localTransform;
	UpdateTransform();
}

//--------------------------------------------------------------------------------------
// Destructor
//--------------------------------------------------------------------------------------
Environment::~Environment()
{
	delete m_backgroundTexture;
}

//--------------------------------------------------------------------------------------
// Update function, this happens every frame.
//
// Param:
//		deltaTime: A float value which is the timer of the game.
//--------------------------------------------------------------------------------------
void Environment::Update(float deltaTime)
{
	UpdateTransform();
}

//--------------------------------------------------------------------------------------
// Draw function, this allows images to be drawn on the screen.
//
// Param:
//		m_2dRenderer: This is a pointer of renderer2D which allows the images to be seen
//		on the screen.
//--------------------------------------------------------------------------------------
void Environment::Draw(Renderer2D* m_2dRenderer)
{
	m_2dRenderer->drawSpriteTransformed3x3(m_backgroundTexture, globalTransform);
}