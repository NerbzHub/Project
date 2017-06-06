//--------------------------------------------------------------------------------------
// Class for Orbit
//
//--------------------------------------------------------------------------------------
#pragma once
#include "Entity.h"
#include "Texture.h"
#include "Renderer2D.h"

//--------------------------------------------------------------------------------------
// Orbit class
// Stores functions and data used by the class
//--------------------------------------------------------------------------------------
class Orbit : public Entity
{
public:

	//--------------------------------------------------------------------------------------
	// Constructor
	//--------------------------------------------------------------------------------------
	Orbit();

	//--------------------------------------------------------------------------------------
	// Destructor
	//--------------------------------------------------------------------------------------
	~Orbit();

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
	Texture* m_orbitTexture;
};

