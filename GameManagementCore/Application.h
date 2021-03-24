#pragma once

#include "Account.h"
#include "User.h"
#include "Store.h"

class application
{
public:
	application();
	~application();

	bool is_account_logged_in() const;
	bool is_user_logged_in() const;
	account* get_current_account() const;
	user* get_current_user() const;

	store& get_store();

	bool login_account(const std::string& email, const std::string& password);
	bool login_user(const std::string& username, const std::string& password);
	void logout_user();

	account* accounts[1] = {}; // TODO: this needs changing to a dynamic collection
private:
	store store_;
	account* current_account_;
	user* current_user_;
};
