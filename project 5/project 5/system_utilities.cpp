#include "definitions.h"
#include "system_utilities.h"
#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

/*
int parseCommandLine(char cline[], char *tklist[]) {	
	memset(tklist, 0, MAX_TOKENS_ON_A_LINE);
	int string_length, k, token_start, token_length;
	int counter = 0;
	string_length = strlen(cline);
	cout << string_length << "  " << cline << "\n";

	int lookingfornonblank = 1;
	for(k = 0; k < string_length; k++) {
		if(cline[k] != ' ' && lookingfornonblank == 1) {
			//cout << k << "\n";
			if(cline[k] == '"') {
				token_start = k + 1;
				lookingfornonblank = -1;
			}
			else {
				lookingfornonblank = 0;
				token_start = k;
			}
		}
		else if(cline[k] == ' ' && lookingfornonblank == 0) {
			//cout << k << "\n";
			lookingfornonblank = 1;
			token_length = k - token_start;			
			tklist[counter] = (char *)malloc(token_length + 1);
			memset(tklist[counter], 0, token_length + 1);
			memcpy(tklist[counter], cline + token_start, token_length);
			cout << tklist[counter] << "\n";
			counter++;
			
		}
		else if(cline[k] == '"' && lookingfornonblank == -1) {
			//cout << k << "\n";
			lookingfornonblank = 1;
			token_length = k - token_start;			
			tklist[counter] = (char *)malloc(token_length + 1);
			memset(tklist[counter], 0, token_length + 1);
			memcpy(tklist[counter], cline + token_start, token_length);
			cout << tklist[counter] << "\n";
			counter++;			
		}
	}

	if(lookingfornonblank == 0 || lookingfornonblank == -1) {
		//cout << k << "\n";
		lookingfornonblank = 1;
		token_length = string_length - token_start;			
		tklist[counter] = (char *)malloc(token_length + 1);
		memset(tklist[counter], 0, token_length + 1);
		memcpy(tklist[counter], cline + token_start, token_length);
		cout << tklist[counter] << "\n";
		counter++;		
	}
	//cout << counter << "\n";
	return counter;
};

*/

//////////////////////////////////////////////////////////////////////

// This file contains functions used at the system and main level.


int parseCommandLine(char line[], char * token_list[]) {
	int  number_of_tokens;
	char *curchar, *token_start;
	int  token_length;
	char delimiter;

	number_of_tokens = 0;

	// Find first non_blank character.
	curchar = line;
	while( (*curchar==' ') ) curchar++;
	
	// Loop to break out individual tokens. curchar points to the 
	// first (or next, on successive iterations) non-blank character
	// at the start of the loop.  When that character is the NULL
	// character (string terminator), the loop should exit.
	while(*curchar!=0) {
		if(*curchar=='"') {
			// This token is enclosed in quotes.
			   curchar++;             // move past the quote mark
			   delimiter = '"';       // We need to look for a quote at the end
		}
		else {
			// This token is just surrounded by blanks
			   delimiter = ' ';       // We need to look for a blank at the end
		}
		token_start = curchar;	      // remember where token starts

		// Now find end of token.
		do { curchar++; } while( (*curchar!=delimiter) && (*curchar!=0) );

		// malloc a char block one longer than token, copy token and 
		// add end of string NULL marker.
		token_length = curchar-token_start+1;
		token_list[number_of_tokens] = (char *)malloc(token_length);
		
		memcpy(token_list[number_of_tokens], token_start, token_length-1);
		token_list[number_of_tokens][token_length-1] = 0;

		// Count the new token.
		number_of_tokens++;
		
		// If the array is filled up, quit.
		if(number_of_tokens>=MAX_TOKENS_ON_A_LINE) return number_of_tokens;

		// Now move curchar to the next non-blank or end of line.
		if(*curchar == '"') curchar++;
		while( (*curchar==' ') ) curchar++;
	}

	return number_of_tokens;
}




//////////////////////////////////////////////////////////////////////

class COMMAND {
	public:
		COMMAND(char *x, int y);
		~COMMAND();
		int amIThisCommand(char *z);
	private:
		char* a;
		int b;
};

//////////////////////////////////////////////////////////////////////

COMMAND::COMMAND(char *x, int y) {
	int rawr = strlen(x);
	a = (char *) malloc(rawr+1);  
	strcpy(a,x);
	b = y;
}

int COMMAND::amIThisCommand(char *z) {
	if(!(strcmp(z, a))) {
		return b;
	}
	else {
		return 0;
	}
}

//////////////////////////////////////////////////////////////////////

COMMAND* systemCommands[NUMBER_OF_COMMANDS];

void fillSystemCommandList() {
	systemCommands[0] = new COMMAND("halt", HALT);
	systemCommands[1] = new COMMAND("status", STATUS);
	systemCommands[2] = new COMMAND("time_click", TIME_CLICK);
	systemCommands[3] = new COMMAND("create_device", CREATE_DEVICE);
	systemCommands[4] = new COMMAND("create_event", CREATE_EVENT);
	systemCommands[5] = new COMMAND("set_device_value", SET_DEVICE_VALUE);
	systemCommands[6] = new COMMAND("process_events", PROCESS_EVENTS);
	
};

int getCommandNumber(char *s) {
	int value = 0;
	for (int i = 0; i < NUMBER_OF_COMMANDS; i++) {
		if (value = systemCommands[i] -> amIThisCommand(s)) {
			return value;
		}
	}
	return UNDEFINED_COMMAND;
};


int convertIntToValue(char *s) {
	int strlength = strlen(s);
	int value = 0;
	//value = atoi(s);
	
	for(int k = 0; k < strlength; k++) {
		value = value*10 + (s[k] - 48);
	}
	
	return value;
};
