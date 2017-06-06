//--------------------------------------------------------------------------------------
// Class for Entity
//
//--------------------------------------------------------------------------------------
#pragma once
#include "Vector2.h"
#include "Collider.h"
#include "Matrix3.h"
#include "Vector2.h"
#include "Renderer2D.h"
#include <vector>

using namespace std;
using namespace aie;

//--------------------------------------------------------------------------------------
// Entity class
// Stores functions and data used by the class.
//--------------------------------------------------------------------------------------
class Entity
{
public:
	//--------------------------------------------------------------------------------------
	// Constructor
	//--------------------------------------------------------------------------------------
	Entity();

	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	~Entity();

	//--------------------------------------------------------------------------------------
	// Sets a parent entity to create a hierarchy.
	//
	// Param:
	//		parent: A pointer to an entity which will be set as a parent
	//--------------------------------------------------------------------------------------
	void setParent(Entity* parent);

	//--------------------------------------------------------------------------------------
	// Adds a child to a parent entity, inheriting the parent's values.
	//
	// Param:
	//		child: A pointer to an entity that will become a child
	//--------------------------------------------------------------------------------------
	void addChild(Entity* child);

	//--------------------------------------------------------------------------------------
	// Update Transform function, this updates the entity's location to whatever you have 
	//	 set it to. It is commonly used just after changing the location of an entity.
	//--------------------------------------------------------------------------------------
	void UpdateTransform();

	//--------------------------------------------------------------------------------------
	// Update function, this happens every frame.
	//
	// Param:
	//		deltaTime: A float value which is the timer of the game.
	//--------------------------------------------------------------------------------------
	virtual void Update(float deltaTime) = 0;

	//--------------------------------------------------------------------------------------
	// Draw function, this allows images to be drawn on the screen.
	//
	// Param:
	//		m_2dRenderer: This is a pointer of renderer2D which allows the images to be seen
	//		on the screen.
	//--------------------------------------------------------------------------------------
	virtual void Draw(Renderer2D* m_2dRenderer) = 0;

	//--------------------------------------------------------------------------------------
	// Gets a vector2 position
	//--------------------------------------------------------------------------------------
	Vector2 GetPosition();

	//--------------------------------------------------------------------------------------
	// Gets a collider through memory reference
	//--------------------------------------------------------------------------------------
	Collider& GetCollider();

	//Creates a float for the timer which will be based off deltaTime
	float m_timer;

protected:

	//Creates a matrix3 to hold the local transform of an entity
	Matrix3 localTransform;

	//Creates a matrix3 to hold the global transform of an entity
	Matrix3 globalTransform;

	//Creates an entity with the address of the parent
	Entity *parent;

	// Creates a list of all of the children
	vector<Entity*> childList;

	//Creates a collider called m_Collider
	Collider m_Collider;
};

