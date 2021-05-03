#include "User.h"
#include <utility>

user::user(std::string username, std::string password, date* created, float credbalance, int player_id) :
	username_(std::move(username)),
	password_(std::move(password)),
	created_date_(created),
	credbalance_(credbalance),
	player_id_(player_id)
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
