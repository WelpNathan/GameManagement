#pragma once

#include <string>
#include "ListT.h"
#include "LibraryItem.h"

class user
{
public:
	user(std::string, std::string, std::string, float);
	virtual ~user();
	const std::string& get_username() const;
	const std::string& get_password() const;
	const float& get_credbalance() const;
	float& set_credbalance(float new_balance);

private:
	std::string username_;
	std::string password_;
	std::string created_;
	float credbalance_;
};
