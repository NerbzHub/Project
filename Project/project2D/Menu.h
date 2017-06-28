#pragma once
#include "State.h"
#include "Entity.h"
#include "Renderer2D.h"
#include "Texture.h"
#include "Matrix3.h"

class Menu;

using namespace aie;

class Menu :
	public State
{
public:
	Menu();
	virtual ~Menu();

	void OnEnter();
	int OnUpdate(float deltaTime, StateMachine* stateMachine);
	int OnDraw(aie::Renderer2D* m_2dRenderer);
	void OnExit();
	void UpdateTransform();

	

private:
	Matrix3 globalTransform;
	Matrix3 localTransform;
	Texture* m_menuTexture;
	float m_fTimer;
};
;
