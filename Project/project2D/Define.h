#pragma once

enum GameStateType
{
	EGAMESTATE_SPLASH = 0,
	EGAMESTATE_MENU = 1,
	EGAMESTATE_LOADING = 2,
};

//Error Debug Codes

#define SUCCESS 0
#define OUT_OF_ARRAY_ACCESS 1
#define UNREGISTERED_STATE 2
#define NEGATIVE_STATELIST_SIZE 3
#define NEGATIVE_STACK_SIZE 4