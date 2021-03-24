#pragma once

#include "Game.h"

class store
{
public:
	store();
	~store();
	game* games[9] = {}; // TODO: should be a dynamic collection
private:
};
