#pragma once

#include <string>
#include "Player.h"
#include "ListT.h"

class account
{
public:
	account(std::string, std::string, std::string);
	~account();
	List<user*> users;

	const std::string& get_account_name() const;

private:
	std::string email_;
	std::string password_;
	std::string created_; // TODO: replace with custom Date class, currently YYYY-MM-DD
};

