#include "User.h"
#include <utility>

user::user(std::string username, std::string password, date* created, const float credbalance, const int player_id) :
	username_(std::move(username)),
	password_(std::move(password)),
	created_date_(created),
	credit_balance_(credbalance),
	player_id_(player_id)
{
}

user::~user()
= default;

const std::string& user::get_username() const
{
	return username_;
}

const float& user::get_credit_balance() const
{
	return credit_balance_;
}

float& user::set_credit_balance(float new_balance)
{
	//set credbalance as new value
	credit_balance_ = new_balance;
	return credit_balance_;
}

const int& user::get_id()
{
	return player_id_;
}

const std::string& user::get_password() const
{
	return password_;
}

date* user::get_created_date()
{
	return created_date_;
}
