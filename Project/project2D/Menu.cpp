#include "Menu.h"
#include "ResourceManager.h"
#include "StateMachine.h"
#include "State.h"
#include "Define.h"


Menu::Menu()
{
	m_menuTexture = ResourceManager<Texture>::GetInstance()->LoadResource("./textures/menu.png");

	m_fTimer = 0.00f;
	//Matrix3 translate;
	//translate.M[2][0] = 600; //x
	//translate.M[2][1] = 300; //y

	//localTransform = translate * localTransform;
	//UpdateTransform();
}


Menu::~Menu()
{
}

void Menu::OnEnter()
{

}

void Menu::OnUpdate(float deltaTime, StateMachine* stateMachine)
{
	m_fTimer += deltaTime;
}

void Menu::OnDraw(aie::Renderer2D* m_2dRenderer)
{
	m_2dRenderer->drawSprite(m_menuTexture, 640, 360, 0, 0, 0, 1);
}
void Menu::OnExit()
{

}
void Menu::UpdateTransform()
{
	globalTransform = localTransform;
}