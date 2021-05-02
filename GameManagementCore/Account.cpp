#include "Account.h"

#include <utility>

account::account(std::string email, std::string password, date* created)
	: email_(std::move(email)), password_(std::move(password)), created_(created)
{
}

account::~account()
{
	// TODO: add deleting users when deconstructing
	//for (auto& user : users)
	//{
	//	delete user;
	//}
}

const std::string& account::get_account_name() const
{
	return email_;
}

const std::string& account::get_account_password() const
{
	return password_;
}
