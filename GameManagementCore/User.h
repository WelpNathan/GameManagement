#pragma once

#include <string>

class user
{
public:
	user(std::string, std::string, std::string, float);
	virtual ~user();

	const std::string& get_username() const;
	const float& get_credbalance() const;


private:
	std::string username_;
	std::string password_;
	std::string created_;
	float credbalance_;
};
