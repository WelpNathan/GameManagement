#include "Application.h"

Application::Application() : userIsLoggedIn(true)
{
}

void Application::LogOut()
{
	userIsLoggedIn = false;
}

void Application::LogIn()
{
	userIsLoggedIn = true;
}

bool Application::IsUserLoggedIn()
{
	return userIsLoggedIn;
}