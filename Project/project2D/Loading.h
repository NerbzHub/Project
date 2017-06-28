#pragma once
#include "State.h"
#include "Entity.h"
#include "Renderer2D.h"
#include "Texture.h"
#include "Matrix3.h"

class Loading;

using namespace aie;

class Loading :
	public State
{
public:
	Loading();
	virtual ~Loading();

	void OnEnter();
	void OnUpdate(float deltaTime, StateMachine* stateMachine);
	void OnDraw(aie::Renderer2D* m_2dRenderer);
	void OnExit();
	void UpdateTransform();



private:
	Matrix3 globalTransform;
	Matrix3 localTransform;
	Texture* m_loadingTexture;
	float m_fTimer;
};
;
