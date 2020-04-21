#include <iostream>
#include <ctime>
#include <sstream> 
#include <string>

using namespace std;

class infoCollector : public base
{
public:
	int seatNo, busNo, luggage, allowedLuggage, busTime;
	string seatgender, name, depart, arrival, reservation, time, date;
	int RC[11][7];

	infoCollector()
	{
		seatNo = busNo = luggage = allowedLuggage = busTime = 0;
		seatgender = name = depart = arrival = reservation = time = date = " ";
		for (int i = 0; i < 11; i++)
		for (int j = 0; j < 7; j++)
			RC[11][7] = 0;
	}

	void getter(int x)
	{
		if (x == 1)
		{
			cout << "Please Enter The Name: ";
			cin.get();
			getline(cin, name);


			cout << endl << "Please Enter The Gender: ";
			cin >> seatgender;
			genderSetter();
		}
		schedule();

		cout << endl << "Please Enter Booking Type (Current/Advance): ";
		cin >> date;
		departuretypeSetter();

		cout << endl << "Please Enter The Time Of Your Departure(HHMM): ";
		cin >> time;
		timeSetter();
		if (x == 1)
		{
			systemTime();
			timeCompatibility();
			if (busTime == 0)
			{
				cout << endl << "Do You Wish To Have A Family Reservation Or Single: ";
				cin >> reservation;
				reservationSetter();
			}
		}
	}

	void reservationSetter()
	{
		if (reservation == "Family" || reservation == "family" || reservation == "f" || reservation == "F")
			reservation = "Family";
		else if (reservation == "Single" || reservation == "single" || reservation == "s" || reservation == "S")
			reservation = "Single";
		else
			try
		{
			throw string("Invalid Input. \nDo You Wish To Have A Family Reservation Or Single: ");
		}
		catch (string x)
		{
			cout << x;
			cin >> reservation;
			reservationSetter();
		}
	}

	void genderSetter()
	{
		if (seatgender == "Male" || seatgender == "male" || seatgender == "m" || seatgender == "M")
			seatgender = "Male";
		else if (seatgender == "Female" || seatgender == "female" || seatgender == "f" || seatgender == "F")
			seatgender = "Female";
		else
			try
		{
			throw string("Invalid Input. \nPlease Enter The Gender: ");
		}
		catch (string x)
		{
			cout << x;
			cin >> seatgender;
			genderSetter();
		}
	}

	void arrivalSetter()
	{
		if (arrival == "Rahim Yar Khan" || arrival == "ryk" || arrival == "RYK" || arrival == "Ryk" || arrival == "rahim yar khan" || arrival == "Rahim yar khan")
			arrival = "RYK";
		else if (arrival == "Lahore" || arrival == "lhr" || arrival == "LHR" || arrival == "Lhr" || arrival == "lahore")
			arrival = "LHR";
		else if (arrival == "Rawalpindi" || arrival == "RWP" || arrival == "Rwp" || arrival == "rawalpindi" || arrival == "rwp")
			arrival = "RWP";
		else
			try
		{
			throw string("Invalid Input. \nPlease Enter The Arrival Terminal: ");
		}
		catch (string x)
		{
			cout << x;
			getline(cin, arrival);
			arrivalSetter();
		}
	}

	void departSetter()
	{
		if (depart == "Rahim Yar Khan" || depart == "ryk" || depart == "RYK" || depart == "Ryk" || depart == "rahim yar khan" || depart == "Rahim yar khan")
			depart = "RYK";
		else if (depart == "Lahore" || depart == "Lhr" || depart == "LHR" || depart == "lhr" || depart == "lahore")
			depart = "LHR";
		else if (depart == "Rawalpindi" || depart == "RWP" || depart == "Rwp" || depart == "rwp" || depart == " rawalpindi")
			depart = "RWP";
		else
			try
		{
			throw string("Invalid Input. \nPlease Enter The Departure Terminal: ");
		}
		catch (string x)
		{
			cout << x;
			getline(cin, depart);
			departSetter();
		}
	}

	void arrivalDepart()
	{
		if (arrival == depart)
		{
			cout << "Invalid Arrival And Departure Destinations. Please Input Again.\n";
			cout << "Please Enter The Departure Terminal: ";
			getline(cin, depart);
			departSetter();
			cout << "Please Enter The Arrival Terminal: ";
			getline(cin, arrival);
			arrivalSetter();
			arrivalDepart();
		}
	}

	void timeSetter()
	{
		if (depart == "RWP" && time != "0000" && time != "0800" && time != "1600")
		{
			cout << "Invalid Input.\n";
			cout << "Please Enter The Time Of Your Departure(HHMM): ";
			cin >> time;
			timeSetter();
		}
		if (depart == "LHR" && arrival == "RWP" &&time != "0000" && time != "0800" && time != "1600")
		{
			cout << "Invalid Input.\n";
			cout << "Please Enter The Time Of Your Departure(HHMM): ";
			cin >> time;
			timeSetter();
		}
		if (depart == "LHR" &&  arrival == "RYK" &&time != "0400" && time != "1200" && time != "2000")
		{
			cout << "Invalid Input.\n";
			cout << "Please Enter The Time Of Your Departure(HHMM): ";
			cin >> time;
			timeSetter();
		}
		if (depart == "RYK" && arrival == "LHR" && time != "0000" && time != "0800" && time != "1600")
		{
			cout << "Invalid Input.\n";
			cout << "Please Enter The Time Of Your Departure(HHMM): ";
			cin >> time;
			timeSetter();
		}
		if (depart == "RYK" && arrival == "RWP" && time != "0000" && time != "0800" && time != "1600")
		{
			cout << "Invalid Input.\n";
			cout << "Please Enter The Time Of Your Departure(HHMM): ";
			cin >> time;
			timeSetter();
		}

	}

	void departuretypeSetter()
	{
		if (date == "current" || date == "Current" || date == "C" || date == "c")
			date = "Current";
		else if (date == "Advance" || date == "advance" || date == "a" || date == "A" || date == "advanced" || date == "Advanced")
			date = "Advanced";
		else
			try
		{
			throw string("Invalid Input. \nPlease Enter Booking Type (Current/Advance): ");
		}
		catch (string x)
		{
			cout << x;
			getline(cin, date);
			departuretypeSetter();
		}
	}

	void schedule()
	{
		cout << endl << "\t\t\tROUTES OF BUSES\n";
		cout << "\t\t\t----------------\n";
		cout << "\tRawalpindi-Lahore\t\tRawalpindi-Rahim Yar Khan\n";
		cout << "\tLahore-Rawalpindi\t\tLahore-Rahim Yar Khan\n";
		cout << "\tRahim Yar Khan-Lahore\t\tRahim Yar Khan-Rawalpindi\n\n";

		cout << "Enter The Departure Terminal: ";
		cin.get();
		getline(cin, depart);
		departSetter();

		cout << endl << "Enter The Arrival Terminal: ";
		getline(cin, arrival);
		arrivalSetter();

		arrivalDepart();

		cout << "\n\t\t\tSCHEDULE OF BUSES\n";
		cout << "\t\t\t-----------------\n";
		if (depart == "RWP" && arrival == "RYK")
		{
			cout << "\t\t    Rawalpindi-Rahim Yar Khan\n";
			cout << "\t\tDeparture\t\tArrival\n";
			cout << "\t\t  0000\t\t\t 1400\n\t\t  0800\t\t\t 2200\n\t\t  1600\t\t\t 0600\n";
		}
		if (depart == "RWP" && arrival == "LHR")
		{
			cout << "\t\t\tRawalpindi-Lahore\n";
			cout << "\t\tDeparture\t\tArrival\n";
			cout << "\t\t  0000\t\t\t 0400\n\t\t  0800\t\t\t 1200\n\t\t  1600\t\t\t 2000\n";
		}
		if (depart == "LHR" && arrival == "RWP")
		{
			cout << "\t\t\tLahore-Rawalpindi\n";
			cout << "\t\tDeparture\t\tArrival\n";
			cout << "\t\t  0000\t\t\t 0400\n\t\t  0800\t\t\t 1200\n\t\t  1600\t\t\t 2000\n";
		}
		if (depart == "LHR" && arrival == "RYK")
		{
			cout << "\t\t     Lahore-Rahim Yar Khan\n";
			cout << "\t\tDeparture\t\tArrival\n";
			cout << "\t\t  0400\t\t\t 1400\n\t\t  1200\t\t\t 2200\n\t\t  2000\t\t\t 0600\n";
		}
		if (depart == "RYK" && arrival == "RWP")
		{
			cout << "\t\t    Rahim Yar Khan-Rawalpindi\n";
			cout << "\t\tDeparture\t\tArrival\n";
			cout << "\t\t  0000\t\t\t 1400\n\t\t  0800\t\t\t 2200\n\t\t  1600\t\t\t 0600\n";
		}
		if (depart == "RYK" && arrival == "LHR")
		{
			cout << "\t\t      Rahim Yar Khan-Lahore\n";
			cout << "\t\tDeparture\t\tArrival\n";
			cout << "\t\t  0000\t\t\t 1000\n\t\t  0800\t\t\t 1800\n\t\t  1600\t\t\t 0200\n";
		}
	}

	void timeCompatibility()
	{
		if (date == "Current")
		{
			int ST = (Time[0] * 1000) + (Time[1] * 100) + (Time[2] * 10) + (Time[3]);
			int T = stoi(time);
			if (T < ST)
			{
				cout << "The Time Of Your Bus Has Passed:-" << endl;
				if ((depart == "RWP" || depart == "RYK" || (depart == "LHR" && arrival == "RWP")) && ST > 1600)
				{
					cout << "And there is no available bus today on this route." << endl;

					int a = 0;
					string Select = "";
					while (true)
					{
						cout << endl <<  "Do you wish to to buy ticket for tomorrow (Press 1) or return to main(Press 0): ";
						cin >> Select;
						stringstream myStream(Select);
						if (myStream >> a)
							break;
					}

					if (a == 1)
					{
						date = "Advanced";
						cout << endl << "Please Enter The Time Of Your Departure(HHMM): ";
						cin >> time;
						timeSetter();
						systemTime();
						timeCompatibility();
					}
					if (a == 0)
						busTime++;
				}
				else if (depart == "LHR" && arrival == "RYK" && ST > 2000)
				{
					cout << "And there is no available bus today on this route." << endl;
					int a = 0;
					string Select = "";
					while (true)
					{
						cout << endl <<"Do you wish to to buy ticket for tomorrow (Press 1) or cancel reservation(Press 0): ";
						cin >> Select;
						stringstream myStream(Select);
						if (myStream >> a)
							break;
					}
					if (a == 1)
					{
						date = "Advanced";
						cout << endl << "Please Enter The Time Of Your Departure(HHMM): ";
						cin >> time;
						timeSetter();
						systemTime();
						timeCompatibility();
					}
					if (a == 0)
						busTime++;
				}
				else
				{
					cout << "Please Enter The Time Of Your Departure(HHMM) For Another Bus: ";
					cin >> time;
					timeSetter();
					timeCompatibility();
				}
			}
		}
	}

	void seater()
	{
		seatNo = 0;
		int x = 1;
		for (int R = 0; R < 11; R++)
		{
			for (int C = 0; C < 7; C++)
			{
				if (R == 0 || C == 0)
					RC[R][C] = 0;
				else if ((C == 3 || C == 4) && R != 10)
					RC[R][C] = 0;
				else
				{
					RC[R][C] = x;
					x++;
				}
			}
		}
		int row = 0, col = 0;
		do
		{
			string Select = "";
			while (true)
			{
				cout << "Enter Row No Of Required Seat R:";
				cin >> Select;
				stringstream myStream(Select);
				if (myStream >> row)
					break;
			}
		} while (row == 0 || row > 10);
		do
		{
			string Select = "";
			while (true)
			{
				cout << "Enter Column No Of Required Seat C:";
				cin >> Select;
				stringstream myStream(Select);
				if (myStream >> col)
					break;
			}
		} while (col == 0 || (col == 3 && row != 10) || (col == 4 && row != 10) || (row == 1 && col == 1) || col > 6);
		seatNo = RC[row][col];
	}

	int reservationCancel()
	{
		int refund = 0;
		SystemTimeAccess();
		systemTime();
		int ST = (Time[0] * 1000) + (Time[1] * 100) + (Time[2] * 10) + (Time[3]);
		int T = stoi(time);
		if (seatsGender[seatNo] != "-")
		{
			if (((ST < T && date == "Current") || date == "Advanced"))
			{
				seatsGender[seatNo] = "-";
				seatsName[seatNo] = "";

				if ((depart == "RWP" && arrival == "RYK") || (arrival == "RWP"&& depart == "RYK"))
					refund = 1260;
				if ((depart == "RWP" &&arrival == "LHR") || (arrival == "RWP"&& depart == "LHR"))
					refund = 910;
				if ((depart == "LHR" && arrival == "RYK") || (arrival == "LHR" && depart == "RYK"))
					refund = 1050;
				seatsDeparture[seatNo] = "";
				seatsArrival[seatNo] = "";
				seatsDate[seatNo] = "";
				seatsTime[seatNo] = 0;
				seatsLugPrice[seatNo] = 0;
				seatsTotalPrice[seatNo] = 0;
				cout << endl << "Refund of money after 30% deduction is " << refund << endl;
				return 1;
			}
			else
			{
				cout << endl << "This ticket reservation cannot be cancelled because the bus has passed." << endl;
				return 0;
			}
		}
		else
		{
			cout << endl << "No passenger is occupying the respective seat." << endl;
			return 0;
		}
	}

	void searchQuery()
	{
		interface();
		cout << "Seat No For Inquiry:-" << endl;
		seater();

		cout << "\nPassenger Data" << endl;
		cout << "--------------" << endl;
		cout << "Passenger Name: " << seatsName[seatNo] << endl;
		cout << "Departure Terminal: " << depart << endl;
		cout << "Arrival Terminal: " << arrival << endl;
		cout << "Departure Timing: " << time << endl;
		if (date == "Current")
			cout << "Date: " << timeArray[8] << timeArray[9] << "/" << timeArray[4] << timeArray[5] << timeArray[6] << "/" << timeArray[20] << timeArray[21] << timeArray[22] << timeArray[23] << endl;
		if (date == "Advanced")
		{
			int x = timeArray[8] - '0';
			int y = timeArray[9] - '0';
			int z = (x * 10) + y + 1;
			if (z == 32)
			{
				z = 1;
				timeArray[4] = 'J'; timeArray[5] = 'U'; timeArray[6] = 'N';
				cout << "Date: " << z << "/" << timeArray[4] << timeArray[5] << timeArray[6] << "/" << timeArray[20] << timeArray[21] << timeArray[22] << timeArray[23] << "\t\t\t\t\t\t\t\t-" << endl;
			}
			else
				cout << "Date: " << z << "/" << timeArray[4] << timeArray[5] << timeArray[6] << "/" << timeArray[20] << timeArray[21] << timeArray[22] << timeArray[23] << "\t\t\t\t\t\t\t\t-" << endl;
		}
		cout << "Seat No: " << seatNo << endl;
		cout << "Gender: " << seatsGender[seatNo] << endl;
		cout << "Luggage Price: " << seatsLugPrice[seatNo] << endl;

		cout << "Total Cost Ticket: " << seatsTotalPrice[seatNo] << endl;
	}

};