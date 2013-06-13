/*	EECS 211 Program 2 

Author: Jeannie Tran / Computer Science / 2583406 / jtr121

Purpose: Give students practice in writing functions, using arrays, using defined constants, and writing simple code.  

*/

#include <iostream>
#include <fstream>
using namespace std;

#define CAPACITY_FIRST 8  //define constants for cabin capacity
#define CAPACITY_BUSINESS 8
#define CAPACITY_ECONOMY 24

int bookSeat(int cabinArray[], int cabinCapacity) {
	int i;  //initialize counter 
	for(i = 0; i < cabinCapacity; i++) {  //loop through the seats until it finds one that is empty, and increment counter
		if(cabinArray[i] == 0) {  //if seat is empty,
			cabinArray[i] = 1;  //mark seat as assigned
			return 1;
		}
	}
	return 0;  //if no empty seats, quit function
}

int bookReservation(int cabinF[], int cabinB[], int cabinE[], int desiredCabin)
{
switch (desiredCabin) {  //for the desired cabin entered
	case 1:  //if it's first class,
		if (bookSeat(cabinF, CAPACITY_FIRST) == 1) {  //and the seat is empty
			return 1;  //book the seat and return that it's booked
		}
		else if (bookSeat(cabinF, CAPACITY_FIRST) == 0) {  //if it's not empty
			if (bookSeat(cabinB, CAPACITY_BUSINESS) == 1) {  //move to lower cabin
				return 2;  //book the seat and return that it's booked
			}
			else if (bookSeat(cabinB, CAPACITY_BUSINESS) == 0) {  //if lower cabin is not empty
				if (bookSeat(cabinE, CAPACITY_ECONOMY) == 1) {  //move to lower cabin
					return 3;  //book the seat and return that it's booked
				}
				else if (bookSeat(cabinE, CAPACITY_ECONOMY) == 0) {  //if everything is full
					return 0;  //return inability to book 
				}	
			}	
		}
		break;
	case 2:  //rinse and repeat the above
		if (bookSeat(cabinB, CAPACITY_BUSINESS) == 1) {  
				return 2;
		}
		else if (bookSeat(cabinB, CAPACITY_BUSINESS) == 0) {
			if (bookSeat(cabinE, CAPACITY_ECONOMY) == 1) {
				return 3;
			}
			else if (bookSeat(cabinE, CAPACITY_ECONOMY) == 0) {
				return 0; 
			}	
		}
		break;
	case 3:  //rinse and repeat the above
		if (bookSeat(cabinE, CAPACITY_ECONOMY) == 1) {
			return 3;
		}
		else if (bookSeat(cabinE, CAPACITY_ECONOMY) == 0) {
			return 0; 
		}
		break;
	default:  //if valid class not entered,
		return 0;  //return inability to book
		break;
	}	
}

void displayCabin(int cabinArray[], int cabinCapacity, int seatsPerRow)
{
	int i;  //initialize counter
	for(i = 0; i < cabinCapacity; i++) {  //loop through the seats
		if (i % seatsPerRow == 0 && seatsPerRow < 6) {  //if only four seats per row
			cout << " ";  //insert blank 
		}
		if (cabinArray[i] == 0) {  //if seat is empty
			cout << "o";  //display o
		} 
		else {  //if seat is occupied
			cout << "X";  //display X	
		}
		if ((i+1) % seatsPerRow == 0) {  //insert line break 
			cout << "\n";
		}				
	}
	return;
}

void displayPlan(int cabinF[], int cabinB[], int cabinE[])  //display current occupany in order 
{
	displayCabin(cabinF, CAPACITY_FIRST, 4);  //from first class
	displayCabin(cabinB, CAPACITY_BUSINESS, 4);  //to business class
	displayCabin(cabinE, CAPACITY_ECONOMY, 6);  //to economy class
	return;
}

int main()
{
	int cabinFirst[CAPACITY_FIRST] = {0, 0, 0, 0, 0, 0, 0, 0};  //initialize all cabins with no passengers
	int cabinBusiness[CAPACITY_BUSINESS] = {0, 0, 0, 0, 0, 0, 0, 0}; 
	int cabinEconomy[CAPACITY_ECONOMY] = {0, 0, 0, 0, 0, 0, 0, 0, 
										  0, 0, 0, 0, 0, 0, 0, 0,
										  0, 0, 0, 0, 0, 0, 0, 0};	
					  
	ifstream infile;  //read data from file
	infile.open("p2input.txt",ios::in);
	if(!infile.is_open()) {
		cout << "File not opened>\n";
		return 1;
	}

	int x;  //initialize counter for first input value
	int bookedCabin;  //value of cabin seat was booked in
	int y;  //initialize counter for second input value
	do {  
		infile >> x;  //read the first number
		switch (x) {
			case 1:  //if it's 1
				infile >> y;  //read the second number 
				if (y <= 3 && y >= 1) {  //if it's valid
					bookedCabin = bookReservation(cabinFirst, cabinBusiness, cabinEconomy, y);
					if (bookedCabin != 0) {  //book a seat in first available cabin
						cout << "You were booked a seat in cabin " << bookedCabin << ".\n";
					}
					else {  //or if there's no seats available
						cout << "No seats were available. You were not booked a seat.\n";
					}
				}
				else {  //if second number isn't valid
					cout << "Invalid cabin number. You were not booked a seat.\n";
				}
				break;
			case 2:  //if it's 2
				infile >> y;  //read the second number
				cout << "\n" << "Seat Assignments for cabin " << y << ":\n";  //display cabin assignments based on y
				if (y == 1) {
					displayCabin(cabinFirst, CAPACITY_FIRST, 4);
				}
				else if (y == 2) {
					displayCabin(cabinBusiness, CAPACITY_BUSINESS, 4);
				}
				else if (y == 3) {
					displayCabin(cabinEconomy, CAPACITY_ECONOMY, 6);
				}
				break;
			case 3:  //if it's 3
				cout << "\n" << "Seat Assignments for entire plane.\n";  //display the whole plane's assignments
				displayPlan(cabinFirst, cabinBusiness, cabinEconomy);
				break;
			default:  //else, (if it's 4), print the following and display the plane
				cout << "End of input file has been reached.\n";
				cout << "\n" << "Seat Assignments for entire plane.\n";
				displayPlan(cabinFirst, cabinBusiness, cabinEconomy);
				break;
		}
	} while(x < 4) ;  //when the number read is 4, break loop
	infile.close();  //close the input file
	char rawr;
	cout << "Enter any letter, and then press enter to terminate:";  //prompt user to terminate program
	cin >> rawr;
	return 1;
}