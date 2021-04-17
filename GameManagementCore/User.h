#pragma once

#include <string>

class user
{
public:
	user(std::string, std::string, std::string);
	virtual ~user();

	const std::string& get_username() const;


private:
	std::string username_;
	std::string password_;
	std::string created_;
};
