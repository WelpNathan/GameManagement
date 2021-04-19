#include "Player.h"

player::player(const std::string& username, const std::string& password, const std::string& created, float credit_balance)
	: user(username, password, created, credit_balance)
{
}

player::~player()
{
	// TODO: implement deconstructor cleanup
	//for (auto& i : library)
	//{
	//	delete i;
	//}
}
