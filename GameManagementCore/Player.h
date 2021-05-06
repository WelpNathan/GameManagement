#pragma once

#include <string>
#include "LibraryItem.h"
#include "User.h"
#include "ListT.h"
#include "date.h"

class player : public user
{
public:
	player(const std::string&, const std::string&, date*, float, int);
	~player() override;
	List<library_item*> library;
};
