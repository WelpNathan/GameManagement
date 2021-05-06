#pragma once

#include <string>
#include "Player.h"
#include "date.h"

class admin final : public player
{
public:
	admin(const std::string&, const std::string&, date*, float, int);
	~admin() override;
};
