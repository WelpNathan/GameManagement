#include <iostream>
#include <string>
#include "Application.h"
#include "Account.h"
#include "User.h"
#include "Player.h"
#include "Admin.h"
#include "Utils.h"

// TODO: Remove from global scope once menu system is integrated
application app;

void create_hardcoded_test_data()
{
	// Setup store with some games
	app.get_store().games[0] = new game("The Witness", "Explore a nice island and solve puzzles.", 2999, 5);
	app.get_store().games[1] = new game("Braid", "A time twisting puzzle game.", 499, 15);
	app.get_store().games[2] = new game("Factorio", "Build a complicated factory in space.", 1599, 12);
	app.get_store().games[3] = new game("LIMBO", "Watch out for that spider.", 299, 12);
	app.get_store().games[4] = new game("INSIDE", "What are those scientists even doing?!", 1299, 15);
	app.get_store().games[5] = new game("Portal 2", "Play around with physics. Shoot the moon.", 1999, 15);
	app.get_store().games[6] = new game("Half Life 3", "It's never coming out.", 5999, 18);
	app.get_store().games[7] = new game("NUVAVULT", "A game where 2D and 3D collide.", 299, 18);
	app.get_store().games[8] = new game("Path", "Draw nice shapes between 2 big dots.", 299, 15);

	// Create some users
	player* u1 = new admin("Alice", "password", "2018-06-16");
	auto* u2 = new player("Bob", "password", "2018-09-19");
	auto* u3 = new player("Charlie", "password", "2018-09-24");

	// With some games in their library
	u1->library[0] = new library_item("2018-06-17", app.get_store().games[7]);
	u1->library[1] = new library_item("2018-06-18", app.get_store().games[1]);
	u2->library[0] = new library_item("2018-09-19", app.get_store().games[2]);
	u2->library[1] = new library_item("2018-09-19", app.get_store().games[3]);
	u3->library[0] = new library_item("2018-09-24", app.get_store().games[3]);
	u3->library[1] = new library_item("2018-09-30", app.get_store().games[6]);

	// Make an account and attach the users
	app.accounts[0] = new account("alice@shu.com", "password", "2018-06-16");
	app.accounts[0]->users[0] = u1;
	app.accounts[0]->users[1] = u2;
	app.accounts[0]->users[2] = u3;

	// TODO: We need a login menu for accounts, for now we log in the only account
	app.login_account("alice@shu.ac.uk", "password");
}

char show_main_menu_and_get_user_choice()
{
	system("CLS");
	std::cout << "                    \n";
	std::cout << "  -= GAME LIBRARY =-\n";
	std::cout << "                    \n";
	std::cout << "  S) Browse Store   \n";

	if (app.is_user_logged_in())
	{
		std::cout << "  L) Logout of " << app.get_current_user()->get_username() << "\n";
		// TODO: User profile option
	}
	else
	{
		std::cout << "  L) Login      \n";
	}

	std::cout << "                    \n";
	std::cout << "  B) Exit           \n";
	std::cout << "                    \n";
	std::cout << "                    \n";
	std::cout << "  >>> ";

	return utils::get_char_from_user();
}

char showStoreMenuAndGetUserChoice()
{
	system("CLS");
	std::cout << "                    \n";
	std::cout << "  -= STORE =-       \n";
	std::cout << "                    \n";

	// Output game list
	for (auto i = 0; i < 9; i++) // TODO: Hardcoded, change when using List<T>
	{
		std::cout << "  " << (i + 1) << ") " << app.get_store().games[i]->get_name() << "\n";
	}

	// TODO: Implement search store option

	// Output rest of menu
	std::cout << "                    \n";
	std::cout << "  B) Back           \n";
	std::cout << "                    \n";
	std::cout << "                    \n";
	std::cout << "  >>> ";

	return utils::get_char_from_user();
}

char show_login_user_menu_and_get_user_choice(account* account)
{
	system("CLS");
	std::cout << "                    \n";
	std::cout << "  -= LOGIN =-       \n";
	std::cout << "                    \n";

	// Output user list
	for (auto i = 0; i < 3; i++) // TODO: Hardcoded, change when using List<T>
	{
		std::cout << "  " << (i + 1) << ") " << account->users[i]->get_username() << "\n";
	}

	// Output rest of menu
	std::cout << "                    \n";
	std::cout << "  B) Back           \n";
	std::cout << "                    \n";
	std::cout << "                    \n";
	std::cout << "  >>> ";

	return utils::get_char_from_user();
}

char show_game_menu_and_get_user_choice(game* game)
{
	system("CLS");
	std::cout << "                                  \n";
	std::cout << "  -= " << game->get_name() << " =- \n";
	std::cout << "                                  \n";
	std::cout << "  " << game->get_description() << "\n";
	std::cout << "                                  \n";

	if (app.is_user_logged_in())
	{
		std::cout << "  P) Purchase for " << game->get_cost() / 100.0f << "\n";
		std::cout << "                                                      \n";
	}

	std::cout << "  B) Back                   \n";
	std::cout << "                            \n";
	std::cout << "                            \n";
	std::cout << "  >>> ";

	return utils::get_char_from_user();
}

void game_menu(game* game)
{
	auto ready_to_go_back = false;

	while (ready_to_go_back == false)
	{
		const int choice = show_game_menu_and_get_user_choice(game);

		switch (choice)
		{
		case 'P':
			{
				if (app.is_user_logged_in())
				{
					// TODO: Implement buying from the store
				}
			}
			break;
		case 'B':
			{
				ready_to_go_back = true;
			}
			break;
		default: ;
		}
	}
}

void store_menu()
{
	auto ready_to_go_back = false;

	while (ready_to_go_back == false)
	{
		const int choice = showStoreMenuAndGetUserChoice();

		switch (choice)
		{
		case 'B':
			{
				ready_to_go_back = true;
			}
			break;
		default:
			{
				const auto index = choice - '1';

				if (index >= 0 && index < 9) // TODO: Hardcoded numbers, change when using List<T>
				{
					game_menu(app.get_store().games[index]);
				}
			}
			break;
		}
	}
}

void login_user_menu()
{
	auto ready_to_go_back = false;

	while (ready_to_go_back == false)
	{
		const int choice = show_login_user_menu_and_get_user_choice(app.get_current_account());

		switch (choice)
		{
		case 'B':
			{
				ready_to_go_back = true;
			}
			break;
		default:
			{
				const auto index = choice - '1';

				if (index >= 0 && index < 3) // TODO: Hardcoded numbers, change when using List<T>
				{
					auto username = app.get_current_account()->users[index]->get_username();

					std::cout << "  Enter password for " << username << ": ";
					if (app.login_user(username, utils::get_line_from_user()))
					{
						ready_to_go_back = true;
					}
				}
			}
			break;
		}
	}
}

void main_menu()
{
	auto wants_to_exit = false;

	while (wants_to_exit == false)
	{
		const int choice = show_main_menu_and_get_user_choice();

		switch (choice)
		{
		case 'S':
			{
				store_menu();
			}
			break;
		case 'L':
			{
				if (app.is_user_logged_in())
				{
					app.logout_user();
				}
				else
				{
					login_user_menu();
				}
			}
			break;
		case 'B':
			{
				wants_to_exit = true;
			}
			break;
		default: ;
		}
	}
}

void main()
{
	// TODO: Remove call to dummy data, instead use Load and Save
	create_hardcoded_test_data();

	// TODO: app.Load();

	main_menu(); // TODO: replace with proper menu system

	// TODO: app.Save();
}
