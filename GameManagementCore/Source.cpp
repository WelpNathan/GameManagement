#include <iostream>
#include <string>
#include "Application.h"
#include "Account.h"
#include "User.h"
#include "MainMenu.h"
#include "Player.h"
#include "Admin.h"
#include "Utils.h"

// TODO: Remove from global scope once menu system is integrated
Application app;
//MainMenu("MAIN MENU", &app);

void create_hardcoded_test_data()
{
	// Setup store with some games
	auto &store_games = app.GetStore().games;
	store_games.addInFront(new game("The Witness", "Explore a nice island and solve puzzles.", 2999, 5));
	store_games.addInFront(new game("Braid", "A time twisting puzzle game.", 499, 15));
	store_games.addInFront(new game("Factorio", "Build a complicated factory in space.", 1599, 12));
	store_games.addInFront(new game("LIMBO", "Watch out for that spider.", 299, 12));
	store_games.addInFront(new game("INSIDE", "What are those scientists even doing?!", 1299, 15));
	store_games.addInFront(new game("Portal 2", "Play around with physics. Shoot the moon.", 1999, 15));
	store_games.addInFront(new game("Half Life 3", "It's never coming out.", 5999, 18));
	store_games.addInFront(new game("NUVAVULT", "A game where 2D and 3D collide.", 299, 18));
	store_games.addInFront(new game("Path", "Draw nice shapes between 2 big dots.", 299, 15));

	// Create some users
	player* u1 = new admin("Alice", "password", "2018-06-16");
	auto* u2 = new player("Bob", "password", "2018-09-19");
	auto* u3 = new player("Charlie", "password", "2018-09-24");

	// With some games in their library
	u1->library.addAtEnd(new library_item("2018-06-17", store_games[7]));
	u1->library.addAtEnd(new library_item("2018-06-18", store_games[1]));

	u2->library.addAtEnd(new library_item("2018-09-19", store_games[2]));
	u2->library.addAtEnd(new library_item("2018-09-19", store_games[3]));

	u3->library.addAtEnd(new library_item("2018-09-24", store_games[3]));
	u3->library.addAtEnd(new library_item("2018-09-30", store_games[6]));

	// Make an account and attach the users
	//app.accounts.addInFront(new account("alice@shu.com", "password", "2018-06-16"));
	app.accounts[0]->users.addAtEnd(u1);
	app.accounts[0]->users.addAtEnd(u2);
	app.accounts[0]->users.addAtEnd(u3);

	// TODO: We need a login menu for accounts, for now we log in the only account
	app.LoginAccount("alice@shu.ac.uk", "password");
}

char show_main_menu_and_get_user_choice()
{
	system("CLS");
	std::cout << "                    \n";
	std::cout << "  -= GAME LIBRARY =-\n";
	std::cout << "                    \n";
	std::cout << "  S) Browse Store   \n";

	if (app.IsUserLoggedIn())
	{
		std::cout << "  L) Logout of " << app.GetCurrentUser()->get_username() << "\n";
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

	return utils::GetCharFromUser();
}

char show_store_menu_and_get_user_choice()
{
	system("CLS");
	std::cout << "                    \n";
	std::cout << "  -= STORE =-       \n";
	std::cout << "                    \n";

	auto &game_store = app.GetStore().games;

	for (auto i = 0; i < game_store.length(); i++)
	{
		std::cout << "  " << (i + 1) << ") " << game_store[i]->get_name() << "\n";
	}

	// TODO: Implement search store option

	// Output rest of menu
	std::cout << "                    \n";
	std::cout << "  B) Back           \n";
	std::cout << "                    \n";
	std::cout << "                    \n";
	std::cout << "  >>> ";

	return utils::GetCharFromUser();
}

char show_login_user_menu_and_get_user_choice(account* account)
{
	system("CLS");
	std::cout << "                    \n";
	std::cout << "  -= LOGIN =-       \n";
	std::cout << "                    \n";

	for (auto i = 0; i < account->users.length(); i++)
	{
		std::cout << "  " << (i + 1) << ") " << account->users[i]->get_username() << "\n";
	}

	// Output rest of menu
	std::cout << "                    \n";
	std::cout << "  B) Back           \n";
	std::cout << "                    \n";
	std::cout << "                    \n";
	std::cout << "  >>> ";

	return utils::GetCharFromUser();
}

char show_game_menu_and_get_user_choice(game* game)
{
	system("CLS");
	std::cout << "                                  \n";
	std::cout << "  -= " << game->get_name() << " =- \n";
	std::cout << "                                  \n";
	std::cout << "  " << game->get_description() << "\n";
	std::cout << "                                  \n";

	if (app.IsUserLoggedIn())
	{
		std::cout << "  P) Purchase for " << game->get_cost() / 100.0f << "\n";
		std::cout << "                                                      \n";
	}

	std::cout << "  B) Back                   \n";
	std::cout << "                            \n";
	std::cout << "                            \n";
	std::cout << "  >>> ";

	return utils::GetCharFromUser();
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
				if (app.IsUserLoggedIn())
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
		const int choice = show_store_menu_and_get_user_choice();

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
					game_menu(app.GetStore().games[index]);
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
		const int choice = show_login_user_menu_and_get_user_choice(app.GetCurrentAccount());

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
					auto username = app.GetCurrentAccount()->users[index]->get_username();

					std::cout << "  Enter password for " << username << ": ";
					if (app.LoginUser(username, utils::GetCharFromUser()))
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
				if (app.IsUserLoggedIn())
				{
					app.LogoutUser();
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
