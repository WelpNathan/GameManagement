#pragma once

#include <string>
#include <vector>

#include "LibraryItem.h"
#include "User.h"
#include "date.h"

class player : public user
{
public:
	player(const std::string&, const std::string&, date*, float, int);
	~player() override;
	std::vector<library_item*> library;
};
