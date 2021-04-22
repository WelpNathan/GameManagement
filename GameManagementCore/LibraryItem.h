#pragma once

#include "Game.h"

class library_item
{
public:
	library_item(std::string, game*);
	~library_item();
	const game* get_game() const;

private:
	const game* game_;
	const std::string purchased_; // TODO: replace with custom Date class, currently YYYY-MM-DD
};
