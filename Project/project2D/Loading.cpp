#include "Loading.h"
#include "ResourceManager.h"
#include "StateMachine.h"
#include "State.h"
#include "Define.h"


Loading::Loading()
{
	m_loadingTexture = ResourceManager<Texture>::GetInstance()->LoadResource("./textures/loading.png");

	m_fTimer = 0.00f;
}


Loading::~Loading()
{
}

void Loading::OnEnter()
{

}

int Loading::OnUpdate(float deltaTime, StateMachine* stateMachine)
{
	m_fTimer += deltaTime;

	_ASSERT(m_fTimer > 0);

	if (m_fTimer > 3)
	{
		stateMachine->PushState(EGAMESTATE_MENU);
	}
	return 0;
}

int Loading::OnDraw(aie::Renderer2D* m_2dRenderer)
{
	m_2dRenderer->drawSprite(m_loadingTexture, 640, 360, 0, 0, 0, 1);
	return 0;
}
void Loading::OnExit()
{

}
void Loading::UpdateTransform()
{
	globalTransform = localTransform;
}