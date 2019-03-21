#include "ConstantsAndGenFuncs.h"
#include "Date.h"

Date::Date(int inDay, int inMonth, int inYear)
{
	day = inDay;
	month = inMonth;
	year = inYear;
}

void Date::showDate() const
{
	if (day < 10)
		cout << "0";
	cout << day <<"/";
	if(month<10)
		cout << "0";
	cout << month <<"/";
	cout << year << endl;
}

