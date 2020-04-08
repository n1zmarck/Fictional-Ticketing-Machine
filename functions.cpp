//functions.cpp
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;
const int SCH_ITEMS = 8;
const int LOC_SIZE = 2;
const int SEAT_SIZE = 40;
const int MAX_SIZE = 10;
string pTime[SCH_ITEMS] = { "7-AM", "9-AM", "11-AM", "1-PM", "3-PM", "5-PM", "7-PM", "9-PM" };
string lTime[SCH_ITEMS] = { "8-AM", "10-AM" ,"12-PM" ,"2-PM" ,"4-PM" ,"6-PM", "8-PM", "10-PM" };
char pFid[SCH_ITEMS + 1] = { '1A', '1B', '1C' , '1D' , '1E' , '1F' , '1G' , '1H' };
char lFid[SCH_ITEMS + 1] = { '2E' , '2F' , '2G' , '2H', '2A', '2B', '2C' , '2D' };
string paymentCardNum;
struct custBook
{
	int noPeople;
	int LdNum = 0;
	int UdNum = 0;
	string timeSlot;
	int portEntry;
	int portDrop;
	string ferryID;
	string ticketID;
};
struct ferryStats
{
	string time;
	int upperDeck;
	int lowerDeck;
};
void displaySchedule(int location)
{
	// conditional statement, using "?" as an if and proceeds as action therefore a bool
	//(location == 0) ? cout << "Penang Schedule" << endl : cout << "Langkawi Schedule" << endl;

		for (int loop = 0 ; loop < SCH_ITEMS; loop++)
		{
			if (location == 1)
			cout << pTime[loop] << "\t" << pFid[loop] << endl;
			else if (location == 2)
			{
				cout << lTime[loop] << "\t" << lFid[loop] << endl;
			
			}
			else
			{
				cout << "incorrect input, please try again" << endl;
			}
			
		}
	
}
int ticketBooking(int portofentry, int Lowerdeck, int Upperdeck, int number)
{
	char UrL;
	do
	{
	
		if (portofentry == 1)
		{
		
			cout << "Upper Deck RM60 or Lower Deck RM40?   ( type U or L to choose Upper deck or Lower deck respectively )" << endl;
			cin >> UrL;
			UrL = toupper(UrL);
			
			
				if (UrL == 'U')
				{
					Upperdeck = 1;
					return portofentry, Lowerdeck, Upperdeck;
					break;
				}
				else if (UrL == 'L')
				{
					Lowerdeck = 1;
					return portofentry, Lowerdeck, Upperdeck;
					break;
				}

			

		
		}
		else if (portofentry == 2)
		{
			
				cout << "Upper Deck RM60 or Lower Deck RM40?   ( type U or L to choose Upper deck or Lower deck respectively )" << endl;
				cin >> UrL;
				UrL = toupper(UrL);
			
				if (UrL == 'U')
				{
					Upperdeck = 1;
					return portofentry, Lowerdeck, Upperdeck;
					break;
				}
				else if (UrL == 'L')
				{
					Lowerdeck = 1;
					return portofentry, Lowerdeck, Upperdeck;
					break;
				}
				
		
		}
		else 
		{
				cout << "wrong Input, please try again";
				cin >> portofentry;

		}

	} while (portofentry != 1 && portofentry != 2 );
	


}
void paymentOptions(int numberofpeople, int Lowerdeck, int Upperdeck)
{
	int lowerDeckP = 40, upperDeckP = 60;
	string cardNumber;
	int cardcheck = 0;
	int customerNum = 1;
	// to set as null by default as to not confuse the checker to think that the empty spaces are digits.

	// prompt user if payment is cash or card.
	if (Lowerdeck == 1)
	{
		cout << setprecision(2) << "Cost of tickets" << numberofpeople * lowerDeckP << endl << "6 % GST" << (numberofpeople * lowerDeckP) * 0.06 << endl << "Grand Total" << ((numberofpeople * lowerDeckP) + ((numberofpeople * lowerDeckP) * 0.06)) << endl;

	}
	else
	{
		cout << setprecision(2) << "Cost of tickets" << numberofpeople * upperDeckP << endl << "6 % GST" << (numberofpeople * upperDeckP) * 0.06 << endl << "Grand Total" << ((numberofpeople * upperDeckP) + ((numberofpeople * upperDeckP) * 0.06)) << endl;

	}
	
	ifstream input;
	input.open("Total_Sales.txt");
	if (input.fail())
	{
		ofstream output;
		output.open("Total_Sales.txt");
		output << customerNum << '\t' << numberofpeople * upperDeckP << endl;
		output.close();

	}
	else
	{
		input >> customerNum;
		input.close();

		// increasing the customerNum by 1
		customerNum + 1;

		ofstream output;
		output.open("Total_Sales.txt");
		output << customerNum << '\t' << numberofpeople * upperDeckP << endl;
		output.close();
	}




	cout << "please enter Customer's credit card number"<< endl;
	cin >> cardNumber;
	cout << "Checking...";

	for (int i = 0; cardNumber[i]; i++)
	{
		cardcheck ++;
	}

	do
	{
		if (cardcheck != 16)
		{
			cout << "error, please try again." << endl;
			cin >> cardNumber;

			for (int i = 0; cardNumber[i]; i++)
			{
				cardcheck++;
			}

		}
		else
		{
			break;
		}

	} while (cardcheck != 16);

}
string genRandom(int n)
{
	char letters[MAX_SIZE] = { '1','2','3','4','5','6','7','8','9','0'};
	string ran = "";
	for (int i = 0; i < n; i++)
		ran = ran + letters[rand() % MAX_SIZE];
	return ran;
	/*
	
*	 Title: <Random String Generator in C++>
*    Author: <mausy 131>
*    Date: <Dec 24, 2012>
*    Code version: <1.0>
*    Availability: < www.cplusplus.com/forum/windows/88843/>

	*/


}

string selectFerry(int location, string ferry, string time, int numCust, int lDeck, int uDeck, int f1u, int f1d, int f2u, int f2d, int f3u, int f3d, int f4u, int f4d, int f5u, int f5d,
	int f6u, int f6d, int f7u, int f7d, int f8u, int f8d, int f9u, int f9d, int f10u, int f10d, int f11u, int f11d, int f12u, int f12d, int f13u, int f13d, int f14u, int f14d, int f15u, int f15d,
	int f16u, int f16d)
{
	char ferrySelected, errorCorr;
	string deck;
	displaySchedule(location);
	cout << "please select your time of departure (SELECT BOAT ID/ ALPHABET TO SELECT)" << endl;
	cin >> ferrySelected;
	ferrySelected = toupper(ferrySelected);

	if (location == 1)
	{

		if (ferrySelected == 'A')
		{
			if (uDeck == 1)
			{
				if (f1u + numCust > 10)
				{
					cout << "Error, overbooked" << endl << "Please enter either switch to lower deck (1) or move to different time slot (1)" << endl;
					cin >> errorCorr;
					errorCorr = toupper(errorCorr);

					if (errorCorr == 1)
					{
						lDeck = 1;
						uDeck = 0;
					}
					else if (errorCorr == 2)
					{
						cout << "please enter boat id for time slot ( B - H )" << endl;
						cin >> ferrySelected;

					}else
					{		
					time = "7-AM";
					ferry = "1A";
					deck = "Upper-Deck";
					f1u + numCust;
					
					return time;
					}

				}
				
			}
			else if (lDeck == 1)
			{
				if (f1d + numCust > 30)
				{
					cout << "Error, overbooked" << endl << "Please enter either switch to lower deck (1) or move to different time slot (1)" << endl;
					cin >> errorCorr;
					errorCorr = toupper(errorCorr);

					if (errorCorr == 1)
					{
						lDeck = 0;
						uDeck = 1;
					}
					else if (errorCorr == 2)
					{
						cout << "please enter boat id for time slot ( B - H )" << endl;
						cin >> ferrySelected;

					}
					else if (errorCorr != 1 && errorCorr != 2)
					{
						cout << "please enter 1(switch to a different deck) or 2(different time slot)" << endl;
						cin >> errorCorr;
						errorCorr = toupper(errorCorr);
					}
					else
					{
						deck = "Lower-Deck";
						f1d + numCust;
						ofstream output;
						output.open("customer.txt");
						output << time << "\t" << ferry << "\t" << deck;
						output.close();
					}

				}
				return time, ferry;
			}

		}
		else

			if (ferrySelected == 'B')
			{
				time = "9-AM";
				ferry = "1B";
				ofstream output;
				output.open("customer.txt");
				output << time << "\t" << ferry;
				output.close();
				if (uDeck == 1)
				{
					if (f2u + numCust > 10)
					{
						cout << "Error, overbooked" << endl << "Please enter either switch to lower deck (1) or move to different time slot (1)" << endl;
						cin >> errorCorr;
						errorCorr = toupper(errorCorr);

						if (errorCorr == 1)
						{
							lDeck = 1;
							uDeck = 0;
						}
						else if (errorCorr == 2)
						{
							cout << "please enter boat id for time slot ( B - H )" << endl;
							cin >> ferrySelected;

						}
					}
					f2u = f2u + numCust;
				}
				else if (lDeck == 1)
				{
					if (f2d + numCust > 30)
					{
						cout << "Error, overbooked" << endl << "Please enter either switch to lower deck (1) or move to different time slot (1)" << endl;
						cin >> errorCorr;
						errorCorr = toupper(errorCorr);

						if (errorCorr == 1)
						{
							lDeck = 0;
							uDeck = 1;
						}
						else if (errorCorr == 2)
						{
							cout << "please enter boat id for time slot ( B - H )" << endl;
							cin >> ferrySelected;

						}
						else if (errorCorr != 1 && errorCorr != 2)
						{
							cout << "please enter 1(switch to a different deck) or 2(different time slot)" << endl;
							cin >> errorCorr;
							errorCorr = toupper(errorCorr);
						}
						else
						{
							f2d = f2d + numCust;
						}

					}
					return time, ferry;
				}


			}
			else
				if (ferrySelected == 'C')
				{
					time = "11-AM";
					ferry = "1C";
					ofstream output;
					output.open("customer.txt");
					output << time << "\t" << ferry;
					output.close();
					if (uDeck == 1)
					{
						if (f3u + numCust > 10)
						{
							cout << "Error, overbooked" << endl << "Please enter either switch to lower deck (1) or move to different time slot (1)" << endl;
							cin >> errorCorr;
							errorCorr = toupper(errorCorr);

							if (errorCorr == 1)
							{
								lDeck = 1;
								uDeck = 0;
							}
							else if (errorCorr == 2)
							{
								cout << "please enter boat id for time slot ( B - H )" << endl;
								cin >> ferrySelected;

							}
						}
						else
						{
							f3u = f3u + numCust;
						}

					}
					else if (lDeck == 1)
					{
						if (f3d + numCust > 30)
						{
							cout << "Error, overbooked" << endl << "Please enter either switch to lower deck (1) or move to different time slot (1)" << endl;
							cin >> errorCorr;
							errorCorr = toupper(errorCorr);

							if (errorCorr == 1)
							{
								lDeck = 0;
								uDeck = 1;
							}
							else if (errorCorr == 2)
							{
								cout << "please enter boat id for time slot ( B - H )" << endl;
								cin >> ferrySelected;

							}
							else if (errorCorr != 1 && errorCorr != 2)
							{
								cout << "please enter 1(switch to a different deck) or 2(different time slot)" << endl;
								cin >> errorCorr;
								errorCorr = toupper(errorCorr);
							}
							else
							{
								f3d = f3d + numCust;
							}

						}
						return time, ferry;
					}
					
				}
				else
					if (ferrySelected == 'D')
					{
						time = "1-PM";
						ferry = "1D";
						ofstream output;
						output.open("customer.txt");
						output << time << "\t" << ferry;
						output.close();
						if (uDeck == 1)
						{
							if (f4u + numCust > 10)
							{
								cout << "Error, overbooked" << endl << "Please enter either switch to lower deck (1) or move to different time slot (1)" << endl;
								cin >> errorCorr;
								errorCorr = toupper(errorCorr);

								if (errorCorr == 1)
								{
									lDeck = 1;
									uDeck = 0;
								}
								else if (errorCorr == 2)
								{
									cout << "please enter boat id for time slot ( B - H )" << endl;
									cin >> ferrySelected;

								}
							}
							else
							{
								f4u = f4u + numCust;
							}

						}
						else if (lDeck == 1)
						{
							if (f4d + numCust > 30)
							{
								cout << "Error, overbooked" << endl << "Please enter either switch to lower deck (1) or move to different time slot (1)" << endl;
								cin >> errorCorr;
								errorCorr = toupper(errorCorr);

								if (errorCorr == 1)
								{
									lDeck = 0;
									uDeck = 1;
								}
								else if (errorCorr == 2)
								{
									cout << "please enter boat id for time slot ( B - H )" << endl;
									cin >> ferrySelected;

								}
								else if (errorCorr != 1 && errorCorr != 2)
								{
									cout << "please enter 1(switch to a different deck) or 2(different time slot)" << endl;
									cin >> errorCorr;
									errorCorr = toupper(errorCorr);
								}
								else
								{
									f4d = f4d + numCust;
								}

							}
							return time, ferry;
						}
					}
					else if (ferrySelected == 'E')
					{
						time = "3-PM";
						ferry = "1E";
						ofstream output;
						output.open("customer.txt");
						output << time << "\t" << ferry;
						output.close();
						if (uDeck == 1)
						{
							if (f5u + numCust > 10)
							{
								cout << "Error, overbooked" << endl << "Please enter either switch to lower deck (1) or move to different time slot (1)" << endl;
								cin >> errorCorr;
								errorCorr = toupper(errorCorr);

								if (errorCorr == 1)
								{
									lDeck = 1;
									uDeck = 0;
								}
								else if (errorCorr == 2)
								{
									cout << "please enter boat id for time slot ( B - H )" << endl;
									cin >> ferrySelected;

								}
							}
							else
							{
								f5u = f5u + numCust;
							}

						}
						else if (lDeck == 1)
						{
							if (f5d + numCust > 30)
							{
								cout << "Error, overbooked" << endl << "Please enter either switch to lower deck (1) or move to different time slot (1)" << endl;
								cin >> errorCorr;
								errorCorr = toupper(errorCorr);

								if (errorCorr == 1)
								{
									lDeck = 0;
									uDeck = 1;
								}
								else if (errorCorr == 2)
								{
									cout << "please enter boat id for time slot ( B - H )" << endl;
									cin >> ferrySelected;

								}
								else if (errorCorr != 1 && errorCorr != 2)
								{
									cout << "please enter 1(switch to a different deck) or 2(different time slot)" << endl;
									cin >> errorCorr;
									errorCorr = toupper(errorCorr);
								}
								else
								{
									f5d = f5d + numCust;
								}

							}
							return time, ferry;
						}

					} 
					else if(ferrySelected == 'F')
					{
						time = "5-PM";
						ferry = "1F";
						ofstream output;
						output.open("customer.txt");
						output << time << "\t" << ferry;
						output.close();
						if (uDeck == 1)
						{
							if (f6u + numCust > 10)
							{
								cout << "Error, overbooked" << endl << "Please enter either switch to lower deck (1) or move to different time slot (1)" << endl;
								cin >> errorCorr;
								errorCorr = toupper(errorCorr);

								if (errorCorr == 1)
								{
									lDeck = 1;
									uDeck = 0;
								}
								else if (errorCorr == 2)
								{
									cout << "please enter boat id for time slot ( B - H )" << endl;
									cin >> ferrySelected;

								}
							}
							else
							{
								f6u = f6u + numCust;
							}

						}
						else if (lDeck == 1)
						{
							if (f6d + numCust > 30)
							{
								cout << "Error, overbooked" << endl << "Please enter either switch to lower deck (1) or move to different time slot (1)" << endl;
								cin >> errorCorr;
								errorCorr = toupper(errorCorr);

								if (errorCorr == 1)
								{
									lDeck = 0;
									uDeck = 1;
								}
								else if (errorCorr == 2)
								{
									cout << "please enter boat id for time slot ( B - H )" << endl;
									cin >> ferrySelected;

								}
								else if (errorCorr != 1 && errorCorr != 2)
								{
									cout << "please enter 1(switch to a different deck) or 2(different time slot)" << endl;
									cin >> errorCorr;
									errorCorr = toupper(errorCorr);
								}
								else
								{
									f6d = f6d + numCust;
								}

							}
							return time, ferry;
						}
		




					}
					else if (ferrySelected == 'G')
					{
						time = "7-PM";
						ferry = "1G";
						ofstream output;
						output.open("customer.txt");
						output << time << "\t" << ferry;
						output.close();
						if (uDeck == 1)
						{
							if (f7u + numCust > 10)
							{
								cout << "Error, overbooked" << endl << "Please enter either switch to lower deck (1) or move to different time slot (1)" << endl;
								cin >> errorCorr;
								errorCorr = toupper(errorCorr);

								if (errorCorr == 1)
								{
									lDeck = 1;
									uDeck = 0;
								}
								else if (errorCorr == 2)
								{
									cout << "please enter boat id for time slot ( B - H )" << endl;
									cin >> ferrySelected;

								}
							}
							else
							{
								f7u = f7u + numCust;
							}

						}
						else if (lDeck == 1)
						{
							if (f7d + numCust > 30)
							{
								cout << "Error, overbooked" << endl << "Please enter either switch to lower deck (1) or move to different time slot (1)" << endl;
								cin >> errorCorr;
								errorCorr = toupper(errorCorr);

								if (errorCorr == 1)
								{
									lDeck = 0;
									uDeck = 1;
								}
								else if (errorCorr == 2)
								{
									cout << "please enter boat id for time slot ( B - H )" << endl;
									cin >> ferrySelected;

								}
								else if (errorCorr != 1 && errorCorr != 2)
								{
									cout << "please enter 1(switch to a different deck) or 2(different time slot)" << endl;
									cin >> errorCorr;
									errorCorr = toupper(errorCorr);
								}
								else
								{
									f7d = f7d + numCust;
								}

							}
							return time, ferry;
						}
					}
					else if (ferrySelected == 'H')
					{
					time = "9-PM";
					ferry = "1H";
					ofstream output;
					output.open("customer.txt");
					output << time << "\t" << ferry;
					output.close();
					if (uDeck == 1)
					{
						if (f8u + numCust > 10)
						{
							cout << "Error, overbooked" << endl << "Please enter either switch to lower deck (1) or move to different time slot (1)" << endl;
							cin >> errorCorr;
							errorCorr = toupper(errorCorr);

							if (errorCorr == 1)
							{
								lDeck = 1;
								uDeck = 0;
							}
							else if (errorCorr == 2)
							{
								cout << "please enter boat id for time slot ( B - H )" << endl;
								cin >> ferrySelected;

							}
						}
						else
						{
							f8u = f8u + numCust;
						}

					}
					else if (lDeck == 1)
					{
						if (f8d + numCust > 30)
						{
							cout << "Error, overbooked" << endl << "Please enter either switch to lower deck (1) or move to different time slot (1)" << endl;
							cin >> errorCorr;
							errorCorr = toupper(errorCorr);

							if (errorCorr == 1)
							{
								lDeck = 0;
								uDeck = 1;
							}
							else if (errorCorr == 2)
							{
								cout << "please enter boat id for time slot ( B - H )" << endl;
								cin >> ferrySelected;

							}
							else if (errorCorr != 1 && errorCorr != 2)
							{
								cout << "please enter 1(switch to a different deck) or 2(different time slot)" << endl;
								cin >> errorCorr;
								errorCorr = toupper(errorCorr);
							}
							else
							{
								f8d = f8d + numCust;
							}

						}
						return time, ferry;
					}
					}
	}
	else if (location == 2) 
	{
	if (ferrySelected == 'A')
	{
		time = "8-AM";
		ferry = "2A";
		ofstream output;
		output.open("customer.txt");
		output << time << "\t" << ferry;
		output.close();
		if (uDeck == 1)
		{
			if (f9u + numCust > 10)
			{
				cout << "Error, overbooked" << endl << "Please enter either switch to lower deck (1) or move to different time slot (1)" << endl;
				cin >> errorCorr;
				errorCorr = toupper(errorCorr);

				if (errorCorr == 1)
				{
					lDeck = 1;
					uDeck = 0;
				}
				else if (errorCorr == 2)
				{
					cout << "please enter boat id for time slot ( B - H )" << endl;
					cin >> ferrySelected;

				}
			}
			else
			{
				f9u = f9u + numCust;
			}

		}
		else if (lDeck == 1)
		{
			if (f9d + numCust > 30)
			{
				cout << "Error, overbooked" << endl << "Please enter either switch to lower deck (1) or move to different time slot (1)" << endl;
				cin >> errorCorr;
				errorCorr = toupper(errorCorr);

				if (errorCorr == 1)
				{
					lDeck = 0;
					uDeck = 1;
				}
				else if (errorCorr == 2)
				{
					cout << "please enter boat id for time slot ( B - H )" << endl;
					cin >> ferrySelected;

				}
				else if (errorCorr != 1 && errorCorr != 2)
				{
					cout << "please enter 1(switch to a different deck) or 2(different time slot)" << endl;
					cin >> errorCorr;
					errorCorr = toupper(errorCorr);
				}
				else
				{
					f9d = f9d + numCust;
				}

			}
			return time, ferry;
		}

	}
	else

		if (ferrySelected == 'B')
		{
			time = "10-AM";
			ferry = "2B";
			ofstream output;
			output.open("customer.txt");
			output << time << "\t" << ferry;
			output.close();
			if (uDeck == 1)
			{
				if (f10u + numCust > 10)
				{
					cout << "Error, overbooked" << endl << "Please enter either switch to lower deck (1) or move to different time slot (1)" << endl;
					cin >> errorCorr;
					errorCorr = toupper(errorCorr);

					if (errorCorr == 1)
					{
						lDeck = 1;
						uDeck = 0;
					}
					else if (errorCorr == 2)
					{
						cout << "please enter boat id for time slot ( B - H )" << endl;
						cin >> ferrySelected;

					}
				}
				f10u = f10u + numCust;
			}
			else if (lDeck == 1)
			{
				if (f10d + numCust > 30)
				{
					cout << "Error, overbooked" << endl << "Please enter either switch to lower deck (1) or move to different time slot (1)" << endl;
					cin >> errorCorr;
					errorCorr = toupper(errorCorr);

					if (errorCorr == 1)
					{
						lDeck = 0;
						uDeck = 1;
					}
					else if (errorCorr == 2)
					{
						cout << "please enter boat id for time slot ( A - H )" << endl;
						cin >> ferrySelected;

					}
					else if (errorCorr != 1 && errorCorr != 2)
					{
						cout << "please enter 1(switch to a different deck) or 2(different time slot)" << endl;
						cin >> errorCorr;
						errorCorr = toupper(errorCorr);
					}
					else
					{
						f10d = f10d + numCust;
					}

				}
				return time, ferry;
			}


		}
		else
			if (ferrySelected == 'C')
			{
				time = "12-PM";
				ferry = "1C";
				ofstream output;
				output.open("customer.txt");
				output << time << "\t" << ferry;
				output.close();
				if (uDeck == 1)
				{
					if (f11u + numCust > 10)
					{
						cout << "Error, overbooked" << endl << "Please enter either switch to lower deck (1) or move to different time slot (1)" << endl;
						cin >> errorCorr;
						errorCorr = toupper(errorCorr);

						if (errorCorr == 1)
						{
							lDeck = 1;
							uDeck = 0;
						}
						else if (errorCorr == 2)
						{
							cout << "please enter boat id for time slot ( B - H )" << endl;
							cin >> ferrySelected;

						}
					}
					else
					{
						f11u = f11u + numCust;
					}

				}
				else if (lDeck == 1)
				{
					if (f11d + numCust > 30)
					{
						cout << "Error, overbooked" << endl << "Please enter either switch to lower deck (1) or move to different time slot (1)" << endl;
						cin >> errorCorr;
						errorCorr = toupper(errorCorr);

						if (errorCorr == 1)
						{
							lDeck = 0;
							uDeck = 1;
						}
						else if (errorCorr == 2)
						{
							cout << "please enter boat id for time slot ( B - H )" << endl;
							cin >> ferrySelected;

						}
						else if (errorCorr != 1 && errorCorr != 2)
						{
							cout << "please enter 1(switch to a different deck) or 2(different time slot)" << endl;
							cin >> errorCorr;
							errorCorr = toupper(errorCorr);
						}
						else
						{
							f11d = f11d + numCust;
						}

					}
					return time, ferry;
				}

			}
			else
				if (ferrySelected == 'D')
				{
					time = "2-PM";
					ferry = "2D";
					ofstream output;
					output.open("customer.txt");
					output << time << "\t" << ferry;
					output.close();
					if (uDeck == 1)
					{
						if (f12u + numCust > 10)
						{
							cout << "Error, overbooked" << endl << "Please enter either switch to lower deck (1) or move to different time slot (1)" << endl;
							cin >> errorCorr;
							errorCorr = toupper(errorCorr);

							if (errorCorr == 1)
							{
								lDeck = 1;
								uDeck = 0;
							}
							else if (errorCorr == 2)
							{
								cout << "please enter boat id for time slot ( B - H )" << endl;
								cin >> ferrySelected;

							}
						}
						else
						{
							f12u = f12u + numCust;
						}

					}
					else if (lDeck == 1)
					{
						if (f12d + numCust > 30)
						{
							cout << "Error, overbooked" << endl << "Please enter either switch to lower deck (1) or move to different time slot (1)" << endl;
							cin >> errorCorr;
							errorCorr = toupper(errorCorr);

							if (errorCorr == 1)
							{
								lDeck = 0;
								uDeck = 1;
							}
							else if (errorCorr == 2)
							{
								cout << "please enter boat id for time slot ( B - H )" << endl;
								cin >> ferrySelected;

							}
							else if (errorCorr != 1 && errorCorr != 2)
							{
								cout << "please enter 1(switch to a different deck) or 2(different time slot)" << endl;
								cin >> errorCorr;
								errorCorr = toupper(errorCorr);
							}
							else
							{
								f12d = f12d + numCust;
							}

						}
						return time, ferry;
					}
				}
				else if (ferrySelected == 'E')
				{
					time = "4-PM";
					ferry = "2E";
					ofstream output;
					output.open("customer.txt");
					output << time << "\t" << ferry;
					output.close();
					if (uDeck == 1)
					{
						if (f13u + numCust > 10)
						{
							cout << "Error, overbooked" << endl << "Please enter either switch to lower deck (1) or move to different time slot (1)" << endl;
							cin >> errorCorr;
							errorCorr = toupper(errorCorr);

							if (errorCorr == 1)
							{
								lDeck = 1;
								uDeck = 0;
							}
							else if (errorCorr == 2)
							{
								cout << "please enter boat id for time slot ( B - H )" << endl;
								cin >> ferrySelected;

							}
						}
						else
						{
							f13u = f13u + numCust;
						}

					}
					else if (lDeck == 1)
					{
						if (f13d + numCust > 30)
						{
							cout << "Error, overbooked" << endl << "Please enter either switch to lower deck (1) or move to different time slot (1)" << endl;
							cin >> errorCorr;
							errorCorr = toupper(errorCorr);

							if (errorCorr == 1)
							{
								lDeck = 0;
								uDeck = 1;
							}
							else if (errorCorr == 2)
							{
								cout << "please enter boat id for time slot ( B - H )" << endl;
								cin >> ferrySelected;

							}
							else if (errorCorr != 1 && errorCorr != 2)
							{
								cout << "please enter 1(switch to a different deck) or 2(different time slot)" << endl;
								cin >> errorCorr;
								errorCorr = toupper(errorCorr);
							}
							else
							{
								f13d = f13d + numCust;
							}

						}
						return time, ferry;
					}

				}
				else if (ferrySelected == 'F')
				{
					time = "6-PM";
					ferry = "2F";
					ofstream output;
					output.open("customer.txt");
					output << time << "\t" << ferry;
					output.close();
					if (uDeck == 1)
					{
						if (f14u + numCust > 10)
						{
							cout << "Error, overbooked" << endl << "Please enter either switch to lower deck (1) or move to different time slot (1)" << endl;
							cin >> errorCorr;
							errorCorr = toupper(errorCorr);

							if (errorCorr == 1)
							{
								lDeck = 1;
								uDeck = 0;
							}
							else if (errorCorr == 2)
							{
								cout << "please enter boat id for time slot ( B - H )" << endl;
								cin >> ferrySelected;

							}
						}
						else
						{
							f14u = f14u + numCust;
						}

					}
					else if (lDeck == 1)
					{
						if (f14d + numCust > 30)
						{
							cout << "Error, overbooked" << endl << "Please enter either switch to lower deck (1) or move to different time slot (1)" << endl;
							cin >> errorCorr;
							errorCorr = toupper(errorCorr);

							if (errorCorr == 1)
							{
								lDeck = 0;
								uDeck = 1;
							}
							else if (errorCorr == 2)
							{
								cout << "please enter boat id for time slot ( B - H )" << endl;
								cin >> ferrySelected;

							}
							else if (errorCorr != 1 && errorCorr != 2)
							{
								cout << "please enter 1(switch to a different deck) or 2(different time slot)" << endl;
								cin >> errorCorr;
								errorCorr = toupper(errorCorr);
							}
							else
							{
								f14d = f14d + numCust;
							}

						}
						return time, ferry;
					}





				}
				else if (ferrySelected == 'G')
				{
					time = "8-PM";
					ferry = "2G";
					ofstream output;
					output.open("customer.txt");
					output << time << "\t" << ferry;
					output.close();
					if (uDeck == 1)
					{
						if (f15u + numCust > 10)
						{
							cout << "Error, overbooked" << endl << "Please enter either switch to lower deck (1) or move to different time slot (1)" << endl;
							cin >> errorCorr;
							errorCorr = toupper(errorCorr);

							if (errorCorr == 1)
							{
								lDeck = 1;
								uDeck = 0;
							}
							else if (errorCorr == 2)
							{
								cout << "please enter boat id for time slot ( B - H )" << endl;
								cin >> ferrySelected;

							}
						}
						else
						{
							f15u = f15u + numCust;
						}

					}
					else if (lDeck == 1)
					{
						if (f15d + numCust > 30)
						{
							cout << "Error, overbooked" << endl << "Please enter either switch to lower deck (1) or move to different time slot (1)" << endl;
							cin >> errorCorr;
							errorCorr = toupper(errorCorr);

							if (errorCorr == 1)
							{
								lDeck = 0;
								uDeck = 1;
							}
							else if (errorCorr == 2)
							{
								cout << "please enter boat id for time slot ( B - H )" << endl;
								cin >> ferrySelected;

							}
							else if (errorCorr != 1 && errorCorr != 2)
							{
								cout << "please enter 1(switch to a different deck) or 2(different time slot)" << endl;
								cin >> errorCorr;
								errorCorr = toupper(errorCorr);
							}
							else
							{
								f15d = f15d + numCust;
							}

						}
						return time, ferry;
					}
				}
				else if (ferrySelected == 'H')
				{
					time = "10-PM";
					ferry = "2H";
					ofstream output;
					output.open("customer.txt");
					output << time << "\t" << ferry;
					output.close();
					if (uDeck == 1)
					{
						if (f16u + numCust > 10)
						{
							cout << "Error, overbooked" << endl << "Please enter either switch to lower deck (1) or move to different time slot (1)" << endl;
							cin >> errorCorr;
							errorCorr = toupper(errorCorr);

							if (errorCorr == 1)
							{
								lDeck = 1;
								uDeck = 0;
							}
							else if (errorCorr == 2)
							{
								cout << "please enter boat id for time slot ( B - H )" << endl;
								cin >> ferrySelected;

							}
						}
						else
						{
							f16u = f16u + numCust;
						}

					}
					else if (lDeck == 1)
					{
						if (f16d + numCust > 30)
						{
							cout << "Error, overbooked" << endl << "Please enter either switch to lower deck (1) or move to different time slot (1)" << endl;
							cin >> errorCorr;
							errorCorr = toupper(errorCorr);

							if (errorCorr == 1)
							{
								lDeck = 0;
								uDeck = 1;
							}
							else if (errorCorr == 2)
							{
								cout << "please enter boat id for time slot ( B - H )" << endl;
								cin >> ferrySelected;

							}
							else if (errorCorr != 1 && errorCorr != 2)
							{
								cout << "please enter 1(switch to a different deck) or 2(different time slot)" << endl;
								cin >> errorCorr;
								errorCorr = toupper(errorCorr);
							}
							else
							{
								f16d = f16d + numCust;
							}

						}
						return time, ferry;
					}
				}
	


	}





}

void ticketGen(string timeSlot, int noPeople, int from, int to, string ferry, string tickID)
{

	int ticketsize = 19;
	cout << "========================SYSTEMA FERRIES====================" << endl;
	ifstream input;
	input.open("customer.txt");
	string timeslot, ferryio;
	
	input >> timeslot >> ferryio;
	cout << "TIME :" << timeslot << endl;
	cout << "Ferry ID :" << ferryio << endl;

	input.close();
	//cout << "TIME :" << timeSlot << endl;
	//cout << "Ferry ID :" << ferry << endl;
	cout << "No.PAX :" << noPeople << endl;

	if (from == 1)
	{
		cout << "From :" << "Penang" << endl;
		cout << "To  :" << "Langkawi" << endl;
	}
	else
	{
		cout << "From :" << "Langkawi" << endl;
		cout << "To  :" << "Penang" << endl;
	}
	cout << "ticket No :" << tickID << endl;

	cout << "===========================================================" << endl;
	// vars are not set properly since they are not declared.
}
int main()
{
	char continuation;
	
		custBook(currentCustomer);
		ferryStats p1{ "7-AM",0,0 };
		ferryStats p2{ "8-AM",0,0 };
		ferryStats p3{ "9-AM",0,0 };
		ferryStats p4{ "10-AM",0,0 };
		ferryStats p5{ "11-AM",0,0 };
		ferryStats p6{ "12-PM",0,0 };
		ferryStats p7{ "1-PM",0,0 };
		ferryStats p8{ "2-PM",0,0 };
		ferryStats p9{ "3-PM",0,0 };
		ferryStats p10{ "4-PM",0,0 };
		ferryStats p11{ "5-PM",0,0 };
		ferryStats p12{ "6-PM",0,0 };
		ferryStats p13{ "7-PM",0,0 };
		ferryStats p14{ "8-PM",0,0 };
		ferryStats p15{ "9-PM",0,0 };
		ferryStats p16{ "10-PM",0,0 };

	do
	{
		char reply;
		

		cout << "Number of people?" << endl;
		cin >> currentCustomer.noPeople;
		do
		{
			if (currentCustomer.noPeople > 40)
			{
			cout << "Error Exceeded Number booking, please split group size into smaller groups. " << endl << "please try again.";
			cin >> currentCustomer.noPeople;
			}
			else
			{
			break;
			}
		} while (currentCustomer.noPeople > 40);

		cout << "Penang or Langkawi?" << endl;
		cin >> reply;
		reply = toupper(reply);
		do
		{
			if (reply == 'P')
			{
				currentCustomer.portEntry = 1;
				break;
			}
			else if (reply == 'L')
				{
				currentCustomer.portEntry = 2;
				break;
				}
			else {
			cout << "error... Please enter a valid Character" << endl;
			cin >> reply;
			reply = toupper(reply);
			}
		} while (reply != 'P' && reply !='L');
	
	
		ticketBooking(currentCustomer.portEntry, currentCustomer.LdNum, currentCustomer.UdNum,currentCustomer.noPeople);
		
		if (currentCustomer.portEntry == 1)
		{
			currentCustomer.portDrop = 2;
		}
		else if (currentCustomer.portEntry == 2)
		{
			currentCustomer.portDrop = 1;
		}
		


		selectFerry(currentCustomer.portEntry, currentCustomer.ferryID,currentCustomer.timeSlot, currentCustomer.noPeople, currentCustomer.LdNum, currentCustomer.UdNum,p1.upperDeck,p1.lowerDeck, p2.upperDeck, p2.lowerDeck,
		p3.upperDeck, p3.lowerDeck, p4.upperDeck, p4.lowerDeck,p5.upperDeck, p5.lowerDeck, p6.upperDeck, p6.lowerDeck, p7.upperDeck, p7.lowerDeck, p8.upperDeck, p8.lowerDeck, p9.upperDeck,
		p9.lowerDeck, p10.upperDeck, p10.lowerDeck, p11.upperDeck, p11.lowerDeck, p12.upperDeck, p12.lowerDeck, p13.upperDeck, p13.lowerDeck, p14.upperDeck, p14.lowerDeck,
		p15.upperDeck, p15.lowerDeck, p16.upperDeck, p16.lowerDeck);
		// select ferry has error, Exception thrown at 0x002FCAE8 in Ticketing machine.exe: 0xC0000005: Access violation reading location 0xCCCCCCD0.
		//Unhandled exception thrown : read access violation.
			//** _Pnext** was 0xCCCCCCD0.
		paymentOptions(currentCustomer.noPeople, currentCustomer.LdNum, currentCustomer.UdNum);

		currentCustomer.ticketID = genRandom(19);
	
		ticketGen(currentCustomer.timeSlot,currentCustomer.noPeople,currentCustomer.portEntry,currentCustomer.portDrop,currentCustomer.ferryID,currentCustomer.ticketID);


	cout << "would you like to continue? (Y to continue, N to exit and end day)" << endl;
	cin >> continuation;

	if (continuation == 'N')
	{
		fstream binaryio;
		binaryio.open("Ferry_Information.dat", ios::in, ios::binary);
		binaryio.write(reinterpret_cast<char*> (&p1), sizeof ferryStats);
		binaryio.write(reinterpret_cast<char*> (&p2), sizeof ferryStats);
		binaryio.write(reinterpret_cast<char*> (&p3), sizeof ferryStats);
		binaryio.write(reinterpret_cast<char*> (&p4), sizeof ferryStats);
		binaryio.write(reinterpret_cast<char*> (&p5), sizeof ferryStats);
		binaryio.write(reinterpret_cast<char*> (&p6), sizeof ferryStats);
		binaryio.write(reinterpret_cast<char*> (&p7), sizeof ferryStats);
		binaryio.write(reinterpret_cast<char*> (&p8), sizeof ferryStats);
		binaryio.write(reinterpret_cast<char*> (&p9), sizeof ferryStats);
		binaryio.write(reinterpret_cast<char*> (&p10), sizeof ferryStats);
		binaryio.write(reinterpret_cast<char*> (&p11), sizeof ferryStats);
		binaryio.write(reinterpret_cast<char*> (&p12), sizeof ferryStats);
		binaryio.write(reinterpret_cast<char*> (&p13), sizeof ferryStats);
		binaryio.write(reinterpret_cast<char*> (&p14), sizeof ferryStats);
		binaryio.write(reinterpret_cast<char*> (&p15), sizeof ferryStats);
		binaryio.write(reinterpret_cast<char*> (&p16), sizeof ferryStats);
		binaryio.close();

		break;
	}

	continuation = toupper(continuation);
	} while (continuation == 'Y');
	




}


