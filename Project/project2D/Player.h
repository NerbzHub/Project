//--------------------------------------------------------------------------------------
// Class for Player
//
//--------------------------------------------------------------------------------------
#pragma once
#include "Texture.h"
#include "Entity.h"
#include "Vector2.h"
#include "Renderer2D.h"
#include "Input.h"

using namespace aie;

//--------------------------------------------------------------------------------------
// Player class
// Stores functions and data used by the class
//--------------------------------------------------------------------------------------
class Player : public Entity
{
public:

	//--------------------------------------------------------------------------------------
	// Constructor
	//--------------------------------------------------------------------------------------
	Player();

	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	~Player();

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
	Texture* m_shipTexture;

	//Creates a vector2 to hold the position of the player in 2D space
	Vector2 m_v2Position;
	
};

