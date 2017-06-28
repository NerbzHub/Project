#include "CollisionManager.h"
#include "Collider.h"
#include <iostream>

CollisionManager* CollisionManager::m_instance = nullptr;

//--------------------------------------------------------------------------------------
// Default Constructor
//--------------------------------------------------------------------------------------
CollisionManager::CollisionManager()
{
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
CollisionManager::~CollisionManager()
{
}

//--------------------------------------------------------------------------------------
// Gets an instance of collision manager. This is used for allocating a collider to
// an entity.
//--------------------------------------------------------------------------------------
CollisionManager* CollisionManager::GetInstance()
{
	return m_instance;
}

//--------------------------------------------------------------------------------------
// Create function creates a collider for an entity.
//--------------------------------------------------------------------------------------
void CollisionManager::Create()
{
	if(!m_instance)
		m_instance = new CollisionManager();
	_ASSERT(m_instance);
}

//--------------------------------------------------------------------------------------
// Destroy function destroys a collider for an entity.
//--------------------------------------------------------------------------------------
void CollisionManager::Destroy()
{
	delete m_instance;
}

//--------------------------------------------------------------------------------------
// Adds an object which is a pointer to an entity.
//
// Param:
//		pObject: A pointer to an entity
//--------------------------------------------------------------------------------------
void CollisionManager::AddObject(Entity* pObject)
{
	m_CollisionList.push_back(pObject);
}

//--------------------------------------------------------------------------------------
// Removes an object which is a pointer to an entity.
//
// Param:
//		pObject: A pointer to an entity
//--------------------------------------------------------------------------------------
void CollisionManager::RemoveObject(Entity* pObject)
{
	auto iter = std::find(m_CollisionList.begin(), m_CollisionList.end(), pObject);
	if (iter != m_CollisionList.end())
		m_CollisionList.erase(iter);
}

//--------------------------------------------------------------------------------------
// This is a simple true or false to see whether an object is colliding or not.
//
// Param:
//		pObject: A pointer to an entity
//--------------------------------------------------------------------------------------
bool CollisionManager::TestCollision(Entity* pObject)
{
	for (int i = 0; i < m_CollisionList.size(); i++)
	{
		if (pObject == m_CollisionList[i])
			continue;

		Collider collider1 = pObject->GetCollider();
		collider1.m_TL = collider1.m_TL + pObject->GetPosition();
		collider1.m_BR = collider1.m_BR + pObject->GetPosition();

		Collider collider2 = m_CollisionList[i]->GetCollider();
		collider2.m_TL = collider2.m_TL + m_CollisionList[i]->GetPosition();
		collider2.m_BR = collider2.m_BR + m_CollisionList[i]->GetPosition();

		//Test if two AABBs are overlapping
		if (collider1.m_BR.x > collider2.m_TL.x &&
			collider1.m_BR.y > collider2.m_TL.y &&
			collider1.m_TL.x < collider2.m_BR.x &&
			collider1.m_TL.y < collider2.m_BR.y)
		{
			return true;
		}


		//if colliding
		//return true
	}
	return false;
}