#include "Loading.h"
#include "ResourceManager.h"
#include "StateMachine.h"
#include "State.h"
#include "Define.h"


Loading::Loading()
{
	m_loadingTexture = ResourceManager<Texture>::GetInstance()->LoadResource("./textures/loading.png");

	m_fTimer = 0.00f;
	//Matrix3 translate;
	//translate.M[2][0] = 600; //x
	//translate.M[2][1] = 300; //y

	//localTransform = translate * localTransform;
	//UpdateTransform();
}


Loading::~Loading()
{
}

void Loading::OnEnter()
{

}

void Loading::OnUpdate(float deltaTime, StateMachine* stateMachine)
{
	m_fTimer += deltaTime;

	if (m_fTimer > 3)
	{
		stateMachine->PushState(EGAMESTATE_MENU);
	}

}

void Loading::OnDraw(aie::Renderer2D* m_2dRenderer)
{
	m_2dRenderer->drawSprite(m_loadingTexture, 640, 360, 0, 0, 0, 1);
}
void Loading::OnExit()
{

}
void Loading::UpdateTransform()
{
	globalTransform = localTransform;
}