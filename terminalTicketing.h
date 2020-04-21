#include <iostream>
#include <sstream> 
#include <string>

using namespace std;

class terminalTicketing : public ticketing
{
protected:
	ticketing Buses[7][3][4];
	int i = 0, j = 0, k = 0, b = 0;

public:

	void randomInput()
	{
		for (int i = 1; i < 7; i++)
		{
			for (int j = 1; j < 3; j++)
			{
				for (int k = 1; k < 4; k++)
				{
					if (i==1 ||i==3)
						Buses[i][j][k].totalPrice= 1300;
					if (i==2 ||i==5)
						Buses[i][j][k].totalPrice= 1800;
					if (i==4|| i==6)
						Buses[i][j][k].totalPrice = 1500;

					Buses[i][j][k].backInput();
				}
					
			}
		}
	}	

	void BusArray()
	{
		if (date == "Current")
			j = 1;
		if (date == "Advanced")
			j = 2;
		if (depart == "RWP")
		{
			if (arrival == "LHR")
			{
				i = 1;
				if (time == "0000")
				{
					k = 1;
					b = 1;
				}
				if (time == "0800")
				{
					k = 2;
					b = 2;
				}
				if (time == "1600")
				{
					k = 3;
					b = 3;
				}
			}
			if (arrival == "RYK")
			{
				i = 2;
				if (time == "0000")
				{
					k = 1;
					if (j == 1) b = 10;
					if (j == 2) b = 7;
				}
				if (time == "0800")
				{
					k = 2;
					if (j == 1) b = 11;
					if (j == 2) b = 8;
				}
				if (time == "1600")
				{
					k = 3;
					if (j == 1) b = 12;
					if (j == 2) b = 9;
				}
			}
		}
		if (depart == "LHR")
		{
			if (arrival == "RWP")
			{
				i = 3;
				if (time == "0000")
				{
					k = 1;
					b = 3;
				}
				if (time == "0800")
				{
					k = 2;
					b = 1;
				}
				if (time == "1600")
				{
					k = 3;
					b = 2;
				}
			}
			if (arrival == "RYK")
			{
				i = 4;
				if (time == "0400")
				{
					k = 1;
					b = 6;
				}
				if (time == "1200")
				{
					k = 2;
					b = 4;
				}
				if (time == "2000")
				{
					k = 3;
					b = 5;
				}
			}
		}
		if (depart == "RYK")
		{
			if (arrival == "RWP")
			{
				i = 5;
				if (time == "0000")
				{
					k = 1;
					if (j == 1) b = 7;
					if (j == 2) b = 10;
				}
				if (time == "0800")
				{
					k = 2;
					if (j == 1) b = 8;
					if (j == 2) b = 11;
				}
				if (time == "1600")
				{
					k = 3;
					if (j == 1) b = 9;
					if (j == 2) b = 12;
				}
			}
			if (arrival == "LHR")
			{
				i = 6;
				if (time == "0000")
				{
					k = 1;
					b = 4;
				}
				if (time == "0800")
				{
					k = 2;
					b = 5;
				}
				if (time == "1600")
				{
					k = 3;
					b = 6;
				}
			}
		}
	}

	void reserveSelect()
	{
		Buses[i][j][k].depart = depart;
		Buses[i][j][k].arrival = arrival;
		Buses[i][j][k].time = time;
		Buses[i][j][k].busNo = b;
		Buses[i][j][k].reservation = reservation;
		Buses[i][j][k].name = name;
		Buses[i][j][k].date = date;
		Buses[i][j][k].seatgender = seatgender;
		Buses[i][j][k].ticketPrice = ticketPrice;
		Buses[i][j][k].seatSelector();
	}

	void busDataSelect()
	{
		Buses[i][j][k].depart = depart;
		Buses[i][j][k].arrival = arrival;
		Buses[i][j][k].time = time;
		Buses[i][j][k].ticketPrice = ticketPrice;
		Buses[i][j][k].BusDataPrinting();
	}

	void reserveCancelSelect()
	{
		Buses[i][j][k].depart = depart;
		Buses[i][j][k].arrival = arrival;
		Buses[i][j][k].time = time;
		Buses[i][j][k].date = date;
		int count = 0;
		for (int a = 2; a < 43; a++)
		{
			if (Buses[i][j][k].seatsGender[a] == "M" || Buses[i][j][k].seatsGender[a] == "F" || Buses[i][j][k].seatsGender[a] == "MF" || Buses[i][j][k].seatsGender[a] == "FF")
			{
				count = 1;
				break;
			}
		}
		if (count > 0)
		{
			Buses[i][j][k].interface();
			Buses[i][j][k].seater();
			int a= Buses[i][j][k].reservationCancel();
			if (a == 1)
			{
				Buses[i][j][k].interface();
				Buses[i][j][k].BusDataPrinting();
				cout << "Reservation Cancelled." << endl;
			}
		}
		else
			cout << "\nThere Isnt Any Passenger In The Bus." << endl;
	}

	void searchSelect()
	{
		Buses[i][j][k].depart = depart;
		Buses[i][j][k].arrival = arrival;
		Buses[i][j][k].time = time;
		Buses[i][j][k].reservation = reservation;
		Buses[i][j][k].date = date;
		Buses[i][j][k].searchQueryPrinting();
	}

	void enrouteSelect()
	{
		enroutetester();
	}
	
	void LuggageSelect()
	{
		Buses[i][j][k].depart = depart;
		Buses[i][j][k].arrival = arrival;
		Buses[i][j][k].time = time;
		Buses[i][j][k].busNo = b;
		Buses[i][j][k].reservation = reservation;
		Buses[i][j][k].ticketPrice = ticketPrice;
		Buses[i][j][k].interface();
		Buses[i][j][k].seater();
		Buses[i][j][k].Luggage();
	}

};