#include "User.h"
#include <utility>

user::user(std::string username, std::string password, std::string created, float credbalance)
	: username_(std::move(username)),
	  password_(std::move(password)),
	  created_date_(std::move(created)),
	  credbalance_(credbalance)
{
}

user::~user()
= default;

const std::string& user::get_username() const
{
	return username_;
}

const float& user::get_credbalance() const
{
	return credbalance_;
}

float& user::set_credbalance(float new_balance)
{
	//set credbalance as new value
	credbalance_ = new_balance;
	return credbalance_;
}

const std::string& user::get_password() const
{
	return password_;
}

const std::string& user::get_created_date() const
{
	return created_date_;
}
