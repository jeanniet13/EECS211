/*	EECS 211 Program 4 

Author: Jeannie Tran / Computer Science / 2583406 / jtr121

Purpose: Learn to do command line and write functions 

*/
#include "definitions.h"
#include "system_utilities.h"
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream infile ("p4input.txt");
	char cline[MAX_CMD_LINE_LENGTH];
	char* tklist[MAX_TOKENS_ON_A_LINE];
	int j;	
	for(j = 0; j < 7; j++) {
		infile.getline(cline, MAX_CMD_LINE_LENGTH);
		//cout << cline << "\n"; 		
		int r = parseCommandLine(cline, tklist);
		//cout << r << "\n";
		free((char *)tklist[j]);
		memset(cline, 0, MAX_CMD_LINE_LENGTH);
	}

	char rawr;
	cout << "Enter any letter, and then press enter to terminate:";  //prompt user to terminate program
	cin >> rawr;
	return 1;
}


