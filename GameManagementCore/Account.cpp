#include "Account.h"

#include <utility>

account::account(std::string email, std::string password, date* created, int id)
	: email_(std::move(email)), password_(std::move(password)), created_(created), id_(id)
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

const int& account::get_id() const
{
	return id_;
}

const date* account::get_date() const
{
	return created_;
}
