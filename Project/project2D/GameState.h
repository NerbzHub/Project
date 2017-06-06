#pragma once
#include "State.h"

class GameState :
	public State
{
public:
	GameState();
	virtual ~GameState();

		void OnEnter();
		void OnUpdate(float fDeltaTime);
		void OnDraw(aie::Renderer2D* m_2dRenderer);
		void OnExit();
};

