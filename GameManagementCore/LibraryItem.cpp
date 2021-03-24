#include "LibraryItem.h"

library_item::library_item(const std::string& date, game* game)
	: game_(game), purchased_(date)
{
}

library_item::~library_item()
= default;
