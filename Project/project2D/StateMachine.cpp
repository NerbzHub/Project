#include "StateMachine.h"
#include "Define.h"
#include <crtdbg.h>


StateMachine::StateMachine()
{
	  
}


StateMachine::~StateMachine()
{
	m_StateList.Clear();
}

int StateMachine::Update(float fDeltaTime)
{
	_ASSERT(m_StateList.Size() >= 0);
		
	if (m_StateList.Size() < 0)
		return NEGATIVE_STATELIST_SIZE;

	//m_StateList[m_nCurrentState]->OnUpdate(fDeltaTime, this);
	m_Stack.Top()->OnUpdate(fDeltaTime, this);

	return SUCCESS;
}

int StateMachine::Draw(Renderer2D* m_2dRenderer)
{
	_ASSERT(m_StateList.Size() > 0);

	if (m_StateList.Size() < 0)
		return NEGATIVE_STATELIST_SIZE;

	//m_StateList[m_nCurrentState]->OnDraw(m_2dRenderer);
	m_Stack.Top()->OnDraw(m_2dRenderer);

	return SUCCESS;
}

int StateMachine::PushState(int nStateIndex)
{
	_ASSERT(m_StateList.Size() > 0);

	if (m_Stack.Size() > 0)
		m_Stack.Top()->OnExit();

	m_Stack.Push(m_StateList[nStateIndex]);

	m_Stack.Top()->OnEnter();

	return SUCCESS;
	
}

void StateMachine::RegisterState(State* state, int nStateIndex)
{
	m_StateList.Insert(nStateIndex, state);
}