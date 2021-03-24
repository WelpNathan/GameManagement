#include "User.h"

user::user(const std::string& username, const std::string& password, const std::string& created)
	: username_(username), password_(password), created_(created)
{
}

user::~user()
= default;

const std::string& user::get_username() const
{
	return username_;
}
