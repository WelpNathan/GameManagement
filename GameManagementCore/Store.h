#pragma once

#include "Game.h"
#include "ListT.h"

class store
{
public:
	store();
	~store();
	//game* games[9] = {}; // TODO: should be a dynamic collection
	List<game*> games;
private:
};
