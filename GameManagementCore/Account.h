#pragma once

#include <string>
#include "Player.h"
#include "ListT.h"
#include "date.h"

class account
{
public:
	account(std::string, std::string, date*);
	~account();
	List<user*> users;

	const std::string& get_account_name() const;

private:
	std::string email_;
	std::string password_;
	date* created_;
};
