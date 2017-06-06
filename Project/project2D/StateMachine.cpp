#include "StateMachine.h"



StateMachine::StateMachine()
{
}


StateMachine::~StateMachine()
{
}

void StateMachine::Update(float fDeltaTime)
{
	if (m_StateList.Size() <= 0)
		return;

	m_StateList[m_nCurrentState]->OnUpdate(fDeltaTime);
}

void StateMachine::Draw(Renderer2D* m_2dRenderer)
{
	m_StateList[m_nCurrentState]->OnDraw(m_2dRenderer);
}

void StateMachine::SetState(int nStateIndex)
{

}

void StateMachine::AddState(State* state, int nStateIndex)
{

}