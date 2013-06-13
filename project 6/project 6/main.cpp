/*	EECS 211 Project 6

Author: Jeannie Tran / Computer Science / 2583406 / jtr121

Purpose: learning about inheritance   

*/
#include "definitions.h"
#include "system_utilities.h"
#include "devices.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

/*
//Input file.
ifstream inp;

//Array of devices and how man are actually created.
device *systemDevices[MAX_DEVICES];
int numberOfDevices = 0;

case CREATE_DEVICE:
	if(numberOfDevices>=MAX_DEVICES) {
		cout << "****ERROR"
			 << parsed_command[2] << 
		break;
	}
	tempDevice = makeDevice(parsed_command);
	if(tempdevice == null)
		cout << "***ERROR"
		     << parsed_command[2] << ".
	else systemDevices[numberofdevices++] = tempdevices
	break;

*/

/////////////////////////////////////////////////////////////////////////////////////////////
int main() {
	ifstream infile ("p6input.txt");
	
	char cline[MAX_CMD_LINE_LENGTH];
	char* tklist[MAX_TOKENS_ON_A_LINE];
	device* systemDevices[MAX_DEVICES];
	device* cat; 
	int j;	
	int devices = 0;
	int time = 0;
	fillSystemCommandList();
	for(j = 0; j < 13; j++) {
		infile.getline(cline, MAX_CMD_LINE_LENGTH);
		//cout << cline << "\n"; 		
		int r = parseCommandLine(cline, tklist);
		//cout << r << "\n";
		//cout << tklist[0] << "\n";
		switch (getCommandNumber(tklist[0])) {
			case HALT: 
				break;
			case STATUS:
				cout << "Current time is " << time << " and number of devices is " << devices << ".\n\n";
				for (int i=0; i<devices; i++) {
					systemDevices[i] -> display();
					cout << "\n\n";
				}
				
				//cout << "Command " << tklist[0] << " recognized.\n";
				//cout << "Value of second token is " << convertIntToValue(tklist[1]) << ".\n";
				break;
			case TIME_CLICK:			
				time++;
				break;
			case CREATE_DEVICE:
				if (devices > MAX_DEVICES) {
					cout << "ERROR: NO MORE SPACE IN SYSTEM.\n";
				}
				else {
					cat = makeDevice(tklist);
					if (cat == NULL) {
						cout << "Device " << tklist[2] << " could not be created.\n\n";
					}
					else {
						systemDevices[devices] = cat;
						devices++;
					}
				}
				break;					
			case CREATE_EVENT:
			case SET_DEVICE_VALUE:
			case PROCESS_EVENTS:
				cout << "Command " << tklist[0] << " recognized.\n";
				break;
			default:
				cout << "Command not recognized.\n";
		}
		free((char *)tklist[0]);
		memset(cline, 0, MAX_CMD_LINE_LENGTH);
	}
	
	char rawr;
	cout << "Enter any letter, and then press enter to terminate:";  //prompt user to terminate program
	cin >> rawr;
	return 1;
}