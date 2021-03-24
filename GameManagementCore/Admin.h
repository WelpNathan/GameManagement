#pragma once

#include <string>
#include "Player.h"

class admin : public player
{
public:
	admin(const std::string&, const std::string&, const std::string&);
	~admin();
};
