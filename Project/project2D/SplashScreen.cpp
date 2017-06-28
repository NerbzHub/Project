#include "SplashScreen.h"
#include "ResourceManager.h"
#include "StateMachine.h"
#include "State.h"
#include "Define.h"


SplashScreen::SplashScreen()
{
	m_splashscreenTexture = ResourceManager<Texture>::GetInstance()->LoadResource("./textures/splashscreen.png");

	m_fTimer = 0.00f;
	//Matrix3 translate;
	//translate.M[2][0] = 600; //x
	//translate.M[2][1] = 300; //y

	//localTransform = translate * localTransform;
	//UpdateTransform();
}


SplashScreen::~SplashScreen()
{
}

void SplashScreen::OnEnter()
{

}

void SplashScreen::OnUpdate(float deltaTime, StateMachine* stateMachine)
{
	m_fTimer += deltaTime;

	if (m_fTimer > 3)
	{
		stateMachine->PushState(EGAMESTATE_LOADING);
	}
	
}

void SplashScreen::OnDraw(aie::Renderer2D* m_2dRenderer)
{
	m_2dRenderer->drawSprite(m_splashscreenTexture, 640, 360, 0, 0, 0, 1);
}
void SplashScreen::OnExit()
{

}
void SplashScreen::UpdateTransform()
{
	globalTransform = localTransform;
}