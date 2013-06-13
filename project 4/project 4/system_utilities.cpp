#include "definitions.h"
#include "system_utilities.h"
#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

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