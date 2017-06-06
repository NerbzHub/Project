#include "Player.h"
#include "CollisionManager.h"
#include "Matrix3.h"
#include "Arm.h"
#include <iostream>

using namespace aie;

//--------------------------------------------------------------------------------------
// Constructor
//--------------------------------------------------------------------------------------
Player::Player()
{
	m_shipTexture = new Texture("./textures/robotShootNoArm.png");

	Arm* arm = new Arm();
	arm->setParent(this);
	addChild(arm);
	CollisionManager::GetInstance()->AddObject(this);
	m_Collider.m_TL = Vector2(-30, -50);
	m_Collider.m_BR = Vector2(30, 50);
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
Player::~Player()
{
	delete m_shipTexture;

	for (int i = 0; i < childList.size(); i++)
	{
		delete childList[i];
	}
}

//--------------------------------------------------------------------------------------
// Update function, this happens every frame.
//
// Param:
//		deltaTime: A float value which is the timer of the game.
//--------------------------------------------------------------------------------------
void Player::Update(float deltaTime)
{
	Input* input = Input::getInstance();

	Vector2 oldPos;

	oldPos = GetPosition();

	Vector2 m_v2Position;

	// use arrow keys to move camera
	if (input->isKeyDown(INPUT_KEY_D))
		m_v2Position.x += 500.0f * (deltaTime);

	if (input->isKeyDown(INPUT_KEY_S))
		m_v2Position.y -= 500.0f * deltaTime;

	if (input->isKeyDown(INPUT_KEY_A))
		m_v2Position.x -= 500.0f * deltaTime;

	if (input->isKeyDown(INPUT_KEY_W))
		m_v2Position.y += 500.0f * deltaTime;


	//create a set pos in math lib
	Matrix3 translate;
	translate.M[2][0] = m_v2Position.x; //x
	translate.M[2][1] = m_v2Position.y; //y

	localTransform = translate * localTransform;
	UpdateTransform();

	//TestCollsion
	CollisionManager* pCollision = CollisionManager::GetInstance();
	bool colliding = pCollision->TestCollision(this);
	if (colliding)
	{
		std::cout << "CRASH!" << std::endl;
		localTransform.M[2][0] = oldPos.x;
		localTransform.M[2][1] = oldPos.y;
		UpdateTransform();
	}

	for (int i = 0; i < childList.size(); i++)
	{
		childList[i]->Update(deltaTime);
	}
}

//--------------------------------------------------------------------------------------
// Draw function, this allows images to be drawn on the screen.
//
// Param:
//		m_2dRenderer: This is a pointer of renderer2D which allows the images to be seen
//		on the screen.
//--------------------------------------------------------------------------------------
void Player::Draw(Renderer2D* m_2dRenderer)
{
	//drawing the sprite
	m_2dRenderer->drawSpriteTransformed3x3(m_shipTexture, globalTransform);

	for (int i = 0; i < childList.size(); i++)
	{
		childList[i]->Draw(m_2dRenderer);
	}
}