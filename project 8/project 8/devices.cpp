#include "devices.h"
#include "definitions.h"
#include "events.h"
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

extern int time;
extern LIST *hat;
extern int checkEngine;


malfunctionRecord::malfunctionRecord() {  //initializing constructor
	lastmalfunctionType = NO_MALFUNCTION;  //set last malfunction type to NO_MALFUNCTION (20)
	malfunctionCount = 0;  //initialize count to 0
	lastmalfunctionTime = 0;  //same with time
	
}

void malfunctionRecord::malfunction(int mlfn, int tm) {  
	malfunctionCount++;  //increment count data
	lastmalfunctionTime = tm;  //set time data member to tm
	lastmalfunctionType = mlfn;  //set type data member to mlfn
	if (lastmalfunctionTime > 0)
		checkEngine = 1;
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

device::device() {}

device::device(char *n, int sn) {  //n is the name, sn is the serial number 
	//points to char array representing device name
	name = (char *) malloc(strlen(n)+1);  //allocate space to hold string n and assign returned address to device name data member
	strcpy(name, n);  //copy string n to newly allocated space
	serialnumber = sn;  //copy sn to serial number data member
	value = 0;  //set value data member to 0
	type = GENERIC;
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

int device::getDeviceType() {
	return type;
}

int device::getValue() {
	return value;
}

void device::createEvent(int tm) {
	EVENT* newEvent = new EVENT(name, value, tm);
	hat->insertEvent(newEvent);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

DigitalSensorDevice::DigitalSensorDevice() {}

DigitalSensorDevice::DigitalSensorDevice(char* n, int sn, int v):device(n, sn) {
	value = v;
	type = DIGITAL_SENSOR;
}

DigitalSensorDevice::~DigitalSensorDevice() {  //frees memory allocated to hold the name data member 
	free( (char *) name);
}

void DigitalSensorDevice::display() {
	device::display(); 
	cout << "This is a digital sensor device.\n";
	if(value==ON) 
		cout << "This device is currently ON.\n";
	else if(value==OFF)
		cout << "This device is currently OFF.\n";
}

void DigitalSensorDevice::setValue(int v) {
	if(v==ON || v==1) 
		value = ON;
	else
		value = OFF;
	if (time > 0)
		device::createEvent(time);
}

////////////////////////////////////////////////////////////////////////////////

AnalogSensorDevice::AnalogSensorDevice() {}

AnalogSensorDevice::AnalogSensorDevice(char* n, int sn, int v, int br):device(n, sn) {
	type = ANALOG_SENSOR;
	if (br < 1 || br > 16) 
		bits = 8;
	else 
		bits = br;
	AnalogSensorDevice::setValue(v);
}

AnalogSensorDevice::~AnalogSensorDevice() {  //frees memory allocated to hold the name data member 
	free( (char *) name);
}

void AnalogSensorDevice::display() {
	device::display();
	cout << "This is an analog sensor device.\n";
	cout << "This resolution is " << bits << " and the value is " << value << ".\n";
}

void AnalogSensorDevice::setValue(int v) {
	float s = bits;
	float r = pow (2,s);
	float x = r - 1;
	if (v < 0) {
		value = 0; }
	else if (v > x) {
		value = r - 1; }
	else {
		value = v; }
	if (time > 0)
		device::createEvent(time);
}

/////////////////////////////////////////////////////////////////////////////////

DigitalControllerDevice::DigitalControllerDevice() {}

DigitalControllerDevice::DigitalControllerDevice(char* n, int sn):device(n, sn) {
	value = OFF;
	type = DIGITAL_CONTROLLER;
}

DigitalControllerDevice::~DigitalControllerDevice() {
	free( (char *) name);
}

void DigitalControllerDevice::display() {
	device::display(); //DOUBLE CHECK IF THIS NEEDS void
	cout << "This is a digital controller device.\n";
	if(value==ON) 
		cout << "This device is currently ON.\n";
	else if(value==OFF)
		cout << "This device is currently OFF.\n";
}

void DigitalControllerDevice::setValue(int v) {
	if(v==ON || v==1) 
		value = ON;
	else
		value = OFF;
}

/////////////////////////////////////////////////////////////////////////////

AnalogControllerDevice::AnalogControllerDevice() {}

AnalogControllerDevice::AnalogControllerDevice(char* n, int sn, int v, int ub, int lb):device(n, sn) {
	lowerbound = lb;
	upperbound = ub;
	type = ANALOG_CONTROLLER;
	AnalogControllerDevice::setValue(v);
}

AnalogControllerDevice::~AnalogControllerDevice() {
	free( (char *) name);
}

void AnalogControllerDevice::display() {
	device::display();
	cout << "This is an analog controller device with range " <<  lowerbound << " to " << upperbound << ".\n";
	cout << "The value is " << value << ".\n";
}

void AnalogControllerDevice::setValue(int v) {
	if (v < lowerbound) {
		value = lowerbound;
		cout << "Value argument for " << name << " is too low.\n\n";
	}
	else if (v > upperbound) {
		value = upperbound;
		cout << "Value argument for " << name << " is too high.\n\n";
	}
	else {
		value = v;
	}
}

