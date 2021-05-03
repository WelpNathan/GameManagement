#include "Admin.h"

admin::admin(const std::string& username, const std::string& password, date* created, float credit_balance, int id)
	: player(username, password, created, credit_balance, id)
{
}

admin::~admin()
= default;
