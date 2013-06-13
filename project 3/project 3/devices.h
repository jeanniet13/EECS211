using namespace std;

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
		device(char *n, int sn);
		~device();
		void display();
		void recordMalfunction(int m, int t);
		int getMalfunctionRecord(int *m, int *t);
		int amIThisDevice(char *n);
	private:  //data members
		char* name;
		int serialnumber;
		int value;
		malfunctionRecord othername;
		
		
	};