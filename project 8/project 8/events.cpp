#include "devices.h"
#include "definitions.h"
#include "events.h"
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

LLNODE::LLNODE() {}

LLNODE::LLNODE(EVENT *e) {
	ev = e;
	next = NULL;
}

LLNODE::~LLNODE() {  
	free( (void *) ev);
}

//---------------------------------------------------------------------------------------------------


LIST::LIST() {
	front = NULL;
}

LIST::~LIST() {
	LLNODE* index;
	index = front; 
	LLNODE* temp;
	temp = front;
	while (temp != NULL) {
		index = temp;
		delete index;
		temp = temp->next;
	}
}

void LIST::display() {
	LLNODE* tempptr;
	tempptr = front;
	cout << "Displaying event list:\n\n";
	if(tempptr == NULL) {
		cout << "\t\t\tEMPTY\n\n";
	}
	
	else {
		while(tempptr != NULL) {
			(tempptr->ev)->display();
			cout<< "\n\n --> \n\n";
			tempptr = tempptr -> next;
		}
		cout << "NULL\n\n";
	}
}

EVENT* LIST::getFirstEvent() {
	if (front != NULL) {
		return front->ev;
	}
	else {
		return NULL;
	}
}

void LIST::removeFirstEvent() {
	if (front != NULL) {
		LLNODE* remove = front;
		front = front->next;
		delete remove;
	}
	else {
		return;
	}
}

void LIST::insertEvent(EVENT *e) {
	LLNODE* newnode = new LLNODE(e);
	
	if (front == NULL) {
		front = newnode;
		return;
	}
	else {		
		LLNODE* beforeptr;
		beforeptr = NULL;
			
		LLNODE* afterptr;
		afterptr = front;
		
		if (front == NULL) {
			front = newnode;
			return;
		}

		while (afterptr != NULL) {
			if (afterptr->ev->getprocessTime() > e->getprocessTime()) {
				break;
			}
			else {
				beforeptr = afterptr;
				afterptr = afterptr->next;
			}
		}
		if (beforeptr == NULL) {
			newnode->next = front;
			front = newnode;			
		}
		else {
			beforeptr->next = newnode;
			newnode->next = afterptr;
		}	
	}
}
	
void LIST::removeEventsNamed(char *d) {
	if (front == NULL) {
		return;
	}
	else {		
		LLNODE* beforeptr;
		beforeptr = NULL;
			
		LLNODE* afterptr;
		afterptr = front;

		LLNODE* lastptr;
		lastptr = NULL;
		
		if (front == NULL) {
			return;
		}

		while (afterptr != NULL) {
			if (afterptr->ev->isThisMyDevice(d) == 1) {
				break;
			}
			else {
				beforeptr = afterptr;
				afterptr = afterptr->next;
			}
		}
			
		if (beforeptr == NULL) {
			LLNODE* remove = front;
			front = front->next;
			delete remove;		
		}
		else if (afterptr->next == NULL) {
			beforeptr->next = NULL;
			delete afterptr;
		}
		else  {
			LLNODE* remove = afterptr;
			afterptr = afterptr->next;
			delete remove;
			
		}	
	}
}
	


//---------------------------------------------------------------------------------------------------

EVENT::EVENT(char *n, int v, int pt) {
	device = (char *) malloc(strlen(n)+1);  //allocate space to hold string n and assign returned address to device name data member
	strcpy(device, n);
	value = v;
	processTime = pt;
}

EVENT::~EVENT() {  //frees memory allocated to hold the name data member 
	free( (char *) device);
}

int EVENT::getprocessTime() {
	return processTime;
}

void EVENT::display() {
	cout << "EVENT:     Device: " << device << "\n";
	cout << "Device value " << value << ".     Scheduled to be processed at " << processTime << ".\n\n\n";
}

int EVENT::isThisMyDevice(char *d) {
	return !(strcmp(d, device));
}

int EVENT::getValue() {
	return value;
}