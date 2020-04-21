#include <iostream>
#include <string>
#include <sstream> 
using namespace std;

class progInterface : public terminalTicketing
{
public:

	void homeScreen()
	{
		cout << endl << endl << endl << endl << endl << endl << endl << endl;
		cout << "\t\t\t*   *\t*****\t*    \t*   *\t*****\t*****\t\t*****\t*   *\t*****\t*****\t*****\t*****\t*****" << endl;
		cout << "\t\t\t*   *\t*   *\t*    \t** **\t*    \t*    \t\t*    \t * * \t*   *\t*   *\t*    \t*    \t*    " << endl;
		cout << "\t\t\t*****\t*   *\t*    \t* * *\t*****\t*****\t\t*****\t  *  \t*****\t*****\t*****\t*****\t*****" << endl;
		cout << "\t\t\t*   *\t*   *\t*    \t*   *\t*    \t    *\t\t*    \t * * \t*    \t* *  \t*    \t    *\t    *" << endl;
		cout << "\t\t\t*   *\t*****\t*****\t*   *\t*****\t*****\t\t*****\t*   *\t*    \t*  * \t*****\t*****\t*****" << endl;
		cout << "\t\t\t*************************************************************************************************************" << endl;

		cout << endl << endl << endl << endl << endl << endl << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\tA Project By:" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tMuhammad Hamza" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tMisbah Hamid Hameed" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tRabbiya Qaiser Inam" << endl;
		cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
		getchar();
		system("cls");
		randomInput();
		selection();
	}

	void selection()
	{
		
		int select = 0;
		cout << endl << endl << endl << endl;
		cout << "Selections Available:-" << endl;
		cout << "\t1- Reservation Of A Ticket" << endl;
		cout << "\t2- Cancellation Of A Ticket" << endl;
		cout << "\t3- Luggage Data Entry" << endl;
		cout << "\t4- Printing Of Bus Data" << endl;
		cout << "\t5- Search Inquiry" << endl;
		cout << "\t6- En route Inquiry" << endl;
		cout << "\t7- Quit The Program" << endl;

		string Select = "";
		while (true)
		{
			cout << endl << "Which Inquiry Do You Want To Proceed: ";
			cin >> Select;
			stringstream myStream(Select);
			if (myStream >> select)
				break;
		}

		system("cls");
		switch (select)
		{
			case 1:
			{
				cout << endl << "\t\t---------RESERVATION CENTRE----------" << endl ;
				cout << "\t\t         ------------------" << endl << endl;
				getter(1);
				if (busTime == 0)
				{
					BusArray();
					reserveSelect();
					getchar();
					cout << "\nYour reservation has been made.\n\n";
				}
				getchar();
				system("cls");
				busTime = 0;
				selection();
				break;
			}
			case 2:
			{	
				cout << endl << "\t\t---------RESERVATION CANCELLATION CENTRE----------" << endl;
				cout << "\t\t         -------------------------------" << endl << endl;
				getter(0);
				BusArray();
				reserveCancelSelect();
				getchar();
				getchar();
				system("cls");
				selection();
				break;
			}
			case 3:
			{
				cout << endl << "\t\t---------LUGGAGE DATA ENTRY----------" << endl;
				cout << "\t\t         ------------------" << endl << endl;
				getter(0);
				BusArray();
				LuggageSelect();
				getchar();
				getchar();
				system("cls");
				selection();
				break;
			}
			case 4:
			{
				cout << endl << "\t\t---------BUS DATA PRINTING CENTRE----------" << endl;
				cout << "\t\t         ------------------------" << endl << endl;
				getter(0);
				BusArray();
				busDataSelect();
				getchar();
				cout << "\nBus data printed to BusData.txt.\n";
				getchar();
				system("cls");
				selection();
				break;
			}
			case 5:
			{
				cout << endl << "\t\t---------SEARCH INQUIRY CENTRE----------" << endl;
				cout << "\t\t         ----------------------" << endl << endl;
				getter(0);
				BusArray();
				searchSelect();
				getchar();
				getchar();
				system("cls");
				selection();
				break;
			}
			case 6:
			{
				cout << endl << "\t\t---------En route Checkup----------" << endl;
				cout << "\t\t         ---------------" << endl << endl;
				getter(0);
				BusArray();
				enrouteSelect();
				getchar();
				getchar();
				system("cls");
				selection();
				break;
			}
			case 7:
			{
				  cout << "\n\n\n\n\n\t\t\t\tGood Day To You\n\n\n\n";
				  getchar();
				  break; 
			}	
			default:
			{	
				selection();
				break; 
			}
		}

	}

};