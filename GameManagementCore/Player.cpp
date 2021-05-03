#include "Player.h"

player::player(const std::string& username, const std::string& password, date* created,
               float credit_balance, int id)
	: user(username, password, created, credit_balance, id)
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
