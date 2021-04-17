#pragma once

#include <string>
#include "LibraryItem.h"
#include "User.h"
#include "ListT.h"

class player : public user
{
public:
	player(const std::string&, const std::string&, const std::string&);
	~player() override;
	List<library_item*> library;
private:
};
