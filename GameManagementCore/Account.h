#pragma once

#include <string>
#include "Player.h"
#include "ListT.h"

class account
{
public:
	account(const std::string&, const std::string&, const std::string&);
	~account();
	user* users[3] = { }; // TODO: replace with custom List<T> class
	//List<user*> users;
private:
	std::string email_;
	std::string password_;
	std::string created_; // TODO: replace with custom Date class, currently YYYY-MM-DD
};

