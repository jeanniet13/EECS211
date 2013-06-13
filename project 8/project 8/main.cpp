/*	EECS 211 Project 

Author: Jeannie Tran / Computer Science / 2583406 / jtr121

Purpose: putting everything together 

*/
#include "definitions.h"
#include "system_utilities.h"
#include "devices.h"
#include "events.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

char cline[MAX_CMD_LINE_LENGTH];
char* tklist[MAX_TOKENS_ON_A_LINE];
device* systemDevices[MAX_DEVICES];
device* cat; 
LIST* hat = new LIST();
EVENT* mat;
int checkEngine = 0;
int j;	
int devices = 0;
int time = 0;
int p;
int q;

int main() {
	ifstream infile ("p8input.txt");	
	
	fillSystemCommandList();
	for(j = 0; j < 50; j++) {
		infile.getline(cline, MAX_CMD_LINE_LENGTH);
		//cout << cline << "\n"; 		
		int r = parseCommandLine(cline, tklist);
		//cout << r << "\n";
		//cout << tklist[0] << "\n";
		switch (getCommandNumber(tklist[0])) {
			case HALT: 
				break;
			case STATUS:
				if (strcmp(tklist[1], "devices") == 0) {
					cout << "Printing device status information: \n\n";
					cout << "Current time is " << time << " and number of devices is " << devices << ".\n\n";
					for (int i=0; i<devices; i++) {
						systemDevices[i] -> display();
						cout << "\n\n";
					}
				}
				else {
					cout << "Printing event status information: \n\n";
					hat->display();
				}
				
				//cout << "Command " << tklist[0] << " recognized.\n";
				//cout << "Value of second token is " << convertIntToValue(tklist[1]) << ".\n";
				break;
			case TIME_CLICK:			
				time++;
				processEvents(hat, time);
				displayDashboard();
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
				mat = new EVENT(tklist[1], convertIntToValue(tklist[2]), convertIntToValue(tklist[3]));
				hat->insertEvent(mat); 
				break;
			case SET_DEVICE_VALUE:
				p = findDevice(tklist[1]);
				q = convertIntToValue(tklist[2]);
				systemDevices[p]->setValue(q);
				break;
			case PROCESS_EVENTS:
			
				processEvents(hat, time);
				cout << "Command " << tklist[0] << " recognized.\n\n";
				break;
			case MALFUNCTION:
				p = findDevice(tklist[1]);
				q = convertIntToValue(tklist[2]);
				systemDevices[p]->recordMalfunction(q, time);
				break;
			default:
				cout << "Command not recognized.\n\n";
		}
		free((char *)tklist[0]);
		memset(cline, 0, MAX_CMD_LINE_LENGTH);
	}
	
	char rawr;
	cout << "Enter any letter, and then press enter to terminate:";  //prompt user to terminate program
	cin >> rawr;
	return 1;
}