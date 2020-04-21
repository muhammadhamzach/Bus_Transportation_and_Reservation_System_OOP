#include <iostream>
#include <string>
#include <fstream>
#include <sstream> 
using namespace std;

class ticketing : public infoCollector
{
public:
	int family, lugprice, ticketPrice, totalPrice;


	ticketing()
	{
		family = lugprice = ticketPrice = totalPrice = 0;
	}

	void seatSelector()
	{
		if (reservation == "Family")
			multipleSeatsSetter();
		if (reservation == "Single")
			singleSeatSetter();
	}

	void singleSeatSetter()
	{
		interface ();
		int z = 0;

		while (z <= 0)
		{
			do
			{
				seater();
			} while (seatNo > 42 || seatNo < 2);
			int x = seatChecker(0);
			if (x == 0)
				z = 1;
		};


		if (seatgender == "Male")
			seatsGender[seatNo] = "M";
		if (seatgender == "Female")
			seatsGender[seatNo] = "F";
		pricing(0);

		seatsName[seatNo] = name;
		seatsArrival[seatNo] = arrival;
		seatsDeparture[seatNo] = depart;
		seatsLugPrice[seatNo] = lugprice;
		seatsTotalPrice[seatNo] = totalPrice;
		ticketPrinting();
		interface();
	}

	void multipleSeatsSetter()
	{
		int males = 0, females = 0, a = 0;
		int count1=0;
		do
		{
			do
			{
				count1 = 0;
				string Select = "";
				while (true)
				{
					cout << endl << "Please Enter The Total Number Of Multiple Tickets: ";
					cin >> Select;
					stringstream myStream(Select);
					if (myStream >> family)
						break;
				}

				for (int i = 2; i < 43; i++)
				{
					if (seatsGender[i] == "-")
						count1++;
				}

			} while (family > count1);

			do
			{
				string Select = "";
				while (true)
				{
					cout << endl << "How Many Total Males Are There In Group: ";
					cin >> Select;
					stringstream myStream(Select);
					if (myStream >> males)
						break;
				}
			} while (males > family);
			females = family - males;

			int z = 0, y = 0, i = 0;
			int m = males;
			int f = females;
			if (males > 0)
			{
				for (i = 3; i < 43; i++)
				{
					if (seatsGender[i] == "-")
					{
						int x = i % 2;
						if ((x == 0 && seatsGender[i - 1] != "F" && seatsGender[i - 1] != "FF") || (x == 1 && seatsGender[i + 1] != "F" && seatsGender[i + 1] != "FF"))
						{
				//			if (z == 0)
					//			s = i;
							z++;
							m--;
							if (m == 0)
								break;
						}
					}
				}
			}
			if (females > 0)
			{
				for (int j = i + 1; j < 43; j++)
				{
					if (seatsGender[j] == "-")
					{
						int x = j % 2;
						if ((x == 0 && seatsGender[j - 1] != "M" && seatsGender[j - 1] != "MF") || (x == 1 && seatsGender[j + 1] != "M" && seatsGender[j + 1] != "MF"))
						{
							z++;
							f--;
							if (f == 0)
								break;
						}
					}
				}
			}
			if (z == family)
				break;
			if (z < family)
			{
				cout << "Seats Available are less then required. Input Data Again" << endl;
				count1 = 0;
			}
		} while (count1 < family);


		interface();
		a = 1;
		do
		{
			seater();

		} while (seatNo > 43 - family || seatNo < 2);

		if (males == 0 || females == 0)
		{
			if (males == 0)
				seatgender = "Female";
			if (females == 0)
				seatgender = "Male";

			for (int i = 1; i <= family; i++)
			{
				int z = 0;
				while (z <= 0)
				{
					int x = seatChecker(1);
					if (x == 0)
					{
						if (seatgender == "Male")
							seatsGender[seatNo] = "M";
						if (seatgender == "Female")
							seatsGender[seatNo] = "F";

						seatsName[seatNo] = name;
						seatsArrival[seatNo] = arrival;
						seatsDeparture[seatNo] = depart;
						seatsLugPrice[seatNo] = lugprice;
						pricing(1);
						seatsTotalPrice[seatNo] = totalPrice;
						seatNo++;
						z = 1;
					}
					else
						seatNo++;
				}

			}
			pricing(0);
			ticketPrinting();
			interface();
		}
		else
		{
			for (int i = 1; i <= males; i++)
			{
				int z = 0;
				while (z <= 0)
				{

					seatgender = "familyM";
					int x = seatChecker(1);
					if (x == 0)
					{
						seatsGender[seatNo] = "mf";
						seatsName[seatNo] = name;
						seatsArrival[seatNo] = arrival;
						seatsDeparture[seatNo] = depart;
						seatsLugPrice[seatNo] = lugprice;
						pricing(1);
						ticketPrinting();
						seatsTotalPrice[seatNo] = totalPrice;
						seatNo++;
						z = 1;
					}
					else
						seatNo++;
				}
			}
			for (int i = 1; i <= females; i++)
			{
				int z = 0;
				while (z <= 0)
				{

					seatgender = "familyF";
					int x = seatChecker(1);
					if (x == 0)
					{
						seatsGender[seatNo] = "ff";
						seatsName[seatNo] = name;
						seatsArrival[seatNo] = arrival;
						seatsDeparture[seatNo] = depart;
						seatsLugPrice[seatNo] = lugprice;
						pricing(1);
						ticketPrinting();
						seatsTotalPrice[seatNo] = totalPrice;
						seatNo++;
						z = 1;
					}
					else
						seatNo++;
				}
			}
			for (int i = 1; i < 43; i++)
			{
				if (seatsGender[i] == "mf")
					seatsGender[i] = "MF";
				if (seatsGender[i] == "ff")
					seatsGender[i] = "FF";
			}
			pricing(0);

			interface();
		}
	}

	int seatChecker(int z)
	{
		int divider = seatNo % 2;  //remainder just a random integer number
		if (seatsGender[seatNo] == "F" || seatsGender[seatNo] == "M" || seatsGender[seatNo] == "MF" || seatsGender[seatNo] == "FF" || seatsGender[seatNo] == "H")
		{
			if (z == 0)
				cout << "This Seat is already occupied. Please Try Again.\n";
			return 1;
		}
		else if ((seatgender == "Male" || seatgender == "familyM") && seatsGender[seatNo - 1] == "H")
		{
			if (z == 0)
				cout << "You Cant Sit With A Hostess.\n";
			return 1;
		}
		else if (seatgender == "Male" && ((divider == 0 && (seatsGender[seatNo - 1] == "F" || seatsGender[seatNo - 1] == "FF")) || (divider == 1 && (seatsGender[seatNo + 1] == "F" || seatsGender[seatNo + 1] == "FF"))))
		{
			if (z == 0)
				cout << "This Seat Cannot Be Offered To You On The Basis Of A Adjacent Female Passenger.\n";
			return 1;
		}
		else if (seatgender == "Female" && ((divider == 0 && (seatsGender[seatNo - 1] == "M" || seatsGender[seatNo - 1] == "MF")) || (divider == 1 && (seatsGender[seatNo + 1] == "M" || seatsGender[seatNo + 1] == "MF"))))
		{
			if (z == 0)
				cout << "This Seat Cannot Be Offered To You On The Basis Of A Adjacent Male Passenger.\n";
			return 1;
		}
		else if (seatgender == "familyM" && ((divider == 0 && (seatsGender[seatNo - 1] == "F" || seatsGender[seatNo - 1] == "FF")) || (divider == 1 && (seatsGender[seatNo + 1] == "F" || seatsGender[seatNo + 1] == "FF"))))
			return 1;
		else if (seatgender == "familyF" && ((divider == 0 && (seatsGender[seatNo - 1] == "M" || seatsGender[seatNo - 1] == "MF")) || (divider == 1 && (seatsGender[seatNo + 1] == "M" || seatsGender[seatNo + 1] == "MF"))))
			return 1;
		else if (seatNo > 37 && seatNo < 42)
		{
			if (seatgender == "Male" && ((seatsGender[seatNo - 1] == "F" || seatsGender[seatNo - 1] == "FF") || (seatsGender[seatNo + 1] == "F" || seatsGender[seatNo + 1] == "FF")))
			{
				if (z == 0)
					cout << "This Seat Cannot Be Offered To You On The Basis Of A Adjacent Female Passenger.\n";
				return 1;
			}

			else if (seatgender == "Female" && (((seatsGender[seatNo - 1] == "M" || seatsGender[seatNo - 1] == "MF")) || ((seatsGender[seatNo + 1] == "M" || seatsGender[seatNo + 1] == "MF"))))
			{
				if (z == 0)
					cout << "This Seat Cannot Be Offered To You On The Basis Of A Adjacent Male Passenger.\n";
				return 1;
			}
			else if (seatgender == "familyM" && ((seatsGender[seatNo - 1] == "F" || seatsGender[seatNo - 1] == "FF") || (seatsGender[seatNo + 1] == "F" || seatsGender[seatNo + 1] == "FF")))
				return 1;
			else if (seatgender == "familyF" && ((seatsGender[seatNo - 1] == "M" || seatsGender[seatNo - 1] == "MF") || (seatsGender[seatNo + 1] == "M" || seatsGender[seatNo + 1] == "MF")))
				return 1;
			else
				return 0;
		}
		else
			return 0;
	}

	void Luggage()
	{
		allowedLuggage = 20;

		string Select = "";
		while (true)
		{
			cout << endl << "Enter The Luggage Carried By The Passenge(kg): ";
			cin >> Select;
			stringstream myStream(Select);
			if (myStream >> luggage)
				break;
		}
		if (luggage > allowedLuggage)
			lugprice = (luggage - allowedLuggage) * 20;
		else
			lugprice = 0;
		totalPrice += lugprice;
		seatsLugPrice[seatNo] = lugprice;
		seatsTotalPrice[seatNo] = totalPrice;
		pricing(0);
	}

	void pricing(int x)
	{
		if (x == 0)
		{
			cout << "\nPRICING:-\n";
			cout << "-------\n";
		}
		if ((depart == "RWP" && arrival == "RYK") || (depart == "RYK" && arrival == "RWP"))
			ticketPrice = 1800;
		if ((depart == "RWP" && arrival == "LHR") || (depart == "LHR" && arrival == "RWP"))
			ticketPrice = 1300;
		if ((depart == "LHR" && arrival == "RYK") || (depart == "RYK" && arrival == "LHR"))
			ticketPrice = 1500;

		if (reservation == "Single")
			totalPrice = ticketPrice + lugprice;
		if (reservation == "Family")
			totalPrice = (ticketPrice * family) + lugprice;
		if (x == 0)
		{
			cout << "The cost of your ticket/tickets is:\t" << ticketPrice << endl;
			cout << "The cost of luggage is:\t" << lugprice << endl;
			cout << "---------------------------------" << endl;
			cout << "The total price of ticket(s) is:\t" << totalPrice << endl;
		}
	}

	void ticketPrinting()
	{
		SystemTimeAccess();
		fstream ticket;
		ticket.open("Ticket.txt", ios::app);
		ticket.setf(ios::left);

		for (int i = 1; i < 90; i++)
			ticket << "-";

		ticket << endl;
		ticket << "-\t\t\t\t\tHOLMES EXPRESS\t\t\t\t\t-" << endl;
		ticket << "-\tPassenger Name: " << name << "\t\t\t\t\t\t\t\t-" << endl;
		ticket << "-\tBus Time: " << time << "\t\t\t\t\t\t\t\t\t-" << endl;

		if (date == "Current")
			ticket << "-\tDate: " << timeArray[8] << timeArray[9] << "/" << timeArray[4] << timeArray[5] << timeArray[6] << "/" << timeArray[20] << timeArray[21] << timeArray[22] << timeArray[23] << "\t\t\t\t\t\t\t\t-" << endl;
		if (date == "Advanced")
		{
			int x = timeArray[8] - '0';
			int y = timeArray[9] - '0';
			int z = (x * 10) + y + 1;
			if (z == 32)
			{
				z = 1;
				timeArray[4] = 'J'; timeArray[5] = 'U'; timeArray[6] = 'N';
				ticket << "-\tDate: " << z << "/" << timeArray[4] << timeArray[5] << timeArray[6] << "/" << timeArray[20] << timeArray[21] << timeArray[22] << timeArray[23] << "\t\t\t\t\t\t\t\t-" << endl;
			}
			else
				ticket << "-\tDate: " << z << "/" << timeArray[4] << timeArray[5] << timeArray[6] << "/" << timeArray[20] << timeArray[21] << timeArray[22] << timeArray[23] << "\t\t\t\t\t\t\t\t-" << endl;
		}
		ticket << "-\tDeparture: " << depart << "\t\t\t\t\t\t\t\t\t-" << endl;
		ticket << "-\tArrival: " << arrival << "\t\t\t\t\t\t\t\t\t-" << endl;
		ticket << "-\tSeat No: " << seatNo << "\t\t\t\t\t\t\t\t\t-" << endl;
		ticket << "-\tTicket Price: " << ticketPrice << "\t\t\t\t\t\t\t\t-" << endl;
		ticket << "-\tIssue Date\Time: " << timeArray[8] << timeArray[9] << "/" << timeArray[4] << timeArray[5] << timeArray[6] << "/" << timeArray[20] << timeArray[21] << timeArray[22] << timeArray[23] << " " << timeArray[11] << timeArray[12] << timeArray[13] << timeArray[14] << timeArray[15] << timeArray[16] << timeArray[17] << timeArray[18] << "\t\t\t\t\t\t-" << endl;

		for (int i = 1; i < 90; i++)
			ticket << "-";

		ticket << endl;
		ticket.close();
	}

	void BusDataPrinting()
	{
		SystemTimeAccess();
		systemTime();
		fstream Bus;
		Bus.open("BusData.txt", ios::app);
		Bus.setf(ios::left);

		for (int i = 1; i < 90; i++)
			Bus << "-";

		Bus << endl;
		Bus << "-\t\t\t\t\tHOLMES EXPRESS\t\t\t\t\t-" << endl;
		for (int i = 1; i < 90; i++)
			Bus << "-";
		Bus << endl;
		Bus << "-\t\t\t\t\tDeparture: " << depart << "\t\t\t\t\t-" << endl;
		Bus << "-\t\t\t\t\tArrival: " << arrival << "\t\t\t\t\t-" << endl;

		if (date == "Current")
			Bus << "-\t\t\t\t\tDate: " << timeArray[8] << timeArray[9] << "/" << timeArray[4] << timeArray[5] << timeArray[6] << "/" << timeArray[20] << timeArray[21] << timeArray[22] << timeArray[23] << "\t\t\t\t-" << endl;
		if (date == "Advanced")
		{
			int x = timeArray[8] - '0';
			int y = timeArray[9] - '0';
			int z = (x * 10) + y + 1;
			if (z == 32)
			{
				z = 1;
				timeArray[4] = 'J'; timeArray[5] = 'U'; timeArray[6] = 'N';
				Bus << "-\tDate: " << z << "/" << timeArray[4] << timeArray[5] << timeArray[6] << "/" << timeArray[20] << timeArray[21] << timeArray[22] << timeArray[23] << "\t\t\t\t\t\t\t\t-" << endl;
			}
			else
				Bus << "-\tDate: " << z << "/" << timeArray[4] << timeArray[5] << timeArray[6] << "/" << timeArray[20] << timeArray[21] << timeArray[22] << timeArray[23] << "\t\t\t\t\t\t\t\t-" << endl;
		}
		Bus << "-\t\t\t\t\tPrice: " << ticketPrice << "\t\t\t\t\t-" << endl;
		for (int i = 1; i < 90; i++)
			Bus << "-";
		Bus << endl;
		Bus << "-\tSeat No\t\tPassenger Name\t\tGender\t\tTotal Price Paid\t-" << endl;
		for (int i = 1; i < 90; i++)
			Bus << "-";
		Bus << endl;
		for (int i = 2; i < 43; i++)
		{
			if (seatsTotalPrice[i] != 0)
				Bus << "-\t   " << i << "\t\t " << seatsName[i] << "\t\t  " << seatsGender[i] << "\t\t\t" << seatsTotalPrice[i] << "\t\t-" << endl;
			else
				Bus << "-\t   " << i << "\t\t\t\t\t\t\t\t" << seatsTotalPrice[i] << "\t\t-" << endl;
		}
		Bus << "-\t\tIssue Date\Time: " << timeArray[8] << timeArray[9] << "/" << timeArray[4] << timeArray[5] << timeArray[6] << "/" << timeArray[20] << timeArray[21] << timeArray[22] << timeArray[23] << " " << timeArray[11] << timeArray[12] << timeArray[13] << timeArray[14] << timeArray[15] << timeArray[16] << timeArray[17] << timeArray[18] << "\t\t\t\t\t-" << endl;

		for (int i = 1; i < 90; i++)
			Bus << "-";

		Bus << endl;
		Bus.close();
	}

	void searchQueryPrinting()
	{
		searchQuery();
		SystemTimeAccess();
		fstream search;
		search.open("SearchData.txt", ios::app);
		search.setf(ios::left);

		for (int i = 1; i < 70; i++)
			search << "-";
		search << endl;
		search << "\t\tSEARCH QUERY" << endl;
		search << "\tPassenger Name: " << seatsName[seatNo] << endl;
		search << "\tDeparture Terminal: " << depart << endl;
		search << "\tArrival Terminal: " << arrival << endl;
		search << "\tDeparture Timing: " << time << endl;
		if (date == "Current")
			search << "\tDate: " << timeArray[8] << timeArray[9] << "/" << timeArray[4] << timeArray[5] << timeArray[6] << "/" << timeArray[20] << timeArray[21] << timeArray[22] << timeArray[23] << endl;
		if (date == "Advanced")
		{
			int x = timeArray[8] - '0';
			int y = timeArray[9] - '0';
			int z = (x * 10) + y + 1;
			if (z == 32)
			{
				z = 1;
				timeArray[4] = 'J'; timeArray[5] = 'U'; timeArray[6] = 'N';
				search << "-\tDate: " << z << "/" << timeArray[4] << timeArray[5] << timeArray[6] << "/" << timeArray[20] << timeArray[21] << timeArray[22] << timeArray[23] << "\t\t\t\t\t\t\t\t-" << endl;
			}
			else
				search << "-\tDate: " << z << "/" << timeArray[4] << timeArray[5] << timeArray[6] << "/" << timeArray[20] << timeArray[21] << timeArray[22] << timeArray[23] << "\t\t\t\t\t\t\t\t-" << endl;
		}
		search << "\tSeat No: " << seatNo << endl;
		search << "\tGender: " << seatsGender[seatNo] << endl;
		search << "\tLuggage Price: " << seatsLugPrice[seatNo] << endl;
		search << "\tTotal Cost Ticket: " << seatsTotalPrice[seatNo] << endl << endl;
		search << "\tSearch Date\Time: " << timeArray[8] << timeArray[9] << "/" << timeArray[4] << timeArray[5] << timeArray[6] << "/" << timeArray[20] << timeArray[21] << timeArray[22] << timeArray[23] << " " << timeArray[11] << timeArray[12] << timeArray[13] << timeArray[14] << timeArray[15] << timeArray[16] << timeArray[17] << timeArray[18] << "-" << endl;
		for (int i = 1; i < 70; i++)
			search << "-";
		search << endl;
	}

	void enroutetester()
	{
		systemTime();
		if (date == "Advanced")
			cout << "The Bus hasn't left" << endl;
		if (date == "Current")
		{
			int ST = (Time[0] * 1000) + (Time[1] * 100) + (Time[2] * 10) + (Time[3]);
			int T = stoi(time);
			if (T <= ST)
			{
				cout << "\nThe Bus ";
				if (depart == "RWP")
				{
					if (arrival == "LHR" && ((T == 0 && ST >= 400 && ST <= 800) || (T == 800 && ST >= 1200 && ST <= 1600) || (T == 1600 && ST >= 2000 && ST <= 2400)))
						cout << "has left RWP, and reached LHR Terminal." << endl;
					else if (arrival == "RYK" && ((T == 0 && ST >= 1400) || (T == 800 && ST >= 2200)))
						cout << "has left RWP, and reached RYK Terminal." << endl;
					else
						cout << "is en route." << endl;
				}
				if (depart == "LHR")
				{
					if (arrival == "RWP" && ((T == 0 && ST >= 400 && ST <= 1600) || (T == 800 && ST >= 1200 && ST <= 2400) || (T == 1600 && ST >= 2000 && ST <= 2400)))
						cout << "has left LHR, and reached RWP Terminal." << endl;
					else if (arrival == "RYK" && ((T == 400 && ST >= 1400 && ST <= 1600) || (T == 1200 && ST >= 2200 && ST <= 2400)))
						cout << "has left LHR, and reached RWP Terminal." << endl;
					else
						cout << "is en route." << endl;
				}
				if (depart == "RYK")
				{
					if (arrival == "RWP" && ((T == 0 && ST >= 1400 && ST <= 2400) || (T == 800 && ST >= 2200 && ST <= 2400)))
						cout << "has left RYK, and reached RWP Terminal." << endl;
					else if (arrival == "LHR" && ((T == 0 && ST >= 1000 && ST <= 1200) || (T == 800 && ST >= 1800 && ST <= 2000)))
						cout << "has left RYK, and reached LHR Terminal." << endl;
					else
						cout << "is en route." << endl;
				}
			}
			if (T > ST)
				cout << "The Bus hasn't left" << endl;
		}
	}

	void backInput()
	{
		string s = seatgender;
		for (int i = 0; i < 10; i++)
		{
			randomizer();
			seatNo = random;
			if (seatNo % 2 == 0)
				seatgender = "M";
			else
				seatgender = "F";
			int x = seatChecker(1);
			if (x == 0)
			{
				if (seatgender == "M") name = "Hassan";
				if (seatgender == "F")
				{
					if (seatNo % 2 == 0)
						name = "Misbah";
					if (seatNo % 2 == 1)
						name = "Rabiya Qaiser";
				}
				seatsGender[seatNo] = seatgender;
				seatsName[seatNo] = name;
				pricing(1);
				seatsTotalPrice[seatNo] = totalPrice;
			}
		}

		randomizer();
		seatNo = random;
		int M = 3; int F = 2;
		if (seatNo % 2 == 0)
		{
			seatgender = "M"; 
			name = "Hamza";
		}
		else
		{
			seatgender = "F";
			if (seatNo % 2 == 0)
				name = "Misbah";
			if (seatNo % 2 == 1)
				name = "Rabiya";
		}
		for (int i = 1; i <= M; i++)
		{
			int z = 0;
			while (z <= 0)
			{

				seatgender = "familyM";
				int x = seatChecker(1);
				if (x == 0)
				{

					seatsGender[seatNo] = "mf";
					seatsName[seatNo] = name;
					pricing(1);
					seatsTotalPrice[seatNo] = totalPrice;
					seatNo++;
					z = 1;
				}
				else
					seatNo++;
			}
		}
		for (int i = 1; i <= F; i++)
		{
			int z = 0;
			while (z <= 0)
			{

				seatgender = "familyF";
				int x = seatChecker(1);
				if (x == 0)
				{
					seatsGender[seatNo] = "ff";
					seatsName[seatNo] = name;
					pricing(1);
					seatsTotalPrice[seatNo] = totalPrice;
					seatNo++;
					z = 1;
				}
				else
					seatNo++;
			}
		}
		for (int i = 1; i < 43; i++)
		{
			if (seatsGender[i] == "mf")
				seatsGender[i] = "MF";
			if (seatsGender[i] == "ff")
				seatsGender[i] = "FF";
		}
		seatgender = s;
	}

};