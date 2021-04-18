#pragma once

#include "Application.h"
#include "utils.h"

#include <iostream>
#include <string>

class menu
{
public:
	virtual ~menu() = default;
	menu(std::string title, application* app);

	void paint();

	// Use this function to output all the options specific to your menu
	virtual void output_options() = 0;

	// Use this function to handle the possible choices from your menu
	// Returning true means you are ready to go back to the previous menu
	// Returning false means you will stay on the same menu
	virtual bool handle_choice(char) = 0;

protected:
	application* app_; // each menu will store a pointer to the main application
	// this way menus can access all the data required

	static void line(); // output blank line
	static void line(const std::string& text); // output a message
	void option(int id, const std::string& option) const; // output menu option
	static void option(char id, const std::string& option); // output menu option
	static std::string question(const std::string& question); // output a question and return the user's input
	static void blocking_message(const std::string& message); // output message and wait for the user to press enter

private:
	std::string title_;

	void header() const;
	static void footer();
};
