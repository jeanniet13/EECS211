#ifndef SYSTEM_UTILITIES_H
#define SYSTEM_UTILITIES_H
#include "devices.h"
#include "events.h"


int parseCommandLine(char cline[], char *tklist[]);

int convertIntToValue(char *s);

int getCommandNumber(char *s);

void fillSystemCommandList();

int getDeviceTypeFromString(char* n);

device* makeDevice(char *token_list[]);

void processEvents(LIST *evl, int tm);

void displayDashboard();

int findDevice(char *d);

void processLeftTurnSignal(EVENT *e);

void processRightTurnSignal(EVENT *e);

void processBrake(EVENT *e);

void processAccelerator(EVENT *e);

void processLeftTurnLamp(EVENT *e);

void processRightTurnLamp(EVENT *e);

#endif