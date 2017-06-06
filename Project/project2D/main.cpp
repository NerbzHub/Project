#include "Application2D.h"

//--------------------------------------------------------------------------------------
// Main
//
// This initiates the application.
//
// In here you can change the resolution of the application window.
//--------------------------------------------------------------------------------------
int main() 
{
	Application2D* app = new Application2D();
	app->run("AIE", 1280, 720, false);
	delete app;

	return 0;
}