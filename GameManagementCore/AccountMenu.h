#pragma once
#include "Menu.h"
#include "StoreMenu.h"
#include "account.h"
#include "Utils.h"



class accountMenu : public Menu
{
public:
	accountMenu(const std::string& title, Application* app);
	void OutputOptions() final;

	bool HandleChoice(char choice) final;

};

