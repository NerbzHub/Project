#include "Menu.h"
#include "ResourceManager.h"


Menu::Menu()
{
	m_menuTexture = ResourceManager<Texture>::GetInstance()->LoadResource("./textures/menu01.jpg");

}


Menu::~Menu()
{
}

void Menu::OnEnter()
{

}

void Menu::OnUpdate(float deltaTime)
{

}

void Menu::OnDraw(aie::Renderer2D* m_2dRenderer)
{
	m_2dRenderer->drawSpriteTransformed3x3(m_menuTexture, globalTransform);
}
void Menu::OnExit()
{

}

void Menu::UpdateTransform()
{
	globalTransform = localTransform;
}