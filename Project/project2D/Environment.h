//--------------------------------------------------------------------------------------
// Class for Environment
//
//--------------------------------------------------------------------------------------
#pragma once
#include "Texture.h"
#include "Entity.h"
#include "Renderer2D.h"

using namespace aie;

//--------------------------------------------------------------------------------------
// Environment class
// Stores functions and data used by the class
//--------------------------------------------------------------------------------------
class Environment : public Entity
{
public:

	//--------------------------------------------------------------------------------------
	// Constructor
	//--------------------------------------------------------------------------------------
	Environment();

	//--------------------------------------------------------------------------------------
	// Destructor
	//--------------------------------------------------------------------------------------
	~Environment();

	//--------------------------------------------------------------------------------------
	// Update function, this happens every frame.
	//
	// Param:
	//		deltaTime: A float value which is the timer of the game.
	//--------------------------------------------------------------------------------------
	void Update(float deltaTime);

	
	//--------------------------------------------------------------------------------------
	// Draw function, this allows images to be drawn on the screen.
	//
	// Param:
	//		m_2dRenderer: This is a pointer of renderer2D which allows the images to be seen
	//		on the screen.
	//--------------------------------------------------------------------------------------
	void Draw(Renderer2D* m_2dRenderer);

private:
	//Creates a texture pointer which will be able to be drawn
	Texture* m_backgroundTexture;

};

