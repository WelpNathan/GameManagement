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

	store* get_store() const;

	bool login_account(const std::string& email, const std::string& password);
	bool login_user(const std::string& username, const std::string& password);
	void logout_user();

	void log_in();
	void log_out();

	List<account*> accounts;

private:
	store* store_;
	account* current_account_;
	user* current_user_;
	bool user_is_logged_in_ = false;

	void setup_data();
};
