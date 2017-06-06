#include "Orbit.h"
#include "CollisionManager.h"


//--------------------------------------------------------------------------------------
// Constructor
//--------------------------------------------------------------------------------------
Orbit::Orbit()
{
	m_orbitTexture = new Texture("./textures/orbit.png");

	Matrix3 translate;
	translate.M[2][0] = 20; //x
	translate.M[2][1] = 0; //y

	localTransform = translate * localTransform;
	UpdateTransform();
}

//--------------------------------------------------------------------------------------
// Destructor
//--------------------------------------------------------------------------------------
Orbit::~Orbit()
{
	delete m_orbitTexture;
}

//--------------------------------------------------------------------------------------
// Update function, this happens every frame.
//
// Param:
//		deltaTime: A float value which is the timer of the game.
//--------------------------------------------------------------------------------------
void Orbit::Update(float deltaTime)
{
	Matrix3 rotation;
	rotation.setRotateZ(10 * deltaTime);

	localTransform = localTransform * rotation;
	UpdateTransform();
}

//--------------------------------------------------------------------------------------
// Draw function, this allows images to be drawn on the screen.
//
// Param:
//		m_2dRenderer: This is a pointer of renderer2D which allows the images to be seen
//		on the screen.
//--------------------------------------------------------------------------------------
void Orbit::Draw(Renderer2D* m_2dRenderer)
{
	//drawing the sprite
	m_2dRenderer->drawSpriteTransformed3x3(m_orbitTexture, globalTransform, 0, 0, 0, 0.2, 0);
}