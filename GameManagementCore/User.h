#pragma once

#include <string>
#include "date.h"

class user
{
public:
	user(const std::string&, const std::string&, const std::string&);
	virtual ~user();

	const std::string& get_username() const;


private:
	std::string username_;
	std::string password_;
	std::string created_;
};
