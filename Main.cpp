#include <iostream>
#include <ctime>
#include <string>
#pragma warning(disable : 4996)
#include "base.h"
#include "Information.h"
#include "ticketing.h"
#include "terminalTicketing.h"
#include "Interface.h"
using namespace std;

void main()
{
	progInterface a;
	SystemTimeAccess();
	a.homeScreen();
}

void SystemTimeAccess()
{
	time_t now = time(0);
	char* dt = ctime(&now);
	for (int i = 0; i < 24; i++)
		timeArray[i] = dt[i];
}

void randomizer()
{
	srand((unsigned)time(0));
	random = (rand() % 35) + 1;
}

