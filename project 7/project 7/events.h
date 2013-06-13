#ifndef EVENTS_H
#define EVENTS_H

class LIST;
class EVENT;

// Linked list class and node class.
class LLNODE {
	friend class LIST;
	
	private:
		LLNODE *next;
		EVENT  *ev;
		
	public:
		LLNODE();
		LLNODE(EVENT *e);
		~LLNODE();
};

class LIST {
	private:
		LLNODE *front;
		
	public:
		LIST();
		~LIST();
		void display();
		EVENT *getFirstEvent();
		void removeFirstEvent();
		void insertEvent(EVENT *e);
};



// Event class.

class EVENT {
	private:
		char *device;
		int value;
		int processTime;
		
	public:
		EVENT(char *n, int v, int pt);
		~EVENT();
		void display();
		int getprocessTime();
};


#endif

