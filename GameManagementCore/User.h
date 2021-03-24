#pragma once

#include <string>

class user
{
public:
	user(const std::string&, const std::string&, const std::string&);
	virtual ~user();
	const std::string& get_username() const;
private:
	std::string username_;
	std::string password_;
	std::string created_; // TODO: replace with custom Date class, currently YYYY-MM-DD
};
