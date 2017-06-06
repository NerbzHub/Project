#pragma once
#include "State.h"
class Menu :
	public State
{
public:
	Menu();
	virtual ~Menu();

	void OnEnter();
	void OnUpdate(float deltaTime);
	void OnDraw(aie::Renderer2D* m_2dRenderer);
	void OnExit();
};
