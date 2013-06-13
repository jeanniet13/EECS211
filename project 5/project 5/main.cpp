/*	EECS 211 Program 5

Author: Jeannie Tran / Computer Science / 2583406 / jtr121

Purpose: Learn to do command line and write functions 

*/
#include "definitions.h"
#include "system_utilities.h"
#include <iostream>
#include <fstream>
using namespace std;


int main() {
	ifstream infile ("p5input.txt");
	char cline[MAX_CMD_LINE_LENGTH];
	char* tklist[MAX_TOKENS_ON_A_LINE];

	int j;	
	fillSystemCommandList();
	for(j = 0; j < 12; j++) {
		infile.getline(cline, MAX_CMD_LINE_LENGTH);
		//cout << cline << "\n"; 		
		int r = parseCommandLine(cline, tklist);
		//cout << r << "\n";
		//cout << tklist[0] << "\n";
		switch (getCommandNumber(tklist[0])) {
			case HALT: 
				break;
			case STATUS:
				cout << "Command " << tklist[0] << " recognized.\n";
				cout << "Value of second token is " << convertIntToValue(tklist[1]) << ".\n";
				break;
			case TIME_CLICK:			
			case CREATE_DEVICE:
			case CREATE_EVENT:
			case SET_DEVICE_VALUE:
			case PROCESS_EVENTS:
				cout << "Command " << tklist[0] << " recognized.\n";
				break;
			default:
				cout << "Command not recognized.\n";
		}
		//for (int m = 0; tklist[m]!=NULL; m++) {
			//free((char *)tklist[m]);
		//}
		free((char *)tklist[0]);
		memset(cline, 0, MAX_CMD_LINE_LENGTH);
	}

	char rawr;
	cout << "Enter any letter, and then press enter to terminate:";  //prompt user to terminate program
	cin >> rawr;
	return 1;
}


