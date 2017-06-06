#pragma once
#include "Renderer2D.h"
class State
{
public:
	State();
	~State();

	virtual void OnEnter() = 0;
	virtual void OnUpdate(float deltaTime) = 0;
	virtual void OnDraw(aie::Renderer2D* m_2dRenderer) = 0;
	virtual void OnExit() = 0;
};
	

