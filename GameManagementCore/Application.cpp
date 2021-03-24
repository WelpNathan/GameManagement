#include "Application.h"

application::application() : current_account_(nullptr), current_user_(nullptr)
{
}

application::~application()
{
	for (auto& account : accounts)
	{
		delete account;
	}
}

bool application::is_user_logged_in() const
{
	return current_user_ != nullptr;
}

bool application::is_account_logged_in() const
{
	return current_account_ != nullptr;
}

account* application::get_current_account() const
{
	return current_account_;
}

user* application::get_current_user() const
{
	return current_user_;
}

store& application::get_store()
{
	return store_;
}

bool application::login_account(const std::string& email, const std::string& password)
{
	// TODO: This currently always logs you in as the first account
	current_account_ = accounts[0];

	return true;
}

bool application::login_user(const std::string& username, const std::string& password)
{
	// TODO: This currently always logs you in as the first user
	current_user_ = current_account_->users[0];

	return true;
}

void application::logout_user()
{
	current_user_ = nullptr;
}
