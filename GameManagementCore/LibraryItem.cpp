#include "LibraryItem.h"

#include <utility>

library_item::library_item(std::string date, game* game)
	: game_(game), purchased_(std::move(date))
{
}

library_item::~library_item()
= default;

const game* library_item::get_game() const
{
	return game_;
}
