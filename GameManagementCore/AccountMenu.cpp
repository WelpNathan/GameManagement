#include "AccountMenu.h"

accountMenu::accountMenu(const std::string& title, Application* app) : Menu(title, app)
{
	Paint(); // required in constructor
}


void accountMenu::OutputOptions()
{

	//for (int i = 0; i < 3; i++) // TODO: Hardcoded, change when using List<T>
	//{
	//	std::cout << "  " << (i + 1) << ") " << account->users[i]->GetUsername()
	//		//<< "\n";
	//}


}



bool accountMenu::HandleChoice(char choice)
{

	return true;
}
