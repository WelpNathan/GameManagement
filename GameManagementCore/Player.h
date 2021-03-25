#pragma once

#include <string>
#include "LibraryItem.h"
#include "User.h"
#include "ListT.h"

class player : public user
{
public:
	player(const std::string&, const std::string&, const std::string&);
	~player();
	// library_item* library[2] = {}; // TODO: replace with custom List<T> class
	List<library_item*> library;
private:
};
