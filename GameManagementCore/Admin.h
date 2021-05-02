#pragma once

#include <string>
#include "Player.h"
#include "Date.h"

class admin final : public player
{
public:
	admin(const std::string&, const std::string&, date*, float);
	~admin() override;
};
