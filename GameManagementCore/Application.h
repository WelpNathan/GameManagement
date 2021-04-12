#pragma once

#include "Account.h"
#include "User.h"
#include "Store.h"

class Application
{
public:
	Application();
	~Application();

	bool IsAccountLoggedIn() const;
	bool IsUserLoggedIn() const;
	account* GetCurrentAccount() const;
	user* GetCurrentUser() const;

	store& GetStore();

	bool LoginAccount(const std::string& email, const std::string& password);
	bool LoginUser(const std::string& username, const std::string& password);
	void LogoutUser();

	account* accounts[1] = { }; // TODO: this needs changing to a dynamic collection

private:
	store store;
	account* currentAccount;
	user* currentUser;
};