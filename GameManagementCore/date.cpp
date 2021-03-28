#include "date.h"
#include <string>

date::date() {
	 day = 1, month = 1, year = 1900;
	//default
};

date::date(std::string inputDate) {
	int Day, Month, Year;

	splitDateString(inputDate);

	day = Day;
	month = Month;
	year = Year;

};


int splitDateString(std::string inputDate){
	//places 0-3 = year
	int a = inputDate[0] * 1000;
	int b = inputDate[1] * 100;
	int c = inputDate[2] * 10;
	int d = inputDate[3];

	int Year = a + b + c + d;

	//places 5 and 6 = month

	int e = inputDate[5] * 10;
	int f = inputDate[6];
	int Month = e + f;
	//places 8 and 9 = day

	int g = inputDate[8] * 10;
	int h = inputDate[9];
	int Day = g + h;

	return (Year, Month, Day);

}