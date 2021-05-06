#pragma once

#include <string>
#include "date.h"

class user
{
public:
	user(std::string, std::string, date*, float, int);
	virtual ~user();
	const std::string& get_username() const;
	const std::string& get_password() const;
	date* get_created_date();
	const float& get_credit_balance() const;
	float& set_credit_balance(float new_balance);
	const int& get_id();

private:
	std::string username_;
	std::string password_;
	date* created_date_;
	float credit_balance_;
	int player_id_;
};
