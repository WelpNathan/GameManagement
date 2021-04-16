#pragma once
#include "Menu.h"
#include "StoreMenu.h"
#include "Utils.h"
#include "User.h"
#include "Account.h"




class LoginMenu: public Menu
{
	public:
		LoginMenu(const std::string& title, Application* app);
		void OutputOptions() final;
		bool HandleChoice(char choice) final;
		char userList(account* account);
		
	private:


};

