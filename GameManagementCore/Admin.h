#pragma once

#include <string>
#include "Player.h"

class admin final : public player
{
public:
	admin(const std::string&, const std::string&, const std::string&, float);
	~admin() override;
};
