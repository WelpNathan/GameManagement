#pragma once

class Application
{
	public:
		Application();
		bool IsUserLoggedIn();
		void LogIn();
		void LogOut();
	private:
		bool userIsLoggedIn = true;

};