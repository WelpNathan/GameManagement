#pragma once
using namespace std;
#include <string>

class date
{

	
public:
	int day, month, year;

	//Constructors
	date(string inputDate);
	date();
	
	
private:

	int splitDateString(std::string inputDate);
};

