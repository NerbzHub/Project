#include "Entity.h"

//--------------------------------------------------------------------------------------
// Constructor
//--------------------------------------------------------------------------------------
Entity::Entity()
{
	parent = nullptr;
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
Entity::~Entity()
{
}

//--------------------------------------------------------------------------------------
// Gets a collider through memory reference
//--------------------------------------------------------------------------------------
Collider& Entity::GetCollider()
{
	return m_Collider;
}

//--------------------------------------------------------------------------------------
// Gets a vector2 position
//--------------------------------------------------------------------------------------
Vector2 Entity::GetPosition()
{
	Vector2 m_v2Position;
	m_v2Position.x = globalTransform.M[2][0];
	m_v2Position.y = globalTransform.M[2][1];
	return m_v2Position;
}

//--------------------------------------------------------------------------------------
// Update Transform function, this updates the entity's location to whatever you have 
//	 set it to. It is commonly used just after changing the location of an entity.
//--------------------------------------------------------------------------------------
void Entity::UpdateTransform()
{
	if (parent)
	{
		globalTransform =  parent->globalTransform * localTransform;
	}

	else
	{
		globalTransform = localTransform;
	}

	for (int i = 0; i < childList.size(); i++)
	{
		childList[i]->UpdateTransform();
	}
}

//--------------------------------------------------------------------------------------
// Adds a child to a parent entity, inheriting the parent's values.
//
// Param:
//		child: A pointer to an entity that will become a child
//--------------------------------------------------------------------------------------
void Entity::addChild(Entity* child)
{
	childList.push_back(child);
}

//--------------------------------------------------------------------------------------
// Sets a parent entity to create a hierarchy.
//
// Param:
//		parent: A pointer to an entity which will be set as a parent
//--------------------------------------------------------------------------------------
void Entity::setParent(Entity* p)
{
	parent = p;
}