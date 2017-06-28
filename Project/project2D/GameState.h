#pragma once
#include "State.h"

class GameState :
	public State
{
public:
	GameState();
	virtual ~GameState();

		void OnEnter();
		int OnUpdate(float fDeltaTime);
		int OnDraw(aie::Renderer2D* m_2dRenderer);
		void OnExit();
};

