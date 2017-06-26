#include "SplashScreen.h"
#include "ResourceManager.h"


SplashScreen::SplashScreen()
{
	m_splashscreenTexture = ResourceManager<Texture>::GetInstance()->LoadResource("./textures/splashscreen.jpg");

	Matrix3 translate;
	translate.M[2][0] = 600; //x
	translate.M[2][1] = 300; //y

	localTransform = translate * localTransform;
	UpdateTransform();
}


SplashScreen::~SplashScreen()
{
}

void SplashScreen::OnEnter()
{

}

void SplashScreen::OnUpdate(float deltaTime)
{

}

void SplashScreen::OnDraw(aie::Renderer2D* m_2dRenderer)
{
	m_2dRenderer->drawSpriteTransformed3x3(m_splashscreenTexture, globalTransform);
}
void SplashScreen::OnExit()
{

}
void SplashScreen::UpdateTransform()
{
	globalTransform = localTransform;
}