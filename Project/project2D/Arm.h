//--------------------------------------------------------------------------------------
// Class for Arm
//
//--------------------------------------------------------------------------------------
#pragma once
#include "Entity.h"
#include "Renderer2D.h"
#include "Texture.h"
#include "Matrix2.h"
#include "Input.h"

using namespace aie;

//--------------------------------------------------------------------------------------
// Arm class
// Stores functions and data used by the class
//--------------------------------------------------------------------------------------
class Arm : public Entity
{
public:
	//--------------------------------------------------------------------------------------
	// Constructor
	//--------------------------------------------------------------------------------------
	Arm();

	//--------------------------------------------------------------------------------------
	// Destructor
	//--------------------------------------------------------------------------------------
	~Arm();

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
	//Pointer to texture so that it can later be drawn
	Texture* m_armTexture;
};

