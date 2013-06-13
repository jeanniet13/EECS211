/*	EECS 211 Program 3 

Author: Jeannie Tran / Computer Science / 2583406 / jtr121

Purpose: Learn to use classes and pointers.   

*/

#include "devices.h"
#include "definitions.h"
#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;


malfunctionRecord::malfunctionRecord() {  //initializing constructor
	lastmalfunctionType = NO_MALFUNCTION;  //set last malfunction type to NO_MALFUNCTION (20)
	malfunctionCount = 0;  //initialize count to 0
	lastmalfunctionTime = 0;  //same with time
	
}

void malfunctionRecord::malfunction(int mlfn, int tm) {  
	malfunctionCount++;  //increment count data
	lastmalfunctionTime = tm;  //set time data member to tm
	lastmalfunctionType = mlfn;  //set type data member to mlfn
}

void malfunctionRecord::display() {
	if(malfunctionCount == 0) {  //if count is 0
		cout << "Device has never malfunctioned.\n";  //print message
	}
	else {  //otherwise, print
		cout << "Number of malfunctions: " << malfunctionCount << "\n";  //count,
		cout << "Last malfunction type: " << lastmalfunctionType << "\n";  //last malfunction type, 
		cout << "Last malfunction time: " << lastmalfunctionTime << "\n";  //and last malfunction time.
	}
}

int malfunctionRecord::getRecord(int *m, int *t) {
	*m = lastmalfunctionType;  //sets m to last malfunction type
	*t = lastmalfunctionTime;  //sets t to last malfunction time
	return malfunctionCount;  //and returns count
}


////////////////////////////////////////////////////////////////////


device::device(char *n, int sn) {  //n is the name, sn is the serial number 
	//points to char array representing device name
	name = (char *) malloc(strlen(n)+1);  //allocate space to hold string n and assign returned address to device name data member
	strcpy(name, n);  //copy string n to newly allocated space
	serialnumber = sn;  //copy sn to serial number data member
	value = 0;  //set value data member to 0
	
}

device::~device() {  //frees memory allocated to hold the name data member 
	free( (char *) name);
}

void device::display() {  //display the device information 
	othername.display();
	cout << "Device Name:   " << name << "\n";
	cout << "Serial Number: " << serialnumber << "\n";
	cout << "Current Value: " << value << "\n";
	return;
}

void device::recordMalfunction(int m, int t) {  //have malfunctionRecord call its malfunction function member
	othername.malfunction(m, t);
}

int device::getMalfunctionRecord(int *m, int *t) {  //have malfunctionRecord call its getRecord function member and return answer 
	return othername.getRecord(m, t);
}

int device::amIThisDevice(char *n) {  //compare device name with arg n
	return !(strcmp(n, name));
}