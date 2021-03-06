//--------------------------------------------------------------------------------------
// Class for Collision Manager
//
//--------------------------------------------------------------------------------------
#pragma once
#include <vector>
#include "Entity.h"

//--------------------------------------------------------------------------------------
// CollisionManager class
// Stores functions and data used by the class.
//--------------------------------------------------------------------------------------
class CollisionManager
{
public:
	//--------------------------------------------------------------------------------------
	// Gets an instance of collision manager. This is used for allocating a collider to
	// an entity.
	//--------------------------------------------------------------------------------------
	static CollisionManager* GetInstance();

	//--------------------------------------------------------------------------------------
	// Create function creates a collider for an entity.
	//--------------------------------------------------------------------------------------
	static void Create();

	//--------------------------------------------------------------------------------------
	// Destroy function destroys a collider for an entity.
	//--------------------------------------------------------------------------------------
	static void Destroy();
	
	//--------------------------------------------------------------------------------------
	// Adds an object which is a pointer to an entity.
	//
	// Param:
	//		pObject: A pointer to an entity
	//--------------------------------------------------------------------------------------
	void AddObject(Entity* pObject);

	//--------------------------------------------------------------------------------------
	// Removes an object which is a pointer to an entity.
	//
	// Param:
	//		pObject: A pointer to an entity
	//--------------------------------------------------------------------------------------
	void RemoveObject(Entity* pObject);

	//--------------------------------------------------------------------------------------
	// This is a simple true or false to see whether an object is colliding or not.
	//
	// Param:
	//		pObject: A pointer to an entity
	//--------------------------------------------------------------------------------------
	bool TestCollision(Entity* pObject);

private:

	//--------------------------------------------------------------------------------------
	// Default Constructor
	//--------------------------------------------------------------------------------------
	CollisionManager();

	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	~CollisionManager();

	//--------------------------------------------------------------------------------------
	// Creates a list of all of the colliders
	//--------------------------------------------------------------------------------------
	std::vector<Entity*> m_CollisionList;

	//--------------------------------------------------------------------------------------
	// Creates an instance of collision manager
	//--------------------------------------------------------------------------------------
	static CollisionManager* m_instance;
};

