#include "Menu.h"

#include <utility>

#include "Utils.h"

menu::menu(std::string title, application* app) : app_(app), title_(std::move(title))
{
}

void menu::paint()
{
	bool ready_to_go_back = false;

	while (!ready_to_go_back)
	{
		header();
		output_options();
		line();
		option('B', "Back");
		footer();

		const char choice = utils::get_char_from_user();

		if (choice == 'B')
		{
			ready_to_go_back = true;
		}
		else
		{
			ready_to_go_back = handle_choice(choice);
		}
	}
}

void menu::line()
{
	std::cout << '\n';
}

void menu::line(const std::string& text)
{
	std::cout << "  " << text << "\n";
}

void menu::option(const char id, const std::string& option)
{
	std::cout << "  " << id << ") " << option << '\n';
}

void menu::option(const int id, const std::string& option) const
{
	// shift the integer value up to the correct position in the ascii table
	const char ascii = id + '0';
	this->option(ascii, option);
}

std::string menu::question(const std::string& question)
{
	std::cout << "  " << question << ": ";
	return utils::get_line_from_user();
}

void menu::blocking_message(const std::string& message)
{
	std::cout << "  " << message;
	utils::get_line_from_user();
}

void menu::header() const
{
#if defined _WIN32 || defined _WIN64
	// we are running on windows so use CLS to clear the screen
	system("CLS");
#else
	// we are running on mac or linux so use CLEAR to clear the screen
	system("CLEAR");
#endif

	std::cout << '\n';
	std::cout << "  -= " << utils::string_to_upper(title_) << " =-  \n";
	std::cout << '\n';
}

void menu::footer()
{
	std::cout << '\n';
	std::cout << '\n';
	std::cout << "  >>> ";
}
