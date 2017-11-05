#include "../common.cpp"
#define STARTINGYEAR 1901
#define ENDINGYEAR 2000

using namespace std;

void incrementWeekDay();
void incrementMonth();
void incrementYear();

int currentYear = STARTINGYEAR;
int currentMonth = 0;
int currentWeekDay = 1;

int main()
{
	int numberOfSundays = 0;
	
	while (currentYear <= ENDINGYEAR)
	{
		incrementMonth();
		
		if (currentWeekDay == 6)
			numberOfSundays++;
	}
	
	cout << "There are " << numberOfSundays << " number of Sundays from 1900 to 2000" << endl;
		
	return 0;
}

void incrementWeekDay()
{
	currentWeekDay++;
	
	if (currentWeekDay == 7)
		currentWeekDay = 0;
}

void incrementMonth()
{
	int numberOfDays = 0;
	
	switch (currentMonth)
	{
		case 0:
			numberOfDays = 31;
			break;
		case 1:
			if (currentYear % 400 == 0 || (currentYear % 4 == 0 && currentYear % 100 != 0))
				numberOfDays = 29;
			else
				numberOfDays = 28;
			break;
		case 2:
			numberOfDays = 31;
			break;
		case 3:
			numberOfDays = 30;
			break;
		case 4:
			numberOfDays = 31;
			break;
		case 5:
			numberOfDays = 30;
			break;
		case 6:
			numberOfDays = 31;
			break;
		case 7:
			numberOfDays = 31;
			break;
		case 8:
			numberOfDays = 30;
			break;
		case 9:
			numberOfDays = 31;
			break;
		case 10:
			numberOfDays = 30;
			break;
		case 11:
			numberOfDays = 31;
			break;
	}
	
	for (int i = 0; i < numberOfDays; i++)
		incrementWeekDay();
	
	currentMonth++;
	
	if (currentMonth == 12)
	{
		currentMonth = 0;
		incrementYear();
	}
}

void incrementYear()
{
	currentYear++;
}