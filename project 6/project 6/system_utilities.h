#ifndef SYSTEM_UTILITIES_H
#define SYSTEM_UTILITIES_H
#include "devices.h"


int parseCommandLine(char cline[], char *tklist[]);

int convertIntToValue(char *s);

int getCommandNumber(char *s);

void fillSystemCommandList();

int getDeviceTypeFromString(char* n);

device* makeDevice(char *token_list[]);

#endif