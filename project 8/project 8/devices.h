#ifndef DEVICES_H
#define DEVICES_H

class malfunctionRecord {
	public:  //function members 
		malfunctionRecord();  
		void malfunction(int mlfn, int tm);  
		void display();
		int getRecord(int *m, int *t);
	private:  //data members 
		int malfunctionCount;
		int lastmalfunctionType;
		int lastmalfunctionTime;
	};
	
class device {
	public:  //function members 
		device();
		device(char *n, int sn);
		~device();
		virtual void display();
		void recordMalfunction(int m, int t);
		int getMalfunctionRecord(int *m, int *t);
		int amIThisDevice(char *n);
		virtual int getDeviceType();
		int getValue();
		virtual void setValue(int v) = 0;
		void createEvent(int tm);
	protected:  //data members
		char* name;
		int serialnumber;
		int value;
		malfunctionRecord othername;
		int type;		
	};

class DigitalSensorDevice : public device {
	public:
		DigitalSensorDevice();
		DigitalSensorDevice(char *n, int sn, int v);
		~DigitalSensorDevice();
		void display();
		void setValue(int v);
	};

class AnalogSensorDevice : public device {
	public:
		AnalogSensorDevice();
		AnalogSensorDevice(char* n, int sn, int v, int br);
		~AnalogSensorDevice();
		void display();
		void setValue(int v);
	private:
		int bits;
	};

class DigitalControllerDevice : public device {
	public:
		DigitalControllerDevice();
		DigitalControllerDevice(char* n, int sn);
		~DigitalControllerDevice();
		void display();
		void setValue(int v);
	};

class AnalogControllerDevice : public device {
	public:
		AnalogControllerDevice();
		AnalogControllerDevice(char* n, int sn, int v, int lb, int ub);
		~AnalogControllerDevice();
		void display();
		void setValue(int v);
	private:
		int lowerbound;
		int upperbound;
	};

#endif

