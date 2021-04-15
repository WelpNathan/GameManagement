#include "Application.h"

Application::Application() : currentAccount(nullptr), currentUser(nullptr), userIsLoggedIn(true)
{
}

Application::~Application()
{
	for (int i = 0; i < 1; ++i)
	{
		delete accounts[i];
	}
}

bool Application::IsUserLoggedIn()
{
	return userIsLoggedIn;
}

bool Application::IsAccountLoggedIn() const
{
	return currentAccount != nullptr;
}


account* Application::GetCurrentAccount() const
{
	return currentAccount;
}

user* Application::GetCurrentUser() const
{
	return currentUser;
}

store& Application::GetStore()
{
	return store;
}

bool Application::LoginAccount(const std::string& email, const std::string& password)
{
	// TODO: This currently always logs you in as the first account
	currentAccount = accounts[0];

	return true;
}

bool Application::LoginUser(const std::string& username, const std::string& password)
{
	// TODO: This currently always logs you in as the first user
	//currentUser = currentAccount->users[0];

	return true;
}

void Application::LogoutUser()
{
	currentUser = nullptr;
}

void Application::LogOut()
{
	userIsLoggedIn = false;
}

void Application::LogIn()
{
	userIsLoggedIn = true;
}