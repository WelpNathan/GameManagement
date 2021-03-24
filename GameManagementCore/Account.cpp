#include "Account.h"

account::account(const std::string& email, const std::string& password, const std::string& created)
	: email_(email), password_(password), created_(created)
{
}

account::~account()
{
	for (auto& user : users)
	{
		delete user;
	}
}
