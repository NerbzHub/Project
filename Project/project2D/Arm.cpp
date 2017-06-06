#include "Arm.h"
#include "CollisionManager.h"
#include "Orbit.h"


using namespace aie;

//--------------------------------------------------------------------------------------
// Constructor
//--------------------------------------------------------------------------------------
Arm::Arm()
{
	m_armTexture = new Texture("./textures/arm.png");
	
	Orbit* orbit = new Orbit();
	orbit->setParent(this);
	addChild(orbit);

	//CollisionManager::GetInstance()->AddObject(this);

	Matrix3 translate;
	translate.M[2][0] = 18; //x
	translate.M[2][1] = 0; //y


	localTransform = translate * localTransform;
	UpdateTransform();
}

//--------------------------------------------------------------------------------------
// Destructor
//--------------------------------------------------------------------------------------
Arm::~Arm()
{
	delete m_armTexture;

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
void Arm::Update(float deltaTime)
{
	Vector3 vrotation;

	Matrix3 rotation;

	Input* input = Input::getInstance();

	if (input->isKeyDown(INPUT_KEY_RIGHT))
		rotation.setRotateZ(-2 * deltaTime);

	if (input->isKeyDown(INPUT_KEY_LEFT))
		rotation.setRotateZ(2 * deltaTime);

	localTransform = localTransform * rotation;
	UpdateTransform();

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
void Arm::Draw(Renderer2D* m_2dRenderer)
{
	//drawing the sprite
	m_2dRenderer->drawSpriteTransformed3x3(m_armTexture, globalTransform, 0, 0, 0, 0.1, 0.5);

	for (int i = 0; i < childList.size(); i++)
	{
		childList[i]->Draw(m_2dRenderer);
	}
}