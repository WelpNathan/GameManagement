#include "LibraryItem.h"

#include <utility>

library_item::library_item(std::string date, game* game, int play_time)
	: game_(game), purchased_(std::move(date)), played_(play_time)
{

}

library_item::~library_item()
= default;

const game* library_item::get_game() const
{
	return game_;
}