#pragma once

#include "Game.h"

class library_item
{
public:
	library_item(const std::string&, game*);
	~library_item();
private:
	const game* game_;
	const std::string purchased_; // TODO: replace with custom Date class, currently YYYY-MM-DD
};
