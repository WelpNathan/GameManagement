#pragma once

#include "Menu.h"
#include <string>
#include <vector>
#include "Application.h"


class LoginMenu : public Menu
{
public:
	LoginMenu(const std::string& title, Application* app);
	void outputUsers();
	

private:
	bool correctPassword(string& accountPassword, string inputPassword);
	std::vector<std::string> registeredUsers = {"name1", "name2", "name3"}; 
	     // change names given here to usernames imported from text file.
	     // can also change from vector to list.
};

