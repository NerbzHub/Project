#pragma once
#include "State.h"
#include "Entity.h"
#include "Renderer2D.h"
#include "Texture.h"

class Menu :
	public State
{
public:
	Menu();
	virtual ~Menu();

	void OnEnter();
	void OnUpdate(float deltaTime, StateMachine* stateMachine);
	void OnDraw(aie::Renderer2D* m_2dRenderer);
	void OnExit();
	void UpdateTransform();



private:
	Matrix3 globalTransform;
	Matrix3 localTransform;
	Texture* m_menuTexture;
};
