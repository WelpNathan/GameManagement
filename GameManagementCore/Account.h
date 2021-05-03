#pragma once

#include <string>
#include "Player.h"
#include "ListT.h"
#include "date.h"

class account
{
public:
	account(std::string, std::string, date*, int);
	~account();
	List<user*> users;

	const std::string& get_account_name() const;
	const std::string& get_account_password() const;
	const int& get_id() const;
	const date* get_date() const;

private:
	std::string email_;
	std::string password_;
	date* created_;
	int id_;
};
