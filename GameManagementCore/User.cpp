#include "User.h"
#include <utility>

user::user(std::string username, std::string password, std::string created)
	: username_(std::move(username)), password_(std::move(password)), created_(std::move(created))
{
}

user::~user()
= default;

const std::string& user::get_username() const
{
	return username_;
}
