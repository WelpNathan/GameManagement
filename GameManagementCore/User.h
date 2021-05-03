#pragma once

#include <string>
#include "ListT.h"
#include "LibraryItem.h"
#include "Date.h"

class user
{
public:
	user(std::string, std::string, date*, float, int);
	virtual ~user();
	const std::string& get_username() const;
	const std::string& get_password() const;
	date* user::get_created_date();
	const float& get_credbalance() const;
	float& set_credbalance(float new_balance);
	const int& get_id();

private:
	std::string username_;
	std::string password_;
	date* created_date_;
	float credbalance_;
	int player_id_;
};
