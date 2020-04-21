#include <iostream>
#include <ctime>
#include <string>
#include <sstream> 
char timeArray[24];
int random;

using namespace std;


class base
{
	friend void randomizer();
	friend void SystemTimeAccess();

public:
	string seatsGender[43];
	string seatsName[44];
	string seatsDeparture[44];
	string seatsArrival[44];
	string seatsDate[44];
	int seatsTime[44];
	int seatsLugPrice[44];
	int seatsTotalPrice[44];
	int Time[4];

	base()
	{
		for (int i = 0; i < 4; i++)
		{
			Time[i] = 0;
		}
		for (int i = 0; i < 44; i++)
		{
			seatsGender[i] = "-";
			seatsArrival[i] = " ";
			seatsDeparture[i] = " ";
			seatsName[i] = " ";
			seatsDate[i] = " ";
			seatsTime[i] = 0;
			seatsLugPrice[i] = 0;
			seatsTotalPrice[i] = 0;
		}
		seatsGender[1] = "H";
	}

	void interface ()
	{
		cout << "\n      Bus Current Booking Status" << endl;
		cout << "        ------------------------\n\n";
		int z = 1;
		cout << "\tC1  C2  C3  C4  C5  C6\n";
		for (int i = 1; i <= 37; i += 4)
		{
			cout << "R" << z << "\t";
			z++;
			for (int j = 0; j <= 3; j++)
			{
				cout << seatsGender[i + j] << "   "; 
				if (j == 1 && i != 37)
					cout << "\t";
				if (i == 37 && j == 3)
					cout << seatsGender[41] << "   " << seatsGender[42];

			}
			cout << endl;
		}
		cout << endl;
	}

	void systemTime()
	{
		Time[0] = timeArray[11] - '0';
		Time[1] = timeArray[12] - '0';
		Time[2] = timeArray[14] - '0';
		Time[3] = timeArray[15] - '0';
	}

};