#include "Block.h"
#include "CollisionManager.h"
#include "Texture.h"
#include "Matrix3.h"
#include "Vector2.h"
#include "Player.h"

//--------------------------------------------------------------------------------------
// Constructor
//--------------------------------------------------------------------------------------
Block::Block()
{
	m_timer = 0.0f;

	m_blockTexture = new Texture("./textures/car.png");

	CollisionManager::GetInstance()->AddObject(this);

	m_Collider.m_TL = Vector2(-10, -10);
	m_Collider.m_BR = Vector2(10, 10);

	Matrix3 translate;
	translate.M[2][0] = 600; //x
	translate.M[2][1] = 100; //y

	localTransform = translate * localTransform;
	UpdateTransform();
}

//--------------------------------------------------------------------------------------
// Destructor
//--------------------------------------------------------------------------------------
Block::~Block()
{
	delete m_blockTexture;
}

//--------------------------------------------------------------------------------------
// Update function, this happens every frame.
//
// Param:
//		deltaTime: A float value which is the timer of the game.
//--------------------------------------------------------------------------------------
void Block::Update(float deltaTime)
{
	m_timer += deltaTime;

	//this makes it go up
	Matrix3 translate;
	translate.M[2][0] = 0; //x
	translate.M[2][1] = 200 * deltaTime; //y

	localTransform = translate * localTransform;
	UpdateTransform();


	//--------------------------------------------------------------------------------------
	// This is the sequence for the car's movement. 
	//--------------------------------------------------------------------------------------
	if (m_timer > 1.8f)
	{
		Matrix3 translate;
		translate.M[2][0] = -200 * deltaTime; //x
		translate.M[2][1] = -200 * deltaTime; //y

		localTransform = translate * localTransform;
		UpdateTransform();
		m_blockTexture = new Texture("./textures/carLeft.png");
	}

	if (m_timer > 3.7)
	{
		Matrix3 translate;
		translate.M[2][0] = 200 * deltaTime; //x
		translate.M[2][1] = -200 * deltaTime; //y

		localTransform = translate * localTransform;
		UpdateTransform();
		m_blockTexture = new Texture("./textures/carInverted.png");
	}

	if (m_timer > 5.5)
	{
		Matrix3 translate;
		translate.M[2][0] = 200 * deltaTime; //x
		translate.M[2][1] = 200 * deltaTime; //y

		localTransform = translate * localTransform;
		UpdateTransform();
		m_blockTexture = new Texture("./textures/carRight.png");
	}

	if (m_timer > 9.3)
	{
		Matrix3 translate;
		translate.M[2][0] = -200 * deltaTime; //x
		translate.M[2][1] = 200 * deltaTime; //y

		localTransform = translate * localTransform;
		UpdateTransform();
		m_blockTexture = new Texture("./textures/car.png");
	}

	if (m_timer > 11.2)
	{
		Matrix3 translate;
		translate.M[2][0] = -200 * deltaTime; //x
		translate.M[2][1] = -200 * deltaTime; //y

		localTransform = translate * localTransform;
		UpdateTransform();
		m_blockTexture = new Texture("./textures/carLeft.png");
	}

	if (m_timer > 13)
	{
		Matrix3 translate;
		translate.M[2][0] = 200 * deltaTime; //x
		translate.M[2][1] = 0 * deltaTime; //y

		localTransform = translate * localTransform;
		UpdateTransform();
		m_blockTexture = new Texture("./textures/carLeft.png");
	}

	CollisionManager* pCollision = CollisionManager::GetInstance();
	bool colliding = pCollision->TestCollision(this);
	if (colliding)
	{	
	}
}

//--------------------------------------------------------------------------------------
// Draw function, this allows images to be drawn on the screen.
//
// Param:
//		m_2dRenderer: This is a pointer of renderer2D which allows the images to be seen
//		on the screen.
//--------------------------------------------------------------------------------------
void Block::Draw(Renderer2D* m_2dRenderer)
{
	m_2dRenderer->drawSpriteTransformed3x3(m_blockTexture, globalTransform);
}