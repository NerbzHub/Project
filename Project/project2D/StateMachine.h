#pragma once
#include "Renderer2D.h"
#include "DynamicArray.h"
#include "State.h"
#include "Stack.h"

using namespace aie;
class StateMachine
{
public:
	StateMachine();
	~StateMachine();

	int Update(float fDeltaTime);
	int Draw(Renderer2D* m_2dRenderer);
	int PushState(int nStateIndex);
	void RegisterState(State* state, int nStateIndex);
	

private:
	DynamicArray<State*> m_StateList;
	//int m_nCurrentState;
	Stack<State*> m_Stack;
};

