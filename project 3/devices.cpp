#include "devices.h"
#include "definitions.h"


malfuntionRecord::malfunctionRecord() {
	lastmalfunctionType = NO_MALFUNCTION;
	malfunctionCount = 0;
	lastmalfunctionTime = 0;
	
}

void malfunctionRecord::malfunction(int mlfn, int tm) {
	malfunctionCount++;
	lastmalfunctionTime = tm;
	lastmalfunctionType = mlfn;
}

void malfunctionRecord::display() {
	if(malfunctionCount == 0) {
		cout << "Device has never malfunctioned.\n";
	}
	else {
		cout << "Number of malfunctions: " << malfunctionCount << "\n";
		cout << "Last malfunction type: " << lastmalfunctionType << "\n";
		cout << "Last malfunction time: " << lastmalfunctionTime << "\n";
	}
}

int malfunctionRecord::getRecord(int *m, int *t) {
	lastmalfunctionType = m;
	lastmalfunctionTime = t;
	return malfunctionCount;
}


////////////////////////////////////////////////////////////////////


device::device(char *n, int sn) {
	int length = strlen(*n);
	name = (char *)malloc(strlen(n) +1);
	void strcpy(char*,char*);
	
	value = 0;
	
}

device::~device {

}

void device::display() {
	cout << "Device Name:   " << "\n";
	cout << "Serial Number: " << serialnumber << "\n";
	cout << "Current Value: " << value << "\n";
	return;
}

void device::recordMalfunction(int m, int t) {
	malfunctionRecord::malfunction(m, t);
}

int device::getMalfunctionRecord(int *m, int *t) {
	return malfunctionRecord::getRecord(*m, *t);
}

int device::amIThisDevice(char *n) {
	int issame = strcmp(*n,name);
	if (issame == 0) {
		return 1;
	} else {
		return 0;
	}
}