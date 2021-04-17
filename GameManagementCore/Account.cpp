#include "Account.h"

#include <utility>

account::account(std::string email, std::string password, std::string created)
	: email_(std::move(email)), password_(std::move(password)), created_(std::move(created))
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
