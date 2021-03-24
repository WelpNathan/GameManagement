#include "Store.h"

store::store()
= default;

store::~store()
{
	for (auto& game : games)
	{
		delete game;
	}
}
